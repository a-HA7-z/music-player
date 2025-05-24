#include "User.h"
using namespace std;

User::User() {
    username = "";
    password = "";
}

User::User(string name,string pass) : username(name) , password(pass) {}

void User::setUsername(string name) {
    username = name;
}

void User::setPassword(string pass) {
    password = pass;
}

string User::getUsername() {
    return username;
}

string User::getPassword() {
    return password;
}

void User::addMusicToPlaylist(PlayList& playList, const Music& music) {
    playList.addMusic(music);
}

void User::deleteMusicFromPlaylist(PlayList& playList,const Music& target) {
    playList.deleteMusic(target);
}
