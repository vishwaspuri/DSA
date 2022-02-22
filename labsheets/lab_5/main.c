#include "creditcard.h"

int main(){
   CreditCard  *cards = ExtractCreditCardInformationFromFile("10");
   PrintCreditCards(cards, 10);
   return 0; 
}


