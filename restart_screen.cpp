#include "restart_screen.h"
#include "ui_restart_screen.h"
#include "src/gamescene.h"
#include "qapplication.h"


Restart_Screen::Restart_Screen(GameScene *gameScene, QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::Restart_Screen)
    , m_gameScene(gameScene)
{
    m_ui->setupUi(this);
    connect(m_ui->restartButton, &QPushButton::clicked,
            this, &Restart_Screen::onRestartButton);
    connect(m_ui->exitButton, &QPushButton::clicked,
            this, &Restart_Screen::onExitButton);

    GameScene gs;
    //connect(m_ui->restartButton, &QPushButton::clicked, &gs, &GameScene::restartGameKeyPressed);

}

Restart_Screen::~Restart_Screen()
{
    delete m_ui;
}


//NAC: This method is called when the restart button is pressed. 
//It closes the current end screen and starts a new game. It also resets the timer.
void Restart_Screen::onRestartButton()
{
    if (m_ui->restartButton)
    {
        m_gameScene->restartGameKeyPressed();
        close();
        m_gameScene->startTimer();
    }
}


//NAC: This method is called when the exit button is pressed.
void Restart_Screen::onExitButton(){
    QApplication::instance()->quit();
}
