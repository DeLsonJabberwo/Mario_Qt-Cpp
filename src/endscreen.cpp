#include "endscreen.h"
#include "qapplication.h"
#include "ui_endscreen.h"
#include "gamescene.cpp"
#include "gamescene.h"


EndScreen::EndScreen(QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::EndScreen)
{
    m_ui->setupUi(this);

    connect(m_ui->restartButton, &QPushButton::clicked,
            this, &EndScreen::onRestartButton);
    connect(m_ui->QuitButton, &QPushButton::clicked,
            this, &EndScreen::onQuitButton);
}

EndScreen::~EndScreen()
{
    delete ui;
}


void EndScreen::onRestartButton(){
    GameScene gs;
    gs.resetGameScene();

}

void EndScreen::onQuitButton(){
    QApplication::instance()->quit();
}
