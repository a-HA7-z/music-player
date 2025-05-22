#pragma once
#include <string>

using namespace std;
class User{
private:
    string username;
    string password;
protected:
    User();
    User(string ,string );
public:
    void setUsername(string );
    void setPassword(string );
    string getUsername();
    string getPassword();
};