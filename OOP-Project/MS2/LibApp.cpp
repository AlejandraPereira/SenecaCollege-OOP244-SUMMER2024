/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
Date: 14/07/2024
*/
#include <iostream>
#include "LibApp.h"
#include "Menu.h"

namespace seneca {

    bool LibApp:: confirm(const char* message){
        Menu confirmMenu(message);
        confirmMenu 
            << "Yes";
        return confirmMenu.run() == 1;
    }

    void LibApp:: load(){
        std::cout << "Loading Data" << std::endl;
    }  
    void LibApp:: save(){
        std::cout << "Saving Data" << std::endl;
    } 
    void LibApp:: search(){
        std::cout << "Searching for publication" << std::endl;
    } 
    void LibApp:: returnPub(){
        search();
        std:: cout << "Returning publication" <<std::endl;
        std:: cout << "Publication returned" <<std::endl;
        m_changed = true;
    } 
    void LibApp:: newPublication(){
        std:: cout << "Adding new publication to library" <<std::endl;
        if (confirm("Add this publication to library?\n")) {
            m_changed = true;
            std::cout << "Publication added" << std::endl;
        }
    }
    void LibApp:: removePublication(){
        std:: cout << "Removing publication from library" << std::endl;
        search();
        if(confirm("Remove this publication from the library?\n")){
            m_changed = true;
            std:: cout << "Publication removed"<< std::endl;
        }
    }

    void LibApp:: checkOutPub(){
        search();
        if(confirm("Check out publication?\n")){
            m_changed = true;
            std:: cout << "Publication checked out"<< std::endl;
        }
    }

    LibApp::LibApp() {
        m_changed = false;
    
        // Populate main menu
        m_mainMenu << "Add New Publication"
                << "Remove Publication"
                << "Checkout publication from library"
                << "Return publication to library";

        // Populate exit menu
        m_exitMenu << "Save changes and exit"
                << "Cancel and go back to the main menu";

        load(); // Load data initially
    }


    void LibApp::run() {
        bool exitProgram = false;
        while (!exitProgram) {
            switch (m_mainMenu.run()) {
                case 1:
                    newPublication();
                    std::cout << std::endl;
                    break;
                case 2:
                    removePublication();
                    std::cout << std::endl;
                    break;
                case 3:
                    checkOutPub();
                    std::cout << std::endl;
                    break;
                case 4:
                    returnPub();
                    std::cout << std::endl;
                    break;
                case 0:
                    if (m_changed) { // If changes have been made
                        switch (m_exitMenu.run()) {
                            case 1:
                                save();
                                exitProgram = true;
                                break;
                            case 2:
                                // Do nothing, go back to the main menu
                                break;
                            case 0:
                                if (confirm("This will discard all the changes. Are you sure?\n")) {
                                    exitProgram = true;
                                }
                                break;
                        }
                    } else { // If no changes have been made
                        exitProgram = true;
                    }
                    std::cout << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
            }
        }
        std::cout << "-------------------------------------------\n"
                "Thanks for using Seneca Library Application" << std::endl;
    }

}
