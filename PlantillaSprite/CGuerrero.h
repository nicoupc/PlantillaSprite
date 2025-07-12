#pragma once
using namespace System;
using namespace System::Drawing;

enum DireccionGuerrero { Ninguna, Abajo, Izquierda, Derecha, Arriba };

ref class CGuerrero {
private:
	int x, y;
	int ancho, alto;
	int indiceX, indiceY;
	int vidas;
	float velocidad;
	DireccionGuerrero direccion;
	DireccionGuerrero ultimaDireccion;
	Bitmap^ imagen;

public:
	CGuerrero(int tipo) {
		x = 0;
		y = 0;
		ancho = 32;
		alto = 48;
		indiceX = 0;
		indiceY = 0;
		vidas = 3;
		velocidad = 15;
		direccion = Ninguna;
		ultimaDireccion = Abajo;

		if (tipo == 1)
			imagen = gcnew Bitmap("Guerrero1.png");
		else
			imagen = gcnew Bitmap("Guerrero2.png");

		int columnas = 4;
		int filas = 4;

		ancho = imagen->Width / columnas;
		alto = imagen->Height / filas;
	}

	void mover() {
		switch (direccion) {
		case Abajo:
			indiceY = 0;
			indiceX = (indiceX + 1) % 4;
			y += velocidad;
			ultimaDireccion = Abajo;
			break;
		case Izquierda:
			indiceY = 1;
			indiceX = (indiceX + 1) % 4;
			x -= velocidad;
			ultimaDireccion = Izquierda;
			break;
		case Derecha:
			indiceY = 2;
			indiceX = (indiceX + 1) % 4;
			x += velocidad;
			ultimaDireccion = Derecha;
			break;
		case Arriba:
			indiceY = 3;
			indiceX = (indiceX + 1) % 4;
			y -= velocidad;
			ultimaDireccion = Arriba;
			break;
		case Ninguna:
			indiceX = 0;
			indiceY = static_cast<int>(ultimaDireccion) - 1;
			break;
		}
	}

	void dibujar(BufferedGraphics^ buffer) {
		Rectangle origen = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle destino = Rectangle(x, y, ancho, alto);

		buffer->Graphics->DrawImage(imagen, destino, origen, GraphicsUnit::Pixel);

		// Dibujar rectángulo rojo para colisiones si querés visualizarlo
		Pen^ pen = gcnew Pen(Color::Red, 2);
		buffer->Graphics->DrawRectangle(pen, obtenerRectangulo());
	}

	Rectangle obtenerRectangulo() {
		return Rectangle(x, y, ancho, alto);
	}

	void setDireccion(DireccionGuerrero nueva) {
		direccion = nueva;
	}

	void setPosicion(int nx, int ny) {
		x = nx;
		y = ny;
	}

	int getX() { return x; }
	int getY() { return y; }
};

