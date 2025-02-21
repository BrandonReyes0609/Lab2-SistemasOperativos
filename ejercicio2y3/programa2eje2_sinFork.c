#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    clock_t inicio, fin;
    double tiempo_total;
    pid_t pid1, pid2, pid3;

    inicio = clock();

    pid1 = fork();

    if (pid1 == 0) {  // Proceso hijo
        pid2 = fork();
        
        if (pid2 == 0) {  // Proceso nieto
            pid3 = fork();
            
            if (pid3 == 0) {  // Proceso bisnieto
                for (long i = 0; i < 1000000; i++) {
                    if (i % 200000 == 0) {
                        printf("Proceso bisnieto - Iteración %ld\n", i);
                    }
                }
            } else {
                wait(NULL); 
                for (long i = 0; i < 1000000; i++) {
                    if (i % 200000 == 0) {
                        printf("Proceso nieto - Iteración %ld\n", i);
                    }
                }
            }
        } else {
            wait(NULL);  
            for (long i = 0; i < 1000000; i++) {
                if (i % 200000 == 0) {
                    printf("Proceso hijo - Iteración %ld\n", i);
                }
            }
        }
    } else {
        wait(NULL);
        fin = clock();
        tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;
        printf("Tiempo de ejecución (con procesos): %f segundos\n", tiempo_total);
    }

    return 0;
}
