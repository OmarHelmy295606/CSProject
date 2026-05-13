#ifndef SHARK_H
#define SHARK_H

#include "GameObject.h"

class Shark : public GameObject {
public:
    Shark(QPoint startPos, int size = 40, int speed = 3);

    void setTarget(QPoint playerPos);

    void update() override;
    void draw(QPainter &painter, QPoint cameraOffset) override;

    bool collidesWith(QPoint playerPos, int playerSize);

private:
    QPoint targetPosition;
    int speed;
};

#endif
