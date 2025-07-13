#pragma once
#include "CInsecto.h"

ref class CInsecto2 : public CInsecto {
private:
	int velocidadX;
	int velocidadY;

public:
	CInsecto2() : CInsecto("Insecto2.png") {
		// Movimiento diagonal
		velocidadX = 5 + (rand() % 5);  // entre 5 y 9
		velocidadY = 5 + (rand() % 5);  // entre 5 y 9
		indiceY = 1; // fila de animación zigzag (podés cambiarla)
	}

	virtual void mover() override {
		indiceX = (indiceX + 1) % 4;

		x += velocidadX;
		y += velocidadY;

		if (abs(velocidadX) > abs(velocidadY)) {
			indiceY = (velocidadX > 0) ? 2 : 1; // Derecha o Izquierda
		}
		else {
			indiceY = (velocidadY > 0) ? 0 : 3; // Abajo o Arriba
		}

		// Rebote horizontal
		if (x <= 0 || x + (ancho * escala) >= 900) {
			velocidadX *= -1;
		}

		// Rebote vertical
		if (y <= 0 || y + (alto * escala) >= 600) {
			velocidadY *= -1;
		}
	}
};
