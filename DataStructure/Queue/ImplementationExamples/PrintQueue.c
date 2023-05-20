#include "../Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define size 5

int main()
{
    char menu[3][15] = {"Sair", "Enfileirar", "Imprimir"};
    int option, num;
    bool exit = false;
    Queue *queue = queue_create(size);

    do
    {
        printf("----------MENU----------\n");
        for (int i = 0; i < 3; i++)
        {
            printf("%d - %s\n", i, menu[i]);
        }
        printf("\nSelecione uma opcao: ");
        scanf("%d", &option);
        system("cls");

        switch (option)
        {
        case 0:
            printf("Saindo!\n");
            system("pause");
            exit = true;
            break;
        case 1:
            printf("Digite o numero que deseja enfileirar: ");
            scanf("%d", &num);
            queue_enqueue(queue, num);
            system("cls");
            printf("Numero enfileirado: %d\n", num);
            system("pause");
            break;
        case 2:
            printf("Numero retirado: %d\n", queue_dequeue(queue));
            system("pause");
            break;
        default:
            printf("Opcao invalida!\n");
            system("pause");
            break;
        }

        system("cls");
    } while (!exit);

    queue_free(queue);
    return 0;
}