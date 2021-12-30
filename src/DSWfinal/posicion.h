#ifndef POSICION_H
#define POSICION_H


class Posicion
{
    public:
        Posicion() {}
        Posicion(int px, int py): x(px), y(py) {}

        int get_x() const { return x; }
        void set_x(int val) { x = val; }
        int get_y() const { return y; }
        void set_y(int val) { y = val; }

    private:
        int x;
        int y;
};

#endif // POSICION_H
