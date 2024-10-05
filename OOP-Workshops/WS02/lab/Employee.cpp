/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/

#include <iostream>
#include <cstring>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace seneca {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee& emp) {
    bool ok = false;
    char name[128];
    int empNo;
    double salary;

    if (!read(empNo)){
        return ok;
    }
    if (!read(salary)){
        return ok;
    }
    if (!read(name)){
        return ok;
    }

    emp.m_name = new char[strlen(name) + 1]; 
    strcpy(emp.m_name, name);
    emp.m_empNo = empNo; 
    emp.m_salary = salary;
    
    return true;
}


   // TODO: Finish the implementation of the 0 arg load function 
bool load() {
        if (openFile(DATAFILE)) {
            noOfEmployees = noOfRecords();
            if (noOfEmployees == 0) {
                std::cout << "Error: No records found in the file." << std::endl;
                closeFile();
                return false;
            }
            employees = new Employee[noOfEmployees];
            for (int i = 0; i < noOfEmployees; ++i) {
                if (!load(employees[i])) {
                    std::cout << "Error: incorrect number of records read; the data is possibly corrupted." << std::endl;
                    delete[] employees;
                    employees = nullptr;
                    noOfEmployees = 0;
                    closeFile();
                    return false;
                }
            }
            closeFile();
            return true;
        } else {
            std::cout << "Could not open data file: " << DATAFILE << std::endl;
            return false;
        }
    }


   // TODO: Implementation for the display functions go here
  void display(const Employee& emp) {
        std::cout << emp.m_empNo << ": " << emp.m_name << ", " << emp.m_salary << std::endl;
    }

void display() {
        std::cout << "Employee Salary report, sorted by employee number" << std::endl;
        std::cout << "no- Empno, Name, Salary" << std::endl;
        std::cout << "------------------------------------------------" << std::endl;
        sort();
        for (int i = 0; i < noOfEmployees; ++i) {
            std::cout << i + 1 << "- ";
            display(employees[i]);
        }
    }


   // TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory() {
        for (int i = 0; i < noOfEmployees; ++i) {
            delete[] employees[i].m_name;
        }
        delete[] employees;
        employees = nullptr;
        noOfEmployees = 0;
    }
}
