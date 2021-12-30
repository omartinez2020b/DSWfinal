#include "habitacion.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Habitacion::Habitacion(Posicion& esquina_inf_dcha)
{
    int filas = esquina_inf_dcha.get_y();
    int columnas = esquina_inf_dcha.get_x();
    esquina_infd = esquina_inf_dcha;
    esquina_inf_dcha.set_x(5);

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
    srand(time(NULL));
    bool puerta_puesta = false;
    int bricks = 2 * esquina_infd.get_x() + 2* (esquina_infd.get_y()-2);
    int door = rand() % bricks;
    int i = 0;
    int n = 0;
    int j = 0;
    while (i < esquina_infd.get_y() && !puerta_puesta)
    {
        j = 0;
        while (j < esquina_infd.get_x() && !puerta_puesta)
        {
            if (matriz[i][j] == '*')
            {
                if (n == door) matriz[i][j] = 'P';
                n++;
            }

            j++;
        }
        i++;
    }

}

void Habitacion::dibujar() const
{
    for (int i = 0; i < esquina_infd.get_y(); i++)
    {
        for (int j = 0; j < esquina_infd.get_x(); j++)
            cout << matriz[i][j];
        cout << endl;
    }
}
