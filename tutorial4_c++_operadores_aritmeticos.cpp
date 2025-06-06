// Que son los operadores aritmeticos?:

// Su funcion consiste en devolver el resultado de una operacion aritmetica especifica. 

#include <iostream>

int main() {

    int estudiantes = 20;

    // Suma:
    // estudiantes = estudiantes + 2;
    // estudiantes += 2; // Es lo mismo de arriba, pero mas corto.
    estudiantes++; 
    std::cout<<estudiantes<<std::endl; 
    std::cout<<" "<<std::endl;

    // Resta:
    // estudiantes = estudiantes - 2;
    // estudiantes -= 2;
    estudiantes--;
    std::cout<<estudiantes<<std::endl;
    std::cout<<" "<<std::endl;

    // Multiplicacion:
    // estudiantes = estudiantes * 2;
    estudiantes *= 2;
    std::cout<<estudiantes<<std::endl;
    std::cout<<" "<<std::endl;

    // Division:
    // estudiantes = estudiantes / 3;
    estudiantes /= 3; // Como 'estudiantes' es un 'int' va a redondear los enteros.
    std::cout<<estudiantes<<std::endl; 
    std::cout<<" "<<std::endl;

    // Modulo (%):
    int resto = estudiantes % 2;
    std::cout<<resto<<std::endl;
    std::cout<<" "<<std::endl;

    

    /* Estos operadores aritmeticos tienen un orden de preescedencia, 
    esto quiere decir que cuando resolvamos cualquier operacion aritmetica se resolvera en este orden:

    1. Dentro de parentesis.
    2. Multiplicacion y division. 
    3. Suma y la resta.

    */

    // Ejemplo:

    int calculo = 6 - (5 + 4) * 3 / 2;
    std::cout<<calculo<<std::endl;
    std::cout<<" "<<std::endl;

    return 0;
}