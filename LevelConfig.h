#pragma once

#include <QString>
#include <QPoint>
#include <QList>

enum class SceneryType{
	SUNKEN_SHIP,
	RUIN_PILLAR,
	CORAL,
	ROCK,
	SEAWEED
};

struct SceneryObject{
	SceneryType type;
	QPoint position;
	int size;
	int colorIndex;
};

struct HintData {
	QPoint position;
	QString message;
	bool isTreasure;
	HintData(QPoint pos, QString msg, bool treasure = false)
	: position(pos), message(msg), isTreasure(treasure) {}
};

struct LevelConfig {
	int levelNumber;
	QString levelName;
	QString introText;

	int mapWidth;
	int mapHeight;
	int oxygenDrainRate;
	int torchRadius;
	int numSharks;

	QPoint playerStartPos;
	QList<HintData> hints;
	QList<SceneryObject> scenery;
};




