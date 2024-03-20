#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestorDeTarefas.h"

node *createNewTask(node *list, int priority, char *id)
{

  if ((priority < 0) || (priority > 5))
  {
    printf("\nNível de prioridade inválida\n");
    return list;
  }
  else
  {

    if (searchID(list,id) == 1)
    {
      return list;
    }
    else
    {
      node *newNode = malloc(sizeof(node));
      newNode->priority = priority;
      newNode->id = malloc(strlen(id) + 1);
      strcpy(newNode->id, id);

      if (list == NULL)
      {
        newNode->next = NULL;
        return newNode;
      }
      else
      {
        node *aux = list;

        while (aux->next != NULL)
        {
          aux = aux->next;
        }

        aux->next = newNode;
        return newNode;
      }
    }
  }
}

void listTasks(node *list, int priority)
{

  if (list == NULL)
  {
    printf("\nAinda não existem tarefas\n");
  }
  else
  {
    node *aux = list;

    printf("\n__________Tarefas__________\n");

    while (aux != NULL)
    {
      if (aux->priority == priority)
      {

        printf("ID: %s\n", aux->id);
        printf("Prioridade: %d\n", aux->priority);
        aux = aux->next;
        printf("\n");
      }
    }
  }
}

int searchID(node *list, char *id)
{

  if (list == NULL)
  {
    printf("\nAinda não existem tarefas\n");
  }
  else
  {

    node *aux = list;

    while (aux != NULL)
    {

      if (strcmp(aux->id, id) == 0)
      {
        printf("\nTarefa com o mesmo ID encontrado\n");
        return 1;
      }

      aux = aux->next;
    }

    printf("\nID de tarefa válido\n");
    return 0;
  }
}

node *removeTask(node *list, char *id)
{

  if (list == NULL)
  {
    printf("\nAinda não existem tarefas\n");
    return list;
  }

  if (searchID(list,id) == 1)
  {
    node *current = list;
    node *previous = NULL;

    if (strcmp(current->id, id) == 0)
    {
      list = current->next;
      free(current);
      return list;
    }

    for (current = current->next; current != NULL; previous = current, current = current->next)
    {
      if (strcmp(current->id, id) == 0)
      {
        previous->next = current->next;
        free(current);
        return list;
      }
    }
  }
}