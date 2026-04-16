#include "GameStateManager.h"

GameStateManager::GameStateManager() : state(newState::Menu) {}
void GameStateManager::setState(GameState newState){State = newState;}
GameState GameStateManager::getState() const{ return state; }
bool GameStateManager::isPlaying() const { return state == GameState::PLAYING;}
bool GameStateManager::isPaused()  const { return state == GameState::PAUSED; }
bool GameStateManager::isOver() const {
	return State == GameState::Win || State == GameState::Lose;
}
