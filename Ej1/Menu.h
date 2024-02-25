
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

enum OPCION_MENU {
    CONSULTA=1,
    ALTA=2,
    BAJA=3,
    SALIDA=4,
    NO_DETERMINADO=5
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