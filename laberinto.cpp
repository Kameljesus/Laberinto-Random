#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <map> //Para poder usar un diccionario.
#include <cctype> // Para poder usar el ".lower()" en C++.
#include <deque>
#include <set>

// El const asegura que la función no modificará el laberinto que recibe.
// Pasarlo por referencia (&) evita hacer una copia pesada de todo el laberinto.
void mostrar_tablero(const std::vector<std::vector<char>>&laberinto, int ancho, int alto)
{
   for (int fila = 0; fila < alto; fila++) {
      for (int columna = 0; columna < ancho; columna++) {
         std::cout << laberinto[fila][columna] << ' ';
      }
      std::cout << std::endl;
   }
}

void generar_mapa(std::vector<std::vector<char>>&laberinto, int x1, int y1, std::mt19937 generador_aleatorio, int alto, int ancho)
{
   laberinto[x1][y1] = '.';
   std::vector<std::pair<int, int>> movimientos_posibles = {{0, 2}, {0, -2}, {2, 0}, {-2, 0}};
   // Vector, seria mi equivalente a una lista.
   // Pair, seria mi equivalente a una tupla (luego le especifique que sera un: 'entero', 'entero').
   std::shuffle(movimientos_posibles.begin(), movimientos_posibles.end(),generador_aleatorio);

   for (size_t movimiento_obtenido = 0; movimiento_obtenido < movimientos_posibles.size(); movimiento_obtenido ++)
   {     
         std::pair<int, int> movimiento_a_usar = movimientos_posibles[movimiento_obtenido];
         
         int dx1 = movimiento_a_usar.first;
         int dy1 = movimiento_a_usar.second;

         int nueva_x1 = x1 + dx1;
         int nueva_y1 = y1 + dy1;

         if (nueva_x1 >= 0 && nueva_x1 < alto &&
         nueva_y1 >= 0 && nueva_y1 < ancho &&
         laberinto[nueva_x1][nueva_y1] == '#') {
            
            laberinto[x1 + dx1 / 2][y1 + dy1 / 2] = '.';
            generar_mapa(laberinto, nueva_x1, nueva_y1, generador_aleatorio, alto, ancho);
}
   }
}

void juego_manual(std::vector<std::vector<char>>&laberinto, int alto, int ancho)
{
   std::map<char, std::pair<int, int>> movimientos_jugador = {
   // std::map es un diccionario en C++:
      {'w', {-1, 0}},
        {'s', {1, 0}},
        {'a', {0, -1}},
        {'d', {0, 1}}
    };
   
   int x2 = 1;
   int y2 = 1;

   while (true) 
   {
      // Condición de salida (si llega a la 'S'):
        if (x2 == alto-2 && y2 == ancho-2)
        {
            std::cout<<"¡Has llegado a la salida!"<< std::endl;
            break;
        }

         char direccion;
         std::cout << "Mover (w/a/s/d): ";
         std::cin >> direccion; 
         direccion = std::tolower(direccion);  // Convierte a minúscula
         /*Nota:
         tolower() solo funciona con un carácter (char), no con strings completos.
         Asegurate de incluir #include <cctype> al principio del archivo.*/
         std::cout<<" "<<std::endl;


         if (movimientos_jugador.find(direccion) == movimientos_jugador.end())
         /*¿Por qué?
         movimientos_jugador.find(direccion) intenta buscar la clave.
         Si no la encuentra, devuelve movimientos_jugador.end().
         Así sabés que no existe esa dirección.*/
         {
             std::cout << "Dirección inválida. Usa w/a/s/d" << std::endl;
             continue;
         }
         
         std::pair<int, int> direccion_elegida = movimientos_jugador[direccion];
         
         int dx2 = direccion_elegida.first;
         int dy2 = direccion_elegida.second;

         int nueva_x2 = x2 + dx2;
         int nueva_y2 = y2 + dy2;

         // Verifica que la nueva posición esté dentro del laberinto
         if (0 <= nueva_x2 && nueva_x2 < alto && 0 <= nueva_y2 && nueva_y2< ancho && laberinto[nueva_x2][nueva_y2] != '#')
         {
            laberinto[x2][y2] = '.';
            
            // Poner la entrada otra vez:
            laberinto[1][1] = 'E';

            // Actualiza a la nueva posición
            x2 = nueva_x2;
            y2 = nueva_y2;
            
            laberinto[x2][y2] = 'O';

            // Muestra el laberinto actualizado
            std::cout<<" "<<std::endl;
            mostrar_tablero(laberinto, alto, ancho);
         }

         else {
            std::cout <<"No se puede chocar con paredes ni salir de los límites";
         }
   }
}

void resolver_laberinto_automatico(std::vector<std::vector<char>>& laberinto, int alto, int ancho, int x3, int y3)
{
   // Tener entrada y salida:
   std::pair<int, int> entrada = {1, 1};
   std::pair<int, int> salida = {alto-2, ancho-2};

   std::deque<std::pair<std::pair<int, int>, 
   // Cola, con una tupla ( de un entero y un entero),
   std::vector<std::pair<int, int>>>> cola;
   // junto a una lista de tuplas, y todo esto se llama: cola

   cola.push_back({entrada, {entrada}});

   std::set<std::pair<int, int>> visitado;
   visitado.insert(entrada);

   std::vector<std::pair<int, int>> movimientos_bfs = 
   {
      {-1, 0},
      {1, 0},
      {0, -1},
      {0, 1}
   };

   while (!cola.empty()) // '!' es lo mismo que 'not' y 'cola.empty' significa: "Mientra la cola no esté vacía"
   {
      auto frente = cola.front();  // "Agarra el elemento de enfrente"
      cola.pop_front();            // "Y ELIMINALO"

      
   }



}

int main() {
   std::random_device random;  // Una fuente de "verdadera" aleatoriedad para la semilla.
   std::mt19937 generador_aleatorio(random()); // Un motor de números pseudoaleatorios, sembrado con rd.


   int ancho;
   std::cout << "Elija el ancho de su laberinto: ";
   std::cin >> ancho;

   int alto;
   std::cout << "Elija el alto de su laberinto: ";
   std::cin >> alto;


   // Forzar a impar o sumar para mantener lo mas posible las dimensiones:
   if (ancho % 2 == 0) {
      ancho += 1;
   }

   else {
      ancho += 2;
   }

   
   if (alto % 2 == 0) {
      alto += 1;
   }

   else {
      alto += 2;
   }

   // Crear laberinto:
  std::vector<std::vector<char>> laberinto(alto, std::vector<char>(ancho, '#'));

  generar_mapa(laberinto, alto-2, ancho-2, generador_aleatorio, alto, ancho); 

   // Poner la entrada:
   laberinto[1][1] = 'E'; 

   // Poner la salida:
   laberinto[alto - 2][ancho - 2] = 'S'; 

  std::cout<<" "<<std::endl;
  mostrar_tablero(laberinto, alto, ancho); 
  std::cout<<" "<<std::endl;


   char eleccion;
   std::cout << "¿Desea resolver el laberinto de forma automatica?(S/N): "<<std::endl;
   std::cin >> eleccion;
   eleccion = std::tolower(eleccion);

   if (eleccion == 's')
   {
     resolver_laberinto_automatico(laberinto, alto, ancho);
 
   }

   else if (eleccion == 'n')
   {
      juego_manual(laberinto, alto, ancho);
   }
   
   else 
   {
      std::cout<<" "<<std::endl;      
      std::cout <<'Por favor, elija entre "Sí" o "No" '<<std::endl;
   }

   return 0;
}

