//
//  main.cpp
//  ConsoleLoginSystem
//
//  Created by Joakim Gårdhagen on 2023-12-23.
//

#include <iostream>
#include "UserManager.h"




int main(int argc, const char * argv[]) {
    
    UserManager usermanager;
    int choice;
    
    do {
        std::cout<<"Menu:\n";
        std::cout<<"1: Register\n";
        std::cout<<"2: Login\n";
        std::cout<<"3: Exit\n";
        std::cout<<"Enter your choice:";
        std::cin>>choice;
        
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
                std::string loginUsername,LoginPassword;
                std::cout<<"Enter username for login: ";
                std::cin>>loginUsername;
                std::cout<<"Enter password for login: ";
                std::cin>>LoginPassword;
                usermanager.loginUser(loginUsername, LoginPassword);
                break;
            }
            case 3:{
                std::cout<<"Exiting Porgram.\n";
            }
        }
        
    } while (choice !=3);
    return 0;
}
