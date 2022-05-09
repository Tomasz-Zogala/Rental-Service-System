#ifndef RENTALSERVICESYSTEM_RENTALSERVICESYSTEM_H
#define RENTALSERVICESYSTEM_RENTALSERVICESYSTEM_H
#include <list>

class Customer{
    std::string name;
    std::string password;
    std::list<std::string> carRentalHistory;
public:
    Customer();
};

class Car{

};

void lobby();
bool customerRecognition();

#endif RENTALSERVICESYSTEM_RENTALSERVICESYSTEM_H
