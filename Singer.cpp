#include <algorithm>
#include "Singer.h"
using namespace std;

Singer::Singer()
{
    number_of_Musics = 0;
}
Singer::Singer(string fullName) : name(fullName),number_of_Albums(0)
{
    number_of_Musics = 0;
}

void Singer::setName(string fullName) {
    name = fullName;
}

void Singer::setAlbumsNumber(int num) {
    number_of_Albums = num;
}

string Singer::getName() {
    return name;
}

void Singer::addMusic(const Music& newMusic) {
    musicList.push_back(newMusic);

    number_of_Musics++;
}

void Singer::deleteMusic(const Music& target)
{
     auto iter = std::find(musicList.begin(),musicList.end(),target);

    musicList.erase(iter);

    number_of_Musics--;
}
