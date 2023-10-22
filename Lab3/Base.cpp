#include"Base.h"

#pragma region Init Static Fields
/// <summary>
/// Vector dimensions
/// </summary>
unsigned char ConsoleCoords::m_DIMENSIONS = 2;

/// <summary>
/// Message that is used to ask Coordinate input
/// </summary>
std::string ConsoleCoords::m_InputMsg = "Enter Coordinate ";

#pragma endregion

#pragma region Definition of the functions

#pragma region Ctors
/// <summary>
/// Empty Ctor
/// </summary>
ConsoleCoords::ConsoleCoords() : m_x(0), m_y(0) {}

/// <summary>
/// Main Ctor
/// </summary>
/// <param name="x">X - Coord</param>
/// <param name="y">Y - Coord</param>
ConsoleCoords::ConsoleCoords(UShort x, UShort y) : m_x(x), m_y(y) {}

/// <summary>
/// Copy ctor
/// </summary>
/// <param name="other">Source for copy</param>
ConsoleCoords::ConsoleCoords(const ConsoleCoords& other) : m_x(other.m_x), m_y(other.m_y) {}

#pragma endregion

#pragma region Functions
/// <summary>
/// Checks wether string is number
/// </summary>
/// <param name="str">String for check</param>
/// <param name="error">Error message</param>
/// <param name="number">number that we get from string</param>
/// <returns>Wether convertion is correct</returns>
bool ConsoleCoords::isNumber(const std::string& str, std::string& error, UShort& number)
{
	if (str.empty())
	{
		error = "You have input empty string1";
		return false;
	}

	for (char c : str)
	{
		if (!isdigit(c))
		{
			error = "Input is not a digit!";

			return false;
		}
	}

	try
	{
		number = static_cast<UShort>(stoi(str));
	}
	catch (const std::exception&)
	{
		error = "Wrong input format. Can't cast to unsigned short!!!";

		return false;
	}

	return true;
}

#pragma region Get Set X
/// <summary>
/// Get the copy of the X coord
/// </summary>
/// <returns>Copy of the X coords</returns>
UShort ConsoleCoords::GetX() const
{
	return m_x;
}
/// <summary>
/// 
/// </summary>
/// <param name="x">New X Coord</param>
void ConsoleCoords::SetX(UShort x)
{
	m_x = x;
}

#pragma endregion

#pragma region Get Set Y
/// <summary>
/// Gets the copy of the Y coord
/// </summary>
/// <returns>Copy of the Y coords</returns>
UShort ConsoleCoords::GetY() const
{
	return m_y;
}

/// <summary>
/// Sets the new Value of the Y coord
/// </summary>
/// <param name="y">New Y coord value</param>
void ConsoleCoords::SetY(UShort y)
{
	m_y = y;
}
/// <summary>
/// Sets new X and Y Coords
/// </summary>
/// <param name="x">New X coord</param>
/// <param name="y">New Y coord</param>
void ConsoleCoords::SetXY(UShort x, UShort y)
{
	m_x = x;

	m_y = y;
}

#pragma endregion

#pragma endregion

#pragma region Operators
/// <summary>
/// Assignment operator
/// </summary>
/// <param name="other">Source object</param>
/// <returns>reference to a new object</returns>
ConsoleCoords& ConsoleCoords::operator= (const ConsoleCoords& other)
{
	m_x = other.m_x;

	m_y = other.m_y;

	return *this;
}

#pragma endregion


#pragma endregion
