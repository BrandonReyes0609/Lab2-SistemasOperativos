#include <stdio.h>
#include <time.h>

int main() {
    clock_t inicio, fin;
    double tiempo_total;

    inicio = clock();

    for (long i = 0; i < 1000000; i++) {
        if (i % 200000 == 0) { // Solo imprimir algunos valores para no saturar la terminal
            printf("Iteración %ld\n", i);
        }
    }

    for (long i = 0; i < 1000000; i++) {
        if (i % 200000 == 0) {
            printf("Iteración %ld\n", i);
        }
    }

    for (long i = 0; i < 1000000; i++) {
        if (i % 200000 == 0) {
            printf("Iteración %ld\n", i);
        }
    }

    fin = clock();
    tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución: %f segundos\n", tiempo_total);

    return 0;
}
