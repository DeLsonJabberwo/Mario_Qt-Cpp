#ifndef END_SCREEN_H
#define END_SCREEN_H

#include <QDialog>

namespace Ui {
class End_Screen;
}

class End_Screen : public QDialog
{
    Q_OBJECT

public:
    explicit End_Screen(QWidget *parent = nullptr);
    ~End_Screen();

private:
    Ui::End_Screen *ui;
};

#endif // END_SCREEN_H
