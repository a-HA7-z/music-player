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
    
    void addSavedMusic(const Music&);

    void deleteSavedMusic(const Music&);

    void addFavoriteMusic(const Music&);

    void deleteFavoriteMusic(const Music&);

    void addFavoritePlaylist(const PlayList& playlist);

    void deleteFavoritePlaylist(int);

    void addPersonalPlaylist(const PlayList& playlist);

    void addMusicToPersonalPlaylist(Music& , int);

    void deletePersonalPlaylist(int);

    void playInPlaylist(PlayList& ,int ,int );

    void playNextInPlaylist(PlayList&);

    void playPreviousInPlaylist(PlayList&);

    void playSelectedMusicInPlaylist(PlayList&,int);

    PlayList& getAPersonalPlaylist(int);

    void showSavedMusic();

    void showFavoriteMusic();

    void showFavoritePlaylistsInfo();

    void showPersonalPlaylistInfo();

    void showFavoritePlaylistMusics(int);

    void showPersonalPlaylistMusics(int);

    void playInSavedMusic(int);

    void playInFavoriteMusic(int);

    void filterPlaylist(PlayList&,int);

    bool searchMusic(PlayList&,Music&);
};