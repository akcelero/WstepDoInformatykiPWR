/*
 * Program wylicza liczby doskonałe mniejsze od 1000
 * oraz pary liczb zaprzyjaźnionych mniejszych od 1000
 */

// wczytuje bibliotekę standardowego wyjścia wejścia
#include <stdio.h>

int sigma(int a){
	int result = 0, i = 0;
	// uzylem tutaj zlozonosci O(sqrt(n)) dla okreslenia sumy dzielnikow
	// jezeli n jest podzielne przez a to dzielnikiem tez jest liczba n/a
	for(i = 1; i*i < a; i++){
		if(a % i == 0){
			result += a / i;
			result += i;
		}
	}
	// jezeli liczba a jest kwadratem liczby i to nalezy liczyc i tylko raz
	// w petli i dodalo by sie dwukrotnie
	if(i*i==a){
		result += i;
	}
	// do sumy nie zalicza się liczba a, natomiast przy pierwszym cyklu pętli
	// liczba a zostala wliczona do sumy
	return result - a;
}

int main(){

	printf("Liczby doskonałe: ");
	for(int i = 1; i<1000;i++){
		// jeżeli warunek liczby doskonałej jest spełniony to liczba zostaje wypisana na standardowe wyjście
		if(sigma(i) == i){
			printf("%d ", i);
		}
	}
	printf("\n");

	printf("Pary zaprzyjaznione:\n");
	// by pary sie nie powtarzaly dla kazdego i szukamy pary od i+1 do 1000
	for(int i=1;i<1000;i++){
		for(int j=i+1;j<1000;j++){
			// jeżeli warunek bycia zaprzyjaźnionymi liczbami jest spełniony to para zostaje wypisana na standardowe wyjście
			if(sigma(i) == j && sigma(j) == i){
				printf("%d i %d\n", i, j);
			}
		}
	}
	return 0;
}
