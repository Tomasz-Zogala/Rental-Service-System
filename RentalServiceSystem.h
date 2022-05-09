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
bool lookingForUserName(std::string userNameToMatch);
bool isUserNameMatchWithPassword(std::string userNameToMatch, std::string userPasswordToMatch);
bool log_in();
bool sign_up();


#endif RENTALSERVICESYSTEM_RENTALSERVICESYSTEM_H
