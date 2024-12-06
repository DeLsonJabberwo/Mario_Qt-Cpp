#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QElapsedTimer>
#include <QTimer>
#include "utils/mapmanager.h"
#include "utils/global.h"
//#include "entities/mario.h"
class Mario;
struct KeyStatus
{
    bool m_held = false;
    bool m_released = false;
};

struct MouseStatus
{
    float m_x = 0.0f;
    float m_y = 0.0f;
    bool m_released = false;
    bool m_pressed = false;
};

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = nullptr);
    KeyStatus* keys(int keyCode);
signals:

private slots:
    void loop();
    /* 2024-12-06 PDH: declare timer slot */
    void level_timing();

private:
    void handlePlayerInput();
    void resetKeyStatus();
    void resetGameScene();
    void renderGameScene();
    float getCameraX(const Mario& mario);
    float m_mostRightX;
    KeyStatus* m_keys[256];
    MouseStatus* m_mouse;

    const int FPS = 60;
    QTimer m_timer;
    /* 2024-12-06 PDH: declare level_timer timer and in-game countdown */
    QTimer level_timer;
    int level_countdown = 400;
    QElapsedTimer m_elapsedTimer;
    float m_deltaTime = 0.0f, m_loopTime = 0.0f;
    const float m_loopSpeed;

    MapManager m_mapManager;
    Mario *m_mario;
    // QGraphicsScene interface
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // GAMESCENE_H
