/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
Date: 11/07/2024
*/
#include <iostream>
#include "MotorVehicle.h"
#include "Truck.h"
namespace seneca {

    Truck::Truck(const char* licensePlate, int yearBuilt, double capacity, const char* address)
        : MotorVehicle(licensePlate, yearBuilt), capacity(capacity), currentCargo(0.0) {
        moveTo(address);
    }

    bool Truck::addCargo(double cargo) {
    bool cargoAdded = false;
    if (cargo > 0 && currentCargo < capacity) {
        if (currentCargo + cargo <= capacity) {
            currentCargo += cargo;
        } else {
            currentCargo = capacity;
        }
        cargoAdded = true;
    }
    return cargoAdded;
}

    bool Truck::unloadCargo() {
        if (currentCargo > 0) {
            currentCargo = 0;
            return true;
        }
        return false;
    }

    std::ostream& Truck::write(std::ostream& os) const {
        MotorVehicle::write(os);
        os << " | " << currentCargo << "/" << capacity;
        return os;
    }

    std::istream& Truck::read(std::istream& is) {
        MotorVehicle::read(is);
        std::cout << "Capacity: ";
        is >> capacity;
        std::cout << "Cargo: ";
        is >> currentCargo;
        return is;
    }

    std::istream& operator>>(std::istream& is, Truck& t) {
        t.read(is);
        return is;
    }

    std::ostream& operator<<(std::ostream& os, const Truck& truck) {
        truck.write(os);
        return os;
    }

}
