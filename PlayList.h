#pragma once
#include <string>
#include <vector>
#include "Music.h"
using namespace std;

class PlayList
{
private:
    string name;
    int number_of_Music;
    vector<Music> musicList;
public:
    PlayList(string);

    string getName();
    int getNumberOfMusic() const;

    vector<Music>& getList();

    void addMusic(const Music&);

    void deleteMusic(const Music& );

    bool checkMusic(const Music& );

    void show() const;
};