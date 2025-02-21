#include <stdio.h>
#include <time.h>  // Librería necesaria para medir el tiempo

int main() {
    clock_t start_time, end_time;  // Variables para medir el tiempo
    double total_time;  // Variable para almacenar el tiempo total en segundos

    // Iniciar la medición del tiempo
    start_time = clock();

    // Tres ciclos for de 1 millón de iteraciones cada uno
    for (long i = 0; i < 1000000; i++);
    for (long i = 0; i < 1000000; i++);
    for (long i = 0; i < 1000000; i++);

    // Finalizar la medición del tiempo
    end_time = clock();

    // Calcular el tiempo total en segundos
    total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Mostrar el tiempo de ejecución
    printf("Tiempo de ejecución: %f segundos\n", total_time);

    return 0;
}
