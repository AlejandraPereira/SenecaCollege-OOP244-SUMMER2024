/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
Date: 06/07/2024
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TextFile.h"

using namespace std;

namespace seneca {

    Line::Line() : m_value(nullptr) {}

    Line::operator const char* () const {
        return m_value;
    }

    Line& Line::operator=(const char* lineValue) {
        if (m_value != lineValue) {
            delete[] m_value;
            m_value = new char[strlen(lineValue) + 1];
            strcpy(m_value, lineValue);
        }
        return *this;
    }

    Line::~Line() {
        delete[] m_value;
    }

    void TextFile::setEmpty() {
        delete[] m_textLines;
        delete[] m_filename;
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {
        delete[] m_filename;
        if (isCopy) {
            m_filename = new char[strlen(fname) + 3];
            strcpy(m_filename, "C_");
            strcat(m_filename, fname);
        } else {
            m_filename = new char[strlen(fname) + 1];
            strcpy(m_filename, fname);
        }
    }

    void TextFile::setNoOfLines() {
        ifstream file(m_filename);
        m_noOfLines = 0;
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                ++m_noOfLines;
            }
            file.close();
        }
        if (m_noOfLines == 0) {
            setEmpty();
        }
    }

    void TextFile::loadText() {
        delete[] m_textLines;
        m_textLines = nullptr;
        if (m_filename) {
            m_textLines = new Line[m_noOfLines];
            ifstream file(m_filename);
            if (file.is_open()) {
                string line;
                int count = 0;
                while (getline(file, line)) {
                    m_textLines[count] = line.c_str();
                    ++count;
                }
                file.close();
            }
        }
    }

    void TextFile::saveAs(const char* fileName) const {
        ofstream file(fileName);
        if (file.is_open()) {
            for (unsigned i = 0; i < m_noOfLines; ++i) {
                file << m_textLines[i].m_value << endl;
            }
            file.close();
        }
    }

    TextFile::TextFile(unsigned pageSize) {
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
        m_pageSize = pageSize;
    }

    TextFile::TextFile(const char* filename, unsigned pageSize) {
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
        m_pageSize = pageSize;
        
        if (filename && filename[0]) {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile& other) {
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
        m_pageSize = other.m_pageSize;

        if (other.m_filename) {
            setFilename(other.m_filename, true);
            other.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }   
    }

    TextFile& TextFile::operator=(const TextFile& text) {
        if (this != &text) {
            delete[] m_textLines;
            m_textLines = nullptr;
            text.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
        return *this;
    }

    TextFile::~TextFile() {
        delete[] m_textLines;
        delete[] m_filename;
    }

    std::ostream& TextFile::view(std::ostream& ostr) const {
        if (m_filename) {
            ostr << m_filename << "\n==========\n";
            for (unsigned i = 0; i < m_noOfLines; ++i) {
                ostr << m_textLines[i].m_value << endl;
                if ((i + 1) % m_pageSize == 0) {
                    ostr << "Hit ENTER to continue..."<<endl;
                    ostr.flush(); 
                }
            }
        }
        return ostr;
    }

    std::istream& TextFile::getFile(std::istream& istr) {
        char filename[250];
        istr >> filename;
        setFilename(filename);
        setNoOfLines();
        loadText();
        return istr;
    }

    TextFile::operator bool() const {
        return m_filename != nullptr;
    }

    unsigned TextFile::lines() const {
        return m_noOfLines;
    }

    const char* TextFile::name() const {
        return m_filename;
    }

    const char* TextFile::operator[](unsigned index) const {
        return m_textLines ? m_textLines[index % m_noOfLines].m_value : nullptr;
    }

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
        return text.view(ostr);
    }

    std::istream& operator>>(std::istream& istr, TextFile& text) {
        return text.getFile(istr);
    }
}
