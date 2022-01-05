#include "habitacion.h"
#include "tipos.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Habitacion::Habitacion(int n_filas, int n_columnas, Posicion& esquina_infd)
{
    filas = n_filas;
    columnas = n_columnas;
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
    // Las paredes se numeran del 1 al 4, empezando por la de arriba, yendo en sentido horario
    bool puerta_puesta = false;
    int bricks = 2 * filas  + 2 * (columnas - 2); // Las paredes tienen ese número de bricks
    int door = rand() % bricks; // El número de brick que debe ser sustituido por una puerta
    cout << door << endl;
    int i = 0;
    int n = 0; // Cantidad de bricks evaluados

    while (i < filas && !puerta_puesta)
    {
        int j = 0;
        while (j < columnas && !puerta_puesta)
        {
            if (matriz[i][j] == '*')
            {
                if (n == door)
                {
                    matriz[i][j] = 'P';
                    pos.set_x(j);
                    pos.set_y(i);
                    puerta_puesta = true;
                }
                n++;
            }
            j++;
        }
        i++;
    }
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
