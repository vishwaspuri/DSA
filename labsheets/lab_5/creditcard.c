#include "creditcard.h"



CreditCard ExtractCreditCardFromLine(char *line);

CreditCard *ExtractCreditCardInformationFromFile(char *fileName) {
    // Result pointer
    int size=5;
    CreditCard * cards = malloc(sizeof(CreditCard)*size);

    // Creating file pointer
    FILE *fp = fopen(fileName, "r");
    if(fp == NULL) exit(EXIT_FAILURE);

    size_t len = 0;
    ssize_t read;
    char * line = NULL;

    int i=0;
    while((read = getline(&line, &len, fp)) != -1) {
        CreditCard card = ExtractCreditCardFromLine(line);
        if(i==size) {
            size = size*2;
            cards = realloc(cards, sizeof(CreditCard)*size);
        }
        cards[i++] = card;
    }

    fclose(fp);
    if (line)   free(line);

    return cards;
}

CreditCard ExtractCreditCardFromLine(char *line) {
    CreditCard card;
    sscanf(line, "\"%lld,%[^,],%[^,],%[^,],%[^\"]\"\n", &card.cno, card.bank, card.expr, card.fir, card.las);
    return card;
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