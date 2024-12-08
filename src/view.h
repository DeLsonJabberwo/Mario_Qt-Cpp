#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include "gamescene.h"

class View : public QGraphicsView
{
    Q_OBJECT
public:
    explicit View();

signals:

private:
    GameScene* m_gameScene;

private slots:
    void showRestartScreen();  //NAC: Slot to open the restart screen
    void showEndScreen(); //NAC: Slot to open the end screen

    // QWidget interface
protected:
    virtual void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // VIEW_H
