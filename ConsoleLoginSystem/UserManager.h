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

class UserManager{
public:
    void registerUser(const std::string& username,const std::string& password);
    bool loginUser(const std::string& username, const std::string& password);
    
private:
    std::vector<User> users;
    void saveUserData();
};

#endif /* UserManager_h */
