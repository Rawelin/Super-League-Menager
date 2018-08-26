#include "musicplayer.h"

extern Container *container;

MusicPlayer::MusicPlayer()
{

}

void MusicPlayer::setPlayer()
{
    index = 1;
    volume = 100;
    playlist = new QMediaPlaylist;

    playlist->addMedia(QUrl("Sound/pharel.mp3"));
    playlist->addMedia(QUrl("Sound/madonna.mp3"));
    playlist->addMedia(QUrl("Sound/earth.mp3"));
    playlist->addMedia(QUrl("Sound/destiny.mp3"));
    playlist->addMedia(QUrl("Sound/pronko.mp3"));
    playlist->addMedia(QUrl("Sound/Kalimba.mp3"));
    playlist->setCurrentIndex(index);

    player = new QMediaPlayer;
    player->setVolume(volume);
    player->setPlaylist(playlist);
    player->play();
}

void MusicPlayer::start()
{
    player->play();
}

void MusicPlayer::stop()
{
    player->stop();
}

void MusicPlayer::pause()
{
    player->pause();
}

void MusicPlayer::volumeTurnUp()
{
    if(volume <= 100)
    {
        volume += 10;
        player->setVolume(volume);
    }
}

void MusicPlayer::volumeTurnDown()
{
    if(volume >= 0)
    {
        volume -= 10;
        player->setVolume(volume);
    }
}

void MusicPlayer::previous()
{
    if(index >= 1)
        playlist->setCurrentIndex(--index);
}

void MusicPlayer::forward()
{
    if(index <= 4)
        playlist->setCurrentIndex(index++);
}

void MusicPlayer::smoothVolumeDown()
{
    while(volume > 0)
    {
        volume -= 10;
        container->functions->delay(200);
        player->setVolume(volume);
    }
    pause();
}

void MusicPlayer::smoothVolumeUp()
{
    start();
    while(volume < 100)
    {
       volume += 10;
       container->functions->delay(200);
        player->setVolume(volume);
    }
}

void MusicPlayer::setTrack(int track)
{
    playlist->setCurrentIndex(track);
}
