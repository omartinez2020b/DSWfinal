#ifndef PIBOT_H_INCLUDED
#define PIBOT_H_INCLUDED

#include "robot.h"

class Pibot : public Robot
{
    public:
        Pibot(const Coordenadas& c): Robot(c) { alcance_sensor = ALCANCE; }
        virtual ~Pibot() {}
        void avanzar(void);
        bool detectar_objeto(Posicion& pos_objeto);
        int leer_ultrasonidos(Posicion& pos_esquina);
        void girar_derecha(void);

    private:
        static const int ALCANCE = 1; // Alcance sensor del Pibot


};

#endif // PIBOT_H_INCLUDED
