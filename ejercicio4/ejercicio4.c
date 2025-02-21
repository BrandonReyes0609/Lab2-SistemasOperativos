#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();  // Crear el proceso hijo

    if (pid == 0) {  // Código del hijo
        printf("Soy el proceso hijo con PID: %d\n", getpid());
    } else {  // Código del padre
        printf("Soy el proceso padre con PID: %d\n", getpid());
        while (1);  // Ciclo infinito
    }

    return 0;
}

