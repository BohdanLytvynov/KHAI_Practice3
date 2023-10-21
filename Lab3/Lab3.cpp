// Lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"VectorMath.h"
#include"ConsoleUI.h"

using namespace ConsoleUI;

using namespace UIControls;

int main()
{
    auto console = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleUIController* const controller = ConsoleUIController::Initialize(console);

    ButtonStyle bs("Button1", Colors::ORANGEBack |
        Colors::BLUE, Colors::BLUEBack, 30, 10, 0,0,0,0,
        Colors::BLACKBack | Colors::White, Vector2D(11,2));

    Button b1("NGButton", Vector2D(43,15), bs, "New Game");

    Button b2("LoadButton", Vector2D(2, 2), bs, "Load Game");

    Button b3("SettingsButton", Vector2D(2, 2), bs, "Settings");

    Button b4("ExitButton", Vector2D(2, 2), bs, "Quite");

    controller->AddUIControl(&b1);
    /*controller->AddUICOntrol(b2);
    controller->AddUICOntrol(b3);
    controller->AddUICOntrol(b4);*/

    controller->Draw();


    system("Pause");
}

