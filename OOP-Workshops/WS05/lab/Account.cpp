/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
Date: 06/12/2024
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
   Account::operator bool() const {
      if (m_number >= 10000 && m_number <= 99999 && m_balance >= 0) {
            return true;
      } else {
           return false;
      }
   }

   Account:: operator int() const{
      return m_number;
   }

   Account:: operator double() const{
      return m_balance;
   }

   bool Account:: operator ~() const{
      if (m_number == 0){
         return true;
      } else{
         return false;
      }
   }

     Account& Account::operator=(int newNumb) {
        if (~(*this) && newNumb >= 10000 && newNumb <= 99999) {
            m_number = newNumb;
        }
        return *this;
    }

    Account& Account:: operator =( Account& account2){
      if (~*this && account2){
         m_number = account2.m_number;
         m_balance = account2.m_balance;
         account2.m_balance = 0;
         account2.m_number  =0;
      }
      return *this;
    }

    Account& Account:: operator +=(double number){
      if(*this && number >0){
         m_balance += number;
      }
      return *this;
    }

    Account& Account:: operator -=(double number){
       if(*this && number > 0  && m_balance >= number){
         m_balance -= number;
      }
      return *this;
    }

    Account& Account:: operator << (Account& account2){
     if( this != &account2 && *this && account2){
      m_balance += account2.m_balance;
      account2.m_balance = 0.0;
     }
     return *this;
    }
    Account& Account:: operator >> (Account& account2){
      if (this != &account2 && *this &&account2)
      {
         account2.m_balance += m_balance;
         m_balance = 0.0;
      }
      return *this;
    }

   double operator+(const Account& left,const Account& right){
       if (left && right){

       return  left.getBalance() + right.getBalance();

      } else {

         return 0.0;
      }
   }

   double& operator+=(double& left, const Account& right){
      if(right){
         left += right.getBalance();
      }
      return left;
   }

   

};

  