/*
 * Program konwertuje liczbę nieujemną na liczbę w zapisie rzymskim
 */

#include <stdio.h>

//tablica dozwolonych znaków
char signs[] = {'I','V','X','L','C','D','M'};

void get(unsigned int n, char* t, int i){
	int j = 0;
	int tmp = 0;
	while(t[j]!=0)j++;


	// jezeli cyfra jest od 5 do 10 to poprzedza ją jakiś znak,
	// w tym miejscu znajduje się sprawdzenie czy liczba zawiera się w tym przedziale
	// oraz ewentualne wstawienie tego znaku
	if(n > 5){
		tmp = 1;
		n -= 5;
	}
	if(n<=3 && tmp){
		t[j++] = signs[i + 1];
	}

	// dodanie reszyty znaków
	switch(n){
		// wykorzystanie braku breaka w celu osiągnięcia odpowiedniej krotności jakiegoś znaku
		case 3:
			t[j++] = signs[i];
		case 2:
			t[j++] = signs[i];
		case 1:
			t[j++] = signs[i];
			break;
		// obsługa znaków które się nie powielają
		case 4:
			t[j++] = signs[i + 1 + tmp];
			t[j++] = signs[i];
			break;
		case 5:
			t[j++] = signs[i + 1];
			break;
	}
}

char result[10];
int main(){
	unsigned int n = 0;
	// wczytanie liczby od użytkownika
	printf("Podaj n\n");
	scanf("%ud", &n);
	int i = 0;
	//wstawianie do tablicy poszczególnie obliczonych znaków
	while(n != 0){
		get(n%10,result, i);
		i+=2;
		n/=10;
	}
	// do tablicy liczby były wpisywane od końca, więc trzeba znaleźć ostatni element i od niego iterować
	int j=0;
	while(result[j]!=0)j++;
	for(int i=j;i>=0;i--)
		printf("%c", result[i]);
	printf("\n");
	return 0;
}
