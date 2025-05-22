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

    static void addMusic(PlayList&, Music&, vector<Singer>&);
};