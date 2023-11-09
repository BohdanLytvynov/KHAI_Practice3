// Lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _USE_MATH_DEFINES

#include <iostream>
#include<cmath>
#include"VectorMath.h"
#include"ConsoleUI.h"
#include"Console.h"
#include<string>
#include<iomanip>

using namespace ConsoleUI;

using namespace UIControls;

using namespace std;

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

void ModifyOutputStream(ostream& ostream)
{
	ostream << setiosflags(ios_base::fixed) << ostream.precision(4);
}

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

#pragma region Styles

	TextBlockStyle cellStyle = TextBlockStyle("txtBlStyle", 5, 6);

	TableRowStyle tablerowStyle = TableRowStyle("TableRowStyle", 0, 0, 1);

	DataTableStyle dataTableStyle = DataTableStyle("DataTblStyle", 0, 0, 1,
		Vector2D(1, 1));

#pragma endregion

#pragma region Get User Input Block

	float startAngle = 0;

	float endAngle = 0;

	float step = 0;

	auto startStr = ConsoleFuncs::Input("Enter the start angle value : ", Colors::GREEN,
		CheckNumber);

	startAngle = stof(startStr);

	auto endStr = ConsoleFuncs::Input("Enter the end angle vaue: ", Colors::GREEN,
		CheckNumber);

	endAngle = stof(endStr);

	auto stepStr = ConsoleFuncs::Input("Enter the step value: ", Colors::GREEN,
		CheckNumber);

	step = stof(stepStr);

#pragma endregion

#pragma region Build Data Table

	string Tablemsg = "Sine and Cosine Table.\n" + string("Start Angle: ") + startStr +
		string("End Angle: ") + endStr;

#pragma endregion

	DataTable table = DataTable("table", Vector2D(), dataTableStyle, Tablemsg, true);

	// 1 Table Row

	TextBlock sineValue = TextBlock("sineValue", Vector2D(), cellStyle, "Sine Value:", true);

	TextBlock cosineValue = TextBlock("cosineValue", Vector2D(), cellStyle, "Cosine Value:", true);

	TextBlock AngleValue = TextBlock("AngleValue", Vector2D(), cellStyle, "Angle Value:", true);

	TableRow rowHeaders = TableRow("Headeers", Vector2D(), tablerowStyle, true);

	rowHeaders.AddUIControl(&AngleValue);

	rowHeaders.AddUIControl(&sineValue);

	rowHeaders.AddUIControl(&cosineValue);

	table.AddTableRow(&rowHeaders);

	int i = 0;

	const int n = (round(endAngle / step) + 1);

	TableRow* rows = new TableRow[n];
							
	while (startAngle <= endAngle)//O(n)
	{				
		rows[i].Build("row" + std::to_string(i + 2), Vector2D(), tablerowStyle, true);

		rows[i].AddUIControl(new TextBlock("Angle" + i, Vector2D(), cellStyle,
			new FloatPrecisionPrinter(startAngle, ModifyOutputStream)
			, true));
		
		rows[i].AddUIControl(new TextBlock("sine" + i, Vector2D(), cellStyle,
			new FloatPrecisionPrinter(std::sin(startAngle * (M_PI / 180)), ModifyOutputStream)
			, true));
		
		rows[i].AddUIControl(new TextBlock("cos" + i, Vector2D(), cellStyle,
			new FloatPrecisionPrinter(std::cos(startAngle * (M_PI / 180)), ModifyOutputStream)
			, true));
		
		i++;

		startAngle += step;				
	}

	

#pragma endregion


	//Draw UI
	controller->Draw();

	system("Pause");
}

