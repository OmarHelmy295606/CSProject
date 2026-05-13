#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

Game::Game(int screenWidth, int screenHeight) :
	screenWidth(screenWidth),
	screenHeight(screenHeight),
	currentLevel(1),
	currentHintIndex(0),
	cameraOffset(0, 0),
	activeMessage(""),
	messageActive(false),
	collectionRadius(40)
{
	stateManager = new GameStateManager();
	player = nullptr;

	std::srand(static_cast<unsigned>(std::time(nullptr)));
}

Game::~Game(){
	delete player;
	delete stateManager;
	qDeleteAll(hints);
	hints.clear();
}


void Game::loadLevel(int levelNumber){
	currentLevel = levelNumber;
	activeConfig = getLevel(levelNumber);
	mapWidth = activeConfig.mapWidth;
	mapHeight = activeConfig.mapHeight;
	oxygenDrainRate = activeConfig.oxygenDrainRate;

	delete player;
	player = new Player("placeholder", activeConfig.playerStartPos);
	player->setMapBounds(mapWidth, mapHeight);
	if(!playerName.isEmpty())
		player->setName(playerName);

	qDeleteAll(hints);
	hints.clear();
	spawnHints();

	currentHintIndex = 0;
	activeMessage    = "";
	messageActive    = false;
	cameraOffset     = QPoint(0, 0);
	updateCamera();
	stateManager->setState(GameState::Playing);

	player->resetOxygen();
}


void Game::start(const QString& name, int levelNum){
	playerName = name;
	loadLevel(levelNum);
}

void Game::reset(){
	loadLevel(currentLevel);
}


void Game::spawnHints(){

	for(int i =0; i< activeConfig.hints.size(); i++){
		const HintData &hd = activeConfig.hints[i];
		Hint* h = new Hint(hd.position, i, hd.message, hd.isTreasure);
		if(i==0)
			h->activate();
		hints.append(h);
	}

}

void Game::update(){
	if(!stateManager->isPlaying()) return;
	if(!player) return;
	player->update();
	updateCamera();
	for(Hint* h : hints)
		h->update();
	checkCollisions();

	checkWinCondition();
	if(checkLoseCondition())
		stateManager->setState(GameState::Lose);
}

void Game::updateCamera(){
	int cx = player->getPosition().x() - screenWidth  / 2;
	int cy = player->getPosition().y() - screenHeight / 2;

	cx = qMax(0, qMin(cx, mapWidth  - screenWidth));
	cy = qMax(0, qMin(cy, mapHeight - screenHeight));

	cameraOffset = QPoint(cx, cy);
}

QPoint Game::getCameraOffset() const {
	return cameraOffset;
}

void Game::checkCollisions(){
	if (currentHintIndex >= hints.size()) return;

	Hint* active = hints[currentHintIndex];
	QPoint playerPos = player->getPosition();
	QPoint hintPos = active->getPosition();

	int dx = playerPos.x() - hintPos.x();
	int dy = playerPos.y() - hintPos.y();
	int dist = static_cast<int>(std::sqrt(dx * dx + dy * dy));

	 if (dist < collectionRadius)
		onHintCollected(currentHintIndex);

}


void Game::onHintCollected(int index){
	hints[index]->collect();
	activeMessage = hints[index]->getMessage();
	messageActive = true;
	currentHintIndex++;

	if (currentHintIndex < hints.size())
        	hints[currentHintIndex]->activate();
}

QString Game::getCurrentMessage() const{
	return activeMessage;
}

bool Game::hasActiveMessage() const{
	return messageActive;
}

void Game::dismissMessage(){
	messageActive = false;
	activeMessage = "";
}

bool Game::checkWinCondition(){
	for(Hint* h :hints)
		if(!h->isCollected()) return false;

	if(currentLevel<3)
		stateManager->setState(GameState::LEVEL_COMPLETE);
	else
		stateManager->setState(GameState::Win);


	return true;
}

bool Game::checkLoseCondition(){
	return player->getOxygenLevel() <= 0.0f;
}

void Game::tickOxygen(){
	if(!stateManager->isPlaying()) return;
	player->depleteOxygen(oxygenDrainRate);
}

void Game::setPlayerMoving(Qt::Key key, bool pressed) {
	player->setMoving(key, pressed);
}

Player* Game::getPlayer() const {return player;}
QList<Hint*> Game::getHints() const {return hints;}
GameStateManager* Game::getStateManager() const {return stateManager;}
int Game::getCurrentHintIndex() const {return currentHintIndex;}
int Game::getCurrentLevel() const {
    return currentLevel;
}

int Game::getMapWidth() const {
    return mapWidth;
}

int Game::getMapHeight() const {
    return mapHeight;
}

QString Game::getLevelName() const {
    return activeConfig.levelName;
}

QString Game::getIntroText() const {
    return activeConfig.introText;
}
int Game::getTorchRadius() const{
	return activeConfig.torchRadius;
}
