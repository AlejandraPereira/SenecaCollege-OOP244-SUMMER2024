/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/
#ifndef BOOK_H
#define BOOK_H
#include "Publication.h"
namespace seneca {
    class Book : public Publication {
        char* author_name;

    public:
        Book();
        Book(const Book& book);
        Book& operator=(const Book& book);
        ~Book();
        char type() const override;
        std::ostream& write(std::ostream& os) const override;
        std::istream& read(std::istream& istr) override;
        void set(int member_id) override;
        operator bool() const override;

        std::ostream &operator<<(std::ostream &os) ;
        std::istream &operator>>(std::istream &is) ;
    };
    std::ostream &operator<<(std::ostream &os, const Book& other);
    std::istream &operator>>(std::istream &is, Book& other);
}

#endif // BOOK_H
