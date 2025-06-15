#include <stdio.h>
#include <stdlib.h>

int main(int ileArg, char const *argumenty[]) {
    int liczbaPierwsza, liczbaDruga, wynik;
    float wynikDzielenia;

    if (ileArg < 4) {
        printf("Zbyt mało argumentów! Użycie: ./program liczba1 operator liczba2\n");
        return 1;
    }

    liczbaPierwsza = atoi(argumenty[1]);
    liczbaDruga = atoi(argumenty[3]);

    printf("Liczba argumentów: %d\n", ileArg);
    for (int i = 0; i < ileArg; i++) {
        printf("Argument #%d\t->\t%s\n", i, argumenty[i]);
    }

    wynik = liczbaPierwsza * liczbaDruga;
    printf("Mnożenie: %d * %d = %d\n", liczbaPierwsza, liczbaDruga, wynik);

    wynik = liczbaPierwsza + liczbaDruga;
    printf("Dodawanie: %d + %d = %d\n", liczbaPierwsza, liczbaDruga, wynik);

    if (liczbaDruga != 0) {
        wynikDzielenia = (float)liczbaPierwsza / liczbaDruga;
        printf("Dzielenie: %d / %d = %.2f\n", liczbaPierwsza, liczbaDruga, wynikDzielenia);
    } else {
        printf("Błąd: nie można dzielić przez zero!\n");
    }

    wynik = liczbaPierwsza - liczbaDruga;
    printf("Odejmowanie: %d - %d = %d\n", liczbaPierwsza, liczbaDruga, wynik);

    return 0;
}
