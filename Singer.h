#pragma once
#include <string>
#include <vector>
#include "Music.h"
#include "PlayList.h"

using namespace std;

class Singer
{
private:
    string name;
    int number_of_Albums;
    int number_of_Musics;
    vector<Music> musicList;
    vector<PlayList> albums;
public:
    Singer();
    Singer(string);

    void setAlbumsNumber(int);

    string getName();

    void addMusic(const Music&);

    void deleteMusic(const Music&);

    void addAlbum(const PlayList&);

    void deleteAlbum(int);

    void setBio(const string&);

    void addMusicToAlbum(const Music& , int);

    void deleteMusicFromAlbum(const Music& , int);

    void showMusicList();

    void ShowBiography() const;
};