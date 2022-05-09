#include <iostream>
#include "RentalServiceSystem.h"
#include <stdlib.h>

bool customerRecognition(){
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
            break;
        case 2:
            std::cout << "Activity number: " << activity << " -  SIGN UP" << std::endl;
            break;
        case 3:
            std::cout << "Activity number: " << activity << " - EXIT" << std::endl;
            exit(0);
        default:
            std::cout << "ERROR This number: " << activity << "has no activity under it" << std::endl;
    }
}

 void lobby(){
    std::cout << "Welcome to Rental Service System!" << std::endl;
    std::cout << "Type number to choose activity: " << std::endl;
    std::cout << "1: List of cars" << std::endl;
    std::cout << "2: Status of car" << std::endl;
    std::cout << "3: Rent a car" << std::endl;
    std::cout << "4: List of customers and their rent history" << std::endl;
    std::cout << "5: Exit" << std::endl;
    int activity;
    std::cin >> activity;
     switch(activity) {
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

