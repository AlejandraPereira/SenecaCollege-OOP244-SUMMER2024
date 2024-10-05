/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
Date: 06/12/2024
*/

#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:

      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator ~() const;
      int getNumber() const { return m_number; }
      double getBalance() const { return m_balance; }
      Account& operator =(int number);
      Account& operator =( Account& account2);
      Account& operator +=( double number);
      Account& operator -=(double number);
      Account& operator <<(Account& account2);
      Account& operator >> (Account& account2);

      friend double operator+(const Account& left,const Account& rigth );
      friend double& operator+=(double& left, const Account& right);
   };

   double operator+(const Account& left, const Account& right);
   double& operator+=(double& left, const Account& right);

}
#endif // SENECA_ACCOUNT_H_
