#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define SHM_NAME "/mi_memoria"
#define SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <número> <carácter>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    char x = argv[2][0];

    int fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, SIZE);
    char *shm_ptr = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (shm_ptr == MAP_FAILED) {
        perror("Error al mapear la memoria");
        return 1;
    }

    printf("Memoria compartida inicializada\n");

    // **Pausa para asegurar que la otra instancia tenga tiempo de conectarse**
    usleep(500000);  // 0.5 segundos

    pid_t pid = fork();

    if (pid == 0) {  // Proceso hijo
        printf("Proceso hijo esperando escritura...\n");
        for (int i = 0; i < n; i++) {
            if (shm_ptr[i] != 0) {
                printf("%c", shm_ptr[i]);  
                fflush(stdout);
            }
            usleep(10000); // Pequeña pausa para evitar sobrecarga
        }
        printf("\nProceso hijo finalizado\n");
    } else {  // Proceso padre
        printf("Proceso padre escribiendo en memoria compartida\n");
        for (int i = 0; i < n; i++) {
            shm_ptr[i] = x;
            usleep(100000);  // Pequeña pausa para evitar que el hijo lea datos incompletos
        }
        printf("Contenido de la memoria compartida:\n%s\n", shm_ptr);
    }

    munmap(shm_ptr, SIZE);
    shm_unlink(SHM_NAME);
    return 0;
}
