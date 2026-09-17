#define _POSIX_C_SOURCE 202405L

#include <fcntl.h>
#include <iostream>
#include <sys/mman.h>
#include <unistd.h>

using namespace std;

/* Função para imprimir mensagem de erro */
void erro(string comando)
{
    string msg = comando + " falhou";
    perror(msg.c_str());
    exit(EXIT_FAILURE);
}

/* Função para criar memória compartilhada */
/* Argumentos: nome da memória compartilhada e tamanho */
int criaMemComp(const char* memoria)
{
    int id = shm_open(memoria, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (id == -1) {
        erro("shm_open");
    }
    return id;
}

/* Função para mapear memória compartilhada */
/* Argumentos: ID da memória compartilhada e tamanho */
void* mapeiaMemComp(int id, int size)
{
    void* ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, id, 0);
    if (ptr == MAP_FAILED) {
        erro("mmap");
    }
    return ptr;
}

/* Função para desmapear memória compartilhada */
/* Argumentos: ponteiro para a memória mapeada e tamanho */
void desmapeiaMemComp(void* ptr, int size)
{
    if (munmap(ptr, size) == -1) {
        erro("munmap");
    }
}

/* Função para apagar memória compartilhada */
/* Argumentos: nome da memória compartilhada */
void apagaMemComp(const char* memoria)
{
    if (shm_unlink(memoria) == -1) {
        erro("shm_unlink");
    }
}

int main()
{

    const int TAM = 64;

    // Cria a memória compartilhada

    // Mapear a memória compartilhada

    // Ler a memória compartilhada

    // Desmapear a memória compartilhada

    // Apagar a memória compartilhada

    return 0;
}