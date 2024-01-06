//
//  main.cpp
//  ConsoleLoginSystem
//
//  Created by Joakim Gårdhagen on 2023-12-23.
//

#include <iostream>
#include "UserManager.h"

// Function to display the main menu and get user's choice
int menu(UserManager& usermanager) {
    int choice;

    std::cout << "Menu:\n";
    std::cout << "1: Register\n";
    std::cout << "2: Login\n";
    std::cout << "3: Exit\n";
    std::cout << "Enter your choice:";
    std::cin >> choice;

    // Clear input buffer
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return choice;
}

// Function to display user dashboard options and handle user interactions
void userPanel(UserManager& usermanager) {
    int choice;

    do {
        std::string newPassword;
        std::cout << "\nDashboard:\n";
        std::cout << "1. View Profile\n";
        std::cout << "2. Change Password\n";
        std::cout << "3. Logout\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                std::cout << "Viewing profile...\n";
                usermanager.viewLoggInUserProfile();
                break;
            case 2:
                std::cout << "Enter a new password: ";
                std::cin >> newPassword;
                usermanager.changePassword(newPassword);
                break;
            case 3:
                std::cout << "Logging out...\n";
                usermanager.logoutUser();
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);
}

// Function to handle user login
bool userLogin(UserManager& usermanager) {
    std::string loginUsername, loginPassword;
    std::cout << "Enter username for login: ";
    std::cin >> loginUsername;
    std::cout << "Enter password for login: ";
    std::cin >> loginPassword;

    // Clear input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return usermanager.loginUser(loginUsername, loginPassword);
}

// Function to handle user registration
void registerUser(UserManager& usermanager) {
    std::string regUsername, regPassword;
    std::cout << "Enter username for registration: ";
    std::cin >> regUsername;
    std::cout << "Enter password for registration: ";
    std::cin >> regPassword;
    
    // Register user with UserManager
    usermanager.registerUser(regUsername, regPassword);
    std::cout << "User registration completed.\n";
}

int main(int argc, const char* argv[]) {
    // Create UserManager object
    UserManager usermanager;
    int choice;

    // Main program loop
    do {
        // Display main menu and get user's choice
        choice = menu(usermanager);

        switch (choice) {
            case 1:
                std::cout << "Registering user..." << std::endl;
                // Call function to handle user registration
                registerUser(usermanager);
                std::cout << "User registered." << std::endl;
                break;
            case 2:
                // Call function to handle user login
                if (userLogin(usermanager)) {
                    std::cout << "Login successful. Going to user panel.\n";
                    // Call function to display user dashboard
                    userPanel(usermanager);
                } else {
                    std::cout << "Login Failed\n";
                }
                break;
            case 3:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}

