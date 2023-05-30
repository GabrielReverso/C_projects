#include "List.h"
#include <stdlib.h>
#include <stdio.h>

#define ERRO -100000   // Index não existente
#define ERRO_2 -100001 // Erro de alocação de memória

/*Definição da struct list*/
struct list
{
    int *array;
    int size;
    int lenght;
};

/*Função que recebe endereço de uma lista que foi criada na memória heap*/
List *list_create()
{
    List *list = (List *)malloc(sizeof(List));    // Reserva um espaço da memória para lista
    list->lenght = 0;                             // Define que a lista não está preenchida
    list->size = 5;                               // Define tamanho máximo da lista
    list->array = (int *)malloc(5 * sizeof(int)); // Reserva um espaço da memória para o array
    return list;
}

/*Função que libera a lista da memória*/
void list_free(List *list)
{
    free(list->array);
    free(list);
}

/*Função que imprime os valores da lista*/
void list_display(List *list)
{
    int i;
    for (i = 0; i < list->lenght; i++)
    {
        printf("%d", list->array[i]);

        if (i != list->lenght - 1) // Se não for o último valor, adiciona uma vírgula
        {
            printf(", ");
        }
        else
        {
            printf("\n");
        }
    }
}

/*Função que adiciona os valores na lista*/
void list_add(List *list, int value)
{
    if (list->lenght >= list->size) // Se o comprimento do array for menor ou igual que o tamanho da lista
    {
        list->size *= 2;                                                     // Multiplica o size atual por 2
        list->array = (int *)realloc(list->array, list->size * sizeof(int)); // Realoca o array antigo para um novo espaço de memória com o novo size

        // printf("\nTamanho novo = %d\n", list->size); //Teste

        if (list->array == NULL) // Se o realloc falhar -> mensagem de erro
        {
            printf("Erro na alocação de memória");
            return;
        }
    }
    list->array[list->lenght] = value; // Adiciona o valor na lista
    list->lenght++;                    // Aumenta comprimento do array
}

/*Função que remove um valor da lista*/
int list_remove(List *list, int index)
{
    int aux; // Variável auxiliar

    if (index > list->lenght || index < 0) // Se o index for maior que o comprimento do array -> mensagem de erro
    {
        printf("Index não existente");
        return ERRO;
    }

    if (list->lenght <= (list->size / 2)) // Se o comprimento for menor ou igual a metade do tamanho da lista
    {
        list->size /= 2;                                                     // Define o size pela metade
        list->array = (int *)realloc(list->array, list->size * sizeof(int)); // Realoca o array antigo para um novo espaço de memória com o novo size

        // printf("\nTamanho novo = %d\n", list->size); //Teste

        if (list->array == NULL) // Se o realloc falhar -> mensagem de erro
        {
            printf("Erro na alocação de memória");
            return ERRO_2;
        }
    }

    aux = list->array[index]; // Auxiliar recebe a variável que vai ser apagada

    for (int i = index; i < list->lenght; i++) // Joga os itens da frente para o index anterior
    {
        list->array[i] = list->array[i + 1];
    }

    list->lenght--; // Diminui o comprimento do array

    // printf("\nTamanho = %d\n", list->size); //Teste

    return aux; // Retorna o auxiliar
}

/*Função que substitui um valor em determinada posição*/
void list_set(List *list, int index, int value)
{
    if (index < 0 || index > list->lenght)
        return;                 // Se index não existe, retorna
    list->array[index] = value; // Substitui valor
}

void list_insert(List *list, int index, int value)
{
    int aux;

    if (index < 0 || index > list->lenght)
        return;                     // Se index não existe, retorna
    if (list->lenght >= list->size) // Se o comprimento do array for menor ou igual que o tamanho da lista
    {
        list->size *= 2;                                                     // Multiplica o size atual por 2
        list->array = (int *)realloc(list->array, list->size * sizeof(int)); // Realoca o array antigo para um novo espaço de memória com o novo size

        // printf("\nTamanho novo = %d\n", list->size); //Teste

        if (list->array == NULL) // Se o realloc falhar -> mensagem de erro
        {
            printf("Erro na alocação de memória");
            return;
        }
    }

    for (int i = list->lenght + 1; i >= index; i--) // Percorre do ultimo valor até o index desejado fazendo swift dos valores
    {
        list->array[i] = list->array[i - 1];
    }

    list->array[index] = value; // Copia o valor no index
    list->lenght++;             // Aunmenta comprimento do array
}

//SORTING AUX
void merge_sorted_arrays(int array[], int left, int middle, int right)
{
    int left_length = middle - left + 1;
    int right_length = right - middle;

    int temp_array_left[left_length];
    int temp_array_right[right_length];

    int i, j, k;

    for (int i = 0; i < left_length; i++)
    {
        temp_array_left[i] = array[left + i];
    }

    for (int i =0; i< right_length; i++) 
    {
        temp_array_right[i] = array[middle + 1 + i];
    }
    
    for (i = 0, j = 0, k = left; k <= right; k++)
    {
        if ((i < left_length) && (j >= right_length || temp_array_left[i] <= temp_array_right[j])) 
        {
            array[k] = temp_array_left[i];
            i++;
        }
        else 
        {
            array[k] = temp_array_right[j];
            j++;
        }
    }
}

void merge_sort_recursion(int array[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        merge_sort_recursion(array, left, middle);
        merge_sort_recursion(array, middle + 1, right);

        merge_sorted_arrays(array, left, middle, right);
    }
}

//MAIN SORT
void list_merge_sort(List *list)
{
    merge_sort_recursion(list->array, 0, list->lenght - 1);
}