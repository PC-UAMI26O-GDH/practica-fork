#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N 3

/*
Entrada: Ninguna (usa la constante N)
Salida: El numero total de procesos del arbol
Descripcion: Arbol escalonado (triangular) de procesos
*/

int main() {
    int t, j, i, status, t1, t2;

    /* Primer for: arma la cadena principal, una fila por cada
       valor de i (0..N). Cada proceso rompe (break) justo despues
       de crear al siguiente de la cadena, y se queda con SU i fijo. */
    for (i = 0; i < N; i++) {
        if (fork())
            break;
    }

    /* Segundo for: cada proceso de la cadena principal arma,
       ADEMAS, su propia cadena de i procesos mas (j=1..i). */
    for (j = 0; j < i; j++) {
        if (fork())
            break;
    }

    if (i != 0) {
        if (i != N && j == 0) {
           /* Cabecera de fila (no la ultima): tiene DOS hijos,
	      el siguiente de la cadena principal y el primero
	      de su propia fila. Espera a ambos y suma. */
            wait(&status);
            t1 = WEXITSTATUS(status);
            wait(&status);
            t2 = WEXITSTATUS(status);
            t = t1 + t2 + 1;
            exit(t);
        } else {
            if (i == N && j == 0) {
		/* Cabecera de la ultima fila: solo tiene el
                   hijo de su propia fila (ya no hay fila N+1). */
                wait(&status);
                t = WEXITSTATUS(status);
                t++;
                exit(t);
            } else
	    if (i == j)
		/* Ultimo de su fila: no crea a nadie mas, es hoja. */
                exit(1);
            else
	    if (j >= 1) {
		/* Proceso intermedio de una fila: un solo hijo,
		   el siguiente de esa misma fila. */
                wait(&status);
                t = WEXITSTATUS(status);
                t++;
                exit(t);
            }
        }
    } else {
	/* i==0: el proceso raiz. Su unico hijo es la cabecera
           de la fila 1. */
        if (N >= 1) {
            wait(&status);
            t = WEXITSTATUS(status);
            t++;
            printf("Total %d\n", t);
        }
    }

    sleep(10);
    return 0;
}
