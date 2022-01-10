#include "habitacion.h"
#include "tipos.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Habitacion::Habitacion(int n_filas, int n_columnas)
{
    if (n_filas > MAX_FILAS) filas = MAX_FILAS;
    else if (n_filas < MIN_FILAS) filas = MIN_FILAS;
    else filas = n_filas;

    if (n_columnas > MAX_COLUMNAS) columnas = MAX_COLUMNAS;
    else if (n_columnas < MIN_COLUMNAS) columnas = MIN_COLUMNAS;
    else columnas = n_columnas;

    // Esta es una función inicializadora, que pone toda la habitación en blanco
    reset();
}

void Habitacion::reset()
{
    esquina_infd.set_x(columnas -1);
    esquina_infd.set_y(filas - 1);
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (i == 0 || j == 0) matriz[i][j] = '*';
            else if (i == filas - 1 || j == columnas - 1) matriz[i][j] = '*';
            else matriz[i][j] = ' ';
        }
    }
}

void Habitacion::colocar_puerta_aleatoria(Posicion& pos)
{
    /* Primero se obtiene una pared aleatoria y luego se obtiene su posición
    mediante la fórmula (rand() % (filas/columnas - 2)) + 1, esto es, se generan
    números entre 0 y filas/columnas - 2 y se le añade 1 */
    t_Orientacion pared = t_Orientacion(rand() % 4);
    int x, y;
    if (pared == NORTE) {y = 0; x = (rand() % (columnas - 2)) + 1; }
    else if (pared == ESTE) {x = columnas - 1; y = (rand() % (filas - 2)) + 1; }
    else if (pared == OESTE) {x = 0; y = (rand() % (filas - 2)) + 1;}
    else {y = filas - 1; x = (rand() % (columnas - 2)) + 1; }
    matriz[y][x] = 'P';
    pos.set_x(x);
    pos.set_y(y);
}

void Habitacion::obtener_coordenadas_aleatorias_para_robot(Coordenadas& coord) const
{
    coord.set_x(rand() % (columnas - 3) + 1); // Número de espacios interiores en X
    coord.set_y(rand() % (filas - 3) + 1); // Número de espacios interiores en Y
    t_Orientacion or_aleatoria = t_Orientacion(rand() % 4);
    coord.set_orientacion(or_aleatoria);
}

void Habitacion::colocar_pibot(Coordenadas& coord)
{
    int x = coord.get_x();
    int y = coord.get_y();
    t_Orientacion orientacion = coord.get_orientacion();
    char signo_orientacion = '^';

    if (orientacion == ESTE) signo_orientacion= '>';
    else if (orientacion == SUR) signo_orientacion= 'v';
    else if (orientacion == OESTE) signo_orientacion= '<';
    // La matriz es de filas por columnas, por lo que los valores de x e y van al revés
    matriz[y][x] = signo_orientacion;
}

void Habitacion::colocar_tello(Coordenadas& coord, bool volando)
{
    int x = coord.get_x();
    int y = coord.get_y();
    char signo = 'x';
    if (volando) signo = 'X';
    matriz[y][x] = signo;
}

void Habitacion::dibujar() const
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
            cout << matriz[i][j];
        cout << endl;
    }
}
