#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

Game::Game(int mapWidth, int mapHeight, int screenWidth, int screenHeight) :
	mapWidth(mapWidth),
	mapHeight(mapHeight),
	screenWidth(mapWidth),
	screenHeight(screenHeight),
	currentHintItem(0),
	cameraOffset(0, 0),
	activeMessage(""),
	messageActive(false),
	oxygenDrainRate(2.0f),
	collectionRadius(40)
{
	stateManager = new GameStateManager();
	player = new Player(QPoint(mapWidth / 2, mapHeight / 2));
	player->setMapBounds(mapWidth, mapHeight);
	std::srand(static_cast<unsigned>(std::time(nullptr)));
}

Game::~Game(){
	delete player;
	delete stateManager;
	qDeleteAll(hints);
	hints.clear;
}


void Game::start(){
	player->setName(playerName);
	reset();
}

void Game::reset(){
	player->setPosition(QPoint(mapWidth / 2, mapHeight / 2));
	player->resetOxygen();
	qDeleteAll(hints);
	hints.clear();
	spawnHints();

	currentHintIndex = 0;
	activeMessage = "";
	messageActive = false;

	cameraOffset = QPoint(0, 0);
	updateCamera();
	setManager->setState(GameState::Playing);
}


void Game::spawnHints(){
	struct HintData {
		QPoint  pos;
        	QString message;
    	};

	QList<HintData> hintDate = {
		{ QPoint(300,  400),  "The sea holds secrets... follow the broken anchor." },
        	{ QPoint(800,  700),  "Near the sunken mast, something gleams..." },
        	{ QPoint(1400, 500),  "The old hull hides a clue beneath its shadow." },
      		{ QPoint(1900, 900),  "Dive deeper — the treasure chest awaits." }
	};

	for(int i =0; i< hintData.size(); i++){
		Hint h* new Hint(hintData[i].pos, i, hintData[i].message;
		if(i==0)
			h->activate();
		hints.append(h);
	}

}

void Game::update(){
	if(!stateManager->isPlaying()) return;

	player->update();
	updateCamera();
	for(Hint* h : hints)
		h->update();
	checkCollisions();

	if(checkWinCondition())
		stateManager->setState(GameState::WIN);
	else if(checkLoseCondition())
		stateManager->setState(GameState::LOSE);
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

	Hint* active = hints[currentHintItem];
	QPoint playerpos = player->getPosition();
	QPoint hintpos = active->getPosition();

	int dx = playerPos.x() - hintPos.x();
	int dy = playerPos.y() - hintPos.y();
	int dist = static_cast<int>(std::sqrt(dx * dx + dy * dy));

	 if (dist < collectionRadius)
		onHintCollected(currentHintIndex);

}


void Game::onHintCollected(int index){
	hints[index]->collect;
	activeMessage = hint[index]->getMessage();
	messageActive = true;
	currentHintIndex++;

	if (currentHintIndex < hints.size())
        	hints[currentHintIndex]->activate();
}

QString Game::getCurrentMessage() const{
	return activeMessgae;
}

bool Game::hasActiveMessage() const{
	return messageActive;
}

void Game::dismissMessage(){
	messageActive = false;
	activeMessage = "";
}

bool Game::checkWinCondition(){
	for(Hint* hint :hints)
		if(!h->isCollected()) return false;
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
QList<Hints*> Game::getHints() const {return hints;}
GameStateManager Game::getStateManager() const {return stateManager;}
int Game::getCurrentHintIndex() const {return currentHintIndex;}

