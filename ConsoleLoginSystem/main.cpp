//
//  main.cpp
//  ConsoleLoginSystem
//
//  Created by Joakim Gårdhagen on 2023-12-23.
//

#include <iostream>
#include "UserManager.h"


int menu(UserManager usermanager){
    int choice;
    
    std::cout<<"Menu:\n";
    std::cout<<"1: Register\n";
    std::cout<<"2: Login\n";
    std::cout<<"3: Exit\n";
    std::cout<<"Enter your choice:";
    std::cin>>choice;
    return choice;
}

int main(int argc, const char * argv[]) {
    
    UserManager usermanager;
    int choice;
    bool loggedIn = false;
    do {
        choice =menu(usermanager);
    
        switch(choice){
            case 1:{
                std::string regUsername,regPassword;
                std::cout<< "Enter username for registration: ";
                std::cin>>regUsername;
                std::cout<<"Enter password for registration: ";
                std::cin>>regPassword;
                usermanager.registerUser(regUsername, regPassword);
                break;
            }
            case 2:{
                do{
                    std::string loginUsername,LoginPassword;
                    std::cout<<"Enter username for login: ";
                    std::cin>>loginUsername;
                    std::cout<<"Enter password for login: ";
                    std::cin>>LoginPassword;
                    loggedIn = usermanager.loginUser(loginUsername, LoginPassword);
                    
                    if(!loggedIn){
                        std::cout<<"Login failed, try again.\n";
                    }
                } while (!loggedIn);
                
                do {
                    std::cout << "\nDashboard:\n";
                    std::cout << "1. View Profile\n";
                    std::cout << "2. Change Password\n";
                    std::cout << "3. Logout\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> choice;
                    
                    switch (choice) {
                        case 1:
                            std::cout << "Viewing profile...\n";
                            break;
                        case 2:
                            std::cout << "Changing password...\n";
                            break;
                        case 3:
                            std::cout << "Logging out...\n";
                            break;
                        default:
                            std::cout << "Invalid choice. Please try again.\n";
                    }
                    
                }while (choice != 3);
                break;
            }
            case 3:
                std::cout<<"Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
            
        }
        }while (choice!=3);
        return 0;
}
