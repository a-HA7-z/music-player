#include <algorithm>
#include <iostream>
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

void PlayList::show() const
{
    for(int i = 0;i < number_of_Music;i++){
        cout << i+1 << "_ ";
        musicList[i].showInfo();
    }
}

bool PlayList::operator==(const PlayList &other) const
{
    if(this->name == other.name && this->number_of_Music == other.number_of_Music){
        for(int i = 0;i < number_of_Music;i++){
            if (musicList[i] != other.musicList[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}
