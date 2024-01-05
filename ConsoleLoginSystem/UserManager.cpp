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
#include <sstream>

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
    std::string line;
    std::string storedUsername,storedPassWord;
    
    while(std::getline(file,line)){
        std::istringstream iss(line);
        if(iss >>storedUsername >> storedPassWord){
            //std::cout << "Checking user: " << storedUsername << std::endl;
            //std::cout << "Expected password: " << storedPassWord << std::endl;
            
            storedPassWord.erase(std::remove_if(storedPassWord.begin(), storedPassWord.end(), ::isspace), storedPassWord.end());
            if(storedUsername == username && storedPassWord==password){
                loggedInUser = std::make_shared<User>(storedUsername,storedPassWord);
                file.close();
                return true;
            }
        }
        
    }
    file.close();
    
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

void UserManager::viewLoggInUserProfile(){
    if(loggedInUser !=nullptr){
        loggedInUser->viewProfile();
    }else{
        std::cout<<"No user is currently logged in.\n";
    }
}
std::shared_ptr<User> UserManager::getLoggedInUser() {
    return loggedInUser;
}

/*void UserManager::changePassword(const std::string& newPassword){
    if(loggedInUser){
        //for(auto& user : users){
            std::cout << "Changing password for user: " << loggedInUser->getUsername() << std::endl;
            loggedInUser->setPassword(newPassword);
            //if(user.getUsername() == loggedInUser->getUsername()){
                //user.setPassword(newPassword);
                saveUserData();
                std::cout<<"Password changed.\n";
                //return;
    }else{
        std::cout<<"Didnt change. . .\n";
    }
}*/
/*void UserManager::changePassword(const std::string& newPassword){
    if(loggedInUser){
        loggedInUser->setPassword(newPassword);
        
        std::ifstream inputFile("userDB.txt");
        std::ofstream outoutFile("userDB_temp.txt");
        
        if(inputFile.is_open() && outoutFile.is_open()){
            std::string username,password,dateCreated;
            
            while(inputFile>>username>>password>>dateCreated){
                if (username==loggedInUser->getUsername()) {
                    outoutFile<<loggedInUser->getUsername()<<" "<<newPassword<<" "<< loggedInUser->getDateCreated()<<"\n";
                }else{
                    outoutFile << username <<" "<< password <<" "<<dateCreated<<'\n';
                }
            }
            inputFile.close();
            outoutFile.close();
            
            std::remove("userDB.txt");
            std::rename("userDB_temp.txt","userDB.txt");
            std::cout<<"Password changed.\n";
        }else{
            std::cerr<<"Unable to open for read or write from or to files.\n";
        }
    }else{
        std::cout<<"Not logged in, unable to change password.\n";
    }
}*/
void UserManager::changePassword(const std::string& newPassword){
    if(loggedInUser != nullptr){
        std::ifstream inFile("userDB.txt");
        if(!inFile.is_open()){
            std::cerr<<"Unable to open userDB.txt for reading.\n";
            return;
        }
        std::vector<std::string>lines;
        std::string line;
        while(std::getline(inFile, line)){
            lines.push_back(line);
        }
        inFile.close();
        
        std::ofstream outFile("userDB.txt");
        if(!outFile.is_open()){
            std::cerr<<"Unable to open userDB.txt for writing.\n";
            return;
        }
        for(const std::string& storedUser : lines){
            std::istringstream iss(storedUser);
            std::string storedUsername, storedPassword, storedDateCreated;
            if(iss >> storedUsername >> storedPassword >> storedDateCreated){
                if(loggedInUser->getUsername()==storedUsername){
                    outFile << storedUsername << " " << newPassword << " " << storedDateCreated << '\n';
                }else{
                    outFile << storedUser<<"\n";
                }
                
            }
        }
        outFile.close();
        std::cout<<"Password changed.\n";
    }else{
        std::cout<<"Not logged in.\n";
    }
}



