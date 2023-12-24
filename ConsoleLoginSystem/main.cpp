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
    
    std::string regUserName,regPassword;
    std::cout<<"Enter Username for registration: ";
    std::cin>>regUserName;
    std::cout<<"Enter Password for registration: ";
    std::cin>>regPassword;
    
    usermanager.registerUser(regUserName, regPassword);
    
    
    

    
    
    return 0;
}
