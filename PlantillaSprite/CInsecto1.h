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

	// Polimorfismo: redefinimos el m�todo mover
	virtual void mover() override {
		indiceX = (indiceX + 1) % 4; // Animaci�n horizontal

		// Movimiento horizontal continuo
		x += velocidad;

		// Establecer direcci�n visual (horizontal)
		if (velocidad > 0)
			indiceY = 2; // Derecha
		else
			indiceY = 1; // Izquierda

		// Rebote en bordes simulando ida y vuelta
		if (x <= 0 || x + (ancho * escala) >= 900) { // ajust� 900 seg�n tu ancho real
			velocidad *= -1;
		}
	}
};
