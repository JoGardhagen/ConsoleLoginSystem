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
    
    User user("Joakim","PassOrd1");// Skapar objekt
    
    std::cout<<"Användarnamn :" << user.getUsername()<<'\n'; // anropar ObjekMethod
    std::cout<<"PassOrd : " << user.getPassword()<<'\n'; // anropar ObjekMethod
    
    user.setUsername("NewUserName");
    user.setPassword("newPassOrd");
    
    std::cout<<"Updated UserName: "<<user.getUsername()<<'\n';
    std::cout<<"Updated Password: "<<user.getPassword()<<'\n';
    
    
    return 0;
}
