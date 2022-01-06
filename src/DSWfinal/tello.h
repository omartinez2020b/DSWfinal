#ifndef TELLO_H_INCLUDED
#define TELLO_H_INCLUDED

#include "pibot.h"

class Tello : public Pibot
{
    public:
        /* A efectos prácticos, el funcionamiento de un tello es el mismo que un pibot
        a excepción de: 1. Hay que realizar el control de vuelo 2. Avanza 2 en vez de 1 */
        Tello(const Coordenadas& c): Pibot(c), volando(false), bateria_actual(BATERIA_INICIAL) {}
        void cambiar_estado() {volando = !volando; }
        void avanzar(void);

    private:
        static const int BATERIA_INICIAL = 25;
        bool volando;
        int alcance_sensor = 2;
        int bateria_actual;



};


#endif // TELLO_H_INCLUDED
