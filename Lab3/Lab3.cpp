// Lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _USE_MATH_DEFINES

#include <iostream>
#include<cmath>
#include"VectorMath.h"
#include"ConsoleUI.h"
#include"Console.h"

using namespace ConsoleUI;

using namespace UIControls;

#pragma region Check Input Functions

bool CheckNumber(const string& str)
{
    size_t l = str.length();

    for (size_t i = 0; i < l; i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }

    return true;
}

#pragma endregion

int main()
{
    ///Get Output Handle
    auto console = GetStdHandle(STD_OUTPUT_HANDLE);

    /// <summary>
    /// Init Console UI Controller
    /// </summary>
    /// <returns></returns>
    ConsoleUIController* const controller = ConsoleUIController::Initialize(console);

#pragma region Lab 3

    ///// <summary>
    ///// Common Buton Style
    ///// </summary>
    ///// <returns></returns>
    //ButtonStyle bs("Button1", 30, 7, Vector2D(4, 1));
    ///// <summary>
    ///// Panel Style
    ///// </summary>
    ///// <returns></returns>
    //PanelStyle ps("Menu", 20, 40, Vector2D(2, 2), Vector2D(5, 1));

    //Panel panel("MenuPanel", Vector2D(50, 6), ps, "Main menu", true);

    //Button b1("NGButton", Vector2D(4, 8), bs, "New Game", true);

    //Button b2("LoadButton", Vector2D(2, 2), bs, "Load Game", true);

    //Button b3("SettingsButton", Vector2D(2, 2), bs, "Settings", true);

    //Button b4("ExitButton", Vector2D(2, 2), bs, "Quite", true);

    //Button b5("EditTest", Vector2D(2, 2), bs, "EditTest", true);
    ////Add Buttons to the Panel
    //panel.AddChild(&b1);

    //panel.AddChild(&b2);

    //panel.AddChild(&b3);

    //panel.AddChild(&b4);

    //panel.EditChild(b4.GetId(), &b5);
    ////Add Panel o the Controller
    //controller->AddUIControl(&panel);
    

#pragma endregion
    
#pragma region Lab 4

    ConsoleFuncs::Init(console);

    ConsoleFuncs::PrintColorMsgAtCenter("Lab 4", Colors::ORANGE, 0);

    ConsoleFuncs::SetDefaultColor(Colors::White);
   
    /*float startAngle = 0;

    float endAngle = 0;

    float step = 0;

    auto startStr = ConsoleFuncs::Input("Enter the start angle value : ", Colors::GREEN,
        CheckNumber);

    startAngle = static_cast<float>(startAngle) * (M_PI/180);

    auto endStr = ConsoleFuncs::Input("Enter the end angle vaue: ", Colors::GREEN,
        CheckNumber);

    endAngle = static_cast<float>(endAngle) * (M_PI/180);

    auto stepStr = ConsoleFuncs::Input("Enter the step value: ", Colors::GREEN,
        CheckNumber);

    step = static_cast<float>(step) * (M_PI / 180);*/

    TextBlockStyle* txtBlStyle = new TextBlockStyle("TextBlockTest", 30, 6);

    /*TextBlock* txtBlock = new TextBlock("TextBlock", Vector2D(3, 4), *txtBlStyle, "text", true);*/

    /*controller->AddUIControl(txtBlock);*/

    TextBlock cell1 = TextBlock("cell1", Vector2D(), *txtBlStyle, "Cell 1", true);

    TextBlock cell2 = TextBlock("cell2", Vector2D(), *txtBlStyle, "Cell 2", true);

    TextBlock cell3 = TextBlock("cell3", Vector2D(), *txtBlStyle, "Cell 3", true);

    TableRowStyle tblRowStyle = TableRowStyle("tblRow", 0,0);

    TableRow row1 = TableRow("TableRow1", Vector2D(3,3), tblRowStyle, "", true);

    row1.AddUIControl(&cell1);

    row1.AddUIControl(&cell2);

    row1.AddUIControl(&cell3);

#pragma endregion

    controller->AddUIControl(&row1);
    //Draw UI
    controller->Draw();
    
    //controller->Dispose();

    system("Pause");
}

