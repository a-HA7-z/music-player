#include <algorithm>
#include <iostream>
#include "Singer.h"
using namespace std;

Singer::Singer() : number_of_Albums(0)
{
    number_of_Musics = 0;
}
Singer::Singer(string fullName) : name(fullName),number_of_Albums(0)
{
    number_of_Musics = 0;
}


void Singer::setAlbumsNumber(int num) {
    number_of_Albums = num;
}

string Singer::getName() {
    return name;
}

void Singer::addMusic(const Music& newMusic) {
    musicList.push_back(newMusic);

    number_of_Musics++;
}

void Singer::deleteMusic(const Music& target)
{
     auto iter = std::find(musicList.begin(),musicList.end(),target);

    musicList.erase(iter);

    number_of_Musics--;
}

void Singer::addAlbum(const PlayList &newAlbum) {
    albums.push_back(newAlbum);
    number_of_Albums++;
}

void Singer::deleteAlbum(int index) {
    albums.erase(albums.begin() + index);
}

void Singer::showMusicList() {
    for (int i = 0;i < number_of_Musics;i++){
        musicList[i].showInfo();
    }
}

void Singer::ShowBiography() const{
    cout << "Artist name: " << name << "   Number of Albums: " << number_of_Albums;
    cout << "   Number of Music: " << number_of_Musics << endl;
}

void Singer::setBio(const string& newName) {
    name = newName;
    for(int i = 0;i < number_of_Musics;i++){
        musicList[i].setName(newName);
    }
}

void Singer::addMusicToAlbum(const Music& albumMusic,int index) {
    albums[index].addMusic(albumMusic);
}

void Singer::deleteMusicFromAlbum(const Music& albumMusic,int index) {
    albums[index].deleteMusic(albumMusic);
}


