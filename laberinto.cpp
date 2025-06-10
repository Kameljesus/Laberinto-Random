#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

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

void generar_mapa(std::vector<std::vector<char>>&laberinto, int x, int y, std::mt19937 generador_aleatorio)
{
   laberinto[x][y] = '.';
   std::vector<std::pair<int, int>> movimientos_posibles = {{0, 2}, {0, -2}, {2, 0}, {-2, 0}};
   // Vector, seria mi equivalente a una lista.
   // Pair, seria mi equivalente a una tupla (luego le especifique que sera un: 'entero', 'entero').
   std::shuffle(movimientos_posibles.begin(), movimientos_posibles.end(),generador_aleatorio);

   for (size_t movimiento_obtenido = 0; movimiento_obtenido < movimientos_posibles.size(); movimiento_obtenido ++)
   {     
         std::pair<int, int> movimiento_a_usar = movimientos_posibles[movimiento_obtenido];
         
         int dx = movimiento_a_usar.first;
         int dy = movimiento_a_usar.second;

         int nueva_x = x + dx;
         int nueva_y = y + dy;

         
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

  std::cout<<" "<<std::endl;
  mostrar_tablero(laberinto, ancho, alto); 
  std::cout<<" "<<std::endl;


  std::cout<<" "<<std::endl;
  generar_mapa(laberinto, ancho-2, alto-2, generador_aleatorio); 
  std::cout<<" "<<std::endl;


  std::cout<<" "<<std::endl;
  mostrar_tablero(laberinto, ancho, alto); 
  std::cout<<" "<<std::endl;

   return 0;
}

