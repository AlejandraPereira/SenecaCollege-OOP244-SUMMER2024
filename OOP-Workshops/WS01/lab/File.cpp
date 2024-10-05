/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/

#include<iostream>
using namespace std;
#include "ShoppingList.h"
#include "ShoppingRec.h"
#include "File.h"
//const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";

FILE* sfptr = nullptr;

bool openFileForRead() {
   sfptr = fopen("shoppinglist.csv", "r");
   return sfptr != NULL;
}

bool openFileForOverwrite() {
   sfptr = fopen("shoppinglist.csv", "w");
   return sfptr != NULL;
}

void closeFile() {
   if (sfptr) fclose(sfptr);
}

bool freadShoppingRec(ShoppingRec* rec) {
   int flag = 0;
   bool success = fscanf(sfptr, "%[^,],%d,%d\n",
      rec->m_title, &rec->m_quantity, &flag) == 3;
   rec->m_bought = !!flag;
   return success;
}

void fwriteShoppintRec(const ShoppingRec* rec) {
   fprintf(sfptr, "%s,%d,%d\n", rec->m_title, rec->m_quantity, rec->m_bought);
}
