/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/
#include <iostream>
#include <cstring>
#include "HtmlText.h"

namespace seneca {

    HtmlText::HtmlText(const char* filename, const char* title) : Text(filename) {
        if (title) {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        } else {
            m_title = nullptr;
        }
    }

    HtmlText::HtmlText(const HtmlText& other) : Text(other) { // Copy constructor
        if (other.m_title) {
            m_title = new char[strlen(other.m_title) + 1];
            strcpy(m_title, other.m_title);
        } else {
            m_title = nullptr;
        }
    }

    HtmlText& HtmlText::operator=(const HtmlText& other) {   // Copy assignment operator
        if (this != &other) {
            Text::operator=(other);

            delete[] m_title;

            if (other.m_title) {
                m_title = new char[strlen(other.m_title) + 1];
                strcpy(m_title, other.m_title);
            } else {
                m_title = nullptr;
            }
        }
        return *this;
    }

    HtmlText::~HtmlText() {
        delete[] m_title;
    }

    void HtmlText::write(std::ostream& os) const {
        bool MS = false;
        os << "<html><head><title>";
        if (m_title != nullptr) {
            os << m_title;
        } else {
            os << "No Title";
        }
        os << "</title></head>\n<body>\n";
        if (getFilename()) {
            os << "<h1>" << m_title << "</h1>\n";
        }

        for (int i = 0; getContent() && getContent()[i] != '\0'; i++) {
            char ch = getContent()[i];
            switch (ch) {
                case ' ':
                    if (MS) {
                        os << "&nbsp;";
                    } else {
                        MS = true;
                        os << ' ';
                    }
                    break;
                case '<':
                    os << "&lt;";
                    MS = false;
                    break;
                case '>':
                    os << "&gt;";
                    MS = false;
                    break;
                case '\n':
                    os << "<br />\n";
                    MS = false;
                    break;
                default:
                    MS = false;
                    os << ch;
                    break;
            }
        }
        os << "</body>\n</html>";
    }
}
