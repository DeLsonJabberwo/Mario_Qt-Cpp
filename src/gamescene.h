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
    void pauseGame();  // Function to pause the game
    void resumeGame(); // Function to resume the game
    bool m_paused = false;

    void stopTimer(); //NAC: to stop or pause the game

    void startTimer(); //NAC: to resume the game timer
    void restartGame();
    void restartGameKeyPressed(); //NAC: calls handlePlayerInput()

    void playerIsDead(); //NAC:

    void gameEnded(); //NAC:




    //NAC: Made it public so that it can be called using the ui
    //void resetGameScene();
signals:
    void playerDied();//NAC: This is a signal that communicates that the player died and to execute the restart screen
    void gameFinished();//NAC: This is a signal that signals that the game finished and executes the end screen 

public slots:
    void resetGameScene();

private slots:
    void loop();

private:
    void handlePlayerInput();
    void resetKeyStatus();
    //void resetGameScene();

    void initializeGame();

    void renderGameScene();
    float getCameraX(const Mario& mario);
    float m_mostRightX;
    KeyStatus* m_keys[256];
    MouseStatus* m_mouse;

    const int FPS = 60;
    QTimer m_timer;
    QElapsedTimer m_elapsedTimer;
    float m_deltaTime = 0.0f, m_loopTime = 0.0f;
    const float m_loopSpeed;

    //bool m_paused = false;

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
