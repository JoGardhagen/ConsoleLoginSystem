//
//  User.h
//  ConsoleLoginSystem
//
//  Created by Joakim Gårdhagen on 2023-12-24.
//

#ifndef User_h
#define User_h


#include <string>

class User {
public:
    User(const std::string& username,const std::string& password);
    
    const std::string& getUsername() const;
    const std::string& getPassword() const;
    const std::string& getDateCreated() const;
    
    void setUsername(const std::string& newUsername);
    void setPassword(const std::string& newPassword);
    
private:
    std::string username;
    std::string password;
    std::string dateCreated;
};

#endif /* User_h */
