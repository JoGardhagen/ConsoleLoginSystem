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

class UserManager {
public:
    // Constructor initializes the loggedInUser pointer to nullptr
    UserManager();

    // Register a new user with the provided username and password
    void registerUser(const std::string& username, const std::string& password);

    // View the profile of a specific user by username
    void viewUserProfile(const std::string& username);

    // Log in a user with the provided username and password
    bool loginUser(const std::string& username, const std::string& password);

    // Log out the currently logged-in user
    void logoutUser();

    // View the profile of the currently logged-in user
    void viewLoggInUserProfile();

    // Change the password of the currently logged-in user
    void changePassword(const std::string& newPassword);

    // Get the shared pointer to the currently logged-in user
    std::shared_ptr<User> getLoggedInUser();

private:
    std::vector<User> users;        // Vector to store registered users
    void saveUserData();            // Save user data to a file
    std::shared_ptr<User> loggedInUser; // Pointer to the currently logged-in user
};

#endif /* UserManager_h */
