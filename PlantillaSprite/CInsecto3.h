#pragma once
#include "CInsecto.h"

ref class CInsecto3 : public CInsecto {
private:
    int dx;
    int dy;

public:
    CInsecto3() : CInsecto("Insecto3.png") {
        dx = (rand() % 7) + 4; // velocidad entre 4 y 10
        dy = (rand() % 7) + 4;

        // Dirección inicial aleatoria
        if (rand() % 2 == 0) dx *= -1;
        if (rand() % 2 == 0) dy *= -1;

        indiceY = 2; // Fila del sprite (podés personalizarla)
    }

    virtual void mover() override {
        indiceX = (indiceX + 1) % 4;

        x += dx;
        y += dy;

        // Rebote con cambio aleatorio
        if (x <= 0 || x + (ancho * escala) >= 800) {
            dx *= -1;

            if (rand() % 3 == 0) dx = (rand() % 5) + 5;
            if (rand() % 2 == 0) dx *= -1;
        }

        if (y <= 0 || y + (alto * escala) >= 600) {
            dy *= -1;

            if (rand() % 3 == 0) dy = (rand() % 5) + 5;
            if (rand() % 2 == 0) dy *= -1;
        }
    }
};
