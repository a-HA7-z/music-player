#include <iostream>
#include <vector>
#include "Admin.h"
#include "Member.h"
#include "Singer.h"
#include "PlayList.h"
using namespace std;

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
                cout << "\n1_Add new music\n2_Delete music\n3_See all music\n4_Playlists setting" << endl;
                cout << "\n9_Log-out\n0_Exit" << endl;
                int act;
                cin >> act;
                cin.ignore();

                if(act == 0) { return 0; }
                if(act == 9) { break; }

                if(act == 1){
                    Music newMusic = createMusicFromInput();
                    admins[index].addMusic(allMusic,newMusic,singers);
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
                {}
            }
        }

        if(role == 2) //Member
        {

        }

        if(role == 0){
            break;
        }
    }
    return 0;
}
