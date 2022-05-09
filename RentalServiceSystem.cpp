#include <iostream>
#include "RentalServiceSystem.h"
#include <stdlib.h>
#include <map>
#include <fstream>

void mainSide(){
    if(userRecognition()){
        lobby();
    } else {
        mainSide();
    }
}

bool userRecognition(){
    std::cout << "Welcome to Rental Service System!" << std::endl;
    std::cout << "Type number to choose activity: " << std::endl;
    std::cout << "1: Log In" << std::endl;
    std::cout << "2: Sign Up" << std::endl;
    std::cout << "3: Exit" << std::endl;
    int activity;
    std::cin >> activity;
    switch(activity) {
        case 1:
            std::cout << "Activity number: " << activity << " - LOG IN" << std::endl;
            return log_in();
        case 2:
            std::cout << "Activity number: " << activity << " -  SIGN UP" << std::endl;
            return sign_up();
        case 3:
            std::cout << "Activity number: " << activity << " - EXIT" << std::endl;
            exit(0);
        default:
            std::cout << "ERROR This number: " << activity << "has no activity under it" << std::endl;
    }
}

 void lobby() {
     std::cout << "Type number to choose activity: " << std::endl;
     std::cout << "1: List of cars" << std::endl;
     std::cout << "2: Status of car" << std::endl;
     std::cout << "3: Rent a car" << std::endl;
     std::cout << "4: List of customers and their rent history" << std::endl;
     std::cout << "5: Exit" << std::endl;
     int activity;
     std::cin >> activity;
     switch (activity) {
         case 1:
             std::cout << "Activity number: " << activity << " - LIST OF CARS" << std::endl;
             break;
         case 2:
             std::cout << "Activity number: " << activity << " -  STATUS OF CAR" << std::endl;
             break;
         case 3:
             std::cout << "Activity number: " << activity << " - RENT A CAR" << std::endl;
             break;
         case 4:
             std::cout << "Activity number: " << activity << " - LIST OF CUSTOMERS AND THEIR RENT HISTORY" << std::endl;
             break;
         case 5:
             std::cout << "Activity number: " << activity << " - EXIT" << std::endl;
             exit(0);
         default:
             std::cout << "ERROR This number: " << activity << "has no activity under it" << std::endl;
     }
 }

bool lookingForUserName(std::string userNameToMatch){
    //std::fstream file("UserData.txt", std::ios::in | std::ios::out | std::ios::app);
    //file.close();

    std::map<std::string, std::string> userData;
    std::ifstream infile("UserData.txt");
    std::string userName, password;

    while (std::getline(infile, userName) && std::getline(infile, password)){
        userData.insert ( std::pair<std::string, std::string>(userName, password));
    }
    infile.close();

    auto ret = userData.find(userNameToMatch);
    if (ret != userData.cend()) {
        return true;
    }
    else {
        return false;
    }

}

bool isUserNameMatchWithPassword(std::string userNameToMatch, std::string userPasswordToMatch){
    std::map<std::string, std::string> userData;
    std::ifstream infile("UserData.txt");
    std::string userName, password;

    while (std::getline(infile, userName) && std::getline(infile, password)){
        userData.insert ( std::pair<std::string, std::string>(userName, password));
    }
    infile.close();

    auto ret = userData.find(userNameToMatch);
    if (ret != userData.cend()) {
        if(ret->second == userPasswordToMatch){
            std::cout << "User name match with password!" << std::endl;
            return true;
        } else {
            std::cout << "User name does not match with password." << std::endl;
            return false;
        }
    }
    else {
        std::cout << "Name is ready to use." << std::endl;
        return false;
    }

}

     bool log_in(){
         std::cout << "Enter your user name: " << std::endl;
         std::string userName;
         std::cin >> userName;
         if(!(lookingForUserName(userName))){
             std::cout << "This name is not used, try again or sign up." << std::endl;
             return false;
         } else {
             std::cout << "Correct name, type your password"  << std::endl;
         }
         std::cout << "Enter your password: " << std::endl;
         std::string password;
         std::cin >> password;
         if(isUserNameMatchWithPassword(userName, password)){
             std::cout << "Hello " << userName << " welcome to our service!" << std::endl;
             return true;
         } else {
             std::cout << "User name does not match with password" << std::endl;
             return false;
         }

     }



     bool sign_up(){
         std::cout << "Enter your user name: " << std::endl;
         std::string userName;
         std::cin >> userName;
         if(!(lookingForUserName(userName))){
            std::cout << "Name is not taken." << std::endl;
         } else {
            std::cout << "Name is already taken, try again with other user name."  << std::endl;
            return false;
         }
         std::cout << "Enter your password: " << std::endl;
         std::string password;
         std::cin >> password;
         std::cout << "Repeat your password: " << std::endl;
         std::string repeatedPassword;
         std::cin >> repeatedPassword;
         if(password == repeatedPassword){
             std::cout << "Congratulation. You create your account to Rental Service System!" << std::endl;
             std::fstream file("UserData.txt", std::ios::in | std::ios::out | std::ios::app);
             file << userName << std::endl;
             file << password << std::endl;
             file.close();
             return true;
         } else {
             std::cout << "Passwords does not match, try again." << std::endl;
             return false;
         }

     }

