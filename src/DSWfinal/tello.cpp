#include "tello.h"
#include <iostream>
using namespace std;

void Tello::avanzar()
{
    cout << bateria_actual << endl;
    if (bateria_actual > 0)
    {
        for (int i = 0; i < 2; i++) Pibot::avanzar();
        bateria_actual--;
    }
    else Pibot::avanzar();

}