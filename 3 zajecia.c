#include <stdio.h>

void zamien(int *wsk1, int *wsk2) {
    printf("\t*wsk1 = %d\n", *wsk1);
    printf("\t*wsk2 = %d\n", *wsk2);
    int tymczasowy = *wsk1;
    *wsk1 = *wsk2;
    *wsk2 = tymczasowy;
    printf("\t*wsk1 = %d\n", *wsk1);
    printf("\t*wsk2 = %d\n", *wsk2);
}

void wypiszWartosci(const int *wsk1, const int *wsk2) {
    printf("*wsk1 = %d\n", *wsk1);
    printf("*wsk2 = %d\n", *wsk2);
}

int main() {
    int liczba1 = 2;
    int liczba2 = 5;

    printf("\tliczba1 = %d\n", liczba1);
    printf("\tliczba2 = %d\n", liczba2);

    zamien(&liczba1, &liczba2);

    printf("\tliczba1 = %d\n", liczba1);
    printf("\tliczba2 = %d\n", liczba2);

    return 0;
}