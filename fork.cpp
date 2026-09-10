#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork falhou");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        cout << "Sou o processo filho!" << endl;
    } else {
        waitpid(pid, NULL, 0);
        cout << "Sou o processo pai!" << endl;
    }
    return 0;
}