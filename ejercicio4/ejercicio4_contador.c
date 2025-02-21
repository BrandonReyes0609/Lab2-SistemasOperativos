#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {  // Proceso hijo
        for (long i = 1; i <= 4000000; i++) {
            if (i % 1000000 == 0) {  // Imprimir cada millón de iteraciones
                printf("Proceso hijo - Contando: %ld\n", i);
            }
        }
        printf("Proceso hijo finalizado\n");
    } else {  // Proceso padre
        printf("Soy el proceso padre con PID: %d\n", getpid());
        while (1);  // Bucle infinito
    }

    return 0;
}
