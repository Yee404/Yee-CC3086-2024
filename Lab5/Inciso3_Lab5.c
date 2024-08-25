#include <stdio.h>
#include <omp.h>

#define serieFibonacci 10
#define numeroFactorial 5
#define sizeArray 10

//Función1
void calcularFactorial(int numero) {
    long long factorial = 1;
    for (int i = 1; i <= numero; i++) {
        factorial *= i;
    }
    printf("\nFuncion1 | Calcular Factorial\n");
    printf("El factorial del número %d es: %lld\n\n", numero, factorial);
}

//Función 2
void generarFibonacci(int numero) {
    long long fib[serieFibonacci];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < numero; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    printf("\nFuncion2 | Generar Serie Fibonacci\n");
    printf("Serie de Fibonacci hasta número %d: ", numero);
    for (int i = 0; i < numero; i++) {
        printf("%5d, ", fib[i]);
    }

}

// Función 3
void maxArreglo(int arr[], int tamanno) {
    int maximo = arr[0];
    for (int i = 1; i < tamanno; i++) {
        if (arr[i] > maximo) {
            maximo = arr[i];
        }
    }
    printf("\nFunción3 | Máximo del array");
    printf("\nValor máximo en el arreglo es: %d\n", maximo);
}

int main() {
    int array[sizeArray] = {12, 45, 67, 89, 34, 23, 78, 56, 90, 11};

    // Ejecución en paralelo de las 3 funciones
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            calcularFactorial(numeroFactorial);
        }

        #pragma omp section
        {
            generarFibonacci(serieFibonacci);
        }

        #pragma omp section
        {
            maxArreglo(array, sizeArray);
        }
    }

    return 0;
}
