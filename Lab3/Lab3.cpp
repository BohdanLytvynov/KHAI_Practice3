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
    
    ButtonStyle bs("Button1", 30, 7, Vector2D(11, 1));

    Button b1("NGButton", Vector2D(4,8), bs, "New Game", true);

    Button b2("LoadButton", Vector2D(2, 2), bs, "Load Game",true);

    Button b3("SettingsButton", Vector2D(2, 2), bs, "Settings",true);

    Button b4("ExitButton", Vector2D(2, 2), bs, "Quite", true);

    controller->AddUIControl(&b1);
    /*controller->AddUICOntrol(b2);
    controller->AddUICOntrol(b3);
    controller->AddUICOntrol(b4);*/

    controller->Draw();


    system("Pause");
}

