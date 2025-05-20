#include "User.h"
using namespace std;

User::User() {
    username = "";
    password = "";
}

User::User(string name,string pass) : username(name) , password(pass) {}

void User::setUsername(string name) {
    username = name;
}

void User::setPassword(string pass) {
    password = pass;
}

string User::getUsername() {
    return username;
}

string User::getPassword() {
    return password;
}