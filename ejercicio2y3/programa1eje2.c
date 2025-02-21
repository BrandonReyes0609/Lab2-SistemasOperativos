#include <stdio.h>
#include <time.h>  
#include <unistd.h>  // Necesario para fork()
#include <sys/wait.h>  // Necesario para wait()

int main() {
    clock_t start_time, end_time;
    double total_time;
    pid_t pid_hijo, pid_nieto, pid_bisnieto;

    // Iniciar medición del tiempo antes de crear procesos
    start_time = clock();

    pid_hijo = fork();  // Primer fork()

    if (pid_hijo == 0) {  // Proceso hijo
        pid_nieto = fork();  // Segundo fork()

        if (pid_nieto == 0) {  // Proceso nieto
            pid_bisnieto = fork();  // Tercer fork()

            if (pid_bisnieto == 0) {  // Proceso bisnieto
                for (long i = 0; i < 1000000; i++);
            } else {
                wait(NULL);  // El nieto espera al bisnieto
                for (long i = 0; i < 1000000; i++);
            }
        } else {
            wait(NULL);  // El hijo espera al nieto
            for (long i = 0; i < 1000000; i++);
        }
    } else {
        wait(NULL);  // El padre espera al hijo
        end_time = clock();  // Medimos el tiempo después de la ejecución de todos los procesos

        total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Tiempo de ejecución 'con procesos': %f segundos\n", total_time);
    }

    return 0;
}
