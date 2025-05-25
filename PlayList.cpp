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

void PlayList::play(int mode, int startIndex)
{
    playMode = mode;
    currentIndex = startIndex;

    musicList[currentIndex].playMusic();
    lastIndex = currentIndex;
}

void PlayList::next()
{
    lastIndex = currentIndex;

    if (playMode == 1)
    {
        currentIndex++;
        if (currentIndex >= musicList.size())
        {
            currentIndex = 0;
        }
    }
    else if (playMode == 2)
    {
        currentIndex = rand() % musicList.size();
    }

    musicList[currentIndex].playMusic();
}

void PlayList::previous()
{
    musicList[lastIndex].playMusic();
}

void PlayList::select(int index)
{
    lastIndex = currentIndex;

    currentIndex = index;

    musicList[currentIndex].playMusic();
}

void PlayList::sortMusicList(int feature) {
    int n = musicList.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            bool needSwap = false;
            switch (feature) {
                case 1: // by name
                    if (musicList[j].getName() < musicList[i].getName())
                        needSwap = true;
                    break;
                case 2: // by Artist name
                    if (musicList[j].getSingerName() < musicList[i].getSingerName())
                        needSwap = true;
                    break;
                case 3: // by Publish year
                    if (musicList[j].getPublishYear() < musicList[i].getPublishYear())
                        needSwap = true;
                    break;
                case 4: // by style
                    if (musicList[j].getStyle() < musicList[i].getStyle())
                        needSwap = true;
                    break;
                default:
                    break;
            }
            if (needSwap){
                Music temp = musicList[i];
                musicList[i] = musicList[j];
                musicList[j] = temp;
            }
        }
    }
}
