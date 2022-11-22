#ifndef MARIO_H
#define MARIO_H
#include "../gamescene.h"
#include "entity.h"
#include <QPixmap>

class GameScene;
class Mario : public Entity {
public:
    Mario();
    static constexpr const float MOVE_SPEED = 80.0f;
    static constexpr const float RUN_SPEED  = 12.0f;
    static constexpr const float JUMP_SPEED = 400.0f;
    static constexpr const float DRAG_VALUE = 3.0f;
    static constexpr const float MAX_MOVE_SPEED = 180.0f;
    static constexpr const float MAX_RUN_SPEED = 12.0f;
    static constexpr const float MAX_FALLDOWN_SPEED = 100.0f;
    // Entity interface
public:
    virtual void draw(GameScene &scene) override;
    virtual void update(float elapsedTime) override;
    void update(float elapsedTime, GameScene& scene);
private:
    void clampVelocities(float elapsedTime);
    void checkCollisionWithBlocks();
    QRectF hitBox();
    QPixmap m_pixmap;
    float m_velocityX, m_velocityY;
    bool m_onGround, m_runMode;
};

#endif // MARIO_H