#include "User.h"
using namespace std;

class Member : public User
{
public:
    Member();
    Member(string ,string );

    void playInPlaylist(PlayList& ,int ,int );

    void playNextInPlaylist(PlayList&);

    void playPreviousInPlaylist(PlayList&);

    void playSelectedMusicInPlaylist(PlayList&,int);
};