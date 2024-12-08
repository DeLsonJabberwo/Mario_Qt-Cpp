#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QObject>

class UIManager : public QObject {
    Q_OBJECT

public:
    explicit UIManager(QGraphicsScene* scene, QObject* parent = nullptr);

    void updateCoinCount(int count);

private:
    QGraphicsTextItem* coinCounter;
};

#endif // UIMANAGER_H
