/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/

#ifndef SENECA_LIBAPP_H
#define SENECA_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
#include "PublicationSelector.h"
#include "Book.h"
namespace seneca {
   class LibApp{
   private: 
      bool m_changed;
      Menu m_mainMenu{"Seneca Library Application"};
      Menu m_exitMenu{"Changes have been made to the data, what would you like to do?"};
      bool confirm(const char* message);
      void load();  // prints: "Loading Data"<NEWLINE>
      void save();  // prints: "Saving Data"<NEWLINE>
      int search(int mode);  // prints: "Searching for publication"<NEWLINE>
      void returnPub();  /*  Calls the search() method.
                             prints "Returning publication"<NEWLINE>
                             prints "Publication returned"<NEWLINE>
                             sets m_changed to true;
                         */
      void newPublication();
      void removePublication();
      void checkOutPub();

      //ms5
      char fileName[256];
      Publication* n_ppa[SENECA_LIBRARY_CAPACITY];
      int n_nolp{};
      int n_llrn{};
      Menu publicationMenuType={"Choose the type of publication:"};
      Publication* getPub(int libRef);

   public: 
      LibApp();
      void run();
      LibApp(const char* filename);
      ~LibApp();
      
   };
}
#endif // !SENECA_LIBAPP_H



