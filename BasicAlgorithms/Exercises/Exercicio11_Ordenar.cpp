/*
	Exercicio 11

	Receber 3 valores inteiros e ordenar do menor pro maior
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct MenorMaior {
	int numOrd[3];
	bool flag;
};

typedef struct MenorMaior Struct;

Struct ordenaMenorMaior(int [3]);

int main() {
	
	int num[3];
	Struct resposta;

	for (int i=0; i<3; i++) {
	
		printf("Digite o numero %i: ", i+1);
		scanf("%i", &num[i]);
	}
	
	resposta = ordenaMenorMaior(num);
	
	if(resposta.flag) {
		printf("ERRO: os numeros sao iguais\n\n");
		system("pause");
		return 0;
	}
	
	printf("Ordem crescente: ");
	for (int i=0; i<3; i++) {
		printf("%i ", resposta.numOrd[i]);
	}
	
	printf("\n\n");
	system("pause");
	return 0;
}

Struct ordenaMenorMaior(int num[3]){
	
	Struct resultado;
	int maior, menor;
	
	if(num[1] == num [2] || num[1] == num [3] || num[2] == num[3]) {
		resultado.flag = true;
		return resultado;
	}
	
	maior = 0;
	menor = num[1];
	
	//Verifica o maior e menor
	
	for (int i=0; i<3; i++){
		
		if(num[i] > maior){
			maior = num[i];
			resultado.numOrd[2] = num[i];
		}
		
		if(num[i] < menor) {
			menor = num[i];
			resultado.numOrd[0] = num[i];
		}
	}
	
	//Verifica o numero do meio
	
	for (int i=0; i<3; i++){
		
		if(num[i] > menor && num[i] < maior ) {
			resultado.numOrd[1] = num[i];
		}
	}

	return resultado;
}