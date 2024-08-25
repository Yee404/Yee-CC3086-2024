#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 131072
#define Umbral 1024

long count_key_recursive(long inicio, long fin, long *a, long key) {
    long contador = 0;
    
    // Base: rango pequeño, contar secuencialmente
    if (fin - inicio < Umbral) {
        for (long i = inicio; i < fin; i++) {
            if (a[i] == key) contador++;
        }
    } else {
        // Recursivo: dividir rango, crear tareas
        long medio = (inicio + fin) / 2;

        #pragma omp task shared(contador)
        {
            contador += count_key_recursive(inicio, medio, a, key);
        }
        
        #pragma omp task shared(contador)
        {
            contador += count_key_recursive(medio, fin, a, key);
        }
        
        #pragma omp taskwait
    }

    return contador;
}


int main() {
    long a[N], key = 42, nkey = 0;

    for (long i = 0; i < N; i++) a[i] = rand() % N;
    a[N % 43] = key; 
    a[N % 73] = key; 
    a[N % 3] = key;

    #pragma omp parallel
    {
        #pragma omp single
        {
            nkey = count_key_recursive(0, N, a, key);
        }
    }

    printf("Número de veces que 'key' aparece paralelamente: %ld\n", nkey);
    return 0;
}