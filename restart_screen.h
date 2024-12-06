#ifndef RESTART_SCREEN_H
#define RESTART_SCREEN_H

#include <QDialog>

namespace Ui {
class Restart_Screen;
}

class Restart_Screen : public QDialog
{
    Q_OBJECT

public:
    explicit Restart_Screen(QWidget *parent = nullptr);
    ~Restart_Screen();

private:
    Ui::Restart_Screen *ui;
};

#endif // RESTART_SCREEN_H
