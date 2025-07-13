#pragma once
#include "CInsecto.h"

ref class CInsecto3 : public CInsecto {
private:
	int dx;
	int dy;
	int contadorAnimacion;

public:
	CInsecto3() : CInsecto("Insecto3.png") {
		dx = (rand() % 7) + 4; // velocidad entre 4 y 10
		dy = (rand() % 7) + 4;

		// Dirección inicial aleatoria
		if (rand() % 2 == 0) dx *= -1;
		if (rand() % 2 == 0) dy *= -1;

		indiceY = 2; // Fila del sprite (podés personalizarla)

		contadorAnimacion = 0;
	}

	virtual void mover() override {
		indiceX = (indiceX + 1) % 4;
		contadorAnimacion++;

		x += dx;
		y += dy;

		// Cambiar dirección cada 4 ciclos de sprite
		if (contadorAnimacion >= 4) {
			contadorAnimacion = 0;

			int direccion = rand() % 4;
			int velocidad = (rand() % 4) + 5;

			switch (direccion) {
			case 0: dx = 0; dy = velocidad; indiceY = 0; break; // Abajo
			case 1: dx = -velocidad; dy = 0; indiceY = 1; break; // Izquierda
			case 2: dx = velocidad; dy = 0; indiceY = 2; break; // Derecha
			case 3: dx = 0; dy = -velocidad; indiceY = 3; break; // Arriba
			}
		}

		// Limites de rebote
		if (x <= 0 || x + (ancho * escala) >= 900) dx *= -1;
		if (y <= 0 || y + (alto * escala) >= 600) dy *= -1;
	}
};
