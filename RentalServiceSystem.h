#ifndef RENTALSERVICESYSTEM_RENTALSERVICESYSTEM_H
#define RENTALSERVICESYSTEM_RENTALSERVICESYSTEM_H

#include <list>

class User {
public:
    std::string userName;

    void setUserName(std::string userName);

    std::string getUserName();

    void historyRent(std::string rent, std::string rentOrReturn);

    void currentRent(std::string rent);
};

void mainSide();

void lobby();

bool userRecognition();

bool lookingForUserName(std::string userNameToMatch);

bool isUserNameMatchWithPassword(std::string userNameToMatch, std::string userPasswordToMatch);

bool log_in();

bool sign_up();

void addCarToData(std::string carModel, std::string carStatus);

void printCarModelsAndTheirStatuses();

int findCarAndItStatus(std::string carModelToMatch);

void garage();

void rentCar();

void rentedCarsList();

void returnCar();

void logOfActivities(std::string car, std::string rentOrReturn);

void showYourRentHistory();

void showLogs();


#endif RENTALSERVICESYSTEM_RENTALSERVICESYSTEM_H
