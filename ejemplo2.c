#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N 4

/*
Entrada: Ninguna (usa la constante N)
Salida: Traza de ejecucion y conteo acumulado
Descripcion: Creacion lineal de procesos
*/

int main() {
    int i, status = 0;
    pid_t pid, pid_raiz;

    pid_raiz = getpid();

    for (i = 0; i < N; i++) {
        if ((pid = fork()) == 0) {
            printf("Soy el proceso hijo: %d y mi padre es %d \n", 
                getpid(), getppid());
        } else {
            if (pid == -1) {
                printf("Error en la creacion del proceso \n");
                exit(1);
            } else {
                printf("Soy el proceso padre: %d \n", getpid());
                wait(&status);
                if (pid_raiz == getpid()) {
                    printf("El numero de procesos que somos es: %d \n", 
                        WEXITSTATUS(status) + 1);
                    exit(0);
                } else {
                    exit(WEXITSTATUS(status) + 1);
                }
            }
        }
    }
    sleep(15);
    return 1;
}
