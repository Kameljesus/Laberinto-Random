// Que es typedef?:

// Es una palabra clave reservada utilizada para crear un nombre adicional para otro tipo de datos. Algo asi como un apodo.
// La gente la suele utilizar porque ayuda con la legibilidad y reduce los errores tipo grafico.

#include <iostream>
#include <vector>

// typedef std::vector<std::pair<std::string, int>> pair_list_t; 
// Eso puede ser un tipo de dato para una lista de pares (obviamente, todavia no se que es eso).
// El typedef lo que hace, es que en vez de escribir tooooodo ese dato, le asignes un apodo.

// Ejemplo mas simple:
// typedef std::string text_t;
// typedef int numero_t;

// La palabra 'typedef' es la mayoria de veces reemplazada por using, ya que esta ultima funciona mejor con plantillas.
// Entonces es recomendable usar la palabra clave using

using text_t = std::string;
using numero_t = int;

int main() {

    // pair_list_t pair_list;
    // std::vector<std::pair<std::string, int>> en vez anotar todo esto, simplemente anotamos lo de arriba

    text_t nombre = "Jesus";
    std::cout<<nombre<<std::endl;

    numero_t edad = 20;
    std::cout<<edad<<std::endl;

    return 0;
}