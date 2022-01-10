#ifndef PIBOT_H_INCLUDED
#define PIBOT_H_INCLUDED

#include "robot.h"

using namespace std;

class Pibot : public Robot
{
    public:
        Pibot(const Coordenadas& c): Robot(c)
            { alcance_sensor = ALCANCE; distancia_avance = AVANCE_INICIAL; }
        virtual ~Pibot() {}
        void avanzar(void);
        bool detectar_objeto(Posicion& pos_objeto);
        int leer_ultrasonidos(Posicion& pos_esquina);
        void girar_derecha(void);
        int obtener_distancia_avance(void) { return distancia_avance;  }

    private:
        static const int ALCANCE = 1; // Alcance sensor del Pibot
        static const int AVANCE_INICIAL = 1;


};

#endif // PIBOT_H_INCLUDED
