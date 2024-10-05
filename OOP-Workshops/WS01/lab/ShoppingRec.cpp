/*Full Name  : Alejandra Vanessa Pereira Leon
Student ID#: 139273221
Email      : avpleon@myseneca.ca
Section    : NEE
*/
#include <iostream>
#include "Utils.h"
#include "File.h"
#include "ShoppingRec.h"
using namespace std;

const int MAX_QUANTITY_VALUE = 50;

ShoppingRec getShoppingRec() {
   ShoppingRec R = {};
   cout << "Item name: ";
   readCstr(R.m_title, MAX_TITLE_LENGTH);
   cout << "Quantity: ";
   R.m_quantity = readInt(1, MAX_QUANTITY_VALUE);
   return R;
}

void displayShoppingRec(const ShoppingRec* shp) {
   cout << "[" << (shp->m_bought ? 'X' : ' ') << "]" << shp->m_title << " qty:(" << shp->m_quantity << ")" << endl;
}
void toggleBoughtFlag(ShoppingRec* rec) {
   rec->m_bought = !rec->m_bought;

}
bool isShoppingRecEmpty(const ShoppingRec* shp) {
   return shp->m_title[0] == 0;
}