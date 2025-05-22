#include <iostream>
#include "Admin.h"
#include "Member.h"
#include "Singer.h"
#include "PlayList.h"
using namespace std;

void addMusic(PlayList& list){
    string name;
    string singer;
    int year;
    string style;

    cout << "Please enter the title:" << endl;
    getline(cin,name);

    cout << "Please enter the artist name:" << endl;
    getline(cin,singer);

    cout << "Please enter the publish year:" << endl;
    cin >> year;
    cin.ignore();

    cout << "Please enter the style:" << endl;
    getline(cin,style);

    list.addMusic(Music(name,singer,year,style));

}

int main() {
    cout << "\n<==------WELCOME TO  ~H~  MUSIC PLAYER------==>\n" << endl;

    Admin admin1("ad1min","qazwsx");
    Admin admin2("ad2min","wsxedc");

    PlayList allMusic("All Music");

    int role;
    while(true){
        cout << "Please select your role:\n" << "1_Admin\n" << "2_Member\n" << "\n0_Exit" << endl;
        cin >> role;
        cin.ignore();

        if(role == 1) //Admin
        {

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
