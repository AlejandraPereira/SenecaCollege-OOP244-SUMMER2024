/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
Date: 11/07/2024
*/
#ifndef SENECA_MOTORVEHICLE_H__
#define SENECA_MOTORVEHICLE_H__
#include <iostream>
namespace seneca {

    class MotorVehicle {
        char licensePlate[9];
        char address[64];
        int yearBuilt;
    public:
        MotorVehicle(const char* plate, int year);
        void moveTo(const char* otherAddress);
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& is);
    };
    std::istream& operator>>(std::istream& is, MotorVehicle& mvh);
    std::ostream& operator<<(std::ostream& os, const MotorVehicle& mvh);

}

#endif //SENECA_MOTORVEHICLE_H