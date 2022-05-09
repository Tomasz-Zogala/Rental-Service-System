#ifndef RENTALSERVICESYSTEM_RENTALSERVICESYSTEM_H
#define RENTALSERVICESYSTEM_RENTALSERVICESYSTEM_H
#include <list>

class User{
    std::string userName;
    std::string password;
    std::list<std::string> carRentalHistory;
public:
    User(std::string username, std::string password);
};

class Car{

};

void mainSide();
void lobby();
bool userRecognition();
bool checkUserData(std::string userNameToMatch);
void log_in();
void sign_up();


#endif RENTALSERVICESYSTEM_RENTALSERVICESYSTEM_H
