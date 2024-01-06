# ConsoleLoginSystem 
this is a smaller project in c++ login and registraion console application.

# Program Summary

## Description
This program is a user management application written in C++. It utilizes two main classes, `UserManager` and `User`, to facilitate user registration, login, and profile management.

## Classes
### UserManager
- Responsible for handling users, including registration, login, and profile management.
- Uses a vector of `User` objects to store user information.
- Implements functions such as `registerUser`, `loginUser`, `viewLoggInUserProfile`, and `changePassword`.

### User
- Represents an individual user with a username, password, and creation date.
- Includes functions to display user profiles and change passwords.

## Usage
1. Launch the program.
2. Choose between registering a new user, logging in, or exiting.
3. Upon login, the user is granted access to a dashboard with options to view the profile, change the password, or log out.

## File Handling
- User information is stored in a text file ("userDB.txt").
- Passwords are stored without extra spaces to avoid issues.

## Build and Run
- The program can be compiled and executed as a console application.

## External Libraries
- No external libraries are required to run the program.

## Improvements and Future Work
- Ability to handle multiple users concurrently.
- More secure password handling with encryption.

