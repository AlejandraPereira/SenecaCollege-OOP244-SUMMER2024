/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
Date: 11/07/2024
*/
#include <iostream>
#include <cstring>
#include <iomanip>
#include "MotorVehicle.h"

namespace seneca {

    MotorVehicle::MotorVehicle(const char* plate, int year) {
        strcpy(licensePlate, plate);
        strcpy(address, "Factory");
        yearBuilt = year;
    }

    void MotorVehicle::moveTo(const char* otherAddress) {
        if (strcmp(address, otherAddress) != 0) {
            std::cout << "|" << std::setw(8) << std::right << licensePlate << "|"
                      << " |"<<std::setw(20) << std::right << address << " ---> " << std::setw(20)
                      << std::left << otherAddress << "|" << std::endl;
            strcpy(address, otherAddress);
        }
    }

    std::ostream& MotorVehicle::write(std::ostream& os) const {
        os << "| " << yearBuilt << " | " << licensePlate << " | " << address;
        return os;
    }

    std::istream& MotorVehicle::read(std::istream& is) {
        std::cout << "Built year: ";
        std::cin >> yearBuilt;
        is.ignore(100, '\n');
        std::cout << "License plate: ";
        is.getline(licensePlate, 9);
        std::cout << "Current location: ";
        is.getline(address, 64);
        return is;
    }

    std::istream& operator>>(std::istream& is, MotorVehicle& mvh) {
        mvh.read(is);
        return is;
    }

    std::ostream& operator<<(std::ostream& os, const MotorVehicle& mvh) {
        mvh.write(os);
        return os;
    }
}
