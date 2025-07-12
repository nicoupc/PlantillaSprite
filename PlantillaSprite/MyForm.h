#pragma once

#include "CGuerrero.h"
#include "CInsecto1.h"

namespace PlantillaSprite {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic; // Para List<>

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Bitmap^ fondo;
		CGuerrero^ guerrero;
		Timer^ timer;
		BufferedGraphics^ buffer;
		BufferedGraphicsContext^ context;
		int tipoGuerrero; // 1 o 2 según la elección
		List<CInsecto^>^ enemigos = gcnew List<CInsecto^>();

	public:
		MyForm(int tipoGuerrero)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			srand(static_cast<unsigned int>(time(0))); // Move srand here and cast time to unsigned int
			this->tipoGuerrero = tipoGuerrero;
			guerrero = gcnew CGuerrero(tipoGuerrero);
			fondo = gcnew Bitmap("fondo.jpg");

			for (int i = 0; i < 5; i++) {
				enemigos->Add(gcnew CInsecto1());
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Label^ lblVidas;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// lblVidas
			this->lblVidas = gcnew System::Windows::Forms::Label();
			this->lblVidas->Location = System::Drawing::Point(10, 10);
			this->lblVidas->Size = System::Drawing::Size(130, 30);
			this->lblVidas->Font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Bold);
			this->lblVidas->ForeColor = System::Drawing::Color::Black;
			this->lblVidas->BackColor = System::Drawing::Color::Transparent;
			this->lblVidas->Text = "Vidas: ";
			this->Controls->Add(this->lblVidas);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1100, 700);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::presionarTecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::soltarTecla);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = context->Allocate(g, this->ClientRectangle);

		// Limpiar la pantalla
		buffer->Graphics->DrawImage(fondo, 0, 0, this->ClientSize.Width, this->ClientSize.Height);

		// Mover y dibujar al guerrero
		guerrero->mover(this->ClientSize.Width, this->ClientSize.Height);
		guerrero->dibujar(buffer);

		for each (CInsecto ^ insecto in enemigos) {
			insecto->mover();
			insecto->dibujar(buffer);
		}

		lblVidas->Text = "Vidas: " + guerrero->getVidas();

		// Mostrar el dibujo
		buffer->Render();

		// Liberar recursos
		delete buffer;
		delete g;
	}
	private: System::Void soltarTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		guerrero->setDireccion(Ninguna);
	}
	private: System::Void presionarTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::W) guerrero->setDireccion(Arriba);
		else if (e->KeyCode == Keys::S) guerrero->setDireccion(Abajo);
		else if (e->KeyCode == Keys::A) guerrero->setDireccion(Izquierda);
		else if (e->KeyCode == Keys::D) guerrero->setDireccion(Derecha);
	}
	};
}
