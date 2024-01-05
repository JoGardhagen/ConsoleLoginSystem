//
//  User.h
//  ConsoleLoginSystem
//
//  Created by Joakim Gårdhagen on 2023-12-24.
//

#ifndef User_h
#define User_h


#include <string>
#include <ctime>

class User {
public:
    User(const std::string& username,const std::string& password);
    
    User(const std::string& username, const std::string& password, time_t dateCreated);
    
    const std::string& getUsername() const;
    const std::string& getPassword() const;
    //const std::string& getDateCreated() const;
    time_t getDateCreated() const;
    
    void viewProfile() const;
    
    void setUsername(const std::string& newUsername);
    void setPassword(const std::string& newPassword);
    
    std::shared_ptr<User>getSharedPtr() const;
    
private:
    std::string username;
    std::string password;
    time_t dateCreated;
    //std::string dateCreated;
};

#endif /* User_h */
