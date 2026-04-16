#pragma once

enum class GameState{
	Menu;
	Playing;
	Paused;
	Win;
	Lose;
};

class GameStateManager{
public:
	GameStateManager();
	void setState(GameState newState);
	GameState getState() const;
	bool isPlaying() const;
	bool isPaused() const;
	bool isOver() const;
private:
	GameState state;
};
