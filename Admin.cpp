#include "Admin.h"
using namespace std;

Admin::Admin(string uName,string pass) : User(uName,pass) {}

void Admin::addMusic(PlayList& playList, Music& mus, vector<Singer>& singers)  {
    playList.addMusic(mus);

    for(int i = 0;i < singers.size();i++){
        if(singers[i].getName() == mus.getName()){
            singers[i].addMusic(mus);
            return;
        }
    }
    singers.push_back(Singer(mus.getName()));
    singers[singers.size()-1].addMusic(mus);
}