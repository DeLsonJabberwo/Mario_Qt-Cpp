#include <QApplication>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QIcon>
#include "view.h"

int main(int argc, char** argv)
{
    QApplication a(argc, argv);

    QMediaPlayer *player = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;

    player->setAudioOutput(audioOutput);

    // Set up the media source
    player->setSource(QUrl("qrc:/res/sounds/music.ogg"));
    player->setLoops(QMediaPlayer::Infinite); // Loop

    audioOutput->setVolume(0.5);
    // Adjust volume level
    player->play(); // Start playback
    View v;
    v.setWindowTitle("Mario Qt/C++ World 1-1");
    v.show();

    return a.exec();
}
