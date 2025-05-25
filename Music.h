#pragma once
#include <string>
using namespace std;

class Music
{
private:
    string name;
    string singer;
    int publishYear;
    string style;
public:
    Music(string,string,int,string);

    Music(const Music&);
    //    void setInfo(string,string,int,string);

    void setName(const string&);

    string getName();
    string getSingerName();
    int getPublishYear();
    string getStyle();

    bool operator==(const Music&) const;

    void showInfo() const;

    void playMusic();
};