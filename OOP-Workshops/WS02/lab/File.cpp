/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"
#include "Employee.h"

namespace seneca {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    void closeFile() {
        if (fptr) fclose(fptr);
    }

    //TODO: read functions go here    
bool read(char* name) {
    if (fscanf(fptr, " %[^\n]\n", name) == 1) {
        return true;
    } else {
        return false;
    }
}

bool read(int& employeeNumber) {
    if (fscanf(fptr, "%d,", &employeeNumber) == 1) {
        return true; 
    } else {
        return false;
    }
}

bool read(double& salary) {
    if (fscanf(fptr, "%lf,", &salary) == 1) {
        return true;
    } else {
        return false;
    }
}

   
}