#include <algorithm>
#include "PlayList.h"
using namespace std;

PlayList::PlayList(string listName) : name(listName),number_of_Music(0) {}

string PlayList::getName() {
    return name;
}

int PlayList::getNumberOfMusic() const{
    return number_of_Music;
}

vector<Music> &PlayList::getList() {
    return musicList;
}

void PlayList::addMusic(const Music& newMusic) {
    musicList.push_back(newMusic);

    number_of_Music++;
}

void PlayList::deleteMusic(const Music &target)
{
    auto iter = std::find(musicList.begin(), musicList.end(), target);

    musicList.erase(iter);

    number_of_Music--;
}

bool PlayList::checkMusic(const Music &target) {
    for(int i = 0;i < musicList.size();i++){
        if(musicList[i] == target){
            return true;
        }
    }
    return false;
}