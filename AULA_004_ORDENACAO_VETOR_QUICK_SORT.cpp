#include <stdio.h>
#include <stdlib.h>
#include <time.h>//Biblioteca para gerar n�meros aleat�rios.
#include <locale.h>//CORRIGIR ACENTUA��O
#include <bits/stdc++.h>//CALCULAR TEMPO

using namespace std;

void QuickSort (int v[], int p, int u);
int particao (int v[], int p, int u);
void trocar(int v[], int i, int j);
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
		
	QuickSort(v, 0, SIZEVECTOR - 1);		
	
	printf("VETOR ORDENADO: \n");
	for(int i = 0; i < SIZEVECTOR; i++)
		printf("%d \n", v[i]);
		
	time(&end);	
	
	calcularTempo(start, end);
	
	system("pause");
		  
	return 0;
}

//RECURSIVIDADE. OU SEJA, A PR�PRIA FUN��O IR� CHAMAR ELA MESMA.
void QuickSort (int v[], int p, int u) {
		
	int m;//PONTO CENTRAL
	
	if(p < u) {//CRIT�RIO DE PARADA
		m = particao(v, p, u);//QUEBRAR O VETOR NO MEIO.
		QuickSort(v, p, m);//ESQUERDO
		QuickSort(v, m + 1, u);//DIREITO
	}	
	
}

//SER� CALCULADO O 'PONTO CENTRAL' E REALIZAR A ORDENA��O 'ESQUERDA' E 'DIREITA'
int particao (int v[], int p, int u) {
	//CALCULAR PONTO CENTRAL
	int pc, pc_calc, i, j;
	
	pc_calc = (p + u) / 2;
	pc = v[pc_calc];
	
	//INICIALIZANDO VARIAVEIS DE VARREDURA.
	i = p - 1;
	j = u + 1; 
	
	while(i < j) {
		//CRESCENCTE
		//do {//TESTA O LADO DIREITO
		//	j--;//VINDO NA DIRE��O AO MEIO.
		//} while(v[j] > pc);//PEGAR VALORES MAIORES
		
		//do {//TESTA O LADO ESQUERDO
		//	i++;//INCIANDO DO '0' E INDO NA DIRE��O AO MEIO.
		//} while(v[i] < pc);//PEGAR VALORES MAIORES
		
		//DECRESCENCTE
		do {//TESTA O LADO DIREITO
			j--;//VINDO NA DIRE��O AO MEIO.
		} while(v[j] < pc);//PEGAR VALORES MAIORES
		
		do {//TESTA O LADO ESQUERDO
			i++;//INCIANDO DO '0' E INDO NA DIRE��O AO MEIO.
		} while(v[i] > pc);//PEGAR VALORES MAIORES
		
		if(i < j) {
			trocar(v, i, j);
		}
	}
	
	return j;//ONDE O LADO DIREITO PAROU.
	
}

void trocar(int v[], int i, int j) {
	int aux;
	aux = v[i];
	v[i] = v[j];
	v[j] = v[i];
}

void calcularTempo(time_t start, time_t end) {
    double time_taken = double(end - start);
    cout << "Tempo de execu��o : " << fixed
        << time_taken << setprecision(5);
    cout << " sec " << endl;
}

