#define _POSIX_C_SOURCE 202405L

#include <fcntl.h>
#include <iostream>
#include <semaphore.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

#define produzItem()
#define consomeItem()

const int TAM = 10; /* Tamanho do buffer */
int total = 1000; /* Total de itens produzidos */

sem_t* mutex;
sem_t* vazio;
sem_t* cheio;

/* Função para imprimir mensagem de erro */
void erro(string comando)
{
    string msg = comando + "falhou";
    perror(msg.c_str());
    exit(EXIT_FAILURE);
}

void produtor()
{
    // Complementar o código do produtor
}

void consumidor()
{
    // Complementar o código do consumidor
}

/* Este procedimento cria uma estrutura de semaforos que contera os 3 que serao
   necessarios, mutex, vazio e cheio */

void criaSemaforo()
{
    mutex = sem_open("/mutex", O_CREAT, S_IRWXU, 1);
    cheio = sem_open("/cheio", O_CREAT, S_IRWXU, 0);
    vazio = sem_open("/vazio", O_CREAT, S_IRWXU, TAM);

    if (mutex == SEM_FAILED || cheio == SEM_FAILED || vazio == SEM_FAILED) {
        erro("sem_open");
    }
}

// Fechar os semaforos apos o uso
void fechaSemaforos()
{
    if (sem_close(mutex) == -1) {
        erro("sem_close mutex");
    }
    if (sem_close(cheio) == -1) {
        erro("sem_close cheio");
    }
    if (sem_close(vazio) == -1) {
        erro("sem_close vazio");
    }
}

// Apagar os semaforos apos o uso
void apagaSemaforos()
{
    if (sem_unlink("/mutex") == -1) {
        erro("sem_unlink mutex");
    }
    if (sem_unlink("/cheio") == -1) {
        erro("sem_unlink cheio");
    }
    if (sem_unlink("/vazio") == -1) {
        erro("sem_unlink vazio");
    }
}

int main()
{
    pid_t pid; /* pid do processo filho */
    criaSemaforo();
    pid = fork();

    if (pid < 0) {
        erro("fork");
    }
    if (pid == 0)
        consumidor();
    else {
        produtor();
    }
    fechaSemaforos();
    if (pid > 0) {
        waitpid(pid, NULL, 0);
        apagaSemaforos();
    }
    return 0;
}