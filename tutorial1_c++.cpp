#include <iostream> // Este import nos permite tanto escrbir en la terminal(consola), como pedirle al usuario que escriba en esta misma tambien.

// "" son para strings.
// '' es para charts (un solo string o letra).


int main() {
    std::cout<<"Hola Mundo" <<std::endl; // Tambien se puede poner '\n' en vez de 'endl'
    std::cout<<"Me gusta a pizza" <<'\n';

// Variables:

    /*
    int x; // Esto es la declaracion (declarar en si la variable).
    x = 5; // Esto es una asignacion (asignar un valor a la variable).
    */

    // Enteros:
    int x = 5; // Declaracion y asignacion en un paso.
    std::cout<<x <<std::endl;
    
    int y = 6;
    std::cout<<y <<std::endl;

    int suma = x + y;
    std::cout<<suma <<std::endl;

    int edad = 20;
    int anho = 2025;
    int dias = 24.7;  // Va a devolver el numero 24 sin los decimales

    // Visual Studio Code solo usa cuatro decimales, redondeando el ultimo.
    // Double: Usa 64 bits, puede almacenar hasta 15 digitos. Tambien existe el "long double".
    double precio = 10.99;
    
    double promedio = 2.5;
    std::cout<<promedio <<std::endl;

    double temperatura = 25.1334887;
    std::cout<<temperatura;
    std::cout<<" Grados" <<std::endl;

    // Float: Usa 32 bit, lo que le permite almacenar cerca de 7 decimales.
    float precio_con_decimales = 33.689078;
    std::cout<<precio_con_decimales <<std::endl;

    //Char: Solo acepta un caracter.
    char calificacion = 'A';
    std::cout<<calificacion <<std::endl;

    /*
    char nombre = 'Sinergia'; // No va a imprimir la primera letra, solo puedes escribir un caracter.
    */

    // Bool (Booleano):
    bool estudiante = true; // En C++, el True y el False van en mayuscula.
    std::cout<<estudiante <<std::endl; // Imprime 1 si es true y 0 si es false.

    // String: Secuencia de texto
    std::string nombre = "Jesus"; // Solo comillas dobles.
    std::cout<<nombre <<std::endl;

    std::cout<<"Hola "<<nombre <<std::endl;

    
    
    // Const: Especifica que el valor de un varible es constante.

    const double PI = 3.14159; // Esta variable no puede ser modificada a lo largo del programa. Tambien, la variable debe estar todo en mayusculas por buenas practicas.
    double radio = 10;
    double circunferencia = 2 * PI * radio;
    std::cout<<circunferencia<<" centimetros" <<std::endl;

    const int velocidad_de_luz = 2999792458;

    // Resolucion de pantallas ejemplo:
    const int ancho = 1920;
    const int alto = 1080;

    return 0;
}