//
//  User.cpp
//  ConsoleLoginSystem
//
//  Created by Joakim Gårdhagen on 2023-12-24.
//

#include "User.h"
#include <ctime>
#include <iostream>

// Constructor with creation date provided
User::User(const std::string& username, const std::string& password, time_t dateCreated)
    : username(username), password(password), dateCreated(dateCreated) {}

// Constructor without creation date (uses current time)
User::User(const std::string& username, const std::string& password)
    : username(username), password(password) {
        dateCreated = std::time(nullptr);
    }

// Getter functions
const std::string& User::getUsername() const {
    return username;
}

const std::string& User::getPassword() const {
    return password;
}

time_t User::getDateCreated() const {
    return dateCreated;
}

// Setter functions
void User::setUsername(const std::string& newUsername) {
    username = newUsername;
}

void User::setPassword(const std::string& newPassword) {
    password = newPassword;
}

// View user profile details
void User::viewProfile() const {
    std::cout << "Profile details:\n";
    std::cout << "Username: " << getUsername() << '\n';
    std::cout << "Password: " << getPassword() << '\n';

    /*std::tm* timeInfo = std::localtime(&dateCreated);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);

    std::cout << "Creation Date: " << buffer << '\n';*/
    
    // Assuming time_t dateCreated is defined earlier in the code

    // Convert time_t to tm structure
    std::tm* timeInfo = std::localtime(&dateCreated);

    // Create a buffer to store the formatted date and time string
    char buffer[80];

    // Format the date and time into the buffer
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);

    // Print the formatted creation date
    std::cout << "Creation Date: " << buffer << '\n';
}

// Get a shared pointer to the current User object
std::shared_ptr<User> User::getSharedPtr() const {
    return std::make_shared<User>(*this);
}
