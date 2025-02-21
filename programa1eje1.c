#include <stdio.h>   // Librería estándar de entrada/salida
#include <unistd.h>  // Necesaria para usar fork()

int main() {
    printf("Padre proceso: PID = %d\n", getpid());

    // Cada fork crea nuevos procesos
    fork();
    fork();
    fork();
    fork();

    // Mensaje que imprimirá cada proceso
    printf("Creado nuevo proceso PID = %d, Padre: PPID = %d\n", getpid(), getppid());

    return 0;  // El programa termina
}
