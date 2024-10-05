/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/

#ifndef PUBLICATION_H
#define PUBLICATION_H
#define MAX_TITLE_LEN 255
#define MAX_SHELF_LEN 4

#include <iostream>
#include <ctime>
#include "Date.h"
#include "Lib.h"
#include "Streamable.h"

//using namespace seneca;
namespace seneca {
    class Publication : public Streamable {
        char* m_title{};
        char m_shelfId[MAX_SHELF_LEN + 1]{};
        int m_membership{};
        int m_libRef = -1;
        Date m_date;
    public:
        Publication();

        Publication(const Publication&);
        Publication& operator=(const Publication&);
        ~Publication() override;

        // Modifiers
        virtual void set(int member_id);
        void setRef(int value);
        void resetDate();

        // Queries
        virtual char type() const;
        bool onLoan() const;
        Date checkoutDate() const;
        bool operator==(const char* title) const;
        operator const char* () const;
        int getRef() const;

        // Implement Streamable
        bool conIO(std::ios& io) const override;
        std::ostream& write(std::ostream&) const override;
        std::istream& read(std::istream&) override;
        operator bool() const override;

        // Streamable operator overloads
        friend std::ostream& operator<<(std::ostream& os, const Publication& publication);
        friend std::istream& operator>>(std::istream& is, Publication& publication);
    };
}
#endif // PUBLICATION_H
