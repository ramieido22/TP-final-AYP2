
#ifndef ABMAEROPUERTOS_H_INCLUDED
#define ABMAEROPUERTOS_H_INCLUDED

#include "ABB.h"
#include "Aeropuerto.h"

class ABM {
    private:
        ABB aeropuertos;
        Aeropuerto* datos_aeropuertos;

        int cantidad();
    public:

        /**
         * Constructor del ABM
         * lee los datos de la base de datos
         * (el archivo) para iniciar el 
         * ABM
        */
        ABM();

        ~ABM();
};

#endif // ABMAEROPUERTOS_H_INCLUDED