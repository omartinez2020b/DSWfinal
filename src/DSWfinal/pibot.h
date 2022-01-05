#ifndef PIBOT_H_INCLUDED
#define PIBOT_H_INCLUDED

#include "robot.h"

class Pibot : public Robot
{
    public:
        Pibot(const Coordenadas& c): Robot(c) {}
        virtual void avanzar(void);
        virtual bool detectar_objeto(Posicion& pos_objeto);
        virtual int leer_ultrasonidos(Posicion& pos_esquina);
        virtual void girar_derecha(void);
        virtual int obtener_distancia_avance(void) const {return distancia_avance;}


};

#endif // PIBOT_H_INCLUDED
