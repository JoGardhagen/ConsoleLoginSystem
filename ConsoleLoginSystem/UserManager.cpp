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

UserManager::UserManager() : loggedInUser(nullptr){}

void UserManager::registerUser(const std::string& username, const std::string& password){
    if (!username.empty() && !password.empty()) {
        std::cout << "Adding user to vector: " << username << std::endl;
        users.push_back(User(username,password));
        std::cout << "Saving user data..." << std::endl;
        saveUserData();
        std::cout << "User data saved." << std::endl;
    }else {
        std::cout << "Invalid input. User not registered." << std::endl;
    }
    
}

void UserManager::logoutUser(){
    loggedInUser = nullptr;
    users.clear();
    std::cout<<"User logged out.\n";
}
bool UserManager::loginUser(const std::string& username, const std::string& password){
    std::ifstream file("userDB.txt");
    if(!file.is_open()){
        std::cerr<<"Unable to open userDB.txt for reading. \n";
        return false;
    }
    
    std::string storedUsername,storedPassWord,storedDateCreated;
    std::vector<User> matchingUsers;
    
    while(file>>storedUsername>>storedPassWord>>storedDateCreated){
        if(storedUsername == username && storedPassWord==password){
            matchingUsers.push_back(User(storedUsername,storedPassWord));
        }
    }
    file.close();
    
    if(!matchingUsers.empty()){
        loggedInUser = std::make_shared<User>(matchingUsers[0]);
        return true;
    }
    
    std::cout << "Login failed. User not found or incorrect password.\n";
    loggedInUser = nullptr;
    return false;
    
}
void UserManager::saveUserData(){
    std::ofstream file("userDB.txt",std::ios::app);
    if(file.is_open()){
        for(const auto& user :users){
            if (!user.getUsername().empty() && !user.getPassword().empty()) {
                file << user.getUsername()<< " " << user.getPassword()<<" "<<user.getDateCreated()<<"\n";
            }
        }
        std::cout<<"User successfully registrated!"<<std::endl;
        file.close();
    }else{
        std::cerr <<"Unable to open file for writing."<<std::endl;
    }
    std::cout << "End of saveUserData method." << std::endl;
}
void UserManager::viewUserProfile(const std::string &username){
    for(const auto& user : users){
        if(user.getUsername()==username){
            user.viewProfile();
            return;
        }
    }
    
}



