/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/
#ifndef SENECA_TEXT_H__
#define SENECA_TEXT_H__
namespace seneca {
   class Text {
      char* m_filename ;
      char* m_content ;
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
      const char* getFilename() const { return m_filename; }
      const char* getContent() const { return m_content; }
   public:
      Text(const char* filename=nullptr);
      Text(const Text& other);  // Copy constructor
      Text& operator=(const Text& other);  // Copy assignment operator
      ~Text();  // Destructor

      void read();
      virtual void write(std::ostream& os)const;
   };
   std::ostream& operator<<(std::ostream& os, const Text& text);
}
#endif // SENECA_TEXT_H__

