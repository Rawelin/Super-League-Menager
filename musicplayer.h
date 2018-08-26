#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "livematch.h"

class LiveMatch;

class MusicPlayer
{
public:
    MusicPlayer();
    void setPlayer();
    void start();
    void stop();
    void pause();
    void volumeTurnUp();
    void volumeTurnDown();
    void previous();
    void forward();
    void smoothVolumeDown();
    void smoothVolumeUp();
    int getVolume(){return volume;}
    void setTrack(int);


private:
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    LiveMatch* livematch;
    int index;
    int volume;
};

#endif // MUSICPLAYER_H
