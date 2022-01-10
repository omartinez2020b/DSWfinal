#ifndef TELLO_H_INCLUDED
#define TELLO_H_INCLUDED

#include "pibot.h"

class Tello : public Pibot
{
    public:
        /* A efectos prácticos, el funcionamiento de un tello es el mismo que un pibot
        a excepción de que mientras tenga batería, distancia_avance = 2; */
        Tello(const Coordenadas& c): Pibot(c), bateria_actual(BATERIA_INICIAL)
            { alcance_sensor = ALCANCE; distancia_avance = AVANCE_INICIAL; }
        ~Tello() {}
        void avanzar(void);

    protected:
        static const int BATERIA_INICIAL = 25;
        int bateria_actual;

    private:
        static const int ALCANCE = 2;
        static const int AVANCE_INICIAL = 2;
};


#endif // TELLO_H_INCLUDED
