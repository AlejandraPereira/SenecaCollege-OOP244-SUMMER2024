/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/
#ifndef SENECA_BILL_H_
#define SENECA_BILL_H_
#include "Item.h"
namespace seneca {
   class Bill {
      char m_title[37];
      Item* m_items;
      int m_noOfItems; // size of m_items
      int m_itemsAdded;// how much of m_items have filled
      double totalTax()const;
      double totalPrice()const;
      void Title()const;
      void footer()const;
      void setEmpty();
      bool isValid()const;
   public:
      void init(const char* title, int noOfItems);
      bool add(const char* item_name, double price, bool taxed);
      void display()const; // con un bucle for 
      void deallocate();
   };
}
#endif // !SENECA_TRANSCRIPT_H
