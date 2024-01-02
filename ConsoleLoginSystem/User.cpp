//
//  User.cpp
//  ConsoleLoginSystem
//
//  Created by Joakim Gårdhagen on 2023-12-24.
//

#include "User.h"
#include <ctime>
#include <iostream>

User::User(const std::string& username,const std::string& password) 
    : username(username), password(password){
        time_t now = time(0);
        dateCreated = ctime(&now);
    }

//Getter
const std::string& User::getUsername() const {
    return username;
}

const std::string& User::getPassword() const {
    return password;
}
const std::string& User::getDateCreated() const{
    return dateCreated;
}
//Setter
void User::setUsername(const std::string& newUsername){
    username = newUsername;
}
void User::setPassword(const std::string& newPassword){
    password = newPassword;
}
void User::viewProfile()const{
    std::cout<<"Profile details:\n";
    std::cout<<"Username: "<<getUsername()<<'\n';
    std::cout<<"Password: "<<getPassword()<<'\n';
    std::cout<<"Creation Date: "<<getDateCreated()<<'\n';
}
std::shared_ptr<User> User::getSharedPtr() const {
    return std::make_shared<User>(*this);
}
