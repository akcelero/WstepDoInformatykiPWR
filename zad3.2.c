#include <stdio.h>

int palindrome(char* t){
	int i = 0, j = 0;
	// obliczanie jak długi jest łańcuch znaków
	// czyli indexu ostatniego elementu
	while(t[j+1] != 0){
		j++;
	}
	// ostatni znak to przejscie do nowej linii, zatem nie nalezy go brac pod uwage
	j--;
	// sprawdzanie warunku palindromu dopóki wskaźnik na początek
	// będzie mniejszy niż wskaźnik na początek
	while(i<j){
		if(t[i] != t[j]){
			// jeżeli znak na pozycji bedzie inny niż znak na tej samej pozycji od tyłu
			// to funkcja zwraca 0
			return 0;
		}
		j--;
		i++;
	}
	// jeżeli sprawdzanie się zakończyło to łańcuch znaków jest palindromem
	// czyli funkcja zwraca 1
	return 1;
}

int main(){
	char string[1000];
	//wczytanie łańcuch
	printf("Podaj ciąg znaków który chcesz sprawdzić czy jest palindromem (max 1000 znaków)\n");
	fgets(string, 1000, stdin);

	if(palindrome((char *)string)){
		printf("Wyraz podany do funkcji jest palindromem\n");
	} else {
		printf("Wyraz podany do funkcji nie jest palindromem\n");
	}
	return 0;
}
