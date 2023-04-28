#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZEVECTOR 10

int buscaSequencial(int vet[], int valorBuscar);

int main() {
	
	int valorBuscar, encontrado;
	int vet[SIZEVECTOR] = {0};
	srand(time(NULL));
	
	for(int i = 0; i < SIZEVECTOR; i++) {
		vet[i] = rand() % 1000;
	}
	
	printf("VETOR GERADO \n");
	for(int i = 0; i < SIZEVECTOR; i++) {
		printf("%d \n", vet[i]);
	}
	
	printf("Selecione um valor para realizar a busca: \n");
	scanf("%d", &valorBuscar);
	
	encontrado = buscaSequencial(vet, valorBuscar);
	
	if(encontrado == -1) {
		printf("Valor não encontrado \n");
	} else {
		printf("Valor encontrado na posição %d \n ", encontrado);
	}
	
	system("pause");
	
	return 0;
	
}

int buscaSequencial(int vet[], int valorBuscar) {
	int econtrou, i;
	econtrou = 0;
	i = 0;
	
	while((i <= SIZEVECTOR) && (econtrou == 0)) {//EXECUTA ENQUANTO O VETOR NÃO CHEGAR NO FINAL
		if(vet[i] == valorBuscar) {
			econtrou = 1;
		} else {
			i++;
		}
	}
	
	if(econtrou == 0) {
		return -1;//NÃO FORA ENCONTRADO O VETOR INFORMADO
	} else {
		return i+1;
	}
	
}

