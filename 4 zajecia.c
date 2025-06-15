#include <stdio.h>

#define ROZMIAR 10

void wyswietlMenu(int tablica[], int *rozmiar) {
    printf("MENU:\n");
    printf("1. Wprowadź wartości do tablicy\n");
    printf("2. Wyświetl zawartość tablicy\n");
    printf("3. Znajdź wartość minimalną\n");
    printf("4. Znajdź wartość maksymalną\n");
    printf("5. Oblicz wartość średnią\n");
    printf("0. WYJŚCIE\n");
}

void wypiszTabliceWskaznikiem(int *tablica, int rozmiar) {
    printf("Zawartość tablicy (przez wskaźnik):\n");
    for (int i = 0; i < rozmiar; i++) {
        printf("*(" "%p" " + %d) = %d\n", tablica, i, *(tablica + i));
    }
    printf("\n");
}

void wypiszTabliceIndeksowo(int tablica[], int rozmiar) {
    printf("Zawartość tablicy (indeksowo):\n");
    for (int i = 0; i < rozmiar; i++) {
        printf("tablica[%d] = %d\n", i, tablica[i]);
    }
    printf("\n");
}

int main() {
    int liczby[ROZMIAR];
    int aktualnyRozmiar = 0;

    wyswietlMenu(liczby, &aktualnyRozmiar);

    return 0;
}