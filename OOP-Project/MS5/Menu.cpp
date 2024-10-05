/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstring>
#include "Menu.h"

namespace seneca {
    MenuItem::MenuItem() : m_info(nullptr) {}

    MenuItem::MenuItem(const char* content) {
        if (content != nullptr) {
            m_info = new char[strlen(content) + 1];
            strcpy(m_info, content);
        } else {
            m_info = nullptr;
        }
    }

    MenuItem::~MenuItem() {
        delete[] m_info;
    }

    MenuItem::operator bool() const {
        return m_info != nullptr && *m_info != '\0';
    }

    MenuItem::operator const char*() const {
        return m_info ? m_info : "";
    }   

    void MenuItem::display(std::ostream& os) const {
        if (m_info != nullptr) {
            os << m_info;
        }
    }

    Menu::Menu() : m_title(nullptr), m_numItems(0) {
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
            m_items[i] = nullptr;
        }
    }

    Menu::Menu(const char* title) : m_title(nullptr), m_numItems(0) {
        if (title != nullptr) {
            m_title = new MenuItem(title);

        }
        
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
            m_items[i] = nullptr;
            
        }
    }

    Menu::~Menu() {
        delete m_title;
        for (unsigned int i = 0; i < m_numItems; ++i) {
            delete m_items[i];
        }
    }

    void Menu::displayTitle(std::ostream& os) const {
        if (m_title && *m_title) {
            m_title->display(os);   
        }
    }

    void Menu::displayEntireMenu(std::ostream& os) const {
    
        if (m_title && *m_title) {
            displayTitle(os);
            os << std::endl; 
            if (m_numItems > 0) {
               // os << ":" << std::endl; 
            } else {
                os << std::endl; 
            }
        }
        
        if (m_numItems == 0) {
            os << "empty" << std::endl;
        } else {
            
            for (unsigned int i = 0; i < m_numItems; ++i) {
                os << std::right << std::setw(2) << (i + 1) << "- ";
                m_items[i]->display(os);
                os << std::endl;
            }
        }

        os << " 0- Exit" << std::endl;
        os << "> ";
    }

    unsigned int Menu::run() const {
        unsigned int selection = 0;
        bool valid = false;
        displayEntireMenu(std::cout);
        do {
            std::cin >> selection;
            if (std::cin.fail() || selection < 0 || selection > m_numItems) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid Selection, try again: ";
            } else {
                valid = true;
            }
        } while (!valid);
    
        return selection;
    }

    unsigned int Menu::operator~() const {
        return run();
    }

    Menu& Menu::operator<<(const char* menuItemContent) {
        if (m_numItems < MAX_MENU_ITEMS) { 
            m_items[m_numItems++] = new MenuItem(menuItemContent);
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const Menu& m) {
        m.displayTitle(os);
        return os;
    }

    const char* Menu::operator[](unsigned int index) const {
        if (index < m_numItems && m_items[index] && *m_items[index]) {
            return m_items[index]->m_info;
        }
        return nullptr;
    }

    Menu::operator int() const {
        return m_numItems;
    }

    
    Menu::operator unsigned int() const {
        return m_numItems;
    }

    Menu::operator bool() const {
        return m_numItems > 0;
    }
}
