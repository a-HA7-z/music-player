#include <string>
using namespace std;

class Singer
{
private:
    string name;
    int number_of_Albums;
    int number_of_Musics;

public:
    Singer();
    Singer(string,int);

    void setName(string);
    void setAlbumsNumber(int);
};