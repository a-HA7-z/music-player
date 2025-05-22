#include "PlayList.h"
using namespace std;

PlayList::PlayList(string listName) : name(listName),number_of_Music(0) {}

string PlayList::getName() {
    return name;
}

int PlayList::getNumberOfMusic() {
    return number_of_Music;
}

void PlayList::addMusic(const Music& newMusic) {
    musicList.push_back(newMusic);

    number_of_Music++;
}