#ifndef TELLO_H_INCLUDED
#define TELLO_H_INCLUDED

#include "pibot.h"

class Tello : public Pibot
{
    public:
        /* A efectos prácticos, el funcionamiento de un tello es el mismo que un pibot
        a excepción de: 1. Hay que realizar el control de vuelo 2. Avanza 2 en vez de 1 */
        Tello(const Coordenadas& c): Pibot(c), bateria_actual(BATERIA_INICIAL) { alcance_sensor = ALCANCE; }
        void avanzar(void);

    protected:
        static const int BATERIA_INICIAL = 25;
        int bateria_actual;

    private:
        static const int ALCANCE = 2;



};


#endif // TELLO_H_INCLUDED
