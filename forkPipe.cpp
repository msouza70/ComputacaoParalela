#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

/* Função para imprimir mensagem de erro */
void erro(string comando)
{
    string msg = comando + " falhou";
    perror(msg.c_str());
    exit(EXIT_FAILURE);
}

int main()
{
    pid_t pid;
    int fd[2];
    char dado[10];

    if (pipe(fd) < 0) {
        erro("pipe");
    }
    pid = fork();

    if (pid < 0) {
        erro("fork");
    }

    if (pid == 0) {
        cout << "Sou o processo filho!" << endl;
        close(fd[0]);
        write(fd[1], "Marcio\n", 8);
    } else {
        close(fd[1]);
        read(fd[0], dado, 8);
        waitpid(pid, NULL, 0);
        cout << "Sou o processo pai!" << endl;
        cout << "Recebi: " << dado << endl;
    }
    return 0;
}