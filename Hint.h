#ifndef HINT_H
#define HINT_H

#include "GameObject.h"
#include <QString>

class Hint : public GameObject {
public:
    Hint(QPoint position ,int sequenceIndex, const QString &message, bool isTreasure = false);

    int  getSequenceIndex() const;
    bool isActive()         const;
    bool isCollected()      const;
    QString getMessage()    const;

    void activate();   // called by Game when the previous hint is collected
    void collect();    // called when the player reaches this hint

    void update() override;   // pulse animation, only when active
    void draw(QPainter &painter, QPoint cameraOffset) override; // only draws when active
    bool isTreasure() const;
private:
    int     sequenceIndex;
    QString message;
    bool    active;
    bool    collected;
    int     pointValue;
    bool Treasure;
    float pulsePhase;
    static constexpr float PULSE_SPEED = 0.08f;
};

#endif
