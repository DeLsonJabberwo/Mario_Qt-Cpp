#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include "gamescene.h"

class View : public QGraphicsView
{
    Q_OBJECT
public:
    explicit View();
    void callThis();

signals:

private:
    GameScene* m_gameScene;

    // QWidget interface
protected:
    virtual void keyReleaseEvent(QKeyEvent *event) override;
    void triggerKeyReleaseEvent(Qt::Key key);
};

#endif // VIEW_H
