/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/

#include "Line.h"
#include <iostream>

namespace seneca {
    Line::Line() : LblShape(), m_length(0) {}

    Line::Line(const char* label, size_t length) : LblShape(label), m_length(length) {}

    void Line::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(1000, '\n');
    }

    void Line::draw(std::ostream& os) const {
        if (m_length > 0 && label() != nullptr) {
            os << label() << std::endl;
            for (size_t i = 0; i < m_length; ++i) {
                os << "=";
            }
           
        }
    }
}
