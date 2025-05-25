#include "Member.h"
using namespace std;

Member::Member() : User() {}

Member::Member(string name,string pass) : User(name,pass) {}

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
