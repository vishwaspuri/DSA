#include <stdio.h>
#include <stdlib.h>


#define MAX 100000
#define MAX_NAME 256
#define EXPIRY_DATE_SIZE 8
#define BANKCODE_SIZE 5

typedef long long int CardNo;
typedef char ExpiryDate[EXPIRY_DATE_SIZE];
typedef char FirstName[MAX_NAME];
typedef char LastName[MAX_NAME];
typedef char BankCode[BANKCODE_SIZE];


typedef struct  credicard
{
    CardNo cno;
    ExpiryDate expr;
    FirstName fir;
    LastName las;
    BankCode bank;
}CreditCard;

typedef CreditCard CreditCards[MAX];


CreditCard ExtractCreditCardFromLine(char *line);
CreditCard *ExtractCreditCardInformationFromFile(char *fileLocation);
void PrintCreditCards(CreditCard cards[], int n);