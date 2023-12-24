//
//  main.cpp
//  ConsoleLoginSystem
//
//  Created by Joakim Gårdhagen on 2023-12-23.
//

#include <iostream>
#include <string>
#include "User.h"


int main(int argc, const char * argv[]) {
    
    std::string usernameInput, passwordInput;
    
    std::cout<< "Username :";
    std::cin>> usernameInput;
    
    std::cout<<"Password :";
    std::cin>>passwordInput;
    
    User user(usernameInput,passwordInput);
    
    std::cout<<"User Created:\n";
    std::cout<<"Username: "<<user.getUsername()<<std::endl;
    std::cout<<"Password: "<<user.getPassword()<<std::endl;
    
    
    return 0;
}
