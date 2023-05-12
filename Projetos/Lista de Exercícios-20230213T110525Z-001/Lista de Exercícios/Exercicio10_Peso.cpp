/*
	Exercício 10

	Recebe altura de uma pessoa e calcula peso ideal de acordo com fórmula
	Masculino: 72.7 * altura - 58
	Feminino: 62.1 * altura - 44.7
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

float calculaPeso(float, char);

int main(){
	
	float altura, pesoIdeal;
	char sexo;
	
	printf("Digite a altura em metros: ");
	scanf("%f", &altura);
	
	printf("Informe o sexo (m/f): ");
	scanf(" %c", &sexo);
	
	pesoIdeal = calculaPeso(altura, sexo);
	
	if(pesoIdeal){
		
		printf("O peso ideal e: %.2f", pesoIdeal);
		
	}
	else{
		
		printf("Sexo ou altura invalida");
		
		return 0;	
	}	
	
	return 0;
}

float calculaPeso(float alt, char sexo){
	
	float r;
	
	sexo = toupper(sexo);
	
	switch(sexo){
		
		case 'M': {
			
			r = 72.7 * alt - 58;
			
			break;
		}
		
		case 'F': {
			
			r = 62.1 * alt - 44.7;
			
			break;
		}
		
		default: {
			
			return 0;
			
			break;
		}
	}
	
	return r;

}