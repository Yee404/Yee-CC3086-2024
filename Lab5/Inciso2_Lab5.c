#include <stdio.h>
#include <omp.h>

#define N 10000000

int main() {
    int suma = 0;
    double inicioTiempo, finTiempo;

    inicioTiempo = omp_get_wtime();

    #pragma omp parallel
    for (int i = 1; i <= N; i++){
        suma += i;
    }

    finTiempo = omp_get_wtime();

    printf("Resultado de la suma: %d", suma);
    printf("\nTiempo inicio: %d\nTiempo final: %d", inicioTiempo, finTiempo);
    printf("\nTiempo duración de la ejecución: %.8f", finTiempo - inicioTiempo);

    return 0;

}