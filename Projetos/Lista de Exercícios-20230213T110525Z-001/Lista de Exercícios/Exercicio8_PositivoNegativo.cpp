/*
	Exercicio 8

	Verificar se numero é positivo ou negativo
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool verificaSinal(int);

int main(){
	
	bool resultado;
	int num;
	
	printf("Digite um numero inteiro: ");
	scanf("%i", &num);
	
	if(num == 0) {
		printf("0 e um numero neutro\n\n");
		system("pause");
		return 0;
	}
	
	resultado = verificaSinal(num);
	
	if(resultado) {
		printf("%i e positivo\n\n", num);
		system("pause");
		return 0;
	} 
	else {
		printf("%i e negativo\n\n", num);
		system("pause");
		return 0;	
	}
}

bool verificaSinal(int num){
	
	if(num > 0)
		return true;
	else
		return false;
}