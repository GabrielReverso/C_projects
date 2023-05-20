/*
	Exercicio 12

	Receber o horario de inicio e fim de um jogo
	retornar duração da partida
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct HorasMinutos {
	int horasTotal, minutosTotal;
	bool flag = false;
};

typedef struct HorasMinutos Struct;

Struct calculaTempo(int, int, int, int);

int main() {
	
	Struct resposta;
	int horasI, minutosI, horasF, minutosF;
	
	printf("Digite horario de inicio do jogo (H:M): ");
	scanf("%i:%i", &horasI, &minutosI);
	
	printf("Digite horario de termino do jogo (H:M): ");
	scanf("%i:%i", &horasF, &minutosF);
	
	resposta = calculaTempo(horasI, minutosI, horasF, minutosF);
	
	if(resposta.flag) {
		printf("ERRO: horario invalido!\n\n");
		system("pause");
		return 0;
	}
	
	printf("O tempo de jogo foi de: %i:%i\n\n", resposta.horasTotal, resposta.minutosTotal);
	
	system("pause");
	return 0;
}

Struct calculaTempo(int horasInicio, int minInicio, int horasFinal, int minFinal) {
	
	Struct resultado;
	
	if (horasInicio < 0 || horasFinal < 0 || minInicio < 0 || minFinal < 0 ||
					   	  minInicio >= 60 || minFinal >= 60 				 ) {
					   	  	
			resultado.flag = true;
			return resultado;		   	  	
			
		}
	
	if(horasInicio>horasFinal) {
		
		horasFinal += 24;
		
		resultado.horasTotal = horasFinal - horasInicio;
		
	} else {
		
		resultado.horasTotal = horasFinal - horasInicio;
		
	}
	
	if(minInicio>minFinal) {
		
		minFinal += 60;

		resultado.minutosTotal = minFinal - minInicio ;
		resultado.horasTotal -= 1;
		
	} else {
		
		resultado.minutosTotal = minFinal - minInicio;
		
	}
	
	if(resultado.minutosTotal < 0){
		resultado.minutosTotal *= -1;
		resultado.horasTotal -= 1;
	}
	
	return resultado;		 
}