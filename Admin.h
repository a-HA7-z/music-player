#include "User.h"
#include "Singer.h"
using namespace std;

class Admin : public User
{
private:

public:
    Admin(string,string);

    void addNewMusic(PlayList&, Music&, vector<Singer>&);

    void deleteMusic(PlayList&, Music&,vector<Singer>&);
};