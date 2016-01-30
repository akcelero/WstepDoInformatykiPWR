/*
 * algorytm liczący 100! oparty o wykorzystanie tablic
 */

#include <stdio.h>

// deklaracja tablic, wielkość może zajmować dwukrotnie wiecej niż czynniki
int result[10000], a[5000], b[5000];

void multiply(int* a, int* b, int* c){

	// należy znaleźć najdalej nie zerowe indexy by nie wykonywać operacji mnożenia i dzielenia na darmo
	int aMax = 1;
	int bMax = 1;
	// szukanie maxymalnego indexu w tablicy a
	for(int i = 0; i < 5000; i++)
		if(a[i]!=0)
			aMax = i;
	// szukanie maxymalnego indexu w tablicy b
	for(int i = 0; i < 5000; i++)
		if(b[i]!=0)
			bMax = i;
	// mnozenie opiera się o dodawanie odpowiednich iloczynów do odpowiednich komórek tablicy wynikowej
	// nastepnie należy "przesówać" cześći większe niż jedności by uzyskać odpowiednio sformatowany wynik
	for(int i = 0; i <= aMax; i++){
		for(int j = 0; j <= bMax; j++){
			c[i+j] += a[i]*b[j];
		}
		for(int j = 0; j <= aMax + bMax; j++){
			c[j+1] += c[j] / 10;
			c[j] %= 10;
		}
	}
}
int main(){
	// należy wynik ustawić jako 1 by umożliwić dalsze mnożenia
	result[0] = 1;

	for(int i=1;i<=1000;i++){
		// przenoszenie wyniku do tablicy b oraz czyszczenie tablicy result
		for(int j=0;j<5000;j++){
			b[j] = result[j];
			result[j] = 0;
		}
		// wstawienie zmiennej od 1 do 100 (jak w przykładzie) do tablicy a
		a[0] = i%10;
		a[1] = (i%100)/10;
		a[2] = i/100;
		multiply(a,b,result);
	}

	// zmienna flaga jest tu użyta by nie wyświetlać zer poprzedzających liczbę
	int flag = -1;
	for(int i=5000-1;i>=0;i--){
		if(result[i] != 0 && flag == -1)
			flag = i;
		if(flag != -1){
			printf("%d", result[i]);
			// obsługa podziału co 3 cyfry
			if(i % 3 == 0){
				printf(" ");
			}
		}
	}
	printf("\n");
	return 0;
}
