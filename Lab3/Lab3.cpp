// Lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"VectorMath.h"
#include"ConsoleUI.h"

using namespace ConsoleUI;

using namespace UIControls;

int main()
{
    ///Get Output Handle
    auto console = GetStdHandle(STD_OUTPUT_HANDLE);
    /// <summary>
    /// Init Console UI Controller
    /// </summary>
    /// <returns></returns>
    ConsoleUIController* const controller = ConsoleUIController::Initialize(console);
    /// <summary>
    /// Common Buton Style
    /// </summary>
    /// <returns></returns>
    ButtonStyle bs("Button1", 30, 7, Vector2D(4, 1));
    /// <summary>
    /// Panel Style
    /// </summary>
    /// <returns></returns>
    PanelStyle ps("Menu", 20, 40, Vector2D(2, 2), Vector2D(5,1));

    Panel panel("MenuPanel", Vector2D(50,6), ps, "Main menu", true);

    Button b1("NGButton", Vector2D(4,8), bs, "New Game", true);

    Button b2("LoadButton", Vector2D(2, 2), bs, "Load Game", true);

    Button b3("SettingsButton", Vector2D(2, 2), bs, "Settings", true);

    Button b4("ExitButton", Vector2D(2, 2), bs, "Quite", true);
    //Add Buttons to the Panel
    panel.AddChild(&b1);

    panel.AddChild(&b2);

    panel.AddChild(&b3);

    panel.AddChild(&b4);
    //Add Panel o the Controller
    controller->AddUIControl(&panel);
    //Draw UI
    controller->Draw();

    system("Pause");
}

