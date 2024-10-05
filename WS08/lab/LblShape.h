/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/

#ifndef SENECA_LblSHAPE_H
#define SENECA_LblSHAPE_H
#include "Shape.h"

namespace seneca{
    class LblShape: public Shape{
    private: 
       char* m_label{};
    protected: 
       const char* label() const;
    public:
        LblShape();
        LblShape(const char* label);
        virtual ~LblShape();
        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;
        void getSpecs(std::istream& is);

    };
    
}
#endif //SENECA_LblSHAPE_H