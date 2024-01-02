//
//  UserManager.cpp
//  ConsoleLoginSystem
//
//  Created by Joakim Gårdhagen on 2023-12-24.
//

#include "UserManager.h"
#include "User.h"
#include <iostream>
#include <fstream>
#include <memory>

void UserManager::registerUser(const std::string& username, const std::string& password){
    users.push_back(User(username,password));
    saveUserData();
}
bool UserManager::loginUser(const std::string& username, const std::string& password){
    for(const auto& user : users){
        if(user.getUsername() == username && user.getPassword() == password){
            //loggedInUser = std::make_shared<User>(user.getUsername(),user.getPassword());
            return true;
        }
    }
    std::cout << "Login failed. User not found or incorrect password.\n";
    //loggedInUser = nullptr;
    return false;
}
void UserManager::saveUserData(){
    std::ofstream file("userDB.txt",std::ios::app);
    if(file.is_open()){
        for(const auto& user :users){
            file << user.getUsername()<< " " << user.getPassword()<<" "<<user.getDateCreated()<<"\n";
        }
        std::cout<<"User successfully registrated!"<<std::endl;
        file.close();
    }else{
        std::cerr <<"Unable to open file for writing."<<std::endl;
    }
}
void UserManager::viewUserProfile(const std::string &username){
    for(const auto& user : users){
        if(user.getUsername()==username){
            user.viewProfile();
            return;
        }
    }
    
}



