#include "end_screen.h"
#include "src/entities/block.h"
#include "src/entities/enemy.h"
#include "src/entities/mario.h"
#include "src/entities/mushroom.h"
#include "src/gamescene.h"
#include "ui_end_screen.h"
#include "src/gamescene.h"
#include "qapplication.h"

End_Screen::End_Screen(GameScene *gameScene, QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::End_Screen)
    , m_gameScene(gameScene)
{
    m_ui->setupUi(this);
    connect(m_ui->restartButton, &QPushButton::clicked,
            this, &End_Screen::onRestartButton);
    connect(m_ui->exitButton, &QPushButton::clicked,
            this, &End_Screen::onExitButton);


    //NAC: This connects the restarts button to restartGameKeyPressed "calls KeyHandler and makes 'R' true"
    GameScene gs;
    connect(m_ui->restartButton, &QPushButton::clicked, &gs, &GameScene::restartGameKeyPressed);
}


End_Screen::~End_Screen()
{
    delete m_ui;
}


//NAC: This method is called when the restart button is pressed. 
//It closes the current end screen and starts a new game. It also resets the timer.
void End_Screen::onRestartButton(){
    if (m_ui->restartButton)
    {
        m_gameScene->restartGameKeyPressed();
        close();
        m_gameScene->startTimer();
    }
}


//NAC: This method is called when the exit button is pressed.
void End_Screen::onExitButton(){
    QApplication::instance()->quit();
}
