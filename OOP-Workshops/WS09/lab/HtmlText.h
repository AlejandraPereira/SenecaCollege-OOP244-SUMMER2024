/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/
#ifndef SENECA_HTMLTEXT_H__
#define SENECA_HTMLTEXT_H__
#include "Text.h"
namespace seneca {
   class HtmlText :  public Text {
      char* m_title;
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);
      HtmlText( const HtmlText& other);
      HtmlText& operator=(const HtmlText& other);
     ~HtmlText();
      virtual void write(std::ostream& os)const override;

   };
}
#endif // SENECA_HTMLTEXT_H__
