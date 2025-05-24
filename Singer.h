#pragma once
#include <string>
#include <vector>
#include "Music.h"
using namespace std;

class Singer
{
private:
    string name;
    int number_of_Albums;
    int number_of_Musics;
    vector<Music> musicList;
public:
    Singer();
    Singer(string);

    void setName(string);
    void setAlbumsNumber(int);

    string getName();

    void addMusic(const Music&);

    void deleteMusic(const Music&);
};