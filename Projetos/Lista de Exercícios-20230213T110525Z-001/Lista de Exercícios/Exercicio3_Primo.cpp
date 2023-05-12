/*
	Exercicio 3
	
	Retornar TRUE para numero primo
	Retornar FALSE para não primo
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool verificaPrimo(int);

int main() {
	
	bool primo;
	int num;
	
	printf("Digite um numero inteiro positivo: ");
	scanf("%i", &num);
	
	if(num < 0){
		printf("ERRO: numero invalido!\n");
		system("pause");
		return 0;
	}
	
	primo = verificaPrimo(num);
	
	if(primo){
		
		printf("O numero e primo!\n");
		system("pause");
		
	} else{
		
		printf("O numero nao e primo!\n");
		system("pause");
	}
	
	return 0;
}

bool verificaPrimo(int a){
	
	bool resultado;
	int b;
	
	b = a - 1;
	
	while(a % b != 0){
		b --;
	}
	
	if(b == 1){
		
		return true; 
		
	} else {
		
		return false;
		
	}
	
}
