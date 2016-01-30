/*
 * Program oblicza różnice czasu między podanymi datami
 */

// wczytuje bibliotekę standardowego wyjścia wejścia
#include <stdio.h>

// funkcja zwraca 1 jeżeli rok jest przestępny, 0 w przeciwnym wypadku
int checkIntercalary(int year){
	if( ( year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0 ){
		return 1;
	} else {
		return 0;
	}
}

// ilości dni w kolejnych miesiącach
int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

// pobiera ilość dni od początku ery
int getNumberOfDay(int day, int month, int year){
	int result = 0,
	tmpMonth = 1,
	tmpYear = 1;

	// dodawanie dni z lat poprzedzających rok w podanej dacie
	while(tmpYear < year){
		result += 365 + checkIntercalary(tmpYear);
		tmpYear++;
	}

	// dodawanie dni z miesięcy poprzedzających miesiąc w podanej dacie
	while(tmpMonth < month){
		// dodawanie dni pobranych z tablic, indexowanie od 0 więc tmpMonth-1
		result += daysInMonth[tmpMonth-1];

		// wyjątek dla lutego
		if(checkIntercalary(tmpYear) && tmpMonth == 2){
			result++;
		}

		tmpMonth++;
	}
	// dodanie dni z miesiąca w podanej dacie
	result += day;
	return result;
}

int main(){
	// zmienne do przechowania dat
	int year1 = 0, month1 = 0, day1 = 0;
	int year2 = 0, month2 = 0, day2 = 0;
	
	// wczytywanie dat
	printf("Podaj date urodzin w formacie dd mm yy odzielając liczby spacja\n");
	scanf("%d%d%d", &day1, &month1, &year1);
	
	printf("Podaj dzisiejsza date w ten sam sposób\n");
	scanf("%d%d%d", &day2, &month2, &year2);

	// obliczanie różnicy wyrażonej w dniach między podanymi datami
	int days = getNumberOfDay(day2, month2, year2) - getNumberOfDay(day1, month1, year1);

	// obliczanie sekund z ilości dni
	long long seconds = ((long long)days) * 24L * 60L * 60L;

	// wyświetlanie wyniku
	printf("Różnica w dniach: %d\nRóżnica w sekundach: %lld\n", days, seconds);

 	return 0;
}
