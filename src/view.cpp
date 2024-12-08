#include "view.h"
#include <QKeyEvent>
#include <QApplication>

View::View()
    : m_gameScene(new GameScene(this))
{
    setScene(m_gameScene);
    resize(m_gameScene->sceneRect().width()+2, m_gameScene->sceneRect().height()+2);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}


void View::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        QApplication::instance()->quit();
    }
    QGraphicsView::keyReleaseEvent(event);
}

void View::triggerKeyReleaseEvent(Qt::Key key)
{
    QKeyEvent event(QEvent::KeyRelease, key, Qt::NoModifier);
    keyReleaseEvent(&event); 
}

void View::callThis()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyRelease, Qt::Key_Escape, Qt::NoModifier);
    QApplication::postEvent(this, event);
}

