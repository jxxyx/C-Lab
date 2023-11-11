#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Def the typedef struct for a linked list called grades
typedef struct intl_money_value {
    int money;
    char currency[4];
} INTL_MONEY_VALUE;

typedef INTL_MONEY_VALUE *INTL_MONEY_VALUE_PTR;

int main() {
    INTL_MONEY_VALUE money1 = {100, "USD"};
    INTL_MONEY_VALUE money2 = {300, "SGD"};

    // Declare variables of INTL_MONEY_VALUE_PTR
    INTL_MONEY_VALUE_PTR money_ptr1 = &money1;
    INTL_MONEY_VALUE_PTR money_ptr2 = &money2;

    printf("Amount and Currency: %d %s\n", money1.money, money1.currency);
    printf("Amount and Currency: %d %s\n", money2.money, money2.currency);

    printf("Pointer Money 1: %d %s\n", money_ptr1->money, money_ptr1->currency);
    printf("Pointer Money 2: %d %s\n", money_ptr2->money, money_ptr2->currency);

    return 0;
}