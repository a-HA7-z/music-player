#include <iostream>
#include "Member.h"
using namespace std;

Member::Member() : User() {}

Member::Member(string name,string pass) : User(name,pass) {}

bool checkMusicInList(vector<Music>& list,const Music& music){
    for(int i = 0;i < list.size();i++){
        if(list[i] == music){
            return true;
        }
    }
    return false;
}

void Member::addSavedMusic(const Music& music) {
    if(checkMusicInList(savedMusic,music)){
        cout << "This Music is available!" << endl;
        return;
    }
    savedMusic.push_back(music);
}

void Member::deleteSavedMusic(const Music& target) {
    for (int i = 0; i < savedMusic.size(); i++) {
        if (savedMusic[i] == target) {
            savedMusic.erase(savedMusic.begin() + i);
            break;
        }
    }
}

void Member::addFavoriteMusic(const Music& music) {
    if(checkMusicInList(favoriteMusic,music)){
        cout << "This Music is available!" << endl;
        return;
    }
    favoriteMusic.push_back(music);
}

void Member::deleteFavoriteMusic(const Music& target) {
    for (int i = 0; i < favoriteMusic.size(); i++) {
        if (favoriteMusic[i] == target) {
            favoriteMusic.erase(favoriteMusic.begin() + i);
            break;
        }
    }
}

void Member::addFavoritePlaylist(const PlayList& playlist) {
    addPlaylist(favoritePlaylists, playlist);
}

void Member::deleteFavoritePlaylist(int index) {
    deletePlaylist(favoritePlaylists, favoritePlaylists[index]);
}

void Member::addPersonalPlaylist(const PlayList& playlist) {
    addPlaylist(personalPlaylists, playlist);
}

void Member::addMusicToPersonalPlaylist(Music& newMusic,int playlistIndex) {
    if(personalPlaylists[playlistIndex].checkMusic(newMusic)){
        cout << "This Music is available!" << endl;
        return;
    }
    addMusicToPlaylist(personalPlaylists[playlistIndex],newMusic);
}

void Member::deletePersonalPlaylist(int index) {
    deletePlaylist(personalPlaylists, personalPlaylists[index]);
}

void Member::playInPlaylist(PlayList &playList,int mode, int firstMusic) {
    playList.play(mode,firstMusic);
}

void Member::playNextInPlaylist(PlayList & playList) {
    playList.next();
}

void Member::playPreviousInPlaylist(PlayList & playList) {
    playList.previous();
}

void Member::playSelectedMusicInPlaylist(PlayList& playList,int index) {
    playList.select(index);
}

void Member::showSavedMusic() {
    for(int i = 0; i < savedMusic.size();i++){
        cout << i+1 << "_ ";
        savedMusic[i].showInfo();
    }
}

void Member::showFavoriteMusic(){
    for(int i = 0; i < favoriteMusic.size();i++){
        cout << i+1 << "_ ";
        favoriteMusic[i].showInfo();
    }
}

void Member::playInSavedMusic(int index) {
    savedMusic[index].playMusic();
}

void Member::playInFavoriteMusic(int index) {
    favoriteMusic[index].playMusic();
}

void Member::showFavoritePlaylistsInfo() {
    for(int i = 0;i < favoritePlaylists.size();i++){
        cout << i+1 << "_ ";
        cout << favoritePlaylists[i].getName() << "  Number of Musics: " << favoritePlaylists[i].getNumberOfMusic() << endl;
    }
}

void Member::showPersonalPlaylistInfo() {
    for(int i = 0;i < personalPlaylists.size();i++){
        cout << i+1 << "_ ";
        cout << personalPlaylists[i].getName() << "  Number of Musics: " << personalPlaylists[i].getNumberOfMusic() << endl;
    }
}

void Member::showFavoritePlaylistMusics(int playlistIndex) {
    favoritePlaylists[playlistIndex].show();
}

void Member::showPersonalPlaylistMusics(int playlistIndex) {
    personalPlaylists[playlistIndex].show();
}

void Member::filterPlaylist(PlayList& target, int feature) {
    target.sortMusicList(feature);
}

bool Member::searchMusic(PlayList& playList, Music& target) {
    bool isHere = playList.checkMusic(target);
    return isHere;
}



