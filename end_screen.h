// KGD created endscreen gui

#ifndef END_SCREEN_H
#define END_SCREEN_H

#include "src/gamescene.h"
#include <QDialog>

namespace Ui {
class End_Screen;
}

class End_Screen : public QDialog
{
    Q_OBJECT

public:
    explicit End_Screen(GameScene *gameScene, QWidget *parent = nullptr);
    ~End_Screen();

signals:
    void restart();

public slots:
    void onRestartButton();
    void onExitButton();


private:
    Ui::End_Screen *m_ui;
    GameScene* m_gameScene;
};

#endif // END_SCREEN_H
