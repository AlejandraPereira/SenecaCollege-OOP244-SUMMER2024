/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/

#include <iostream>
#include "LblShape.h"
#include <cstring> 
namespace seneca{
   
    const char* LblShape:: label() const{
        return m_label;
    }

    LblShape::LblShape() : m_label(nullptr) {}

    LblShape::LblShape(const char* label){
        if(label){
            m_label=new char[strlen(label) + 1];
            strcpy(m_label,label);
        }
    }

    LblShape::~LblShape(){
        delete [] m_label;
    }

    void LblShape:: getSpecs(std::istream& is){
        std:: string temp;
        std:: getline(is,temp,',');
        delete [] m_label;
        m_label=new char[temp.length() + 1];
        strcpy(m_label,temp.c_str());
    }
  
}