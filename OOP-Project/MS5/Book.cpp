/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/
#include "Book.h"
#include "iostream"
#include <iomanip>
#include <cstring>
namespace seneca{

    Book:: Book(): author_name(nullptr){
    }

    Book:: Book(const Book& book) : Publication(book), author_name(nullptr){
        *this =book;
    }
    
    Book& Book:: operator=(const Book& book){
        if (this != &book) {
           
            delete[] author_name;
            author_name = nullptr;
            if (book.author_name != nullptr) {
                author_name = new char[strlen(book.author_name) + 1];
                strcpy(author_name, book.author_name);
                Publication::operator=(book);            
            }
          
        }
        return *this;
    }  

    Book:: ~Book(){
        delete[] author_name;
        author_name = nullptr;
    }

    char Book:: type() const{
        return 'B';
    }
    
    std::ostream &Book::write(std::ostream &os) const {
        if (!(*this) || !author_name){
            return os;
        }

        Publication::write(os);
        
        if (conIO(os)) {
            os << ' '   ;
            int authorLength = strlen(author_name);
            if (authorLength > SENECA_AUTHOR_WIDTH) {
                    os.write(author_name, SENECA_AUTHOR_WIDTH);
            } else {
            os << std::setw(SENECA_AUTHOR_WIDTH) << std::left << author_name; 
        }

        os << " |";
    } else {
        os << '\t' << author_name;
    }
        os << std::setfill(' ');
        return os;
    }


    std::istream &Book::read(std::istream &is) {
        char authorName[255]{};
        Publication::read(is);

        if(author_name != nullptr){
            delete[] author_name;
            author_name = nullptr;
        }

        if(Publication::conIO(is)){
            is.ignore(1,'\n');
            std::cout << "Author: ";
            is.get(authorName, 256,'\n');
        }else{
            is.ignore(1,'\t');
            is.get(authorName, 255,'\n');
        }

        if(!is.fail()){
            author_name = new char[strlen(authorName) + 1];
            strcpy(author_name,authorName);
        }
        return is;
    }

    void Book::set(int member_id){
        Publication:: set(member_id);
        Publication:: resetDate();
    }

     Book::operator bool() const {
        
        return (author_name != nullptr && author_name[0] != '\0' && Publication::operator bool());
    }

     std::ostream &Book::operator<<( std::ostream &os) {
        return write(os);
    }
     std::istream &Book::operator>>( std::istream &is) {
        return read(is);
    }

    std::ostream &operator<<(std::ostream &os, const Book& other) {
        return other.write(os);
    }
    std::istream &operator>>(std::istream &is, Book& other) {
        return other.read(is);
    }

}
