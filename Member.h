#include "User.h"
using namespace std;

class Member : public User
{
    vector<Music> savedMusic;
    vector<Music> favoriteMusic;
    vector<PlayList> favoritePlaylists;
    vector<PlayList> personalPlaylists;
public:
    Member();
    Member(string ,string );
};