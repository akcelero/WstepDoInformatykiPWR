/*
 *  Program przekształca temperaturę podaną w stopniach Celsjusza
 *  na temperaturę w stopniach Fahrenheita
 */

// wczytuje bibliotekę wyjścia wejścia 
#include <stdio.h>

// główna funkcja programu
int main(){

	// deklaracja i zczytanie temperatury
	float celsius = 0, fahrenheit = 0;

	printf("Podaj stopnie w skali celsjusza: ");
	scanf("%f", &celsius);

	// obliczenie i wystwietlenie temperatury w innej skali
	fahrenheit = 1.8 * celsius + 32;

	printf("Stopni w skali fahrenheita: %f\n", fahrenheit);

	// zakończenie programu
	return 0;
}
