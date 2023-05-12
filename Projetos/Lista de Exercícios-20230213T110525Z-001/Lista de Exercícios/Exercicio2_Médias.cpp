/*
	Exercicio 2

	Calcular média aritimética, ponderada e harmonica 
	de 3 notas.

	Peso: 5, 3, 2

	Parametros: A, B, C, TIPO MEDIA
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

float calculaMedia(float, float, float, char);

int main() {
	
	float nota1, nota2, nota3, media;
	char tipo;
	
	printf("Digite as 3 notas e o tipo de media separados por virgula: \n");
	printf("A - Aritimetica\nP - Ponderada\nH - Harmonica\n\n");
	scanf("%f, %f, %f, %c", &nota1, &nota2, &nota3, &tipo);
	
	media = calculaMedia(nota1, nota2, nota3, tipo);
	
	if(media < 0){
		printf("ERRO: informacao invalida!");
		system("pause");
		return 0;
	}
	
	system("cls");
	
	printf("Media: %.2f", media);
	
	system("pause");
	
	return 0;
}

float calculaMedia(float a, float b, float c, char tipo) {
	
	float media;
	
	if(a < 0 || b < 0 || c < 0){
		return -1;
	}
	
	tipo = toupper(tipo);
	
	switch(tipo) {
		case 'A': {
			
			media = (a + b + c)/3;
			
			return media;
			
			break;
		}
		case 'P': {
			
			media = ((a*5) + (b*3) + (c*2))/10;
			
			return media;
			
			break;
		}
		case 'H': {
			
			media = 3/((1/a) + (1/b) + (1/c));
			
			return media;
			
			break;
		}
		default: {
			
			return -1;
			
			break;
		}
	}
	
}
