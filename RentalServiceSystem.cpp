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
            log_in();
            break;
        case 2:
            std::cout << "Activity number: " << activity << " -  SIGN UP" << std::endl;
            sign_up();
            break;
        case 3:
            std::cout << "Activity number: " << activity << " - EXIT" << std::endl;
            exit(0);
        default:
            std::cout << "ERROR This number: " << activity << "has no activity under it" << std::endl;
    }
}

 void lobby() {
     std::cout << "Welcome to Rental Service System!" << std::endl;
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

bool checkUserData(std::string userNameToMatch)
{
    std::map<std::string, std::string> userData;

    std::fstream file("UserData.txt", std::ios::in | std::ios::out | std::ios::app);
    file.close();
    std::ifstream infile("UserData.txt");
    std::string userName, password;

    while (std::getline(infile, userName) && std::getline(infile, password)){
        userData.insert ( std::pair<std::string, std::string>(userName, password));
    }

    infile.close();

    // for (const auto& p : userData)
    //    std::cout << p.first << " : " << p.second << std::endl;
    // std::cout << std::endl;

    auto ret = userData.find(userNameToMatch);
    if (ret != userData.cend()) {
        //std::cout << userNameToMatch << " : " << ret->second << std::endl;
        std::cout << "Name is taken." << std::endl;
        return true;
    }
    else {
        std::cout << "Name is ready to use." << std::endl;
        return false;
    }

}

     void log_in(){
         std::cout << "Enter your user name: " << std::endl;
         std::string userName;
         std::cin >> userName;
     }



     void sign_up(){
         std::cout << "Enter your user name: " << std::endl;
         std::string userName;
         std::cin >> userName;
         if(!(checkUserData(userName))){
            std::cout << "Name is not taken." << std::endl;
         } else {
            std::cout << "Name is already taken, try again with other user name."  << std::endl;
            sign_up();
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
             mainSide();
         } else {
             std::cout << "Passwords does not match, try again." << std::endl;
             sign_up();
         }

     }

