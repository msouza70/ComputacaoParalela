#define _POSIX_C_SOURCE 202405L

#include <semaphore.h>
#include <stdio.h>
#include <string>

using namespace std;

const int TAM = 10; /* tamanho da fila circular */
int totalP = 1000; /* total de itens a serem produzidos  */
int totalC = 1000; /* total de itens a serem consumidos */

sem_t mutex;
sem_t vazio;
sem_t cheio;

/* Função para imprimir mensagem de erro */
void erro(string comando)
{
    string msg = comando + "falhou";
    perror(msg.c_str());
    exit(EXIT_FAILURE);
}

int produzItem()
{
    int item = rand() % 100; // Gera um número aleatório entre 0 e 99
    printf("Produzindo %dº item: %d\n", totalP, item);
    return item;
}

void consomeItem(int item)
{
    printf("Consumindo %dº item: %d\n", totalC, item);
}

/* Função para criar os semaforos */
void criaSemaforos()
{
    if (sem_init(&mutex, 0, 1) == -1)
        erro("sem_init");
    if (sem_init(&cheio, 0, 0) == -1)
        erro("sem_init");
    if (sem_init(&vazio, 0, TAM) == -1)
        erro("sem_init");
}

/* Função para apagar os semaforos apos o uso */
void apagaSemaforos()
{
    if (sem_destroy(&mutex) == -1)
        erro("sem_destroy");
    if (sem_destroy(&cheio) == -1)
        erro("sem_destroy");
    if (sem_destroy(&vazio) == -1)
        erro("sem_destroy");
}

int main()
{
}
