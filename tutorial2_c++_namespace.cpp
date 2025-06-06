# include <iostream>

namespace primero {
    int x = 1;
}

namespace segundo {
    int x = 2;
}

int main() {

    // using namespace std;

    using std::cout; // Esto es preferible de usar, ya que namespace puede confundir nuestro los datos de nuestro proyectos y no siempre es de buenas practicas.
    using std::string;

    string nombre = "Jesus Kamel";

    cout<<nombre<<std::endl;

    cout<<"X = "<<primero::x <<std::endl; // '::' se les conoce como el "operador de resolucion de ambitos".

    cout<<"X = "<<segundo::x <<std::endl;
    
    return 0;
}