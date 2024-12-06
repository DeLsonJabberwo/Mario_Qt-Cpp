#include "end_screen.h"
#include "ui_end_screen.h"

End_Screen::End_Screen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::End_Screen)
{
    ui->setupUi(this);
}

End_Screen::~End_Screen()
{
    delete ui;
}
