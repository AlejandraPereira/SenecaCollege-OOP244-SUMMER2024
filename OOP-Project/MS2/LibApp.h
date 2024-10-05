/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
Date: 14/07/2024
*/

#ifndef SENECA_LIBAPP_H
#define SENECA_LIBAPP_H
#include "Menu.h"
namespace seneca {
   class LibApp{
   private: 
      bool m_changed;
      Menu m_mainMenu{"Seneca Library Application\n"};
      Menu m_exitMenu{"Changes have been made to the data, what would you like to do?\n"};
      bool confirm(const char* message);
      void load();  // prints: "Loading Data"<NEWLINE>
      void save();  // prints: "Saving Data"<NEWLINE>
      void search();  // prints: "Searching for publication"<NEWLINE>
      void returnPub();  /*  Calls the search() method.
                             prints "Returning publication"<NEWLINE>
                             prints "Publication returned"<NEWLINE>
                             sets m_changed to true;
                         */
      void newPublication();
      void removePublication();
      void checkOutPub();
   public: 
      LibApp();
      void run();
   };
}
#endif // !SENECA_LIBAPP_H



