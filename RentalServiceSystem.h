#ifndef RENTALSERVICESYSTEM_RENTALSERVICESYSTEM_H
#define RENTALSERVICESYSTEM_RENTALSERVICESYSTEM_H
#include <list>

class User{
    std::string userName;
    std::string password;
    void rentHistory();
    void currentRent();
    User(std::string userName, std::string password);
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


#endif RENTALSERVICESYSTEM_RENTALSERVICESYSTEM_H
