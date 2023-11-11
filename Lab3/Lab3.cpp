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
	ostream.precision(4);

	ostream << setiosflags(ios_base::fixed);
}

void ModifyOutputStreamForNummbers(ostream& ostream)
{
	ostream.precision(0);	
}


float Function(float x1, float a, float b, float c)
{
	if (x1 + 5 < 0 && c == 0)
	{
		return (1 / (a * x1)) - b;
	}
	else if (x1 + 5 > 0 && c != 0)
	{
		return (x1 - a) / x1;
	}
	else
	{
		return (10 * x1) / (c - 4);
	}
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

#pragma region Lab 4 Test 

	ConsoleFuncs::Init(console);

	ConsoleFuncs::PrintColorMsgAtCenter("Lab 4", Colors::ORANGE, 0);

	ConsoleFuncs::SetDefaultColor(Colors::White);

#pragma region Styles

	TextBlockStyle cellStyle = TextBlockStyle("txtBlStyle", 20, 6);

	TableRowStyle tablerowStyle = TableRowStyle("TableRowStyle", 1);

	DataTableStyle dataTableStyle = DataTableStyle("DataTblStyle", 1,
		Vector2D(5, 2));

#pragma endregion

#pragma region Get User Input Block

	float a = 0, b = 0, c = 0, x1 = 0, x2 = 0, dx = 0;
	
	auto Astr = ConsoleFuncs::Input("Enter the a value : ", Colors::GREEN,
		CheckNumber);

	a = stof(Astr);

	auto bstr = ConsoleFuncs::Input("Enter the b vaue: ", Colors::GREEN,
		CheckNumber);

	b = stof(bstr);

	auto cstr = ConsoleFuncs::Input("Enter the c vaue: ", Colors::GREEN,
		CheckNumber);

	c = stof(cstr);

	auto x1str = ConsoleFuncs::Input("Enter the x1 vaue: ", Colors::GREEN,
		CheckNumber);

	x1 = stof(x1str);

	auto x2str = ConsoleFuncs::Input("Enter the x2 vaue: ", Colors::GREEN,
		CheckNumber);

	x2 = stof(x2str);

	auto dxStr = ConsoleFuncs::Input("Enter the dx value: ", Colors::GREEN,
		CheckNumber);

	dx = stof(dxStr);

#pragma endregion

#pragma region Build Data Table

	string Tablemsg = "Values of F(x).\n" + string("X1: ") + x1str +
		string("X2: ") + x2str + "a: " + Astr + "b: " + bstr + "c: " + cstr
		+ "dx: " + dxStr;

#pragma endregion

	DataTable table = DataTable("table", Vector2D(2,3), &dataTableStyle, Tablemsg, true);

	// 1 Table Row

	TextBlock number = TextBlock("number", Vector2D(), &cellStyle, "Number:", true);

	TextBlock argument = TextBlock("argument", Vector2D(), &cellStyle, "Argument X:", true);

	TextBlock funcValue = TextBlock("funcValue", Vector2D(), &cellStyle, "F(X) Value:", true);

	TableRow rowHeaders = TableRow("Headers", Vector2D(), &tablerowStyle, true);

	rowHeaders.AddUIControl(&number);

	rowHeaders.AddUIControl(&argument);

	rowHeaders.AddUIControl(&funcValue);

	table.AddTableRow(&rowHeaders);

	int i = 0;

	const int n = (round(x2 / dx) + 1);

	TableRow* rows = new TableRow[n];
							
	while (x1 <= x2)//O(n)
	{				
		rows[i].Build("row" + std::to_string(i + 2), Vector2D(), tablerowStyle, true);

		rows[i].AddUIControl(new TextBlock("Number" + i, Vector2D(), &cellStyle,
			new FloatPrecisionPrinter(i + 1, ModifyOutputStreamForNummbers)
			, true));
		
		rows[i].AddUIControl(new TextBlock("Argument" + i, Vector2D(), &cellStyle,
			new FloatPrecisionPrinter(x1, ModifyOutputStream)
			, true));
		
		rows[i].AddUIControl(new TextBlock("FxValue" + i, Vector2D(), &cellStyle,
			new FloatPrecisionPrinter(Function(x1, a, b, c), ModifyOutputStream)
			, true));
		
		i++;

		x1 += dx;				
	}

	for (size_t i = 0; i < n; i++)//O(n)
	{
		table.AddTableRow(&rows[i]);
	}

#pragma endregion

	controller->AddUIControl(&table);
	//Draw UI
	controller->Draw();

	system("Pause");
}

