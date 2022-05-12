#include <iostream>
#include <stdlib.h>
#include <map>
#include <fstream>
#include <ctime>

#include "RentalServiceSystem.h"

time_t now = time(0);
char *dt = ctime(&now);
User loggedInUser;

void mainSide() {
    if (userRecognition()) {
        lobby();
    } else {
        mainSide();
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
    std::cout << "1: Cars models and statues"  << std::endl;
    std::cout << "2: Rent a car" << std::endl;
    std::cout << "3: Return a car" << std::endl;
    std::cout << "4: Current rent" << std::endl;
    std::cout << "5: History rent" << std::endl;
    std::cout << "6: Logs" << std::endl;
    std::cout << "7: Exit" << std::endl;
    int activity;
    std::cin >> activity;
    std::string clean;
    getline(std::cin, clean);
    switch (activity) {
        case 1: {
            std::cout << "Activity number: " << activity << " - CARS MODELS AND STATUSES" << std::endl;
            printCarModelsAndTheirStatuses();
            lobby();
        }
        case 2: {
            std::cout << "Activity number: " << activity << " - RENT A CAR" << std::endl;
            rentCar();
            lobby();
        }
        case 3: {
            std::cout << "Activity number: " << activity << " - RETURN A CAR" << std::endl;
            returnCar();
            lobby();
        }
        case 4: {
            std::cout << "Activity number: " << activity << " - CURRENT RENT" << std::endl;
            printCurrentRent();
            lobby();
        }
        case 5: {
            std::cout << "Activity number: " << activity << " - HISTORY RENT" << std::endl;
            printHistoryRent();
            lobby();
        }
        case 6: {
            std::cout << "Activity number: " << activity << " - LOGS" << std::endl;
            printLogs();
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
            return false;
        }
    } else {
        return false;
    }

}

bool sign_up() {
    std::cout << "Enter your user name: " << std::endl;
    std::string userName;
    std::cin >> userName;
    if (!(lookingForUserName(userName))) {
        std::cout << "Name is ready to use" << std::endl;
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
            //std::cout << "The car is ready to rent." << std::endl;
            return 1;
        }
        if (ret->second == "rented") {
            //std::cout << "The car is rented right now." << std::endl;
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
//TODO "type exit if you dont want to rent a car"
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
        logs(line, "rented");

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

//TODO if file is empty print "You dont have any car to return"
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
    std::ifstream infileRentedCars(loggedInUser.userName + "_currentRent.txt");
    std::string rentedCarModel;
    std::string rentedStatus;

    while (std::getline(infileRentedCars, rentedCarModel) && std::getline(infileRentedCars, rentedStatus)) {
        rentedCars.insert(std::pair<std::string, std::string>(rentedCarModel, rentedStatus));
    }
    infileRentedCars.close();

    std::cout << "This is your rented car list, type car model that you want to return:" << std::endl;
    printCurrentRent();

    std::string line;
    getline(std::cin, line);
    auto ret = rentedCars.find(line);
    if (ret != rentedCars.cend()) {
        rentedCars.erase(line);
        loggedInUser.historyRent(line, "returned");
        logs(line, "returned");
    } else {
        std::cout << "ERROR" << std::endl;
    }

    std::ofstream fileRented(loggedInUser.userName + "_currentRent.txt");
    fileRented << "";
    fileRented.close();

    std::fstream fileRewrite(loggedInUser.userName + "_currentRent.txt", std::ios::in | std::ios::out | std::ios::app);

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

void printWithoutStatus(std::string fileName) {
    std::map<std::string, std::string> carModelAndStatus;
    std::ifstream file(fileName);
    std::string carModel;
    std::string carStatus;

    while (std::getline(file, carModel) && std::getline(file, carStatus)) {
        carModelAndStatus.insert(std::pair<std::string, std::string>(carModel, carStatus));
    }
    file.close();

    int i = 1;

    for (const auto &p: carModelAndStatus) {
        std::cout << i << " " << p.first << std::endl;
        i++;
    }
    std::cout << std::endl;
}

void printCurrentRent() {
    printWithoutStatus(loggedInUser.userName + "_currentRent.txt");
}

//TODO print every second line
void printHistoryRent() {
    printWithoutStatus(loggedInUser.userName + "_rentHistory.txt");
}

void logs(std::string car, std::string rentOrReturn) {
    std::fstream file("LogOfActivities.txt", std::ios::in | std::ios::out | std::ios::app);
    file << loggedInUser.getUserName() << " " << rentOrReturn << " " << car << " on " << dt;
}

void printLogs() {
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

void User::currentRent(std::string rent) {
    std::fstream file(this->userName + "_currentRent.txt", std::ios::in | std::ios::out | std::ios::app);
    file << rent << std::endl;
    file << "rented" << std::endl;
    file.close();
}

void User::historyRent(std::string car, std::string rentOrReturn) {
    std::fstream file(this->userName + "_rentHistory.txt", std::ios::in | std::ios::out | std::ios::app);
    file << car << " " << rentOrReturn << " on " << dt;
    file.close();
}