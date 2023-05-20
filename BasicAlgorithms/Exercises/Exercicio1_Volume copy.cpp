// Exercicio 1
//
// Recebe o raio de uma esfera e calcula o volume
// V = 3/4 * 3.14 * r^3

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float calculaVolume(float);

int main()
{
	float raio, volume;
	
	printf("Digite o raio da esfera: ");
	scanf("%f", &raio);
	
	volume = calculaVolume(raio);
	
	if(volume < 0){
		printf("ERRO: raio invalido!");
		system("pause");
		return 0;
	}
	
	printf("O volume da esfera e: %.2f", volume);
	
	system("pause");
	
	return 0;
}

float calculaVolume(float r)
{
	float v;
	
	if(r < 0) {
		return -1;
	}
	
	v = ((float) 4/ (float) 3) * 3.14 * pow(r, 3);
	
	return v;
}
