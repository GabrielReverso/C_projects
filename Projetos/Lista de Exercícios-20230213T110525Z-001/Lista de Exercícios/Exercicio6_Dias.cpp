/*
	Exercicio 6

	Recebe idade em anos, meses e dias e retorna em dias
*/

#include<stdio.h>
#include<stdlib.h>

int converteDias (int, int, int);

int main()
{
	int resultado, anos, meses, dias;
	
	printf("Digite a idade em anos, meses e dias: \n"
			"Considere 1 mes = 30 dias\n");
			
	scanf("%i%i%i", &anos, &meses, &dias);
	
	resultado = converteDias(anos, meses, dias);
	
	if(resultado < 0)
	{
		printf("ERRO: Impossivel calcular!\n\n");
		system("pause");
		return 0;
	}
	
	printf("\nResultado: %i dias\n\n", resultado);
	
	system("pause");
	return 0;
}

int converteDias (int a, int m, int d)
{
	int diasTotal = 0;
	
	if(a < 0 || m < 0 || d < 0 || m > 12 || d > 30)
	{
		return -1;
	}
	
	diasTotal = a * 12 * 30;
	diasTotal += m * 30;
	diasTotal += d;
	
	return diasTotal;
}