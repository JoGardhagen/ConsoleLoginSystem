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

// Constructor initializes the loggedInUser pointer to nullptr
UserManager::UserManager() : loggedInUser(nullptr) {}

// Register a new user with the provided username and password
void UserManager::registerUser(const std::string& username, const std::string& password) {
    if (!username.empty() && !password.empty()) {
        std::cout << "Adding user to vector: " << username << std::endl;
        // Create a User object and add it to the users vector
        users.push_back(User(username, password));
        std::cout << "Saving user data..." << std::endl;
        // Save user data to the "userDB.txt" file
        saveUserData();
        std::cout << "User data saved." << std::endl;
    } else {
        std::cout << "Invalid input. User not registered." << std::endl;
    }
}

// Log out the currently logged-in user
void UserManager::logoutUser() {
    loggedInUser = nullptr;
    users.clear();
    std::cout << "User logged out.\n";
}

// Log in a user with the provided username and password
bool UserManager::loginUser(const std::string& username, const std::string& password) {
    std::ifstream file("userDB.txt");
    if (!file.is_open()) {
        std::cerr << "Unable to open userDB.txt for reading. \n";
        return false;
    }
    std::string line;
    std::string storedUsername, storedPassword, storedDateCreated;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (iss >> storedUsername >> storedPassword >> storedDateCreated) {
            // Remove spaces from the stored password
            storedPassword.erase(std::remove_if(storedPassword.begin(), storedPassword.end(), ::isspace), storedPassword.end());
            try {
                time_t dateCreated = std::stol(storedDateCreated);
                if (storedUsername == username && storedPassword == password) {
                    // Create a User object and store it in the loggedInUser pointer
                    loggedInUser = std::make_shared<User>(storedUsername, storedPassword, dateCreated);
                    file.close();
                    return true;
                }
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid argument: " << e.what() << "\n";
            } catch (const std::out_of_range& e) {
                std::cerr << "Out of range: " << e.what() << "\n";
            }
        }
    }
    file.close();

    std::cout << "Login failed. User not found or incorrect password.\n";
    loggedInUser = nullptr;
    return false;
}

// Save user data to the "userDB.txt" file
void UserManager::saveUserData() {
    std::ofstream file("userDB.txt", std::ios::app);
    if (file.is_open()) {
        for (const auto& user : users) {
            if (!user.getUsername().empty() && !user.getPassword().empty()) {
                file << user.getUsername() << " " << user.getPassword() << " " << user.getDateCreated() << "\n";
            }
        }
        std::cout << "User successfully registered!" << std::endl;
        file.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

// View the profile of the currently logged-in user
void UserManager::viewLoggInUserProfile() {
    if (loggedInUser != nullptr) {
        loggedInUser->viewProfile();
    } else {
        std::cout << "No user is currently logged in.\n";
    }
}

// Get the shared pointer to the currently logged-in user
std::shared_ptr<User> UserManager::getLoggedInUser() {
    return loggedInUser;
}

// Change the password of the currently logged-in user
void UserManager::changePassword(const std::string& newPassword) {
    if (loggedInUser != nullptr) {
        std::ifstream inFile("userDB.txt");
        if (!inFile.is_open()) {
            std::cerr << "Unable to open userDB.txt for reading.\n";
            return;
        }
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(inFile, line)) {
            lines.push_back(line);
        }
        inFile.close();

        std::ofstream outFile("userDB.txt");
        if (!outFile.is_open()) {
            std::cerr << "Unable to open userDB.txt for writing.\n";
            return;
        }
        for (const std::string& storedUser : lines) {
            std::istringstream iss(storedUser);
            std::string storedUsername, storedPassword, storedDateCreated;
            if (iss >> storedUsername >> storedPassword >> storedDateCreated) {
                if (loggedInUser->getUsername() == storedUsername) {
                    outFile << storedUsername << " " << newPassword << " " << storedDateCreated << '\n';
                } else {
                    outFile << storedUser << "\n";
                }
            }
        }
        outFile.close();
        std::cout << "Password changed.\n";
    } else {
        std::cout << "Not logged in.\n";
    }
}



