/* Calculate the equivalent Outside-IR35 rate from a given Inside-IR35 rate */
/* Based on https://www.contractorcalculator.co.uk/ir35taxessummary.aspx */
/* Assuming making full pension contributions, a burden of 21% */
/* 20220113 - TRCM */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int tax_burden_percent = 21;

    unsigned long size = 4;
    int bytes_read;
    char *rate;

    char *ptr;
    float result;

    printf("Inside IR35 day rate? : ");
    rate = (char *) malloc (size);
    bytes_read = getdelim (&rate, &size, '\n', stdin);
    rate[strcspn(rate, "\n")] = 0;
    result = strtol(rate, &ptr, 10);
    result = (result/(100-tax_burden_percent)*100);

    if (bytes_read == -1) {
        puts("error!");
    } else {
        printf("Is equal to £%0.0f/day outside IR35 (at a %d%% tax burden)\n"
                , result
                , tax_burden_percent);
    }
}
