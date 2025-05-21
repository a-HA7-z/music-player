#include <iostream>
#include "Music.h"
using namespace std;

Music::Music(string MusicName,string artist,int year,string type)
{
name = MusicName;
singer = artist;
publishYear = year;
style = type;
}

//void Music::setInfo(string MusicName,string artist,int year,string type)
//{
//    name = MusicName;
//    singer = artist;
//    publishYear = year;
//    style = type;
//}

string Music::getName() {
    return name;
}

string Music::getSingerName() {
    return singer;
}

int Music::getPublishYear() {
    return publishYear;
}

string Music::getStyle() {
    return style;
}

void Music::playMusic()
{
    cout << ".-..-..-.~<" << name << ">~.-..-..-." << endl;
    cout << "Artist ======>" << singer << "<======= Artist" << endl;
}