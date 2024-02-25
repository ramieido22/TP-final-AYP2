
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

enum OPCION_MENU {
    CONSULTA_GENERAL=1,
    CONSULTA=2,
    ALTA=3,
    BAJA=4,
    SALIDA=5,
    NO_DETERMINADO=6
};

class Menu {
    private:
        int opcion;
    public:

        /**
         * Constructor del menu de administracion
        */
        Menu() = default;

        /**
         * POST: termina grabando la opcion que solicito
         * el usuario
        */
        void pregunarOpcionUsuario();

        /**
         * POST: devuelve true si la opcion grabada
         * es salida
        */
        OPCION_MENU obtenerOpcionUsuario();
};

#endif // MENU_H_INCLUDED