/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/

#include <iostream>
#include <cstring>
#include "Item.h"
using namespace std;
namespace seneca {

    const double TAX_RATE = 0.13;

    void Item::setName(const char* name){
        if(name != nullptr){
                strncpy(m_itemName,name,20);
                m_itemName[20] = '\0';

        }
    }

    void Item::setEmpty (){
        m_itemName[0]= '\0'; 
        m_price = 0.0;
       
    }

    void Item::set(const char* name, double price, bool taxed){
        if (name != nullptr && price >=0){
            setName(name);
            m_price =price;
            m_taxed = taxed;
        } else{
            setEmpty();
        }
    }
    
   void Item::display() const {
    if (isValid()) {
        std::cout << "| ";
        std::cout.width(20);
        std::cout.fill('.');
        std::cout << std::left << m_itemName;  
        std::cout.fill(' '); 
        std::cout << " | ";
        
        std::cout.width(7);
        std::cout.precision(2);
        std::cout << std::fixed << std::right << m_price;
        
        std::cout << " | ";
        std::cout.width(3);
        if (m_taxed) {
            std::cout << "Yes";
        } else {
            std::cout << "No ";
        }
        std::cout << " |" << std::endl;
    } else {
        std::cout << "| ";
        std::cout.width(23);
        std::cout.fill('x');
        std::cout << " | ";

        std::cout.width(7);
        std::cout.fill('x');
        std::cout << std::right << "xxxxxxx";
        std::cout << " | ";

        std::cout.width(3);
        std::cout.fill('x');
        std::cout << std::right << "xxx";
        std::cout << " |" << std::endl;
    }
}


    

    bool Item:: isValid()const{
        return m_price > 0.0 && m_itemName[0] != '\0';
    }

    double Item:: price()const{
        return m_price;
    }

    double Item:: tax()const{
        if (m_taxed){
            return m_price * TAX_RATE;
        }else{
            return 0.0;
        }
    }
}

