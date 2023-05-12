/* 
	Exercicio 4

	Recebe elementos de baskara e retorna raizes
	
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <stdbool.h>

struct baskara {
    float raiz1, raiz2;
    bool flag = false;
};

typedef struct baskara Struct;

Struct calcularBaskara(float, float, float);

int main()
{
    float a, b, c;
    Struct result;
 
    printf("Digite os valores a, b, c da funcao: \n");
    scanf("%f, %f, %f", &a, &b, &c);
    
    result = calcularBaskara(a, b, c);
    
    if(result.flag){
    	printf("ERRO: impossivel calcular raizes!\n\n");
    	system("pause");     
    	return 0;
	}
    
    printf("\nAs raizes sao: "
		   "%.2f e %.2f\n\n",
           result.raiz1, result.raiz2);
      
	system("pause");     
    return 0;
}

Struct calcularBaskara(float a, float b, float c)
{
	Struct r;
	   		
	if(a != 0) {
		
		float raizDelta, delta;
		
		delta = (pow(b, 2) - (4*a*c));
			
		if(delta >= 0) {
			
			raizDelta = sqrt(delta);
			
			r.raiz1 = (-b - raizDelta) / (2*a);
			r.raiz2 = (-b + raizDelta) / (2*a);	
			
			return r;
		}
	    else {
	    	r.flag = true;
			return r;	
		}
	}
	else {
		r.flag = true;
		return r;
	}
}