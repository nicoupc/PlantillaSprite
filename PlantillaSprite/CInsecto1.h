#pragma once
#include "CInsecto.h"

ref class CInsecto1 : public CInsecto {
private:
	int velocidad;

public:
	CInsecto1() : CInsecto("Insecto1.png") {
		velocidad = 10;
		indiceY = 0; // Fila del sprite usada para animar (opcional)
	}

	// Polimorfismo: redefinimos el método mover
	virtual void mover() override {
		indiceX = (indiceX + 1) % 4; // Animación horizontal

		// Movimiento horizontal continuo
		x += velocidad;

		// Rebote en bordes simulando ida y vuelta
		if (x <= 0 || x + (ancho * escala) >= 800) { // ajustá 800 según tu ancho real
			velocidad *= -1;
		}
	}
};
