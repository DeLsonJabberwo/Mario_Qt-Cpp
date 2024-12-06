// KGD created endscreen gui
#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <QDialog>

namespace Ui {
class EndScreen;
}

class EndScreen : public QDialog
{
    Q_OBJECT

public:
    explicit EndScreen(QWidget *parent = nullptr);
    ~EndScreen();

public slots:
//NAC: This functions are called when buttons are clicked
    void onRestartButton();
    void onQuitButton();


private:
    Ui::EndScreen *m_ui;
};

#endif // ENDSCREEN_H
