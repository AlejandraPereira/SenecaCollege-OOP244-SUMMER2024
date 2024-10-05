/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/

#ifndef SENECA_MENU_H__
#define SENECA_MENU_H__
#include <iostream>
#include <cstring>

namespace seneca {

    const unsigned int MAX_MENU_ITEMS = 20;

    class MenuItem {
        char* m_info;
    private:
        MenuItem();
        MenuItem(const char*);
        ~MenuItem();
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        operator bool() const;
        operator const char*() const;
        void display(std::ostream& os) const;
        friend class Menu;
    };

    class Menu {
        MenuItem* m_title;
        MenuItem* m_items[MAX_MENU_ITEMS];
        unsigned int m_numItems;

    public:
        Menu();
        Menu(const char* title);
        ~Menu();
        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;

        void displayTitle(std::ostream& os) const;
        void displayEntireMenu(std::ostream& os) const;
        unsigned int run() const;

        Menu& operator<<(const char* menuItemContent);
        unsigned int operator~() const;
        operator bool() const;
        operator int() const;
        operator unsigned int() const;
        const char* operator[](unsigned int index) const;
        
    };

   std::ostream& operator<<(std::ostream& os, const Menu& m);

}

#endif
