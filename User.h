#pragma once
#include <string>
#include "PlayList.h"
#include "Music.h"

using namespace std;
class User{
private:
    string username;
    string password;
protected:
    User();
    User(string ,string );
public:
    void setUsername(string );
    void setPassword(string );
    string getUsername();
    string getPassword();

    void addMusicToPlaylist(PlayList&,const Music&);

    void deleteMusicFromPlaylist(PlayList&,const Music&);
};