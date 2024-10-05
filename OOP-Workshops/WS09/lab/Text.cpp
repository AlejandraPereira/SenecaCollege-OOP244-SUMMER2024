/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/
#include <fstream>
#include <iostream>
#include  <cstring>
#include "Text.h"
using namespace std;
namespace seneca {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   const char& Text:: operator[](int index)const{
      return m_content[index];
   }

   Text::Text(const char* filename): m_filename(nullptr),m_content(nullptr){
      if(filename != nullptr){
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename,filename);
            read();
        }
   }

   Text::Text(const Text& other){   // Copy constructor
     if (other.m_filename) {
            m_filename = new char[strlen(other.m_filename) + 1];
            strcpy(m_filename, other.m_filename);
         } else {
            m_filename = nullptr;
         }

        if (other.m_content) {
            m_content = new char[strlen(other.m_content) + 1];
            strcpy(m_content, other.m_content);
         } else {
            m_content = nullptr;
         }
   }

   Text& Text:: operator=(const Text& other){     // Copy assignment operator
         if (this != &other) {
            delete[] m_filename;
            delete[] m_content;

            if (other.m_filename) {
                m_filename = new char[strlen(other.m_filename) + 1];
                strcpy(m_filename, other.m_filename);
            } else {
                m_filename = nullptr;
            }

            if (other.m_content) {
                m_content = new char[strlen(other.m_content) + 1];
                strcpy(m_content, other.m_content);
            } else {
                m_content = nullptr;
            }
         }
        return *this;
   }
      
   Text::~Text(){    // Destructor
      delete[] m_filename;
      delete[] m_content;
   }

   void Text::read(){
      int fileLength = getFileLength();
      if (fileLength <= 0) {
        
        delete[] m_content;
        m_content = nullptr;
        return;
      }
      delete[] m_content;
      m_content = new char[fileLength + 1];
      std:: ifstream file(m_filename);
      if (file){
         file.read(m_content,fileLength);
         if(file){
           m_content[fileLength]= '\0';
         }
      }
   }
      
   void Text::write(std::ostream& os)const{
      
      if(m_content != nullptr){
         os << m_content;
      }
   }
   
   std::ostream& operator<<(std::ostream& os, const Text& text){
      text.write(os);
      return os;
   }
}

