# include <iostream>

namespace primero {
    int x = 1;
}

namespace segundo {
    int x = 2;
}

int main() {

    using namespace primero;
    std::cout<<"X = "<<x <<std::endl; // '::' se les conoce como el "operador de resolucion de ambitos".

    std::cout<<"X = "<<segundo::x <<std::endl;

    
    return 0;
}