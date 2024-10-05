/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/
#include <iostream>
#include <cstring>
#include "Bill.h"
using namespace std;
namespace seneca {


    void Bill::setEmpty (){
        m_title[0]= '\0'; 
        m_items = nullptr;
        m_noOfItems =0;
        m_itemsAdded=0;
       
    }

   bool Bill::isValid() const {
        if (m_title[0] != '\0' && m_items != nullptr) {
            for (int i = 0; i < m_noOfItems; ++i) {
                if (!m_items[i].isValid()) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
  
    double Bill:: totalTax()const{
        double priceTax =0.0;
        int i;
        for ( i = 0; i < m_noOfItems; i++)
        {
            priceTax += m_items[i].tax();
        }
        return priceTax;
    }
    
    double Bill:: totalPrice()const{
        double sum =0.0;
        for (int i = 0; i < m_noOfItems; i++)
        {
           sum += m_items[i].price();
        }
        
        return sum;
    }

  void Bill::Title() const {
    std::cout << "+--------------------------------------+" << std::endl;
    if (isValid()) {
        std::cout << "| ";
        std:: cout.width(36);
        std::cout.fill(' ');
        std:: cout << std::left << m_title;  
        std::cout << " |" << std::endl; 
    } else {
        std::cout << "| Invalid Bill                         |" << std::endl;
    }
    std::cout << "+----------------------+---------+-----+" << std::endl;
    std::cout << "| Item Name            | Price   + Tax |" << std::endl;
    std::cout << "+----------------------+---------+-----+" << std::endl;
}

    void Bill:: footer()const{
        std:: cout <<"+----------------------+---------+-----+"<< std::endl;
        if (isValid())
        {
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.width(10);
            cout.precision(2);
            std::cout << "|                Total Tax: " << std::right;
            cout.width(10);
            std::cout << totalTax() <<  " |" << std::endl;
            std::cout << "|              Total Price: " << std::right;
            cout.width(10);
            std:: cout << totalPrice() << " |" << std::endl;
            std::cout << "|          Total After Tax: " << std::right;
            cout.width(10);
            std::cout << totalTax() + totalPrice() << " |" << std::endl;
        } else {

        std::cout << "| Invalid Bill                         |" << std::endl;
    }

    std::cout << "+--------------------------------------+" << std::endl;
}
        
   
    void Bill:: init(const char* title, int noOfItems){
        if (title == NULL || noOfItems <= 0)
        {
            setEmpty();
        }else{
        m_noOfItems = noOfItems;
        m_itemsAdded =0;
        strncpy(m_title,title,36);
        m_title[35] = '\0';
        m_items = new Item[m_noOfItems];
        for ( int i = 0; i < m_noOfItems; i++)
            {
                m_items[i].setEmpty();
            }
    
        }
    }


    bool Bill:: add(const char* item_name, double price, bool taxed){
        if (m_itemsAdded < m_noOfItems){
            m_itemsAdded = m_itemsAdded;
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            return true;
        }
        
        return false;
    }
    
    void Bill:: display()const{
        Title();
        for ( int i = 0; i < m_noOfItems; i++){
           m_items[i].display();
        }
        
        footer();

    } 

    void Bill:: deallocate(){
        delete[] m_items;
        m_items = nullptr;
    }
}
   

   


