/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/

#ifndef SENECA_LINE_H
#define SENECA_LINE_H
#include "LblShape.h"
namespace seneca{
    class Line : public LblShape{
    private:
       size_t m_length ;
    public: 
        Line();
        Line(const char* label,size_t length);
        void getSpecs(std::istream& is);
        void draw(std::ostream& os)const;

    };
    
}
#endif //SENECA_LINE_H