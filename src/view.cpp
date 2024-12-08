#include "view.h"
#include "end_screen.h"
#include "restart_screen.h"
#include <QKeyEvent>
#include <QApplication>

View::View()
    : m_gameScene(new GameScene(this))
{
    setScene(m_gameScene);
    resize(m_gameScene->sceneRect().width()+2, m_gameScene->sceneRect().height()+2);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //NAC: Trigger showRestartScreen with signal playerDied
    connect(m_gameScene, &GameScene::playerDied, this, &View::showRestartScreen);

}


void View::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        showEndScreen();
    }
    QGraphicsView::keyReleaseEvent(event);
}

void View::callThis()
{
    showEndScreen();
}

//NAC: execute restart screen when dead and stop timer
void View::showRestartScreen()
{

    //m_gameScene->stopTimer();
    Restart_Screen* restartScreen = new Restart_Screen(m_gameScene, this);
    //m_gameScene->stopTimer();
    restartScreen->exec();
}

//NAC: open end screen when escape key is pressed and stop timer
void View::showEndScreen()
{
    m_gameScene->stopTimer();  // Call a method in GameScene to stop the timer
    End_Screen* endScreen = new End_Screen(m_gameScene, this);  // Pass GameScene* to End_Screen
    endScreen->exec();
}

