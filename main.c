#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestorDeTarefas.h"

int readLineArguments(char **argVector, int vectorSize, char *buffer, int buffersize)
{
    int numtokens = 0;
    char *s = " \r\n\t";

    int i;

    char *token;

    if (argVector == NULL || buffer == NULL || vectorSize <= 0 || buffersize <= 0)
        return 0;

    if (fgets(buffer, buffersize, stdin) == NULL)
    {
        return -1;
    }

    /* get the first token */
    token = strtok(buffer, s);

    /* walk through other tokens */
    while (numtokens <= vectorSize - 1 && token != NULL)
    {
        argVector[numtokens] = token;
        numtokens++;

        token = strtok(NULL, s);
    }

    for (i = numtokens; i < vectorSize; i++)
    {
        argVector[i] = NULL;
    }

    return numtokens;
}

void main()
{

    int decision = 0;
    char *arguments[3];
    char buffer[256];
    int priority;

    node *taskManager;

    do
    {
        printf("\n__________MENU__________\n");
        printf("1-Adicionar tarefa\n");
        printf("2-Listar tarefas\n");
        printf("3-Remover tarefa\n");
        printf("4-Sair\n");

        scanf("%d", &decision);
        getchar();

        switch (decision)
        {
        case 1:
            printf("Insira o comando 'new' seguido do número da prioridade e por fim o id da nova tarefa\n");

            if (readLineArguments(arguments, 3, buffer, sizeof(buffer)) >= 2)
            {
                if ((strcmp(arguments[0], "new")) != 0)
                {
                    printf("Erro na escrita do comando 'new'\n");
                }
                else
                {
                    priority = atoi(arguments[1]);
                    taskManager = createNewTask(taskManager, priority, arguments[2]);
                    printf("Inserido com sucesso\n");
                }
            }
            else
            {
                printf("Comando inválido\n");
            }

            break;

        case 2:
            printf("Insira o comando 'list' seguido do número da prioridade\n");

            if (readLineArguments(arguments, 2, buffer, sizeof(buffer)) >= 1)
            {
                if ((strcmp(arguments[0], "list")) != 0)
                {
                    printf("Erro na escrita do comando 'list'\n");
                }
                else
                {
                    priority = atoi(arguments[1]);
                    listTasks(taskManager,priority);    
                }
            }
            else
            {
                printf("Comando inválido\n");
            }

            break;

        case 3:

            printf("Insira o comando 'complete' seguido do id da tarefa\n");

            if (readLineArguments(arguments, 2, buffer, sizeof(buffer)) >= 1)
            {
                if ((strcmp(arguments[0], "complete")) != 0)
                {
                    printf("Erro na escrita do comando 'complete'\n");
                }
                else
                {
                    taskManager = removeTask(taskManager,arguments[1]);
                    printf("Removida com sucesso");
                }
            }
            else
            {
                printf("Comando inválido\n");
            }

            break;

        case 4:
        printf("Adeus\n");
            break;

        default:
        printf("Opção inválida");
            break;
        }

    } while (decision != 4);
}