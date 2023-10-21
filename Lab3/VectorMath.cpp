#include"VectorMath.h"
#include <cstddef>
using namespace VectorMath;
#pragma region Point

#pragma region Definitions

#pragma region Ctors

Point2D::Point2D() :ConsoleCoords() {}

Point2D::Point2D(const Point2D& other)
{
	//Initialize private fields of the base class
	ConsoleCoords::SetXY(other.GetX(), other.GetY());

	//Init logic for the current class
}

Point2D::Point2D(const UShort x, const UShort y) : ConsoleCoords(x, y) {}



#pragma endregion

#pragma region Functions

#pragma region Getters

UShort Point2D::GetX() const
{
	return ConsoleCoords::GetX();
}

UShort Point2D::GetY() const
{
	return ConsoleCoords::GetY();
}

#pragma endregion

#pragma region Setters

void Point2D::SetX(UShort x)
{
	ConsoleCoords::SetX(x);
}

void Point2D::SetY(UShort y)
{
	ConsoleCoords::SetY(y);
}

void Point2D::SetXY(UShort x, UShort y)
{
	ConsoleCoords::SetXY(x, y);
}

#pragma endregion

#pragma endregion

#pragma region Operators

#pragma region Nath

Vector2D Point2D::operator-(const Point2D& start)const
{
	return Vector2D(start, *this);
}

#pragma endregion




#pragma endregion


#pragma endregion


#pragma endregion

#pragma region Vectors

#pragma region Ctors

Vector2D::Vector2D() : ConsoleCoords()
{

}

Vector2D::Vector2D(const UShort x, const UShort y)
{
	ConsoleCoords::SetXY(x, y);
}

Vector2D::Vector2D(const Point2D& start, const  Point2D& end)
{
	ReCalcVectorCoords(start, end);
}

Vector2D::Vector2D(const Vector2D& other)
{
	SetXY(other.GetX(), other.GetY());
}

#pragma endregion

#pragma region Functions

#pragma region Private Functions



void Vector2D::ReCalcVectorCoords(const Point2D& start, const Point2D& end)
{
	SetXY(end.GetX() - start.GetX(), end.GetY() - start.GetY());
}

#pragma endregion

#pragma region Getters

UShort Vector2D::GetX() const
{
	return ConsoleCoords::GetX();
}

UShort Vector2D::GetY() const
{
	return ConsoleCoords::GetY();
}

#pragma endregion

#pragma region Setters

void Vector2D::SetXY(UShort x, UShort y)
{
	ConsoleCoords::SetXY(x, y);
}

void Vector2D::SetX(UShort x)
{
	ConsoleCoords::SetX(x);
}

void Vector2D::SetY(UShort y)
{
	ConsoleCoords::SetY(y);
}

#pragma endregion

UShort Vector2D::GetLength()const
{
	return static_cast<UShort>(sqrtf(GetX() * GetX() + GetY() * GetY()));
}

UShort Vector2D::DotProduct(const Vector2D& vector)const
{
	return vector.GetX() * this->GetX() + vector.GetY() * this->GetY();
}

Vector2D Vector2D::Normalize()
{
	UShort len = this->GetLength() == 0 ? len = 1 : this->GetLength();

	return Vector2D(this->GetX() / len, this->GetY() / len);
}

#pragma region Operators

#pragma region LogicalOperators

bool Vector2D::operator == (const Vector2D& other)const
{
	return (this->GetX() == other.GetX()) && (this->GetY() == other.GetY());
}

bool Vector2D::operator != (const Vector2D& other)const
{
	return !(this->GetX() == other.GetX()) && (this->GetY() == other.GetY());
}

bool Vector2D::operator > (const Vector2D& other)const
{
	return this->GetLength() > other.GetLength();
}

bool Vector2D::operator < (const Vector2D& other)const
{
	return this->GetLength() < other.GetLength();
}

bool Vector2D::operator >= (const Vector2D& other)const
{
	return this->GetLength() >= other.GetLength();
}

bool Vector2D::operator <= (const Vector2D& other)const
{
	return this->GetLength() <= other.GetLength();
}

#pragma endregion


Vector2D Vector2D::operator+(const Vector2D& vector)const
{
	return Vector2D(vector.GetX() + ConsoleCoords::GetX(), vector.GetY() + ConsoleCoords::GetY());
}

Vector2D Vector2D::operator-(const Vector2D& vector)const
{
	return Vector2D(this->GetX() - vector.GetX(), this->GetY() - vector.GetY());
}

UShort Vector2D::operator *(const Vector2D& vector)const
{
	return DotProduct(vector);
}

Vector2D Vector2D::operator *(const UShort& number)const
{
	return Vector2D(this->GetX() * number, this->GetY() * number);
}

Vector2D& Vector2D::operator=(const Vector2D& vector)
{
	this->SetXY(vector.GetX(), vector.GetY());

	return *this;
}

void Vector2D::operator+=(const Vector2D& other)
{
	SetXY(GetX() + other.GetX(), GetY() + other.GetY());
}

void Vector2D::operator-=(const Vector2D& other)
{
	SetXY(GetX() - other.GetX(), GetY() - other.GetY());
}

void Vector2D::operator *= (const UShort& number)
{
	this->SetXY(this->GetX() * number, this->GetY() * number);
}

UShort Vector2D::operator[](const unsigned int& i) const
{
	switch (i)
	{
	case 0:
		return GetX();

	case 1:
		return GetY();
	default:
		throw std::runtime_error("You are requesting to the dimension that doesn't exist!!!");
	}
}

#pragma endregion


#pragma endregion


#pragma endregion

