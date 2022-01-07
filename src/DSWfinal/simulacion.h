#ifndef SIMULACION_H_INCLUDED
#define SIMULACION_H_INCLUDED

#include "pibot.h"
#include "tello.h"
#include "habitacion.h"
#include "posicion.h"
#include "coordenadas.h"

class Simulacion
{
    public:
        Simulacion(Habitacion& h): hab(h) {}
        void simular_pibot();
        void simular_tello();
        void reset() { hab.reset();}

    protected:
        void inicializar_entorno();
        Habitacion hab;
        // Variables importantes para el entorno
        Posicion pos_esquina_infd;
        Posicion pos_puerta;
        Coordenadas coord_robot;

};


#endif // SIMULACION_H_INCLUDED
