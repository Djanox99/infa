#include <stdio.h>                /// Dołączenie biblioteki standardowego wejścia/wyjścia
#include <stdlib.h>              /// Dołączenie biblioteki dla funkcji systemowych (np. exit, malloc)
#include <string.h>              /// Dołączenie biblioteki do obsługi łańcuchów znaków

#define MAX_CARS 20              /// Definicja maksymalnej liczby samochodów
#define FILENAME "cars.txt"      /// Nazwa pliku do zapisu i odczytu danych

/// Definicja struktury reprezentującej samochód
typedef struct {
    char marka[50];              /// Marka samochodu
    int rok;                     /// Rok produkcji
    char nr_rejestracyjny[20];  /// Numer rejestracyjny
    int przebieg;               /// Przebieg w kilometrach
} Samochod;

/// Funkcja do dodawania nowego samochodu
void dodajSamochod(Samochod auta[], int *liczba_aut) {
    if (*liczba_aut >= MAX_CARS) {                     /// Sprawdzenie, czy osiągnięto maksymalną liczbę samochodów
        printf("Osiągnięto maksymalną liczbę samochodów.\n");
        return;
    }

    printf("Dodawanie nowego samochodu:\n");
    printf("Marka: ");
    scanf(" %[^\n]", auta[*liczba_aut].marka);         /// Wczytanie marki (z uwzględnieniem spacji)
    printf("Rok produkcji: ");
    scanf("%d", &auta[*liczba_aut].rok);               /// Wczytanie roku produkcji
    printf("Numer rejestracyjny: ");
    scanf(" %[^\n]", auta[*liczba_aut].nr_rejestracyjny); /// Wczytanie numeru rejestracyjnego
    printf("Przebieg (w km): ");
    scanf("%d", &auta[*liczba_aut].przebieg);          /// Wczytanie przebiegu

    (*liczba_aut)++;                                   /// Zwiększenie liczby zapisanych samochodów
    printf("Samochód dodany.\n");
}

/// Funkcja do wyświetlania listy samochodów
void wyswietlSamochody(Samochod auta[], int liczba_aut) {
    if (liczba_aut == 0) {                             /// Jeśli nie ma samochodów, wypisz komunikat
        printf("Brak zapisanych samochodów.\n");
        return;
    }

    printf("\nLista samochodów:\n");
    for (int i = 0; i < liczba_aut; i++) {             /// Iteracja po tablicy samochodów
        printf("%d. %s | %d | %s | %dkm\n", i + 1,     /// Wyświetlenie danych każdego samochodu
               auta[i].marka, auta[i].rok, auta[i].nr_rejestracyjny, auta[i].przebieg);
    }
}

/// Funkcja zapisująca dane samochodów do pliku
void zapiszDoPliku(Samochod auta[], int liczba_aut) {
    FILE *plik = fopen(FILENAME, "w");                 /// Otwarcie pliku do zapisu
    if (plik == NULL) {                                /// Sprawdzenie błędu otwierania pliku
        printf("Błąd przy zapisie do pliku.\n");
        return;
    }

    for (int i = 0; i < liczba_aut; i++) {             /// Iteracja i zapis samochodów do pliku
        fprintf(plik, "%s;%d;%s;%d\n", auta[i].marka, auta[i].rok,
                auta[i].nr_rejestracyjny, auta[i].przebieg);
    }

    fclose(plik);                                      /// Zamknięcie pliku
    printf("Dane zapisane do pliku '%s'.\n", FILENAME);
}

/// Funkcja wczytująca dane samochodów z pliku
void wczytajZPliku(Samochod auta[], int *liczba_aut) {
    FILE *plik = fopen(FILENAME, "r");                 /// Otwarcie pliku do odczytu
    if (plik == NULL) {                                /// Sprawdzenie błędu otwierania pliku
        printf("Brak pliku lub błąd przy otwieraniu.\n");
        return;
    }

    *liczba_aut = 0;                                   /// Reset liczby wczytanych samochodów
    while (*liczba_aut < MAX_CARS &&
           fscanf(plik, " %49[^;];%d;%19[^;];%d\n",    /// Wczytanie danych jednego samochodu z pliku
                  auta[*liczba_aut].marka,
                  &auta[*liczba_aut].rok,
                  auta[*liczba_aut].nr_rejestracyjny,
                  &auta[*liczba_aut].przebieg) == 4) {
        (*liczba_aut)++;                               /// Inkrementacja liczby wczytanych rekordów
    }

    fclose(plik);                                      /// Zamknięcie pliku
    printf("Wczytano %d samochodów z pliku '%s'.\n", *liczba_aut, FILENAME);
}

/// Funkcja wyświetlająca menu
void menu() {
    printf("\n--- REJESTR SAMOCHODÓW ---\n");
    printf("1. Dodaj samochód\n");                     /// Opcja 1 - dodanie samochodu
    printf("2. Wyświetl samochody\n");                 /// Opcja 2 - pokazanie listy
    printf("3. Zapisz do pliku\n");                    /// Opcja 3 - zapis danych
    printf("4. Wczytaj z pliku\n");                    /// Opcja 4 - odczyt danych
    printf("0. Wyjście\n");                            /// Opcja 0 - zakończenie programu
    printf("Wybierz opcję: ");
}

int main() {
    Samochod auta[MAX_CARS];                           /// Deklaracja tablicy samochodów
    int liczba_aut = 0;                                /// Licznik aktualnej liczby samochodów
    int opcja;                                         /// Zmienna wyboru

    do {
        menu();                                        /// Wywołanie menu
        scanf("%d", &opcja);                           /// Wczytanie opcji od użytkownika
        switch (opcja) {                               /// Wybór działania na podstawie opcji
            case 1:
                dodajSamochod(auta, &liczba_aut);      /// Dodanie samochodu
                break;
            case 2:
                wyswietlSamochody(auta, liczba_aut);   /// Wyświetlenie listy samochodów
                break;
            case 3:
                zapiszDoPliku(auta, liczba_aut);       /// Zapis do pliku
                break;
            case 4:
                wczytajZPliku(auta, &liczba_aut);      /// Wczytanie z pliku
                break;
            case 0:
                printf("Zakończono program.\n");       /// Wyjście z programu
                break;
            default:
                printf("Niepoprawna opcja. Spróbuj ponownie.\n"); /// Obsługa błędnego wyboru
        }
    } while (opcja != 0);                              /// Pętla do momentu wyboru "0"

    return 0;                                          /// Zakończenie programu
}
