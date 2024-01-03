//
//  UserManager.h
//  ConsoleLoginSystem
//
//  Created by Joakim Gårdhagen on 2023-12-24.
//

#ifndef UserManager_h
#define UserManager_h

#include "User.h"
#include <vector>
#include <fstream>
#include <memory>

class UserManager{
public:
    UserManager();
    
    void registerUser(const std::string& username,const std::string& password);
    //bool loginUser(const std::string& username, const std::string& password);
    void viewUserProfile(const std::string& username);
    bool loginUser(const std::string& username,const std::string& password);
    void logoutUser();
    
private:
    std::vector<User> users;
    void saveUserData();
    std::shared_ptr<User> loggedInUser;
    
};

#endif /* UserManager_h */
