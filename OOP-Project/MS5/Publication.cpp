/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/
#include <cstring>
#include <iomanip>
#include "Publication.h"

namespace seneca {

    Publication::Publication() : m_title(nullptr), m_shelfId{ "" }, m_membership(0), m_libRef(-1), m_date() {}

    Publication::Publication(const Publication& other) 
        : m_title(nullptr) {
        *this = other;
    }
    Publication& Publication::operator=(const Publication& other) {
        if (this != &other) {
            if (m_title != nullptr) {
                delete[] m_title;
                m_title = nullptr;
            }

            if (other.m_title != nullptr && other.m_title[0] != '\0') {
                m_title = new char[strlen(other.m_title) + 1];
                strcpy(m_title, other.m_title);
            }
            strcpy(m_shelfId, other.m_shelfId);
            m_membership = other.m_membership;
            m_libRef = other.m_libRef;
            m_date = other.m_date;
        }
        return *this;
    }

     Publication::~Publication(){
        
        delete[] m_title;
       
    }

    void Publication::set(int member_id) {
        if ((member_id >= 10000 && member_id <= 99999) || member_id == 0) {
            m_membership = member_id;
        }
    }


    void Publication::setRef(int value) {
        m_libRef = value;
    }

    void Publication::resetDate() {
        m_date = Date();
    }

    char Publication::type() const {
        return 'P';
    }

    bool Publication::onLoan() const {
        return (m_membership != 0);
    }

    Date Publication::checkoutDate() const {
        return m_date;
    }

     bool Publication::operator==(const char *title) const {
        return strstr(m_title, title) != nullptr;
    }

    Publication::operator const char *() const {
        return m_title;
    }

    int Publication::getRef() const {
        return m_libRef;
    }

    bool Publication::conIO(std::ios &io) const {
        return (&std::cin == &io) || (&std::cout == &io);
    }

    std::ostream& Publication::write(std::ostream& os) const {
    if (*this && m_date) {
        if (conIO(os)) {
            os << "| " << std::setw(SENECA_SHELF_ID_LEN)
               << m_shelfId
               << " | ";

            if (strlen(m_title) > SENECA_TITLE_WIDTH) {
                os.write(m_title, SENECA_TITLE_WIDTH);
            } else {
                os << std::setw(SENECA_TITLE_WIDTH) << std::left << std::setfill('.');
                os << m_title;
            }
            os << std::right << std::setfill(' ');

            os << " | ";
            onLoan() ? os << m_membership : os << " N/A ";
            os << " | "
               << m_date
               << " |";
        } else {
            os << type() << '\t'
               << m_libRef << '\t'
               << m_shelfId << '\t'
               << m_title << '\t'
               << m_membership << '\t'
               << m_date;
        }
    }
    return os;
}


    std::istream& Publication::read(std::istream& istr) {
        // Reset attributes
        delete[] m_title;
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        m_date = Date();

        char titlePub[256]{};
        char shelfPub[SENECA_SHELF_ID_LEN + 1]{};
        int membershipPub = 0;
        int libRefPub = -1;
        Date datePub;

        if (conIO(istr)) {
            std::cout << "Shelf No: ";
            istr >> shelfPub;
            if (strlen(shelfPub) != SENECA_SHELF_ID_LEN) {
                istr.setstate(std::ios::failbit);
            } else {
                istr.ignore();
            }
            std::cout << "Title: ";
            if (!istr.fail()) {
                istr.getline(titlePub, 1000, '\n');
            }
            std::cout << "Date: ";
            if (!istr.fail()) {
                istr >> datePub;
                if (!datePub) {
                    istr.setstate(std::ios::failbit);
                }
            }
        } else {
            istr >> libRefPub;
            istr.ignore();
            istr.getline(shelfPub, SENECA_SHELF_ID_LEN + 1, '\t');
            istr.getline(titlePub, 256, '\t');
            istr >> membershipPub;
            istr.ignore();
            istr >> datePub;
            if (!datePub)
                istr.setstate(std::ios::failbit);
        }

        if (!istr.fail()) {
            if (titlePub[0] != '\0') {
                delete[] m_title;
                m_title = nullptr;
                m_title = new char[strlen(titlePub) + 1];
                strcpy(m_title, titlePub);
            }
            if (shelfPub[0] != '\0') {
                strcpy(m_shelfId, shelfPub);
            }
            m_membership = membershipPub;
            m_libRef = libRefPub;
            m_date = datePub;
        }
        return istr;
    }

    Publication::operator bool() const {
        return m_title != nullptr && m_shelfId[0] != '\0';
    }

    std::ostream& operator<<(std::ostream& os, const Publication& publication) {
        return publication.write(os);
    }

    std::istream& operator>>(std::istream& is, Publication& publication) {
        return publication.read(is);
    }
}
