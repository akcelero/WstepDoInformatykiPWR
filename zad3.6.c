/*
 * Program obliczający funkcje eulera dla podanej liczby
 */

// wczytuje bibliotekę wyjścia wejścia 
#include <stdio.h>

long int phi (long int n) {
	long int backup = n;
	long int result = n;
	// pętla gwarantuje przejście po liczbach od 2 do n włącznie
	for (long int i = 2; i <= backup; i++) {
		// sprawdzanie czy n dzieli sie przez i
		if (backup % i == 0){
			result *= 1 - 1./i;
		}
		// operacja dzielenia przez i dopóki liczba jest podzielna przez i
		// gwarantuje nie pojawienie sie wielokrotnosci i jako dzielnika
		while (backup % i == 0){
			backup /= i;
		}
	}
	return result;
}

int main(){
	// wczytanie danych i obliczenie wyniku
	long int n = 0;
	printf("Podaj n\n");
	scanf("%ld", &n);
	printf("%ld\n", phi(n));
	return 0;
}
