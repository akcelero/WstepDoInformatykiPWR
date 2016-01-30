/*
 * Program wyszukuje najmniejsze n takie że:
 * 1/1 + 1/2 + 1/3 + ... + 1/n > 10
 */

// wczytuje bibliotekę standardowego wyjścia wejścia
#include <stdio.h>

int main(){
	const double P = 10.0;		// Prawa strona nierówności, nigdy się nie zmienia więc const
	double L = 0.0;	// Lewa strona nierówności
	int i = 0;		// iterator od 1 do szukanego n
	// wartosc 0 jest spowodowana konstrukcją pętli gdzie najpierw się inkrementuje zmienną i

	// warunek określony z treści zadania
	while(!(L > P)){
		i++;
		// zmiana wartości lewej strony nierówności
		L += 1.0 / (double)i;
	}

	//wypisywanie wyniku
	printf("Dana jest nierówność 1/1 + 1/2 + 1/3 + ... + 1/n > 10\n");
	printf("Najmniejsze n dla którego nierówność jest spełniona to: %d\n", i);

	return 0;
}
