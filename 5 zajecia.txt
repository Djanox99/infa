#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROZMIAR 10

float sredniaTablicy(int *tablica, int rozmiar) {
    int suma = 0;
    for (int i = 0; i < rozmiar; i++) {
        suma += *(tablica + i);
    }
    return (float)suma / rozmiar;
}

int zapiszTablice(int tablica[]) {
    FILE *plik = fopen("C:\\aisr\\dane.txt", "w");
    if (plik == NULL) return 1;

    for (int i = 0; i < ROZMIAR; i++) {
        fprintf(plik, "%d\n", tablica[i]);
    }

    fclose(plik);
    return 0;
}

int znajdzMinimum(int *tablica) {
    int min = *tablica;
    for (int i = 1; i < ROZMIAR; i++) {
        if (*(tablica + i) < min) {
            min = *(tablica + i);
        }
    }
    return min;
}

void generujTablice(int *tablica) {
    srand(time(NULL));
    for (int i = 0; i < ROZMIAR; i++) {
        tablica[i] = rand() % 99 + 1;
    }
}

int znajdzMaksimum(int *tablica) {
    int max = *tablica;
    for (int i = 1; i < ROZMIAR; i++) {
        if (*(tablica + i) > max) {
            max = *(tablica + i);
        }
    }
    return max;
}

void wyswietlTablice(int *tablica) {
    for (int i = 0; i < ROZMIAR; i++) {
        printf("tablica[%d] = %d\n", i, tablica[i]);
    }
}

int wczytajTablice(int tablica[]) {
    FILE *plik = fopen("C:\\aisr\\dane.txt", "r");
    if (plik == NULL) return 1;

    for (int i = 0; i < ROZMIAR; i++) {
        fscanf(plik, "%d", &tablica[i]);
    }

    fclose(plik);
    return 0;
}

int main(void) {
    int opcja_menu = 0;
    int kodBledu = 0;
    int tablica[ROZMIAR] = {1, 2, 5, -2, 19, 5, 21, -32, 43, 1};

    do {
        printf("\n=== MENU ===\n");
        printf("1. Znajdź wartość najmniejszą\n");
        printf("2. Znajdź wartość największą\n");
        printf("3. Oblicz wartość średnią\n");
        printf("4. Wczytaj tablicę z pliku\n");
        printf("5. Wyświetl tablicę\n");
        printf("6. Generuj losowe wartości\n");
        printf("7. Zapisz tablicę do pliku\n");
        printf("8. (Brak: Mediana)\n");
        printf("9. Zakończ program\n");
        printf("Wybierz opcję: ");

        scanf("%d", &opcja_menu);

        switch (opcja_menu) {
            case 1:
                printf("Najmniejsza wartość: %d\n", znajdzMinimum(tablica));
                break;
            case 2:
                printf("Największa wartość: %d\n", znajdzMaksimum(tablica));
                break;
            case 3:
                printf("Średnia wartość: %.2f\n", sredniaTablicy(tablica, ROZMIAR));
                break;
            case 4:
                printf("Wczytywanie tablicy z pliku...\n");
                kodBledu = wczytajTablice(tablica);
                if (!kodBledu)
                    printf("Odczytano pomyślnie.\n");
                else
                    printf("Błąd odczytu!\n");
                break;
            case 5:
                wyswietlTablice(tablica