#include "Member.h"
using namespace std;

Member::Member() : User() {}

Member::Member(string name,string pass) : User(name,pass) {}

void Member::addSavedMusic(const Music& music) {
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

void Member::deleteFavoritePlaylist(const PlayList& target) {
    deletePlaylist(favoritePlaylists, target);
}

void Member::addPersonalPlaylist(const PlayList& playlist) {
    addPlaylist(personalPlaylists, playlist);
}

void Member::deletePersonalPlaylist(const PlayList& target) {
    deletePlaylist(personalPlaylists, target);
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