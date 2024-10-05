/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
Date: 11/07/2024
*/
#ifndef SENECA_TRUCK_H__
#define SENECA_TRUCK_H__
#include <iostream>
#include "MotorVehicle.h"
namespace seneca {

    class Truck : public MotorVehicle {
        double capacity;
        double currentCargo;

    public:
        Truck(const char* licensePlate, int yearBuilt, double capacity, const char* address);
        bool addCargo(double cargo);
        bool unloadCargo();
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& is);
    };

    std::istream& operator>>(std::istream& is, Truck& t);
    std::ostream& operator<<(std::ostream& os, const Truck& truck);

}

#endif // SENECA_TRUCK_H
