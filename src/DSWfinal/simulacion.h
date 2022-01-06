#ifndef SIMULACION_H_INCLUDED
#define SIMULACION_H_INCLUDED

#include "pibot.h"
#include "tello.h"
#include "habitacion.h"

class Simulacion
{
    public:
        Simulacion(Habitacion& h): hab(h) {}
        void simular_pibot(Pibot& pibot);
        void simular_tello(Tello& tello);

    protected:
        Habitacion hab;



#endif // SIMULACION_H_INCLUDED
