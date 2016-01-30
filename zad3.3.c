/*
 * sposób kompilacji:
 * make -e CODE=3.3 EXT=-lm
 */ 
// wczytuje bibliotekę wyjścia wejścia 
#include <stdio.h>
// wczytuje bibliotekę matematyczną
#include <math.h>

// funkcja podana w zadaniu
double f(double x){
	return cos(x/2);
}

double rozwiazanie(double a, double b, double eps, double fun()){
	// jeżeli funkcja dla parametrów a i b przyjmuje ten sam znak
	// to nie ma miedzy nimi miejsca zerowego
	if(!(fun(a) * fun(b) <= 0.0))
		return INFINITY;

	// wyszukiwanie miejsca zerowego wyszukiwaniem binarnym
	// ustawiany jest srodek przedzialu
	// i sprawdzane jest czy jest on wiekszy czy mniejszy niz 0
	// jezeli mniejszy to a jest ustawiane w poz. srodku przedzialu
	// jezeli wiekszy to b jest ustawiane w poz srodku przedizalu
	double srd = 0.0;
	while(b-a > eps){
		srd = (a + b) / 2;
		if(fun(a) * fun(srd) <= 0.0){
			b = srd;
		} else if(fun(b) * fun(srd) <= 0.0){
			a = srd;
		}
	}
	return srd;
}

int main(){

	float tmp=0.0;
	double a = 0.0, b = 0.0;
	printf("Podaj przedizał\n");
	scanf("%lf", &a);
	scanf("%lf", &b);

	// część kodu testujaca funkcję rozwiazanie() dla k = {1..8}
	for(int k=1;k<=8;k++){
		tmp = 1;
		for(int j=0;j<k;j++)
			tmp/=10;
		printf("%d) eps = %.8lf) %lf\n", k, tmp, rozwiazanie(a, b, tmp, f));
		
	}
	return 0;
}
