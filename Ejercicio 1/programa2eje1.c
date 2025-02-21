#include <stdio.h>
#include <unistd.h>

int main() {
    int i;
    printf("Padre Proceso: PID = %d\n", getpid());

    for (i = 0; i < 4; i++) {
        fork();
        printf("Iteración en proceso %d: PID = %d, PPID = %d\n", i, getpid(), getppid());
    }

    return 0;
}
