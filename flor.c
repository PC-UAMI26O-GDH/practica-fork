#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TALLO 5
#define PETALOS 5
#define FLORES 3

/*
Entrada: ninguna (usa las constantes de arriba).
Salida: el número total de procesos del árbol.
Descripción: árbol de procesos en forma de flor.
*/
int main(){
    pid_t pid_raiz = getpid();
    int i, j = 0, k;

    for (i = 0; i < (TALLO - 1); i++) {
        if (fork())
            break;
    }

    if (i == (TALLO - 1)) {
        for (j = 0; j < FLORES; j++) {
            if (fork())
                break;
        }

        if (j > 0) {
            if (!fork()) {
                for (k = 0; k < PETALOS; k++) {
                    if (!fork())
                        break;
                }
            }
        }
    }

    /* TODO: aquí va tu solución.
       Pistas:
       - Cada proceso del tallo debe crear DOS hijos: el siguiente
         eslabón del tallo (salvo el último) y el centro de su
         propia flor.
       - El centro de una flor crea PETALOS hijos, y esos sí son hojas
         (no crean a nadie).
       - Cada proceso que no sea hoja debe hacer wait() de cada uno de sus
         hijos y sumar lo que le devuelven con exit(), igual que en el
         Ejercicio 1.
       - Solo el proceso raíz (getpid() == pid_raiz) imprime el total final.*/

    return 0;
}
