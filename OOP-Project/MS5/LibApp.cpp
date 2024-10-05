/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "LibApp.h"
#include "Menu.h"
#define SEARCH_ALL 1
#define SEARCH_CHECKOUT_OUT 2
#define SEARCH_AVAILABLE 3

namespace seneca {

    bool LibApp:: confirm(const char* message){

        Menu confirmMenu(message);
        confirmMenu
            << "Yes";
        return confirmMenu.run() == 1;
    }

    void LibApp::load() {
        std::cout << "Loading Data" << std::endl;
        std::ifstream infile(fileName);
        if (!infile) {
            std::cout << "Error opening file!" << std::endl;
            return;
        }

        char publicationMenuType{};
        while (infile >> publicationMenuType) {
            infile.ignore();
            if (publicationMenuType == 'P') {
                n_ppa[n_nolp] = new Publication;
            } else if (publicationMenuType == 'B') {
                n_ppa[n_nolp] = new Book;
            }
            if (n_ppa[n_nolp] != nullptr) {
                infile >> *n_ppa[n_nolp];
                n_llrn = n_ppa[n_nolp]->getRef();
                n_nolp++;
            }
        }
    }


    void LibApp:: save(){

        std::cout << "Saving Data" << std::endl;
        std::ofstream outfile(fileName);
        for (int i = 0; i < n_nolp; i++) {
            if (n_ppa[i] != nullptr && n_ppa[i]->getRef() != 0) {
                outfile << *n_ppa[i] << std::endl;
            }
        }
        outfile.close();
    }

    int LibApp::search(int mode) {
        char title[256];
        Menu typeMenu("Choose the type of publication:");
        typeMenu << "Book" << "Publication";
        int typeSelection = typeMenu.run();

        if (typeSelection == 0) {
            std::cout << "Aborted!" << std::endl;
            return -1;
        }

        std::cin.ignore();
        std::cout << "Publication Title: ";
        if (!std::cin.getline(title, 256)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Failed to read title. Please try again." << std::endl;
            return -1;
        }

        char selectedType = (typeSelection == 1) ? 'B' : 'P'; 
        PublicationSelector selector("Select one of the following found matches:");

        // Array to store matched publications
        const int MAX_MATCHES = 100;
        Publication* matchedPublications[MAX_MATCHES];
        int count = 0;

        // Filter publications based on the selected type and title
        for (int i = 0; i < n_nolp; ++i) {
            if (n_ppa[i] != nullptr && n_ppa[i]->getRef() != 0) {
                bool matchesType = n_ppa[i]->type() == selectedType;
                bool matchesTitle = std::strstr(static_cast<const char*>(*n_ppa[i]), title) != nullptr;
                bool matchesMode = (mode == SEARCH_ALL) ||
                                    (mode == SEARCH_CHECKOUT_OUT && n_ppa[i]->onLoan()) ||
                                    (mode == SEARCH_AVAILABLE && !n_ppa[i]->onLoan());

                if (matchesType && matchesTitle && matchesMode) {
                    if (count < MAX_MATCHES) {
                        matchedPublications[count++] = n_ppa[i];
                    }
                }
            }
        }

        // Sort the array of matched publications
        for (int i = 0; i < count - 1; ++i) {
            for (int j = i + 1; j < count; ++j) {
                bool swap = false;
                if (selectedType == 'B') { // For books
                    if (matchedPublications[i]->getRef() == 0 && matchedPublications[j]->getRef() != 0) {
                        swap = true;
                    } else if (matchedPublications[i]->getRef() != 0 && matchedPublications[j]->getRef() == 0) {
                        swap = false;
                    } else {
                        const char* title1 = matchedPublications[i]->operator const char*();
                        const char* title2 = matchedPublications[j]->operator const char*();
                        if (std::strcmp(title1, title2) > 0) {
                            swap = true;
                        }
                    }
                } else if (selectedType == 'P') { // For publications
                    const char* titleA = matchedPublications[i]->operator const char*();
                    const char* titleB = matchedPublications[j]->operator const char*();

                    if (std::strcmp(titleA, titleB) > 0) {
                        swap = true;
                    } else if (std::strcmp(titleA, titleB) == 0) {
                        // If titles are equal, sort by checkout date
                        Date dateA = matchedPublications[i]->checkoutDate();
                        Date dateB = matchedPublications[j]->checkoutDate();

                        if (dateA > dateB) {
                            swap = true;
                        } else if (dateA == dateB) {
                            // If dates are also equal, sort by reference from lowest to highest
                            int refA = matchedPublications[i]->getRef();
                            int refB = matchedPublications[j]->getRef();

                            if (refA > refB) {
                                swap = true;
                            }
                        }
                    }
                }

                if (swap) {
                    Publication* temp = matchedPublications[i];
                    matchedPublications[i] = matchedPublications[j];
                    matchedPublications[j] = temp;
                }
            }
        }

        // Add matched publications to the selector
        if (count == 0) {
            std::cout << "No matches found!" << std::endl;
            return -1;
        }

        for (int i = 0; i < count; ++i) {
            selector << matchedPublications[i];
        }

        // Run the publication selector
        int selectedRef = selector.run();
        if (selectedRef == 0) {
            std::cout << "Aborted!" << std::endl;
            return -1;
        } else if (selectedRef == -1) {
            std::cout << "Exiting...\n";
            return -1;
        } else {
            for (int i = 0; i < n_nolp; ++i) {
                if (n_ppa[i] != nullptr && n_ppa[i]->getRef() == selectedRef) {
                    std::cout << *n_ppa[i] << std::endl;
                    return selectedRef;
                }
            }
        }

        return -1;
    }


    void LibApp:: returnPub(){
            Date today;
            std:: cout << "Return publication to the library" <<std::endl;
            int libRef = search(SEARCH_CHECKOUT_OUT);
            Publication* pubToReturn = getPub(libRef);

            if(pubToReturn){

                if (confirm("Return Publication?")) {
                    int daysLate = today - pubToReturn->checkoutDate();
                    if (daysLate > 15) {
                        double penalty = (daysLate - 15) * 0.50;
                        std::cout << std::fixed << std::setprecision(2);
                        std::cout << "Please pay $" << penalty << " penalty for being " << (daysLate - 15) << " days late!" << std::endl;
                    }
                   
                    pubToReturn->set(0);
                    m_changed = true;
                    std::cout << "Publication returned" << std::endl;
                }
            }

    }

    void LibApp::newPublication() {
        if (n_nolp >= SENECA_LIBRARY_CAPACITY) {
            std::cout << "Library is at its maximum capacity!" << std::endl;
            return;
        }
        std::cout << "Adding new publication to the library" << std::endl;

        int publicationTypeSelection = publicationMenuType.run();
        
        Publication* newPub = nullptr;
        if (publicationTypeSelection == 1) {
            newPub = new Book();
        } else if (publicationTypeSelection == 2) {
            newPub = new Publication();
        } else {
            std::cout << "Aborted!" << std::endl;
            return;
        }

        std::cin >> *newPub;

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Aborted!" << std::endl;
            delete newPub;
            return;
        }

        if (!confirm("Add this publication to the library?")) {
            std::cout << "Aborted!" << std::endl;
            delete newPub;
            return;
        }

        if (newPub && newPub->getRef() != 0) {
            n_llrn++;
            newPub->setRef(n_llrn);
            n_ppa[n_nolp] = newPub;
            n_nolp++;
            m_changed = true;
            std::cout << "Publication added" << std::endl;
        } else {
            std::cout << "Failed to add publication!" << std::endl;
            delete newPub;
        }
    }

    void LibApp::removePublication() {
        std::cout << "Removing publication from the library" << std::endl;
        
        int libReference =  search(SEARCH_ALL);
        Publication* removePub = getPub(libReference);
        if(removePub){
            std::cout << *removePub << std::endl;
            if(confirm("Remove this publication from the library?")){
                removePub->setRef(0);
                m_changed = true;
                std::cout << "Publication removed" <<std::endl;
            }
        }

    }
    void LibApp::checkOutPub() {
        std::cout << "Checkout publication from the library" << std::endl;
        int libRef = search(SEARCH_AVAILABLE);
        Publication* pubToCheckout = getPub(libRef);

        if (pubToCheckout) {
            if (confirm("Check out publication?")) {
                int membershipNumber;
                bool validMembership = false;
                std::cout << "Enter Membership number: ";
                do {
                    std::cin >> membershipNumber;

                    if (std::cin.fail() || membershipNumber <= 0 || membershipNumber > 99999) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << "Invalid membership number, try again: ";
                    } else {
                        validMembership = true;
                    }
                } while (!validMembership);

                // Proceed with checking out the publication
                pubToCheckout->set(membershipNumber);
                pubToCheckout->resetDate();
                m_changed = true;
                std::cout << "Publication checked out" << std::endl;
            }
        }
    }

    LibApp::LibApp() {

        m_changed = false;
        m_mainMenu  << "Add New Publication"
                    << "Remove Publication"
                    << "Checkout publication from library"
                    << "Return publication to library";
        m_exitMenu  << "Save changes and exit"
                    << "Cancel and go back to the main menu";

        load(); // Load data initially
    }

    LibApp::LibApp(const char* filename) : m_changed(false), n_nolp(0) {
        m_mainMenu  << "Add New Publication"
                    << "Remove Publication"
                    << "Checkout publication from library"
                    << "Return publication to library";
        m_exitMenu  << "Save changes and exit"
                    << "Cancel and go back to the main menu";
        publicationMenuType << "Book"
                            << "Publication";
        if (filename) {
            strncpy(fileName, filename, sizeof(fileName) - 1);
            fileName[sizeof(fileName) - 1] = '\0';
        }
        load();
    }

    LibApp::~LibApp() {
        for (int i = 0; i < n_nolp; ++i) {
            delete n_ppa[i];
                n_ppa[i] = nullptr;
        }
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
                                if (confirm("This will discard all the changes are you sure?")) {
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

  Publication* LibApp::getPub(int libRef) {
    for (int i = 0; i < n_nolp; ++i) {
        if (n_ppa[i] != nullptr && n_ppa[i]->getRef() == libRef) {
            return n_ppa[i];
        }
    }
    return nullptr;
    }
}