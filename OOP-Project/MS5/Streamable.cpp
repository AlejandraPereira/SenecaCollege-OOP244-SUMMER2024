/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/

#include "Streamable.h"

namespace seneca {
    std::ostream& operator<<(std::ostream& os, const Streamable& stream) {
        if (stream.conIO(os)) {
            stream.write(os);
        }
        return os;
    }

    std::istream& operator>>(std::istream& is, Streamable& stream) {
        if (stream.conIO(is)) {
            stream.read(is);
        }
        return is;
    }

    Streamable::~Streamable() { }
}
