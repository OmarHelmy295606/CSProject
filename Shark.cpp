#include "Shark.h"

#include <QPainter>
#include <cmath>

Shark::Shark(QPoint startPos, int size, int speed)
    : GameObject(startPos, size),
      speed(speed),
      targetPosition(startPos)
{
}

void Shark::setTarget(QPoint playerPos) {
    targetPosition = playerPos;
}

void Shark::update() {
    int dx = targetPosition.x() - position.x();
    int dy = targetPosition.y() - position.y();

    float length = std::sqrt(dx * dx + dy * dy);

    if (length > 0) {
        dx = static_cast<int>((dx / length) * speed);
        dy = static_cast<int>((dy / length) * speed);

        position.rx() += dx;
        position.ry() += dy;
    }
}

void Shark::draw(QPainter &painter, QPoint cameraOffset) {
    QPoint screenPos = position - cameraOffset;

    painter.setBrush(Qt::red);
    painter.setPen(Qt::black);

    painter.drawEllipse(screenPos, size, size);
}

bool Shark::collidesWith(QPoint playerPos, int playerSize) {
    int dx = playerPos.x() - position.x();
    int dy = playerPos.y() - position.y();

    int distanceSquared = dx * dx + dy * dy;
    int minDistance = size + playerSize;

    return distanceSquared <= (minDistance * minDistance);
}
