/*
 * Program wczytuje podany rok i wyświetla zgodnie z prawdą napis czy podany rok jest przestępny czy też nie
 */

// wczytuje bibliotekę standardowego wyjścia wejścia
#include <stdio.h>

int main(){
	// deklaracja zmiennej rok i wczytanie danych
	int rok = 0;
	printf("Podaj rok: ");
	scanf("%d", &rok);
	// warunek roku przestępnego
	if( ( rok % 4 == 0 && rok % 100 != 0 ) || rok % 400 == 0 ){
		// wypisywanie odopwiedniego napisu
		printf("Rok %d jest przestępny\n", rok);
	} else {
		// wypisywanie odopwiedniego napisu
		printf("Rok %d jest zwykły\n", rok);
	}
	return 0;
}
