#include "Admin.h"
using namespace std;

Admin::Admin(string uName,string pass) : User(uName,pass) {}

void Admin::addNewMusic(PlayList& playList, Music& mus, vector<Singer>& singers) {
    playList.addMusic(mus);

    for(int i = 0;i < singers.size();i++){
        if(singers[i].getName() == mus.getName()){
            singers[i].addMusic(mus);
            return;
        }
    }
    singers.push_back(Singer(mus.getName()));
    singers[singers.size()-1].addMusic(mus);
}

void Admin::deleteMusic(PlayList &list, Music &target,vector<Singer>& singers)
{
    list.deleteMusic(target);

    for(int i = 0;i < singers.size();i++){
        if(singers[i].getName() == target.getName()){
            singers[i].deleteMusic(target);
            return;
        }
    }
}

void Admin::updateArtistBio(Singer& artist, const string& newBio) {
    artist.setBio(newBio);
}

void Admin::addAlbumToArtist(Singer& artist, const PlayList& newAlbum) {
    artist.addAlbum(newAlbum);
}

void Admin::deleteAlbumFromArtist(Singer& artist,int index) {
    artist.deleteAlbum(index);
}

void Admin::addMusicToArtistAlbum(Singer& artist,const Music& newMusic, int albumIndex) {
    artist.addMusicToAlbum(newMusic,albumIndex);
}

void Admin::deleteMusicFromArtistAlbum(Singer& artist,const Music& targetMusic, int albumIndex) {
    artist.deleteMusicFromAlbum(targetMusic,albumIndex);
}
