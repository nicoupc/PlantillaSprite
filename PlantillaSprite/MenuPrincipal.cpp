#include "MenuPrincipal.h"

using namespace PlantillaSprite;

int main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it
	PlantillaSprite::MenuPrincipal form;
	Application::Run(% form);

	return 0;
}