#include <iostream>
#include "RentalServiceSystem.h"
#include <stdlib.h>
#include <map>
#include <fstream>

User loggedInUser;

void mainSide() {
    if (userRecognition()) {
        lobby();
    } else {
        mainSide();
    }
}

bool userRecognition() {
    std::cout << "Welcome to Rental Service System!" << std::endl;
    std::cout << "Type number to choose activity: " << std::endl;
    std::cout << "1: Log In" << std::endl;
    std::cout << "2: Sign Up" << std::endl;
    std::cout << "3: Exit" << std::endl;
    int activity;
    std::cin >> activity;
    switch (activity) {
        case 1:
            std::cout << "Activity number: " << activity << " - LOG IN" << std::endl;
            return log_in();
        case 2:
            std::cout << "Activity number: " << activity << " - SIGN UP" << std::endl;
            return sign_up();
        case 3:
            std::cout << "Activity number: " << activity << " - EXIT" << std::endl;
            exit(0);
        default:
            std::cout << "ERROR This number: " << activity << " has no activity under it" << std::endl;
            return false;
    }
}

void lobby() {
    std::cout << "Type number to choose activity: " << std::endl;
    std::cout << "1: List of cars and their statuses" << std::endl;
    std::cout << "2: Rent a car" << std::endl;
    std::cout << "3: Your rented cars list" << std::endl;
    std::cout << "4: Return a car" << std::endl;
    std::cout << "5: Your rent history" << std::endl;
    std::cout << "6: Log of activities" << std::endl;
    std::cout << "7: Exit" << std::endl;
    int activity;
    std::cin >> activity;
    std::string clean;
    getline(std::cin, clean);
    switch (activity) {
        case 1: {
            std::cout << "Activity number: " << activity << " - LIST OF CARS AND THEIR STATUSES" << std::endl;
            printCarModelsAndTheirStatuses();
            lobby();
        }
        case 2: {
            std::cout << "Activity number: " << activity << " - RENT A CAR" << std::endl;
            rentCar();
            lobby();
        }
        case 3: {
            std::cout << "Activity number: " << activity << " - RENTED CARS LIST" << std::endl;
            rentedCarsList();
            lobby();
        }
        case 4: {
            std::cout << "Activity number: " << activity << " - RETURN A CAR" << std::endl;
            returnCar();
            lobby();
        }
        case 5: {
            std::cout << "Activity number: " << activity << " - YOUR RENT HISTORY" << std::endl;
            showYourRentHistory();
            lobby();
        }
        case 6: {
            std::cout << "Activity number: " << activity << " - LOG" << std::endl;
            showLogs();
            lobby();
        }
        case 7: {
            std::cout << "Activity number: " << activity << " - EXIT" << std::endl;
            exit(0);
        }
        default:
            std::cout << "ERROR This number: " << activity << " has no activity under it" << std::endl;
            lobby();
    }
}

void garage() {
    addCarToData("Mercedes-Benz CLA-Class", "garage");
    addCarToData("Audi A4", "garage");
    addCarToData("Tesla Model 3", "garage");
    addCarToData("Audi A6", "garage");
    addCarToData("Mercedes-Benz E-Class", "garage");
    addCarToData("BMW 8 Series", "garage");
    addCarToData("Audi A7", "garage");
    addCarToData("Tesla Model S", "garage");
    addCarToData("Audi A8", "garage");
    addCarToData("Mercedes-Benz S-Class", "garage");
}

bool lookingForUserName(std::string userNameToMatch) {
    std::map<std::string, std::string> userData;
    std::ifstream infile("UserData.txt");
    std::string userName, password;

    while (std::getline(infile, userName) && std::getline(infile, password)) {
        userData.insert(std::pair<std::string, std::string>(userName, password));
    }
    infile.close();

    auto ret = userData.find(userNameToMatch);
    if (ret != userData.cend()) {
        return true;
    } else {
        return false;
    }

}

bool isUserNameMatchWithPassword(std::string userNameToMatch, std::string userPasswordToMatch) {
    std::map<std::string, std::string> userData;
    std::ifstream infile("UserData.txt");
    std::string userName, password;

    while (std::getline(infile, userName) && std::getline(infile, password)) {
        userData.insert(std::pair<std::string, std::string>(userName, password));
    }
    infile.close();

    auto ret = userData.find(userNameToMatch);
    if (ret != userData.cend()) {
        if (ret->second == userPasswordToMatch) {
            std::cout << "User name match with password!" << std::endl;
            return true;
        } else {
            std::cout << "User name does not match with password." << std::endl;
            return false;
        }
    } else {
        std::cout << "Name is ready to use" << std::endl;
        return false;
    }

}

bool log_in() {
    std::cout << "Enter your user name: " << std::endl;
    std::string userName;
    std::cin >> userName;
    if (!(lookingForUserName(userName))) {
        std::cout << "This name is not used, try again or sign up." << std::endl;
        return false;
    } else {
        std::cout << "Correct name, type your password" << std::endl;
    }
    std::cout << "Enter your password: " << std::endl;
    std::string password;
    std::cin >> password;
    if (isUserNameMatchWithPassword(userName, password)) {
        std::cout << "Hello " << userName << " welcome to our service!" << std::endl;
        loggedInUser.setUserName(userName);
        return true;
    } else {
        std::cout << "User name does not match with password" << std::endl;
        return false;
    }

}


bool sign_up() {
    std::cout << "Enter your user name: " << std::endl;
    std::string userName;
    std::cin >> userName;
    if (!(lookingForUserName(userName))) {
        std::cout << "Name is not taken." << std::endl;
    } else {
        std::cout << "Name is already taken, try again with other user name." << std::endl;
        return false;
    }
    std::cout << "Enter your password: " << std::endl;
    std::string password;
    std::cin >> password;
    std::cout << "Repeat your password: " << std::endl;
    std::string repeatedPassword;
    std::cin >> repeatedPassword;
    if (password == repeatedPassword) {
        std::cout << "Congratulation. You create your account to Rental Service System!" << std::endl;
        std::fstream file("UserData.txt", std::ios::in | std::ios::out | std::ios::app);
        file << userName << std::endl;
        file << password << std::endl;
        file.close();
        loggedInUser.setUserName(userName);
        return true;
    } else {
        std::cout << "Passwords does not match, try again." << std::endl;
        return false;
    }

}

int findCarAndItStatus(std::string carModelToMatch) {
    std::map<std::string, std::string> carModelAndStatus;
    std::ifstream infile("CarsData.txt");
    std::string carModel;
    std::string carStatus;

    while (std::getline(infile, carModel) && std::getline(infile, carStatus)) {
        carModelAndStatus.insert(std::pair<std::string, std::string>(carModel, carStatus));
    }
    infile.close();

    auto ret = carModelAndStatus.find(carModelToMatch);
    if (ret != carModelAndStatus.cend()) {
        if (ret->second == "garage") {
            std::cout << "The car is ready to rent." << std::endl;
            return 1;
        }
        if (ret->second == "rented") {
            std::cout << "The car is rented right now." << std::endl;
            return 2;
        }
    } else {
        std::cout << "We dont have this model in data" << std::endl;
        return 3;

    }
}

void addCarToData(std::string carModel, std::string carStatus) {
    std::fstream file("CarsData.txt", std::ios::in | std::ios::out | std::ios::app);
    if (findCarAndItStatus(carModel) == 3) {
        file << carModel << std::endl;
        file << carStatus << std::endl;
        file.close();
    } else {
        std::cout << "Car is already in our data" << std::endl;
    }
}

void printCarModelsAndTheirStatuses() {
    std::map<std::string, std::string> carModelAndStatus;
    std::ifstream infile("CarsData.txt");
    std::string carModel;
    std::string carStatus;

    while (std::getline(infile, carModel) && std::getline(infile, carStatus)) {
        carModelAndStatus.insert(std::pair<std::string, std::string>(carModel, carStatus));
    }
    infile.close();

    int i = 1;

    for (const auto &p: carModelAndStatus) {
        std::cout << i << " " << p.first << " : " << p.second << std::endl;
        i++;
    }
    std::cout << std::endl;
}

void rentCar() {
    std::cout << "Cars ready to rent: " << std::endl;
    std::map<std::string, std::string> carModelAndStatus;
    std::ifstream infile("CarsData.txt");
    std::string carModel;
    std::string carStatus;

    while (std::getline(infile, carModel) && std::getline(infile, carStatus)) {
        carModelAndStatus.insert(std::pair<std::string, std::string>(carModel, carStatus));
    }
    infile.close();

    int i = 1;

    for (const auto &p: carModelAndStatus) {
        if (p.second == "garage") {
            std::cout << i << " " << p.first << std::endl;
            i++;
        }
    }

    std::cout << "Enter car model that you want to rent" << std::endl;
    std::string line;
    getline(std::cin, line);
    auto ret = carModelAndStatus.find(line);
    if (ret != carModelAndStatus.cend()) {
        ret->second = "rented";

        loggedInUser.currentRent(line);
        loggedInUser.historyRent(line, "rented");
        logOfActivities(line, "rented");

    } else {
        std::cout << "ERROR" << std::endl;
    }

    std::ofstream file("CarsData.txt");
    file << "";
    file.close();

    std::fstream fileRewrite("CarsData.txt", std::ios::in | std::ios::out | std::ios::app);

    for (const auto &p: carModelAndStatus) {
        fileRewrite << p.first << std::endl;
        fileRewrite << p.second << std::endl;
    }

    file.close();
}

void returnCar() {
    std::map<std::string, std::string> carModelAndStatus;
    std::ifstream infileCarsData("CarsData.txt");
    std::string carModel;
    std::string carStatus;

    while (std::getline(infileCarsData, carModel) && std::getline(infileCarsData, carStatus)) {
        carModelAndStatus.insert(std::pair<std::string, std::string>(carModel, carStatus));
    }
    infileCarsData.close();

    std::map<std::string, std::string> rentedCars;
    std::ifstream infileRentedCars(loggedInUser.userName+ "_currentRent.txt");
    std::string rentedCarModel;
    std::string rentedStatus;

    while (std::getline(infileRentedCars, rentedCarModel) && std::getline(infileRentedCars, rentedStatus)) {
        rentedCars.insert(std::pair<std::string, std::string>(rentedCarModel, rentedStatus));
    }
    infileRentedCars.close();

    std::cout << "This is your rented car list, type car model that you want to return:" << std::endl;
    rentedCarsList();

    std::string line;
    getline(std::cin, line);
    auto ret = rentedCars.find(line);
    if (ret != rentedCars.cend()) {
        rentedCars.erase(line);
        loggedInUser.historyRent(line, "returned");
        logOfActivities(line, "returned");
    } else {
        std::cout << "ERROR" << std::endl;
    }

    std::ofstream fileRented(loggedInUser.userName+ "_currentRent.txt");
    fileRented << "";
    fileRented.close();

    std::fstream fileRewrite(loggedInUser.userName+ "_currentRent.txt", std::ios::in | std::ios::out | std::ios::app);

    for (const auto &p: rentedCars) {
        fileRewrite << p.first << std::endl;
        fileRewrite << p.second << std::endl;
    }

    fileRewrite.close();

    auto it = carModelAndStatus.find(line);
    if (it != rentedCars.cend()) {
        it->second = "garage";
    } else {
        std::cout << "ERROR" << std::endl;
    }

    std::ofstream fileData("CarsData.txt");
    fileData << "";
    fileData.close();

    std::fstream fileRewriteData("CarsData.txt", std::ios::in | std::ios::out | std::ios::app);

    for (const auto &p: carModelAndStatus) {
        fileRewriteData << p.first << std::endl;
        fileRewriteData << p.second << std::endl;
    }

    fileRewriteData.close();
}

void rentedCarsList(){
    std::map<std::string, std::string> rentedCars;
    std::ifstream infileRentedCars(loggedInUser.userName+ "_currentRent.txt");
    std::string rentedCarModel;
    std::string rentedStatus;

    while (std::getline(infileRentedCars, rentedCarModel) && std::getline(infileRentedCars, rentedStatus)) {
        rentedCars.insert(std::pair<std::string, std::string>(rentedCarModel, rentedStatus));
    }
    infileRentedCars.close();

    int i = 1;

    for (const auto &p: rentedCars) {
        std::cout << i << " " << p.first << std::endl;
        i++;
    }
    std::cout << std::endl;
}

void showYourRentHistory(){
    std::ifstream infileRentedCars(loggedInUser.userName+ "_rentHistory.txt");

    std::string line;
    while (std::getline(infileRentedCars, line)) {
        std::cout << line << std::endl;
    }
    infileRentedCars.close();

}

void showLogs(){
    std::ifstream infileRentedCars("LogOfActivities.txt");

    std::string line;
    while (std::getline(infileRentedCars, line)) {
        std::cout << line << std::endl;
    }
    infileRentedCars.close();

}

void User::setUserName(std::string userName) {
    this->userName = userName;
}

std::string User::getUserName() {
    return this->userName;
}

void User::historyRent(std::string rent, std::string rentOrReturn) {
    std::fstream file(this->userName + "_rentHistory.txt", std::ios::in | std::ios::out | std::ios::app);
    file << rent << std::endl;
    file << rentOrReturn << std::endl;
    file.close();
}

void User::currentRent(std::string rent) {
    std::fstream file(this->userName + "_currentRent.txt", std::ios::in | std::ios::out | std::ios::app);
    file << rent << std::endl;
    file << "rented" << std::endl;
    file.close();
}

void logOfActivities(std::string car, std::string rentOrReturn){
    std::fstream file("LogOfActivities.txt", std::ios::in | std::ios::out | std::ios::app);
    file << loggedInUser.getUserName() << " " << rentOrReturn << " " << car << std::endl;
}
