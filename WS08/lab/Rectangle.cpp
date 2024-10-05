/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/

#include <cstring>
#include "Rectangle.h"
namespace seneca{

   Rectangle::Rectangle() : LblShape(), m_width(0), m_height(0) {}

    Rectangle::Rectangle(const char* label, size_t width, size_t height)
        : LblShape(label), m_width(width), m_height(height) {
        if (height < 3 || width < strlen(label) + 2) {
            m_width = 0;
            m_height = 0;
        }
    }
    void Rectangle:: getSpecs(std::istream &is){
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore(1,',');
        is >> m_height;
        is.ignore(1000,'\n');
    }
    void Rectangle:: draw(std::ostream &os) const{
        if(m_width > 0 && m_height > 0){
           // First line
            os << "+";
            for (size_t i = 1; i < m_width - 1; ++i) {
                os << "-";
            }
            os << "+" << std::endl;

        // Second line
            os << "|" << label();
            size_t spaces = m_width - strlen(label()) - 2;
            for (size_t i = 0; i < spaces; ++i) {
                os << " ";
            }
            os << "|" << std::endl;
                   
         
         // Middle lines
            for (size_t i = 2; i < m_height - 1; ++i) {
                os << "|";
                for (size_t j = 1; j < m_width - 1; ++j) {
                    os << " ";
                }
                os << "|" << std::endl;
            }
        // Last line 
            os << "+";
            for (size_t i = 1; i < m_width - 1; ++i) {
                os << "-";
            }
            os << "+";
        }
    }
    
}