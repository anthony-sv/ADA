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
    ARCHIVO: BusquedaEnSubArreglo.cpp
    DESARROLLO:
        Se desarrollará un programa para la implementación de un algoritmo que nos diga si
        existe un número en los subarreglos A[0, ..., n/2], A[n/2 + 1, ..., n − 1] del 
        arreglo A[0, ..., n − 1], que ha sido llenado de valores random entre 0 y 3n,
        tal que sea igual. Posteriormente mostrando cuál ha sido el valor, y las posiciones
        sobre el arreglo donde fue encontrado, si existe más de 1, solo devolver el primero.
        Finalmente determinaremos la complejidad de este algoritmo mediante el análisis
        aposteriori, tanto para el mejor caso, como para el peor caso.
    ENTREGA: 
        28/02/2022
*/

// librerías
#include <iostream>
#include <vector>
#include <random>
#include <sstream>

/**
 * Busca un elemento repetido en un arreglo A[0, ..., n − 1], que se encuntre tanto en A[0, ..., n/2], como en A[n/2 + 1, ..., n − 1].
 * Posteriormente escribe en la salida estándar el valor encontrado, y sus posiciones en el arreglo A.
 * 
 * @param arr Arreglo (dinámico) de enteros en el que se buscarán los elementos, con valores entre 0 y 3n.
 * 
 * @note El código tiene algunas operaciones extras aumentando a un contador para poder
 * medir la complejidad temporal de este algoritmo de manera experimental.
 */
void buscarEnSubArreglos(const std::vector<int> &arr, int &cnt) // arreglo donde buscaremos
{
    cnt++;
    auto tam = arr.size(); // tamaño del arreglo
    cnt++;
    int valor{-1}; // valor encontrado
    cnt++;
    int posi{-1}; // posición en donde estuvo `valor` por primera vez en el arreglo.
    cnt++;
    int posf{-1}; // posición en donde estuvo `valor` por segunda vez en el arreglo.
    /* 
        Mejor caso
        El valor del arreglo en la posición 0 del 1er subarreglo es igual al 
        de la posición 0 del segundo subarreglo.
    */
    if (arr[0] == arr[tam / 2])  
    {
        cnt++;
        cnt++;
        valor = arr[0]; // guardamos el valor
        cnt++;
        posi = 0; // guardamos la posición 1
        cnt++;
        posf = tam / 2; // guardamos la posición 2
    }
    /*
        Peor caso
        Para saber si existen 1 elemento que este en ambos subarreglos guardaremos en un arreglo auxiliar 
        los valores hasheados, es decir haremos un mapeo de los valores del arreglo A, en otro arreglo,
        con una función de hasheo de identidad pues los valores a mapear, son enteros pequeños, esto nos
        garantiza un hasheo perfecto.
    */
    else
    {
        cnt++;
        cnt++;
        std::vector<int> hash(10000, -1); // arreglo donde mapearemos los valores
        cnt++;
        int i{}; // variable auxiliar para poder iterar sobre el arreglo
        cnt++;
        for (i = 0; i < tam; i++) //iteramos sobre el arreglo
        {
            cnt++;
            if (i < tam / 2)// valores en la primera mitad del arreglo i.e. A[0, ..., n/2]
            {
                cnt++;
                cnt++;
                hash[arr[i]] = arr[i]; // hasheamos los valores con la función de hash identidad
            } 
            else // estamos en la otra mitad
            {
                cnt++;
                if (hash[arr[i]] != -1) // encontramos un valor previante hasheado esto es un valor repetido
                {
                    cnt++;
                    cnt++;
                    valor = arr[i]; // guardamos el valor
                    cnt++;
                    posf = i; // guardamos la posición 2
                    cnt++;
                    break; // rompemos el ciclo para ya no buscar
                }
                cnt++;
            }
            cnt++;
        }
        cnt++;
        cnt++;
        for (i = 0; i < tam / 2; i++) // iteramos sobre la primera mitad del arreglo
        {
            cnt++;
            if (arr[i] == valor) // buscamos el valor en la primera mitad del arreglo
            {
                cnt++;
                cnt++;
                posi = i; // guardamos la posición 1
                cnt++;
                break; // rompemos el ciclo para encontrar el primeros
            }
            cnt++;
            cnt++;
        }
        cnt++;
    }
    if(valor != -1 && posi != -1 && posf != -1)// checamos si se encontró un elemento que cumpliera las características
    {
        cnt++;
        cnt++;
        std::cout  
            << "dato: " << valor 
            << ", posiciones: [" 
            << posi << "], " 
            << "[" << posf 
            << "].\n"; // mostramos en pantalla
    }
    cnt++;
}

/**
 * @brief Función para imprimir un arreglo
 * 
 * @param arr Arreglo a imprimir
 */
void imprimirArreglo(const std::vector<int>& arr) // arreglo a imprimir
{
    std::cout << "Arreglo A:\n"; // imprimimos algo de formato
    for(const auto& a : arr) // iteramos sobre el arreglo
        std::cout << a << " "; // imprimimos en pantalla el valor
    std::cout << "\n______________________________\n"; // imprimirmos una división
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
    int n; // variable para el tamaño del arreglo
    if (argc >= 2) // checamos si nos han dado un argumento al correr el programa
    {
        std::istringstream iss(argv[1]); // leer el argumento como string
        iss >> n; // convertir el string del argumento a entero y guardandolo en n
    }
    else // hay que pedir el valor de n
    {
        std::cout << "Ingrese el valor de n: "; // Imprimir algo que nos permita saber que necesitamos el valor de n
        std::cin >> n; // guardamos el valor en n
    }
    std::vector<int> A(n, 0); // declaración del arreglo (dinámico)
    /*
        Código para generar números enteros aleatorios en C++. 
    */
    std::random_device semillaOs; // generador de números aleatorios enteros uniformemente distribuidos que produce números aleatorios no deterministas.
    const uint_least32_t semilla = semillaOs(); //genera la semilla avanzando el estado del motor y devuelve el valor generado
    /*
        mt19937 es un Generador de números pseudoaleatorios (PRNG) de 32 bits que lleva por nombre Mersenne Twister 
        desarrollado por Matsumoto and Nishimura en 1998.
    */
    std::mt19937 generador(semilla); // motor de números aleatorios basado en el algoritmo Mersenne Twister. Produce números aleatorios enteros sin signo de alta calidad de tipo UIntType en el intervalo [0, 2^w)
    /* 
        uniform_int_distribution produce valores enteros aleatorios i, distribuidos uniformemente en el intervalo cerrado [a,b], es decir, 
        distribuidos según la función de probabilidad discreta P(i|a,b) = 1 / (b-a+1)
    */
    std::uniform_int_distribution<uint_least32_t> distribuir(0, 3 * n); // asignando el rango de 0 a 3n
    int i{}; //variable para iterar sobre el arreglo
    for (i = 0; i < n; ++i) // iterando sobre el arreglo
    {
        A[i] = distribuir(generador); // guardar en cada posición un valor aleatorio
    }
    imprimirArreglo(A); // imprimimos el arreglo
    buscarEnSubArreglos(A, contador); // mandamos a llamar nuestro algoritmo
    std::cout << "El algoritmo hizo: " << contador << " operaciones.\n"; // Impresión en pantalla de la cantidad de operaciones que realizó el algoritmo
    return 0; // retornamos 0
}