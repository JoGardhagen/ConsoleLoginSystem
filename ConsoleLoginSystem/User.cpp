//
//  User.cpp
//  ConsoleLoginSystem
//
//  Created by Joakim Gårdhagen on 2023-12-24.
//

#include "User.h"

User::User(const std::string& username,const std::string& password) : username(username), password(password){}

//Getter
const std::string& User::getUsername() const {
        return username;
    }

const std::string& User::getPassword() const {
        return password;
    }
//Setter
void User::setUsername(const std::string& newUsername){
    username = newUsername;
}
void User::setPassword(const std::string& newPassword){
    password = newPassword;
}
