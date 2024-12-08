#include "uimanager.h"
#include <QtDebug>

UIManager::UIManager(QGraphicsScene* scene, QObject* parent)
    : QObject(parent), coinCounter(nullptr)
{
    // Initialize Coin Counter
    coinCounter = new QGraphicsTextItem("Coins: 0");
    coinCounter->setDefaultTextColor(Qt::white);
    coinCounter->setFont(QFont("Arial", 16));
    coinCounter->setPos(10, 10); // Top-left corner
    scene->addItem(coinCounter);
    qDebug() << "UIManager initialized.";

}

void UIManager::updateCoinCount(int count) {
    coinCounter->setPlainText(QString("Coins: %1").arg(count));

    qDebug() << "Updating coin count to:" << count;
}
