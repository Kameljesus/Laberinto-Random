// Basicamente, es la transformacion de un tipo de dato, a otro.
// Ejemplo: de un dato 'int' a un dato 'float'.

#include <iostream>

int main() {

    // Existen dos formas de hacer esto:

    // Forma Implicita: Esta forma se realiza automaticamente.

    /*int x = 3.14;
    std::cout<<x<<std::endl;
    std::cout<<" "<<std::endl;   */

    // Forma Explicita: Esta forma se lleva a cabo precediendo un valor con el nuevo tipo de dato dentro de un conjunto de parentesis.
    /*double x = (int)3.14;
    std::cout<<x<<std::endl;
    std::cout<<" "<<std::endl;

    x = x + 1.5;
    std::cout<<x<<std::endl;
    std::cout<<" "<<std::endl;   */

    char x = 100;
    
    std::cout<<x<<std::endl;
    std::cout<<" "<<std::endl;

    return 0;
}