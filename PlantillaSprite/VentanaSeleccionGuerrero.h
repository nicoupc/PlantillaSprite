#pragma once

#include "MyForm.h"

namespace PlantillaSprite {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for VentanaSeleccionGuerrero
	/// </summary>
	public ref class VentanaSeleccionGuerrero : public System::Windows::Forms::Form
	{
	private:
		int tipoGuerrero; // 1 o 2 según la elección

	public:
		VentanaSeleccionGuerrero(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VentanaSeleccionGuerrero()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ btnElegir1;
	private: System::Windows::Forms::Button^ btnElegir2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->btnElegir1 = (gcnew System::Windows::Forms::Button());
			this->btnElegir2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(101, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(214, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Seleccione un Guerrero:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(59, 89);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(110, 133);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(240, 89);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(116, 133);
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// btnElegir1
			// 
			this->btnElegir1->Location = System::Drawing::Point(59, 285);
			this->btnElegir1->Name = L"btnElegir1";
			this->btnElegir1->Size = System::Drawing::Size(110, 23);
			this->btnElegir1->TabIndex = 3;
			this->btnElegir1->Text = L"Guerrero 1";
			this->btnElegir1->UseVisualStyleBackColor = true;
			this->btnElegir1->Click += gcnew System::EventHandler(this, &VentanaSeleccionGuerrero::btnElegir1_Click);
			// 
			// btnElegir2
			// 
			this->btnElegir2->Location = System::Drawing::Point(240, 285);
			this->btnElegir2->Name = L"btnElegir2";
			this->btnElegir2->Size = System::Drawing::Size(116, 23);
			this->btnElegir2->TabIndex = 4;
			this->btnElegir2->Text = L"Guerrero 2";
			this->btnElegir2->UseVisualStyleBackColor = true;
			this->btnElegir2->Click += gcnew System::EventHandler(this, &VentanaSeleccionGuerrero::btnElegir2_Click);
			// 
			// VentanaSeleccionGuerrero
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(412, 362);
			this->Controls->Add(this->btnElegir2);
			this->Controls->Add(this->btnElegir1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Name = L"VentanaSeleccionGuerrero";
			this->Text = L"VentanaSeleccionGuerrero";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnElegir1_Click(System::Object^ sender, System::EventArgs^ e) {
		tipoGuerrero = 1; // Asignar tipo de guerrero
		MyForm^ myForm = gcnew MyForm(tipoGuerrero);
		myForm->Show(); // Mostrar la ventana del juego
		this->Hide(); // Ocultar la ventana de selección de guerrero
	}
	private: System::Void btnElegir2_Click(System::Object^ sender, System::EventArgs^ e) {
		tipoGuerrero = 2; // Asignar tipo de guerrero
		MyForm^ myForm = gcnew MyForm(tipoGuerrero);
		myForm->Show(); // Mostrar la ventana del juego
		this->Hide(); // Ocultar la ventana de selección de guerrero
	}
	};
}
