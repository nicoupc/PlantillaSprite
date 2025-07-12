#pragma once
using namespace System;
using namespace System::Drawing;

#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()

ref class CInsecto {
protected:
	int x, y;
	int ancho, alto;
	int indiceX, indiceY;
	Bitmap^ imagen;
	int escala;
	Random^ r;

public:
	CInsecto(String^ archivoImagen) {
		escala = 1;
		imagen = gcnew Bitmap(archivoImagen);

		int columnas = 4;
		int filas = 4;

		ancho = imagen->Width / columnas;
		alto = imagen->Height / filas;

		// Limite de aparición aleatoria dentro de la ventana
		x = rand() % (800 - ancho * escala); // Ajusta según el ancho de la ventana
		y = rand() % (500 - alto * escala); // Ajusta según el alto de la ventana

		indiceX = 0;
		indiceY = 0;
	}

	// Métodos virtuales: se redefinen en cada tipo de insecto
	virtual void mover() = 0;

	virtual void dibujar(BufferedGraphics^ buffer) {
		Rectangle origen = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle destino = Rectangle(x, y, ancho * escala, alto * escala);
		buffer->Graphics->DrawImage(imagen, destino, origen, GraphicsUnit::Pixel);
		// Dibujar un rectángulo alrededor del insecto (opcional)
		buffer->Graphics->DrawRectangle(Pens::Red, obtenerRectangulo());
	}

	virtual Rectangle obtenerRectangulo() {
		return Rectangle(x, y, ancho * escala, alto * escala);
	}

	property int X { int get() { return x; } }
	property int Y { int get() { return y; } }
};
