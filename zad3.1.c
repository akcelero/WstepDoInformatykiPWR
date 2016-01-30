// wczytuje bibliotekę wyjścia wejścia 
#include <stdio.h>

/* definiowanie macra by różne typy mogły być wykorzystane w jednej częsci kodu
 * metoda uzyskiwania maximum:
 * przesówa bity o 1 w lewo i dodaje 1, tak długo aż wielkość po operacji jest większa niż przed
 * minimum to maximum +1
 * nastepnie wyswietlany jest wynik
 */
#define GET(type, formatString){			\
	type min = 1;						\
	type max = 1;						\
	while(max < (type)(max<<1))			\
		max=(max<<1)|1;					\
	min = max + 1;						\
	printf(#type" ) "#formatString" : "#formatString"\n\n", min, max);		\
}

int main(){
	// operacja przeprowadzana jest dla wszystkich typów określonych w zadaniu
	GET(unsigned long,		%lu);
	GET(unsigned int,		%u);
	GET(unsigned short int,	%hu);
	GET(unsigned char,		%d);
	GET(signed long,		%ld);
	GET(signed int,			%d);
	GET(signed short int,	%hd);
	GET(signed char,		%d);
	return 0;
}
