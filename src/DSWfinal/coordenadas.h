#ifndef COORDENADAS_H
#define COORDENADAS_H

#include "tipos.h"
#include "posicion.h"


class Coordenadas : public Posicion
{
    public:
        Coordenadas() {}

        t_Orientacion get_orientacion() const { return orientacion; }
        void set_orientacion(t_Orientacion val) { orientacion = val; }

    private:
        t_Orientacion orientacion;
};

#endif // COORDENADAS_H
