/*
	Exercicio 7

	Verificar se numero é perfeito
	(soma dos divisores igual ao numero)
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool verificaPerfeito(int);

int main(){
	
	bool resultado;
	int num;
	
	printf("Digite um numero inteiro positivo: ");
	scanf("%i", &num);
	
	if(num < 0) {
		printf("ERRO: numero invalido!\n\n");
		system("pause");
		return 0;
	}
	
	resultado = verificaPerfeito(num);
	
	if(resultado) {
		printf("O numero e perfeito!\n\n");
		system("pause");
		return 0;
	} 
	else {
		printf("O numero nao e perfeito!\n\n");
		system("pause");
		return 0;	
	}
}

bool verificaPerfeito(int num){
	
	int num_aux, somatoria = 0;
	
	if(num == 1) {
		return true;
	}
	
	num_aux = num - 1;
	
	while(num_aux){
		
		if(num % num_aux == 0) {
			
			somatoria += num_aux;
			
		}	
		num_aux --;	
	}
	
	if(somatoria == num) {
		return true;
	}
	else {
		return false;
	}
}