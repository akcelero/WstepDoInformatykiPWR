/*
 * wczytuje bibliotekę wyjścia wejścia 
 * sposób kompilacji:
 * make -e CODE=2.3 EXT=-lm
 */
#include <stdio.h>
// wczytuje bibliotekę matematyczną
#include <math.h>

int main(){
	// deklaracja i przypisanie wartości zmiennym;
	int n = 1000;
	double result = 1.0;

	// korzystając z tego że pierwiastek iloczynu jest równy iloczynowi pierwiastków
	for(int i=1;i<=n;i++){
		// pow - funkcja oblicza potęgę liczby, postać wykładnik 1/n oblicza pierwiastek n-tego stopnia
		result *= pow( i, 1.0 / 1000.0 );
	}

	// wyświetlenie wyniku
	printf("pierwiastek stopnia 1000 z liczby 1000! = %lf\n", result);
	return 0;
}
