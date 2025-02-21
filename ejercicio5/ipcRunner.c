#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Error en fork()");
        exit(1);
    } else if (pid == 0) {  // Proceso hijo ejecutando 'ipc' con 'A'
        execl("./ipc", "ipc", "4", "A", NULL);
        perror("Error en execl");
        exit(1);
    } else {  // Proceso padre ejecutando 'ipc' con 'B'
        execl("./ipc", "ipc", "4", "B", NULL);
        perror("Error en execl");
        exit(1);
    }

    return 0;
}
