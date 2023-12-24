//
//  main.cpp
//  ConsoleLoginSystem
//
//  Created by Joakim Gårdhagen on 2023-12-23.
//

#include <iostream>
#include <string>
#include <fstream>
#include "User.h"


int main(int argc, const char * argv[]) {
    
    std::string usernameInput, passwordInput;
    
    std::cout<< "Username :";
    std::cin>> usernameInput;
    
    std::cout<<"Password :";
    std::cin>>passwordInput;
    
    User user(usernameInput,passwordInput);
    
    std::ofstream outputFile("userDB.txt");
    
    if(outputFile.is_open()){
        outputFile<<"Username: "<<user.getUsername()<<std::endl;
        outputFile<<"Password: "<<user.getPassword()<<std::endl;
        
        outputFile.close();
        
        std::cout<<"\nUserInformation has been saved to userDB.txt"<<std::endl;
    }else{
        std::cerr<<"Saving to File unsuccessful. . ."<<std::endl;
    }
    
    

    
    
    return 0;
}
