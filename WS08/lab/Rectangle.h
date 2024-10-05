/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/

#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H
#include "LblShape.h"

namespace seneca{
    class Rectangle : public LblShape{
    private:
       size_t m_width;
       size_t m_height;
    public: 
    Rectangle();
    Rectangle(const char* label,size_t width, size_t height);
    void getSpecs(std::istream& is);
    void draw(std::ostream& os) const;

    };
    
}
#endif //SENECA_RECTANGLE_H