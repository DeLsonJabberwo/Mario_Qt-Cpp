#include "restart_screen.h"
#include "ui_restart_screen.h"

Restart_Screen::Restart_Screen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Restart_Screen)
{
    ui->setupUi(this);
}

Restart_Screen::~Restart_Screen()
{
    delete ui;
}
