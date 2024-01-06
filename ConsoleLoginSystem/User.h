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
#include <memory>

class User {
public:
    // Constructors
    User(const std::string& username, const std::string& password);
    User(const std::string& username, const std::string& password, time_t dateCreated);

    // Getter functions for username, password, and creation date
    const std::string& getUsername() const;
    const std::string& getPassword() const;
    time_t getDateCreated() const;

    // View the user's profile information
    void viewProfile() const;

    // Setter functions for username and password
    void setUsername(const std::string& newUsername);
    void setPassword(const std::string& newPassword);

    // Get a shared pointer to the current User object
    std::shared_ptr<User> getSharedPtr() const;

private:
    std::string username; // User's username
    std::string password; // User's password
    time_t dateCreated;   // Date and time when the user was created
};

#endif /* User_h */
