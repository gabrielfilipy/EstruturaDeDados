#include <stdio.h>
#include <stdlib.h>
#include <time.h>//Biblioteca para gerar n�meros aleat�rios.
#include <locale.h>//CORRIGIR ACENTUA��O
#include <bits/stdc++.h>//CALCULAR TEMPO

using namespace std;

void BubbleSort (int v[]);
void calcularTempo(time_t start, time_t end);
 
#define SIZEVECTOR 100000

int main() {
	time_t start, end;
	
	setlocale(LC_ALL, "");//CORRIGIR ACENTUA��O
	
	int v[SIZEVECTOR] = { 0 }; //Inicializando todas as posi��es com o valor '0'.
	
	srand(time(NULL));//Gera uma semente aleat�ria baseada no hor�rio do computador.
	
	time(&start);
	
	//INSER��O DE DADOS
	for(int i = 0; i < SIZEVECTOR; i++)
		v[i] = rand() % 10000; //Gerando valores aleat�rios entre 0 e 99. Utilizando a semente.
		
	printf("VETOR N�O ORDENADO: \n");  
	for(int i = 0; i < SIZEVECTOR; i++)
		printf("%d \n", v[i]);
		
	BubbleSort(v);		
	
	printf("VETOR ORDENADO: \n");
	for(int i = 0; i < SIZEVECTOR; i++)
		printf("%d \n", v[i]);
		
	time(&end);	
	
	calcularTempo(start, end);		
		
	system("pause");
		
	return 0;
}

void BubbleSort (int v[]) {
	int aux;
	
	for(int n = 1; n <= SIZEVECTOR; n++) {
		for(int i = 0; i < (SIZEVECTOR - 1); i++) {//PRIMEIRA POSI��O
			if(v[i] < v[i + 1]) {//CRESCENTE. VERIFICA CASO PRECISE ALTERAR POSI��O DESSE ELEMENTO.
				//REALIZA A TROCA.
				aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
			}
			//if(v[i] > v[i + 1]) {//CRESCENTE. VERIFICA CASO PRECISE ALTERAR POSI��O DESSE ELEMENTO.
				//REALIZA A TROCA.
				//aux = v[i];
				//v[i] = v[i + 1];
			//	v[i + 1] = aux;
			//}
		}
	} 	
	
}

void calcularTempo(time_t start, time_t end) {
    double time_taken = double(end - start);
    cout << "Tempo de execu��o : " << fixed
        << time_taken << setprecision(5);
    cout << " sec " << endl;
}




