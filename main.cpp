#include <iostream>
#include <vector>
#include "Admin.h"
#include "Member.h"
#include "Singer.h"
#include "PlayList.h"
using namespace std;

int signUp(vector<Member>& members) {
    string username, password;

    bool uNameIsNew = false;
    while(!uNameIsNew) {
        cout << "Please enter your username: ";
        getline(cin,username);

        int i;
        for(i = 0;i < members.size();i++){
            if(members[i].getUsername() == username){
                cout << "This username already used.\n";
                break;
            }
        }
        if(i == members.size()) { uNameIsNew = true; }
    }
    cout << "Enter password: ";
    getline(cin,password);

    Member newMember(username, password);

    members.push_back(newMember);

    cout << "Registration successful!" << endl;
    return members.size()-1;
}

template<typename T>
int login(vector<T>& usersList)
{
    string username;
    string password;

    while(true){
        cout << "Please enter your Username:" << endl;
        getline(cin,username);

        for(int i = 0;i < usersList.size();i++)
        {
            if(username == usersList[i].getUsername()){
                while(true)
                {
                    cout << "Please enter your Password:" << endl;
                    getline(cin,password);

                    if(password == usersList[i].getPassword()){
                        return i;
                    } else{
                        cout << "Your Password is wrong!" << endl;
                    }
                }
            }
        }
        cout << "Your Username is wrong!" << endl;
    }
}

Music createMusicFromInput() {
    cout << "\n(Enter music Info)\n" << endl;

    string title, artistName,style;
    int year;

    cout << "Please enter the Title:" << endl;
    getline(cin, title);

    cout << "Please enter the Artist Name:" << endl;
    getline(cin, artistName);

    cout << "Please enter the Publish Year:" << endl;
    cin >> year;
    cin.ignore();

    cout << "Please enter the Style:" << endl;
    getline(cin, style);

    return Music(title,artistName,year,style);
}


int main() {
    cout << "\n<==------WELCOME TO  ~H~  MUSIC PLAYER------==>\n" << endl;

    Admin admin1("ad1min","qazwsx");
    Admin admin2("ad2min","wsxedc");
    vector<Admin> admins;
    admins.push_back(admin1);
    admins.push_back(admin2);

    PlayList allMusic("All Music");

    vector<PlayList> officialPlaylists;

    vector<Singer> singers;

    vector<Member> members;

    int role;
    while(true){
        cout << "\nPlease select your role:\n" << "1_Admin\n" << "2_Member\n" << "\n0_Exit" << endl;
        cin >> role;
        cin.ignore();

        if(role == 1) //Admin
        {
            cout << "<Log-in>\n" << endl;

            int index = login(admins);

            while(true){
                cout << "\n1_Add new music\n2_Delete music\n3_See all music\n4_Playlists setting\n";
                cout << "5_Artists Homepage setting\n" << "\n" << "9_Log-out\n0_Exit" << endl;
                int act;
                cin >> act;
                cin.ignore();

                if(act == 0) { return 0; }
                if(act == 9) { break; }

                if(act == 1){
                    Music newMusic = createMusicFromInput();
                    admins[index].addNewMusic(allMusic,newMusic,singers);
                    cout << "Music " << newMusic.getName() << "successfully added :)" << endl;
                }

                if(act == 2)
                {
                    Music targetMusic = createMusicFromInput();

                    bool isHere = allMusic.checkMusic(targetMusic);

                    while( !isHere )
                    {
                        cout << "This music is unavailable!" << endl;

                        int act2;
                        cout << "1_Retry\n2_Return to  main menu\n";

                        cin >> act2;
                        cin.ignore();

                        if(act2 == 2){
                            break;
                        }
                        if(act2 == 1){
                            targetMusic = createMusicFromInput();
                            isHere = allMusic.checkMusic(targetMusic);
                        }
                    }
                    if(isHere){
                        admins[index].deleteMusic(allMusic,targetMusic,singers);
                        cout << "Music " << targetMusic.getName() << "successfully deleted." << endl;
                    }
                }

                if(act == 3){
                    allMusic.show();
                }

                if(act == 4)
                {
                    while(true)
                    {
                        cout << "1_All Playlists Info\n2_Add Playlist\n3_Delete Playlist" << endl;
                        cout << "\n9_Back to menu\n0_Exit" << endl;
                        int act2;

                        cin >> act2;
                        cin.ignore();

                        if(act2 == 0){
                            return 0;
                        }
                        if(act2 == 9){
                            break;
                        }

                        if(act2 == 1){
                            while(true)
                            {
                                cout << "--> All Playlists:" << endl;

                                for(int i = 0;i < officialPlaylists.size(); i++){
                                    cout << i+1 << "_ Playlist title: " << officialPlaylists[i].getName() << "   Number of music: "
                                         << officialPlaylists[i].getNumberOfMusic() << endl;
                                }

                                cout << "\n--> Do you want to add or delete music in a Playlist??" << endl;
                                cout << "1_Yes\n2_No" << endl;
                                int act3;
                                cin >> act3;
                                cin.ignore();

                                if(act3 == 1)
                                {
                                    cout << "Choose a Playlist to changing:\n(enter the row of target Playlist)\n" << endl;
                                    int act4;
                                    cin >> act4;
                                    cin.ignore();

                                    while(act4 < 0 || act4 > officialPlaylists.size()){
                                        cout << "ENTER THE ROW OF TARGET PLAYLIST!" << endl;
                                        cin >> act4;
                                        cin.ignore();
                                    }

                                    PlayList& targetPlaylist = officialPlaylists[act4-1];

                                    while(true)
                                    {
                                        cout << targetPlaylist.getName() << " music:\n" << endl;

                                        targetPlaylist.show();

                                        cout << "\n1_Add music\n2_Delete music\n3_Change another Playlist" << endl;
                                        cout << "\n9_Back to menu" << endl;
                                        int act5;
                                        cin >> act5;
                                        cin.ignore();

                                        if(act5 == 3) { break; }

                                        if(act5 == 9) {
                                            act3 = 2;
                                            break;
                                        }

                                        if(act5 == 1){
                                            cout << "--> All music:" << endl;
                                            allMusic.show();

                                            Music targetMusic = createMusicFromInput();

                                            bool isHere = allMusic.checkMusic(targetMusic);

                                            while( !isHere )
                                            {
                                                cout << "This music is unavailable!" << endl;

                                                targetMusic = createMusicFromInput();
                                                isHere = allMusic.checkMusic(targetMusic);
                                            }

                                            admins[index].addMusicToPlaylist(targetPlaylist,targetMusic);
                                        }

                                        if(act5 == 2){
                                            cout << "--> " << targetPlaylist.getName() << " music:" << endl;
                                            targetPlaylist.show();

                                            Music targetMusic = createMusicFromInput();

                                            bool isHere = allMusic.checkMusic(targetMusic);

                                            while( !isHere )
                                            {
                                                cout << "This music is unavailable!" << endl;

                                                targetMusic = createMusicFromInput();
                                                isHere = allMusic.checkMusic(targetMusic);
                                            }

                                            admins[index].deleteMusicFromPlaylist(targetPlaylist,targetMusic);
                                        }
                                    }
                                }

                                if(act3 == 2) { break; }
                            }
                        }


                        if(act2 == 2){
                            string listName;
                            cout << "Please enter the name of Playlist" << endl;
                            getline(cin,listName);
                            admins[index].addPlaylist(officialPlaylists , PlayList(listName) );
                        }

                        if(act2 == 3){
                            cout << "--> All Playlists:" << endl;

                            for(int i = 0;i < officialPlaylists.size(); i++)
                            {
                                cout << i+1 << "_ Playlist title: " << officialPlaylists[i].getName() << "   Number of music: "
                                     << officialPlaylists[i].getNumberOfMusic() << endl;
                            }

                            cout << "\nChoose a Playlist to deleting:\n(enter the row of target Playlist)\n" << endl;
                            int act3;

                            cin >> act3;
                            cin.ignore();

                            while(act3 < 0 || act3 > officialPlaylists.size()){
                                cout << "ENTER THE ROW OF TARGET PLAYLIST!" << endl;
                                cin >> act3;
                                cin.ignore();
                            }

                            admins[index].deletePlaylist(officialPlaylists , officialPlaylists[act3-1]);
                        }
                    }
                }

                if(act == 5)
                {
                    cout << "\n--> All Artists:\n" << endl;
                    for(int i = 0;i < singers.size();i++){
                        cout << i+1 << "_ " << singers[i].getName() << endl;
                    }
                    cout << "\nChoose an Artist to Change Page:\n(enter the row of target Artist)\n" << endl;
                    int singerIndex;

                    cin >> singerIndex;
                    cin.ignore();

                    while(singerIndex < 0 || singerIndex > singers.size()){
                        cout << "ENTER THE ROW OF TARGET ARTIST!" << endl;
                        cin >> singerIndex;
                        cin.ignore();
                    }
                    singerIndex--;
                    while(true){
                        singers[singerIndex].showHomePage();
                        cout << "1_Change Artist Name\n2_Add Album\n3_Delete Album\n4_Add Music to an Album\n";
                        cout << "5_Delete Music from an Album\n\n9_Back to menu\n0_Exit" << endl;
                        int act2;

                        cin >> act2;
                        cin.ignore();

                        if(act2 == 0) { return 0; }
                        if(act2 == 9) { break; }

                        if(act2 == 1){
                            cout << "Enter the new name of Artist " << singers[singerIndex].getName() << endl;

                            string newName;
                            getline(cin,newName);

                            admins[index].updateArtistBio(singers[singerIndex],newName);
                        }

                        if(act2 == 2){
                            string newAlbum;
                            cout << "Please enter the name of Album" << endl;
                            getline(cin,newAlbum);

                            admins[index].addAlbumToArtist(singers[singerIndex],newAlbum);
                        }

                        if(act2 == 3){
                            cout << "\nChoose an Album to deleting:\n(enter the row of target Album)\n" << endl;
                            int act3;

                            cin >> act3;
                            cin.ignore();

                            while(act3 < 0 || act3 > singers[singerIndex].getNumberOfAlbums()){
                                cout << "ENTER THE ROW OF TARGET ALBUM!" << endl;
                                cin >> act3;
                                cin.ignore();
                            }
                            int albumIndex = act3 - 1;

                            admins[index].deleteAlbumFromArtist(singers[singerIndex],albumIndex);
                        }

                        if(act2 == 4 || act2 == 5){
                            cout << "\nChoose an Album to deleting:\n(enter the row of target Album)\n" << endl;
                            int act3;

                            cin >> act3;
                            cin.ignore();

                            while(act3 < 0 || act3 > singers[singerIndex].getNumberOfAlbums()){
                                cout << "ENTER THE ROW OF TARGET ALBUM!" << endl;
                                cin >> act3;
                                cin.ignore();
                            }
                            int albumIndex = act3 - 1;

                            cout << "\n--> " << singers[singerIndex].getName() << "music:\n" << endl;
                            singers[singerIndex].showMusicList();

                            if(act2 == 4)
                            {
                                Music newMusic = createMusicFromInput();

                                admins[index].addMusicToArtistAlbum(singers[singerIndex],newMusic,albumIndex);
                            }

                            if(act2 == 5)
                            {
                                Music newMusic = createMusicFromInput();

                                admins[index].deleteMusicFromArtistAlbum(singers[singerIndex],newMusic,albumIndex);
                            }
                        }
                    }
                }
            }
        }

        if(role == 2) //Member
        {
            cout << "1_Sign-up\n2_Log-in\n\n9_Log-out\n0_Exit" << endl;
            int act;

            cin >> act;
            cin.ignore();

            if(act == 0) { return 0; }

            int memberIndex;

            if(act == 1){
                memberIndex = signUp(members);
            }

            if(act == 2){
                if(members.empty()){
                    cout << "Please sign-up first!" << endl;
                    break;
                }
                memberIndex = login(members);
            }

            if(act == 1 || act == 2){
                cout << "\n<---WELCOME--->\n" << endl;

                while(true){
                    cout << "1_See your library\n2_See all Musics\n3_See all Playlists\n4_See Artists Homepage\n";
                    cout << "9_Log-out\n0_Exit" << endl;
                    int act1;

                    cin >> act1;
                    cin.ignore();

                    if(act1 == 0) { return 0; }
                    if(act1 == 9) { break; }

                    if(act1 == 1){
                        while(true){
                            cout << "1_Saved Musics\n2_Favorite Musics\n3_Favorite Playlists\n4_Personal Playlists\n";
                            cout << "9_Back to main menu\n0_Exit" << endl;
                            int act2;

                            cin >> act2;
                            cin.ignore();

                            if(act2 == 0) { return 0; }
                            if(act2 == 9) { break; }

                            if(act2 == 1){
                                while(true){
                                    cout << "--> Saved musics:" << endl;

                                    members[memberIndex].showSavedMusic();

                                    cout << "\n1_Play a music\n2_Delete a music from list\n\n0_Back" << endl;
                                    int act3;

                                    cin >> act3;
                                    cin.ignore();

                                    if(act3 == 0) { break; }

                                    if(act3 == 1){
                                        cout << "\nEnter the row of target music to PLAY" << endl;
                                        int musicIndex;

                                        cin>> musicIndex;
                                        cin.ignore();

                                        members[memberIndex].playInSavedMusic(musicIndex-1);
                                    }

                                    if(act3 == 2){
                                        Music targetMusic = createMusicFromInput();

                                        members[memberIndex].deleteSavedMusic(targetMusic);
                                    }
                                }
                            }

                            if(act2 == 2){
                                while(true) {
                                    cout << "--> Favorite musics:" << endl;

                                    members[memberIndex].showFavoriteMusic();

                                    cout << "\n1_Play a music\n2_Delete a music from list\n\n0_Back" << endl;
                                    int act3;

                                    cin >> act3;
                                    cin.ignore();

                                    if (act3 == 0) { break; }

                                    if (act3 == 1) {
                                        cout << "\nEnter the row of target music to PLAY" << endl;
                                        int musicIndex;

                                        cin >> musicIndex;
                                        cin.ignore();

                                        members[memberIndex].playInFavoriteMusic(musicIndex - 1);
                                    }

                                    if (act3 == 2) {
                                        Music targetMusic = createMusicFromInput();

                                        members[memberIndex].deleteFavoriteMusic(targetMusic);
                                    }
                                }
                            }

                            if(act2 == 3){
                                while(true){
                                    cout << "\nFavorite playlists Info:\n" << endl;

                                    members[memberIndex].showFavoritePlaylistsInfo();

                                    cout << "1_Select a playlist to see music\n2_Delete a playlist from the list\n\n0_Back" << endl;
                                    int act3;

                                    cin >> act3;
                                    cin.ignore();

                                    if(act3 == 0) { break; }

                                    if(act3 == 1){
                                        cout << "Enter the row of target playlist to see MUSIC" << endl;
                                        int playlistIndex;

                                        cin >> playlistIndex;
                                        cin.ignore();

                                        members[memberIndex].showFavoritePlaylistMusics(playlistIndex);
                                    }

                                    if(act3 == 2){
                                        cout << "Enter the row of target playlist to DELETE" << endl;
                                        int playlistIndex;

                                        cin >> playlistIndex;
                                        cin.ignore();

                                        members[memberIndex].deleteFavoritePlaylist(playlistIndex-1);
                                    }
                                }
                            }
                            if(act2 == 4){
                                while(true){
                                    cout << "\nPersonal playlists Info:\n" << endl;

                                    members[memberIndex].showPersonalPlaylistInfo();

                                    cout << "1_Select a playlist to see music\n2_Delete a Playlist from the list\n\n0_Back" << endl;
                                    int act3;

                                    cin >> act3;
                                    cin.ignore();

                                    if(act3 == 0) { break; }

                                    if(act3 == 1){
                                        cout << "Enter the row of target playlist to see MUSIC" << endl;
                                        int playlistIndex;

                                        cin >> playlistIndex;
                                        cin.ignore();

                                        members[memberIndex].showFavoritePlaylistMusics(playlistIndex);
                                    }

                                    if(act3 == 2){
                                        cout << "Enter the row of target playlist to DELETE" << endl;
                                        int playlistIndex;

                                        cin >> playlistIndex;
                                        cin.ignore();

                                        members[memberIndex].deletePersonalPlaylist(playlistIndex-1);
                                    }
                                }
                            }
                        }
                    }
                    if(act1 == 2) //all music
                    {
                        cout << "\n--> All music:\n" << endl;
                    }

                    if(act1 == 3) //all playlist
                    {

                    }

                    if(act1 == 4) //artists Homepage
                    {

                    }
                }
            }
        }

        if(role == 0){
            break;
        }
    }
    return 0;
}
