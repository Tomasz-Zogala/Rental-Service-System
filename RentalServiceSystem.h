#ifndef RENTALSERVICESYSTEM_RENTALSERVICESYSTEM_H
#define RENTALSERVICESYSTEM_RENTALSERVICESYSTEM_H

#include <list>

/**
 * @brief
 * Class which shows information about current loggedIn user
 */

class User {
public:
/**
 * @brief
 * String which hold userName
 */

    std::string userName;

/**
 * @param userName user name
 * @brief
 * Function which set user name
 */

    void setUserName(std::string userName);

/**
 * @brief
 * Function which get user name
 */

    std::string getUserName();

/**
 * @param car car model
 * @param rentOrReturn hold string with information that car is in "garage" or "rented"
 * @brief
 * Function which save to file history rent information
 */

    void historyRent(std::string car, std::string rentOrReturn);

/**
 * @param car car model
 * @brief
 * Function which save to file current rent information
 */

    void currentRent(std::string car);
};

/**
 * @brief
 * Function that is a main side, uses lobby and user recognition
 */

void mainSide();

/**
 * @brief
 * Function that is a main side, uses lobby and user recognition
 */

void lobby();

/**
 * @brief
 * Function which checks user information
 */

bool userRecognition();

/**
 * @param userNameToMatch user name which is it in file "UserData.txt"
 * @brief
 * Function which looking for user name from file "UserData.txt", checks is it in data
 */

bool lookingForUserName(std::string userNameToMatch);

/**
 * @param userNameToMatch user name which is it in file "UserData.txt"
 * @param userPasswordToMatch user password is it in file "UserData.txt"
 * @brief
 * Function which looking for correct password for user
 */

bool isUserNameMatchWithPassword(std::string userNameToMatch, std::string userPasswordToMatch);

/**
 * @brief
 * Function which looking for input data and compare it to data from file
 */

bool log_in();

/**
 * @brief
 * Function which looking for input user name, checks is it not already use, two times checks password correctness and
 * save data to file "UserData.txt"
 */

bool sign_up();

/**
 * @param carModel car model
 * @param carStatus car status (is it in garage or rented)
 * @brief
 * Function which add car to file "CarsData.txt"
 */

void addCarToData(std::string carModel, std::string carStatus);

/**
 * @brief
 * Function which prints car's models and their statuses
 */

void printCarModelsAndTheirStatuses();

/**
 * @param carModelToMatch car model whose status we are looking for
 * @brief
 * Function which looking for car and status of it from a file "CarsData.txt"
 */

int findCarAndItStatus(std::string carModelToMatch);

/**
 * @brief
 * Function which set main data base of cars in system, use addCarToData function some times
 */

void garage();

/**
 * @brief
 * Function that allows the logged in user to rent a car that is in "garage". Change rented car status in "CarsData.txt"
 */

void rentCar();

/**
 * @brief
 * Function that prints the current list of rented cars of the logged in user
 */

void printCurrentRent();

/**
 * @brief
 * Function that prints the current list of rented cars of the logged in user at activity of return car
 * prints activity "Back" at end to give the user the option to withdraw from the operation
 */

void printCurrentRentForReturn();

/**
 * @brief
 * Function that allows the logged in user to return a car rented car. Change returned car status in "CarsData.txt"
 */

void returnCar();

/**
 * @brief
 * Function that prints all users names in the system from file "UserData.txt"
 */

void printUsers();

/**
 * @param car car model
 * @param rentOrReturn hold string with information that car is in "garage" or "rented"
 * @brief
 * Function that saves all information about the rental and return of the cars to all users in the system to file "Logs.txt"
 */

void logs(std::string car, std::string rentOrReturn);

/**
 * @brief
 * Function that prints the history list of rented cars of the logged in user
 */

void printHistoryRent();

/**
 * @brief
 * Function that prints all information about the rental and return of the cars to all users in the system from file "Logs.txt"
 */

void printLogs();

/**
 * @param pFile file which function checks is it empty
 * @brief
 * Function that checks if a given file is empty
 */

bool isEmpty(std::ifstream &pFile);

#endif RENTALSERVICESYSTEM_RENTALSERVICESYSTEM_H