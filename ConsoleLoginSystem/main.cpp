//
//  main.cpp
//  ConsoleLoginSystem
//
//  Created by Joakim Gårdhagen on 2023-12-23.
//

#include <iostream>
#include <string>

class User{
//Constructor
public:
    User(const std::string& username,const std::string& password) : username(username), password(password){}
    
    //Getter
    const std::string& getUsername() const {
            return username;
        }

    const std::string& getPassword() const {
            return password;
        }
    //Setter
    void setUsername(const std::string& newUsername){
        username = newUsername;
    }
    void setPassword(const std::string& newPassword){
        password = newPassword;
    }
    
private:
    //Attributes
    std::string username;
    std::string password;
};

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
