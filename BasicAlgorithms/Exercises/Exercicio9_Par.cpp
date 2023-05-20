/*
	Exercicio 9

	Verificar se numero é par ou impar
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool verificaPar(int);

int main(){
	
	bool resultado;
	int num;
	
	printf("Digite um numero inteiro: ");
	scanf("%i", &num);
	
	resultado = verificaPar(num);
	
	if(resultado) {
		printf("%i e par\n\n", num);
		system("pause");
		return 0;
	} 
	else {
		printf("%i e impar\n\n", num);
		system("pause");
		return 0;	
	}
}

bool verificaPar(int num){
	
	if(num % 2 == 0)
		return true;
	else
		return false;
}