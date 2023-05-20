/*
10	Exercicio 13

	Recebe X, Y e Z e verifica se é possivel formar 
	um triangulo com eles e retorna o tipo de triangulo:

	Isosceles : 2 lados iguais
	Equilatero : 3 lados iguais
	Escaleno : 3 lados diferentes

	Triangulo é verdade se o lado for menor que a soma dos outros dois lados
*/

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

struct Triangulo{
	char tipo[10];
	bool flag = false;
};

typedef struct Triangulo Struct;

Struct verificaTriangulo(float, float, float);

int main(){
	
	Struct resultado;
	float lado1, lado2, lado3;
	
	printf("Digite os lados do triangulo: ");
	scanf("%i %i %i", &lado1, &lado2, &lado3);
	
	resultado = verificaTriangulo(lado1, lado2, lado3);
	
	if(resultado.flag){
		printf("ERRO: triangulo nao existe!\n\n");
		system("pause");	
		return 0;
	}
	
	printf("Triangulo: %s\n\n", resultado.tipo);
	
	system("pause");	
	return 0;
}

Struct verificaTriangulo(float X, float Y, float Z){
	
	Struct retorno;
	
	//Verifica se existe
	
	if(X < 0 || Y < 0 || Z < 0){
		retorno.flag = true;
		return retorno;	
	}	
	
	if(X >= (Y + Z)) {
		retorno.flag = true;
		return retorno;	
	}
	
	if(Y >= (X + Z)) {
		retorno.flag = true;
		return retorno;		
	}
	
	if(Z >= (Y + X)) {
		retorno.flag = true;
		return retorno;	
	}
	
	//Verifica tipo
	
	if(X == Y && X == Z){
		strcpy(retorno.tipo, "Equilatero");
		return retorno;
	} else if(X == Y || X == Z || Y == Z){
		strcpy(retorno.tipo, "Isosceles");
		return retorno;
	} else {
		strcpy(retorno.tipo, "Escaleno");
		return retorno;
	}
}