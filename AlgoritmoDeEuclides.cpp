/*
    INSTITUTO POLITÉCNICO NACIONAL
    ESCUELA SUPERIOR DE CÓMPUTO
    ASIGNATURA:
        ANÁLISIS DE ALGORITMOS
    GRUPO: 
        3CV11
    PROFESOR: 
        LUNA BENOSO BENJAMÍN
    ALUMNO: 
        STEINER VÁZQUEZ ANTHONY FRANCIS
    TÍTULO: 
        PRÁCTICA 1: DETERMINACIÓN EXPERIMENTAL DE LA COMPLEJIDAD TEMPORAL DE UN ALGORITMO
    ARCHIVO: AlgoritmoDeEuclides.cpp
    DESARROLLO:
        Implementación del algoritmo de Euclides, para encontrar el máximo común divisor (mcd)
        de 2 números enteros positivos m, y n. Posteriormente haremos un análisis de su complejidad
        temporal para el peor caso, donde probaremos con números consecutivos de la sucesión de Fibonacci,
        como 4181 = F19, 6765 = F20.
    ENTREGA: 
        28/02/2022
*/

// librerías
#include <iostream>
#include <sstream>

/**
 * Función para encontrar el máximo común divisor de 2 números enteros positivos m y n,
 * mediante el algoritmo de Euclides.
 * 
 * @param m 1er número entero
 * @param n 2ndo número entero
 * @return int - mcd(m,n) 
 */
int algoritmoDeEuclides(int m, int n, int &cnt) // números enteros positivos
{
    cnt++;
    int r{}; // variable para el residuo 
    while (n != 0) // iteramos hasta que sea diferente de 0
    {
        cnt++;
        r = m % n; // calculamos el residuo de la división entre m y n
        cnt++;
        m = n; // guardamos en m el valor de n
        cnt++;
        n = r; // guardamos el valor del residuo
        cnt++;
    }
    cnt++;
    cnt++;
    return m; // retornamos el último valor de m, esto es mcd(m,n)
}

/**
 * @brief Función main
 * 
 * @param argc contador de argumentos
 * @param argv arreglo de strings con los argumentos
 * @return 0 - valor de retorno de la función main
 */
int main(int argc, char const *argv[])
{
    int contador{}; // variable para contar las operaciones realizadas por el algoritmo
    int m; // variable para el número m
    int n; // variable para el número n
    if (argc >= 3) // checamos si nos han dado los números mediante línea de comandos
    {
        std::istringstream iss1(argv[1]); // leer el 1er argumento
        iss1 >> m; // convertir el string del argumento a entero y guardandolo en m
        std::istringstream iss2(argv[2]); // leer el 2ndo argumento
        iss2 >> n; // convertir el string del argumento a entero y guardandolo en n
    }
    else // hay que pedir el valor de m y n
    {
        std::cout << "Ingrese valor para m y n: "; // Imprimir algo que nos permita saber que necesitamos el valor de m,n
        std::cin >> m >> n; // guardamos el valor en m y n
    }
    int mcd{}; // variable para guardar el mcd
    mcd = algoritmoDeEuclides(m, n, contador); // ejecutamos nuestro algoritmo y guardamos el resultado en la variable mcd
    std::cout
        << "mcd(" << m
        << ", " << n
        << ") = "
        << mcd << "\n"; // mostramos en pantalla el resultado
    std::cout << "El algoritmo hizo: " << contador << " operaciones.\n"; // Impresión en pantalla de la cantidad de operaciones que realizó el algoritmo
    return 0; // retornamos 0
}