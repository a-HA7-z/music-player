#include "User.h"
#include "Singer.h"
using namespace std;

class Admin : public User
{
private:

public:
    Admin(string,string);

    void addNewMusic(PlayList&, Music&, vector<Singer>&);

    void deleteMusic(PlayList&, Music&,vector<Singer>&);

    void updateArtistBio(Singer&, const string&);

    void addAlbumToArtist(Singer&, const PlayList&);

    void deleteAlbumFromArtist(Singer&,int);

    void addMusicToArtistAlbum(Singer& ,const Music& , int );

    void deleteMusicFromArtistAlbum(Singer& ,const Music& , int );

};