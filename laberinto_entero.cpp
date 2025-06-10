#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <queue>
#include <unordered_set>
#include <utility> // Para std::pair

// Declaraciones adelantadas de funciones
void mostrar_tablero(const std::vector<std::vector<char>>& laberinto);
void generar_mapa(int x, int y, std::vector<std::vector<char>>& laberinto, int alto, int ancho);
void juego_manual(std::vector<std::vector<char>>& laberinto, int alto, int ancho);
void resolver_lab_automatico(std::vector<std::vector<char>>& laberinto, int alto, int ancho);

int main() {
    // Entrada de dimensiones del laberinto
    int ancho, alto;
    std::cout << "Elija el ancho de su laberinto: ";
    std::cin >> ancho;
    std::cout << "Elija el largo de su laberinto: ";
    std::cin >> alto;

    // Forzar a impar
    if (ancho % 2 == 0) {
        ancho += 1;
    }
    if (alto % 2 == 0) {
        alto += 1;
    }

    // Creación del laberinto inicial
    std::vector<std::vector<char>> laberinto(alto, std::vector<char>(ancho, '#'));

    // Generación del mapa
    generar_mapa(ancho-2, alto-2, laberinto, alto, ancho);

    // Colocar entrada y salida
    laberinto[1][1] = 'E';
    laberinto[alto-2][ancho-2] = 'S';

    std::cout << "\n";
    mostrar_tablero(laberinto);

    // Elección del modo de juego
    std::string eleccion;
    std::cout << "\n¿Desea jugar al laberinto de forma automatica?(Sí/No): ";
    std::cin >> eleccion;

    if (eleccion == "si" || eleccion == "Si" || eleccion == "SI") {
        resolver_lab_automatico(laberinto, alto, ancho);
    }
    else if (eleccion == "no" || eleccion == "No" || eleccion == "NO") {
        juego_manual(laberinto, alto, ancho);
    }
    else {
        std::cout << "Por favor, elija entre \"Sí\" o \"No\";
    }

    return 0;
}

// Función para mostrar el tablero
void mostrar_tablero(const std::vector<std::vector<char>>& laberinto) {
    for (const auto& fila : laberinto) {
        for (char c : fila) {
            std::cout << c << " ";
        }
        std::cout << "\n";
    }
}

// Función recursiva para generar el laberinto
void generar_mapa(int x, int y, std::vector<std::vector<char>>& laberinto, int alto, int ancho) {
    laberinto[x][y] = '.';
    std::vector<std::pair<int, int>> movimientos_posibles = {{0, 2}, {0, -2}, {2, 0}, {-2, 0}};
    
    // Barajar movimientos posibles (similar a random.shuffle)
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(movimientos_posibles.begin(), movimientos_posibles.end(), g);

    for (const auto& movimiento : movimientos_posibles) {
        int nueva_x = x + movimiento.first;
        int nueva_y = y + movimiento.second;
        
        if (nueva_x >= 0 && nueva_x < alto && nueva_y >= 0 && nueva_y < ancho && laberinto[nueva_x][nueva_y] == '#') {
            laberinto[x + movimiento.first / 2][y + movimiento.second / 2] = '.';
            generar_mapa(nueva_x, nueva_y, laberinto, alto, ancho);
        }
    }
}

// Función para el juego manual
void juego_manual(std::vector<std::vector<char>>& laberinto, int alto, int ancho) {
    std::unordered_map<char, std::pair<int, int>> movimientos = {
        {'w', {-1, 0}},
        {'s', {1, 0}},
        {'a', {0, -1}},
        {'d', {0, 1}}
    };

    int x = 1, y = 1;
    while (true) {
        // Condición de salida
        if (x == alto-2 && y == ancho-2) {
            std::cout << "¡Has llegado a la salida!\n";
            break;
        }

        char direccion;
        std::cout << "Mover (w/a/s/d): ";
        std::cin >> direccion;

        if (movimientos.find(direccion) == movimientos.end()) {
            std::cout << "Dirección inválida. Usa w, a, s o d.\n";
            continue;
        }

        int dx = movimientos[direccion].first;
        int dy = movimientos[direccion].second;
        int nueva_x = x + dx;
        int nueva_y = y + dy;

        if (nueva_x >= 0 && nueva_x < alto && nueva_y >= 0 && nueva_y < ancho && laberinto[nueva_x][nueva_y] != '#') {
            laberinto[x][y] = '.';
            laberinto[1][1] = 'E';
            x = nueva_x;
            y = nueva_y;
            laberinto[x][y] = 'O';

            std::cout << "\n";
            mostrar_tablero(laberinto);
        }
        else {
            std::cout << "No se puede chocar con paredes ni salir de los límites\n";
        }
    }
}

// Función para resolver el laberinto automáticamente
void resolver_lab_automatico(std::vector<std::vector<char>>& laberinto, int alto, int ancho) {
    std::pair<int, int> entrada, salida;
    
    // Buscar entrada y salida
    for (int i = 0; i < alto; ++i) {
        for (int j = 0; j < ancho; ++j) {
            if (laberinto[i][j] == 'E') {
                entrada = {i, j};
            }
            if (laberinto[i][j] == 'S') {
                salida = {i, j};
            }
        }
    }

    // Cola para BFS
    std::queue<std::pair<std::pair<int, int>, std::vector<std::pair<int, int>>>> cola;
    cola.push({entrada, {entrada}});

    std::unordered_set<std::string> visitado;
    visitado.insert(std::to_string(entrada.first) + "," + std::to_string(entrada.second));

    std::vector<std::pair<int, int>> movimientos = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!cola.empty()) {
        auto actual = cola.front();
        cola.pop();
        int x = actual.first.first;
        int y = actual.first.second;
        auto camino = actual.second;

        if (x == salida.first && y == salida.second) {
            for (size_t i = 1; i < camino.size()-1; ++i) {
                laberinto[camino[i].first][camino[i].second] = 'O';
            }
            std::cout << "El Laberinto se ha resuelto automáticamente:\n";
            mostrar_tablero(laberinto);
            return;
        }

        for (const auto& movimiento : movimientos) {
            int nx = x + movimiento.first;
            int ny = y + movimiento.second;
            std::string clave = std::to_string(nx) + "," + std::to_string(ny);
            
            if (nx >= 0 && nx < alto && ny >= 0 && ny < ancho) {
                if ((laberinto[nx][ny] == '.' || laberinto[nx][ny] == 'S') && 
                    visitado.find(clave) == visitado.end()) {
                    visitado.insert(clave);
                    auto nuevo_camino = camino;
                    nuevo_camino.emplace_back(nx, ny);
                    cola.push({{nx, ny}, nuevo_camino});
                }
            }
        }
    }

    std::cout << "No se pudo encontrar un camino hasta la salida.\n";
}