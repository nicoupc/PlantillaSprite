#pragma once
using namespace System;
using namespace System::Drawing;

ref class CRayo {
private:
    int x, y;
    int dx, dy;
    int escala;
    Bitmap^ imagen;
    int tamanoRayo = 25; // o 25, lo que se vea bien

public:
    CRayo(int px, int py, int direccion) {
        x = px;
        y = py;
        escala = 1;
        imagen = gcnew Bitmap("rayo.png");

        int velocidad = 20;

        // Dirección: 0=Abajo, 1=Izquierda, 2=Derecha, 3=Arriba
        switch (direccion) {
        case 1: dx = 0; dy = velocidad; break;   // Abajo
        case 2: dx = -velocidad; dy = 0; break;  // Izquierda
        case 3: dx = velocidad; dy = 0; break;   // Derecha
        case 4: dx = 0; dy = -velocidad; break;  // Arriba
        default: dx = 0; dy = 0; break;
        }
    }

    void mover() {
        x += dx;
        y += dy;
    }

    void dibujar(BufferedGraphics^ buffer) {
        buffer->Graphics->DrawImage(imagen, x, y, tamanoRayo, tamanoRayo);
        // Dibujar un rectángulo rojo para colisiones si se desea visualizar
		buffer->Graphics->DrawRectangle(Pens::Red, obtenerRectangulo());
    }

    Rectangle obtenerRectangulo() {
        return Rectangle(x, y, tamanoRayo, tamanoRayo);
    }

    bool fueraDePantalla(int anchoPantalla, int altoPantalla) {
        return (x < 0 || x > anchoPantalla || y < 0 || y > altoPantalla);
    }
};
