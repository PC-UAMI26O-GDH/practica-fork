# Practica: Arbol de Procesos

Este repositorio contiene la implementación en lenguaje C para la creación, manipulación y sincronización de procesos en Linux mediante las llamadas al sistema `fork()`, `wait()` y `exit()`.

El proyecto abarca desde la creación de estructuras lineales simples hasta árboles de procesos ramificados con recolección de estados, los cuales son Escalonado y Flor.

---

## Estructura del Repositorio

* **`ejemplo1.c`**: Creación básica de un proceso padre e hijo utilizando `switch(fork())`. Muestra la diferenciación de ejecución y PIDs en terminal.
* **`ejemplo2.c`**: Cadena lineal de $N$ procesos ($N=4$). Los procesos comunican su estado de salida de abajo hacia arriba con `wait()` y `exit()` para retornar el total de la línea.
* **`escalonado.c`**: Construcción de un árbol de procesos en forma escalonada/triangular. Genera un total de $\frac{(N + 1)(N + 2)}{2}$ procesos en la jerarquía.
* **`flor.c`**: Estructura ramificada compleja dividida en tres secciones:
  * **Tallo (`TALLO = 5`)**: Cadena de procesos base.
  * **Flores (`FLORES = 3`)**: Subcadena de centros de flor generada al final del tallo.
  * **Pétalos (`PETALOS = 5`)**: Procesos hoja asociados a cada centro de flor.

---

## Compilar y ejecutar

Para compilar cualquiera de los programas en un entorno Linux con `gcc`:

```bash
# Compilar los programas
gcc ejemplo1.c -o ejemplo1
gcc ejemplo2.c -o ejemplo2
gcc escalonado.c -o escalonado
gcc flor.c -o flor

# Ejecutar el programa principal
./flor
