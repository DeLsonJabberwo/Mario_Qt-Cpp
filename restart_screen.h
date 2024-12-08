// KGD created restartscreen gui

#ifndef RESTART_SCREEN_H
#define RESTART_SCREEN_H

#include "src/gamescene.h"
#include <QDialog>

namespace Ui {
class Restart_Screen;
}

class Restart_Screen : public QDialog
{
    Q_OBJECT

public:
    explicit Restart_Screen(GameScene *gameScene, QWidget *parent = nullptr);
    ~Restart_Screen();

signals:
    void restartGame();

public slots:

//NAC: This functions are called when buttons are clicked
    void onRestartButton();
    void onExitButton();

private:
    Ui::Restart_Screen *m_ui;
    GameScene* m_gameScene;
};

#endif // RESTART_SCREEN_H
