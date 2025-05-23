#include <string>
#include <vector>
#include "Music.h"
using namespace std;

class PlayList
{
private:
    string name;
    int number_of_Music;
    vector<Music> musicList;
public:
    PlayList(string);

    string getName();
    int getNumberOfMusic();

    void addMusic(const Music&);
};