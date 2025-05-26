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

Music::Music(const Music & other)
{
    name = other.name;
    singer = other.singer;
    publishYear = other.publishYear;
    style = other.style;
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

bool Music::operator==(const Music& other) const {
    return this->name == other.name && this->singer == other.singer
    && this->publishYear == other.publishYear && this->style == other.style;
}

void Music::showInfo() const
{
    cout << "Title: " << name << "  ";
    cout << "Artist: " << singer << "  ";
    cout << "Publish year: " << publishYear << "  ";
    cout << "Style: " << style << endl;
}

void Music::playMusic()
{
    cout << ".-..-..-.~<" << name << ">~.-..-..-." << endl;
    cout << "Artist ======>" << singer << "<======= Artist" << endl;
}

void Music::setName(const string &newName) {
    name = newName;
}
