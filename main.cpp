#include <iostream>
#include <vector>
#include "Admin.h"
#include "Member.h"
#include "Singer.h"
#include "PlayList.h"
using namespace std;

int main() {
    cout << "\n<==------WELCOME TO  ~H~  MUSIC PLAYER------==>\n" << endl;

    Admin admin1("ad1min","qazwsx");
    Admin admin2("ad2min","wsxedc");

    PlayList allMusic("All Music");
    vector<Singer> singers;

    int role;
    while(true){
        cout << "Please select your role:\n" << "1_Admin\n" << "2_Member\n" << "\n0_Exit" << endl;
        cin >> role;

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
