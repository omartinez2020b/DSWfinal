#include "habitacion.h"
#include "tipos.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Habitacion::Habitacion(int n_filas, int n_columnas)
{
    filas = n_filas;
    columnas = n_columnas;
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
    // Las paredes se numeran del 1 al 4, empezando por la de arriba, yendo en sentido horario
    bool puerta_puesta = false;
    int bricks = 2 * filas  + 2 * (columnas - 2); // Las paredes tienen ese número de bricks
    int door = rand() % bricks; // El número de brick que debe ser sustituido por una puerta
    int i = 0;
    int n = 0; // Cantidad de bricks evaluados

    while (i < filas && !puerta_puesta)
    {
        int j = 0;
        while (j < columnas && !puerta_puesta)
        {
            if (matriz[i][j] == '*')
            {
                if (n == door) matriz[i][j] = 'P';
                pos.set_x(i);
                pos.set_y(j);
                n++;
            }
            j++;
        }
        i++;
    }
}

void Habitacion::obtener_coordenadas_aleatorias_para_robot(Coordenadas& coord) const
{
    coord.set_x(rand() % (columnas - 1) + 1); // Número de espacios interiores en X
    coord.set_y(rand() % (filas - 1) + 1); // Número de espacios interiores en Y
    coord.set_orientacion(t_Orientacion(rand() % 4);
}

void Habitacion::colocar_pibot(Coordenadas& coord)
{
    x = coord.get_x();
    y = coord.get_y();
    matriz[x][y] = '^'^;
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
