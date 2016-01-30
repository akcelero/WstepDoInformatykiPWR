/*
 *  Program wczytuje dwie liczby rzeczywiste (typu float)
 *  następnie wyprowadza ich sumę, różnicę, iloczyn i iloraz
 */

// wczytuje bibliotekę wyjścia wejścia
#include <stdio.h>

// główna funkcja programu
int main(){

	// deklaracja oraz zczytanie liczb
	float a = 0.0,
	b = 0.0;

	printf("Podaj liczbe a: ");
	scanf("%f", &a);

	printf("Podaj liczbe b: ");
	scanf("%f", &b);

	// obliczanie poszczególnych wyników
	float suma = a + b,
	roznica = a - b,
	iloczyn = a * b;

	// wyświetlanie wyników
	printf("Suma: %f\n", suma);
	printf("Różnica: %f\n", roznica);
	printf("Iloczyn: %f\n", iloczyn);

	// Sprawdzanie czy b jest 0, wtedy nie można wykonać operacji dzielenia
	if(b != 0.0){
		// jeżeli b jest różne niż 0 to iloraz jest możliwy do obliczenia i wyświetlenia
		float iloraz = a / b;
		printf("Iloraz:  %f\n", iloraz);
	} else {
		// obsługa błędu kiedy b jest równe 0
		printf("Iloraz jest nie możliwy do policzenia\n");
	}

	// zakończenie programu
	return 0;
}
