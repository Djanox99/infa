#include <stdio.h>

#define ROZMIAR 10

int znajdzMinMaks(int tablica[], int szukajMaks) {
    int wynik = tablica[0];
    for (int i = 1; i < ROZMIAR; ++i) {
        if ((szukajMaks && tablica[i] > wynik) || (!szukajMaks && tablica[i] < wynik)) {
            wynik = tablica[i];
        }
    }
    return wynik;
}

void wyswietlMenu() {
    printf("1. Wprowadź wartości\n2. Wyświetl tablicę\n3. Minimalna wartość\n4. Maksymalna wartość\n5. Średnia\n0. WYJŚCIE\nWybierz: ");
}

double obliczSrednia(int tablica[]) {
    int suma = 0;
    for (int i = 0; i < ROZMIAR; ++i)
        suma += tablica[i];
    return (double)suma / ROZMIAR;
}

void wyswietlTablice(int tablica[]) {
    for (int i = 0; i < ROZMIAR; ++i)
        printf("tablica[%d] = %d\n", i, tablica[i]);
}

int main() {
    int tablica[ROZMIAR] = {1, 2, 3, -4, 50, 6, 7, 8, 9, 10};
    int opcja;

    printf("PROSTA TABLICA\n\n");

    do {
        wyswietlMenu();
        scanf("%d", &opcja);

        switch (opcja) {
            case 1:
                printf("Wprowadź %d wartości:\n", ROZMIAR);
                for (int i = 0; i < ROZMIAR; ++i)
                    scanf("%d", &tablica[i]);
                break;
            case 2:
                wyswietlTablice(tablica);
                break;
            case 3:
                printf("Minimum: %d\n", znajdzMinMaks(tablica, 0));
                break;
            case 4:
                printf("Maksimum: %d\n", znajdzMinMaks(tablica, 1));
                break;
            case 5:
                printf("Średnia: %.2f\n", obliczSrednia(tablica));
                break;
            case 0:
                printf("Zamykanie programu...\n");
                break;
            default:
                printf("Wybierz poprawną opcję...\n\n");
        }
    } while (opcja);

    printf("KONIEC PROGRAMU!\n");
    return 0;
}
