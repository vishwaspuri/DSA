#include "creditcard.h"



CreditCard ExtractCreditCardFromLine(char *line);

CreditCard *ExtractCreditCardInformationFromFile(char *fileName) {
    // Result pointer
    CreditCard * cards = malloc(10*sizeof(CreditCard));

    // Creating file pointer
    FILE *fp = fopen(fileName, "r");
    if(fp == NULL) exit(EXIT_FAILURE);

    size_t len = 0;
    ssize_t read;
    char * line = NULL;

    int i=0;
    while((read = getline(&line, &len, fp)) != -1) {
        CreditCard card = ExtractCreditCardFromLine(line);
        *(cards + i++) = card;
    }

    fclose(fp);
    if (line)   free(line);

    return cards;
}

CreditCard ExtractCreditCardFromLine(char *line) {
    CreditCard *card = malloc(sizeof(CreditCard));
    int month, year;
    sscanf(line, "\"%lld,%s,%d/%d,%s,%s\"", &card->cno, card->bank, &month, &year, card->fir, card->las);
    sprintf(card->expr, "%d/%d", month, year);
    return *card;
}

void printCard(CreditCard card) {
    printf(
        "Card Number: %lld\nBank Code: %s\nCard Expiry Date: %s\nClient First Name: %s\nClient Last Name: %s\n",
        card.cno, card.bank, card.expr, card.fir, card.las
    );
}


void PrintCreditCards(CreditCard *cards, int n) {
    printf("Credit Card Information:\n");
    for(int i=0; i<n; i++) {
        printf("-----------------\n");
        printCard(cards[i]);
    }
}