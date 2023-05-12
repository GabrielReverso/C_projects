/*
	Exercicio 5

	Recebe valor em segundos e converte para horas, minutos e segundos
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct horario{
	int horas = 0, minutos = 0, segundos = 0;
	bool functionFlag = false;
};

typedef struct horario Struct;

Struct conversor (int);

int main() {
	
	int s;
	
	Struct resposta;
	
	printf("Digite o tempo em segundos: ");
	scanf("%i", &s);
	
	resposta = conversor(s);
	
	if(resposta.functionFlag){
		printf("ERRO: impossivel concluir conversao!\n\n");
		
		system("pause");
		return 0;
	}
	
	printf("Tempo resultante em horas: %i:%i:%i\n\n", resposta.horas, resposta.minutos, resposta.segundos);
	
	system("pause");
	return 0;
} 

Struct conversor (int s){
	
	Struct resultado;
	
	if(s < 0) {
		resultado.functionFlag = true;
		return resultado;
	}
	
	bool flag = false;
	
	s -= 60;
	
	if (s < 0) {
		s += 60;
		flag = true;
	}
	
	while (!flag) {
	
		resultado.minutos += 1;
		s -= 60;
		
		if (s < 0) {
			s += 60;
			flag = true;
		}
		
	}
	
	flag = false;
	
	resultado.minutos -= 60;
	
	if (resultado.minutos < 0) {
		resultado.minutos += 60;
		flag = true;
	}
	
	while (!flag) {
	
		resultado.horas += 1;		
		resultado.minutos -= 60;
		
		if (resultado.minutos < 0) {
			resultado.minutos += 60;
			flag = true;
		}
		
	}
	
	if (resultado.minutos < 0) {
		resultado.minutos += 60;
	}
	
	resultado.segundos = s;
	
	return resultado;
}