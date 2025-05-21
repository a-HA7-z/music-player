#include "Singer.h"
using namespace std;

Singer::Singer()
{
    number_of_Musics = 0;
}
Singer::Singer(string fullName,int AlbumsNumber) : name(fullName),number_of_Albums(AlbumsNumber)
{
    number_of_Musics = 0;
}

void Singer::setName(string fullName) {
    name = fullName;
}

void Singer::setAlbumsNumber(int num) {
    number_of_Albums = num;
}