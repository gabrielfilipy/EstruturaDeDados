#include <stdio.h>
#include <stdlib.h>
#include <time.h>//Biblioteca para gerar números aleatórios.
#include <locale.h>//CORRIGIR ACENTUAÇÃO
#include <bits/stdc++.h>//CALCULAR TEMPO

using namespace std;

void QuickSort (int v[], int p, int u);
int particao (int v[], int p, int u);
void trocar(int v[], int i, int j);
void calcularTempo(time_t start, time_t end);
 
#define SIZEVECTOR 100000

int main() {
	time_t start, end;
	
	setlocale(LC_ALL, "");//CORRIGIR ACENTUAÇÃO
	
	int v[SIZEVECTOR] = { 0 }; //Inicializando todas as posições com o valor '0'.
	
	srand(time(NULL));//Gera uma semente aleatória baseada no horário do computador.
	
	time(&start);
	
	//INSERÇÃO DE DADOS
	for(int i = 0; i < SIZEVECTOR; i++)
		v[i] = rand() % 10000; //Gerando valores aleatórios entre 0 e 99. Utilizando a semente.
		
	printf("VETOR NÃO ORDENADO: \n");  
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

//RECURSIVIDADE. OU SEJA, A PRÓPRIA FUNÇÃO IRÁ CHAMAR ELA MESMA.
void QuickSort (int v[], int p, int u) {
		
	int m;//PONTO CENTRAL
	
	if(p < u) {//CRITÉRIO DE PARADA
		m = particao(v, p, u);//QUEBRAR O VETOR NO MEIO.
		QuickSort(v, p, m);//ESQUERDO
		QuickSort(v, m + 1, u);//DIREITO
	}	
	
}

//SERÁ CALCULADO O 'PONTO CENTRAL' E REALIZAR A ORDENAÇÃO 'ESQUERDA' E 'DIREITA'
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
		//	j--;//VINDO NA DIREÇÃO AO MEIO.
		//} while(v[j] > pc);//PEGAR VALORES MAIORES
		
		//do {//TESTA O LADO ESQUERDO
		//	i++;//INCIANDO DO '0' E INDO NA DIREÇÃO AO MEIO.
		//} while(v[i] < pc);//PEGAR VALORES MAIORES
		
		//DECRESCENCTE
		do {//TESTA O LADO DIREITO
			j--;//VINDO NA DIREÇÃO AO MEIO.
		} while(v[j] < pc);//PEGAR VALORES MAIORES
		
		do {//TESTA O LADO ESQUERDO
			i++;//INCIANDO DO '0' E INDO NA DIREÇÃO AO MEIO.
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
    cout << "Tempo de execução : " << fixed
        << time_taken << setprecision(5);
    cout << " sec " << endl;
}

