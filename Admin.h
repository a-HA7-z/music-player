#include "User.h"
#include "Music.h"
#include "PlayList.h"
#include "Singer.h"
using namespace std;

class Admin : public User
{
private:

public:
    Admin(string,string);

    void addMusic(PlayList&, Music&, vector<Singer>&);

    void deleteMusic(PlayList&, Music&,vector<Singer>&);
};