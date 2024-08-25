#include <stdio.h>
#include <omp.h>

int main() {
    //Variable1 = compartida  ;  Variable2 = privada
    int variable1 = 0;
    int variable2;

    // Modificar variable1 con "shared"
    printf("variable1 modificada con 'shared':\n");
    #pragma omp parallel for shared(variable1)
    for (int i = 0; i < 10; i++) {
        variable1 += i;
    }
    printf("variable1 ya modificada con 'shared': %d\n\n", variable1);

    // Reinicio variable1
    variable1 = 0;

    // Modificar variable2 con clausula private
    printf("variable2 modificada con 'private'\n");
    #pragma omp parallel for private(variable2)
    for (int i = 0; i < 10; i++) {
        // Cada hilo con copia propie de variable2
        variable2 = i;
    }

    printf("variable2 sin modificar: %d\n", variable2);
    
    return 0;
}