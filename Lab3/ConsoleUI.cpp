#include"ConsoleUI.h"

using namespace UIControls;

using namespace ConsoleUI;

using namespace ConsoleFuncs;

using namespace ConsoleGraphics;

#pragma region Static Definitions

WORD UIControls::Colors::White = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE |

FOREGROUND_INTENSITY;

WORD UIControls::Colors::BLACK = 0;

WORD UIControls::Colors::GREY = FOREGROUND_INTENSITY;

WORD UIControls::Colors::LIGHTGRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

WORD UIControls::Colors::BLUE = FOREGROUND_BLUE;

WORD UIControls::Colors::ORANGE = FOREGROUND_RED | FOREGROUND_GREEN;

WORD UIControls::Colors::WhiteBack = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE |

BACKGROUND_INTENSITY;

WORD UIControls::Colors::BLACKBack = 0;

WORD UIControls::Colors::GREYBack = BACKGROUND_INTENSITY;

WORD UIControls::Colors::LIGHTGRAYBack = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;

WORD UIControls::Colors::BLUEBack = BACKGROUND_BLUE;

WORD UIControls::Colors::ORANGEBack = BACKGROUND_RED | BACKGROUND_GREEN;

#pragma endregion

#pragma region Styles definitions

#pragma region Style

#pragma region Ctor

Style::Style(const string name, UShort width, UShort height, WORD brdColor, WORD backColor, 
	UShort minWidth,
	UShort minHeight, UShort maxWidth, UShort maxHeight):
	m_Name(name), m_width(width), m_height(height), m_BorderColor(brdColor),
	m_BackGroundColor(backColor), m_minWidth(minWidth), m_minHeight(minHeight),
	m_maxWidth(maxWidth), m_maxHeight(maxHeight)
{}

#pragma endregion

#pragma region Getters

string Style::GetName()const
{
	return m_Name;
}

WORD Style::GetBrdColor()const
{
	return m_BorderColor;
}

WORD Style::GetBackColor()const
{
	return m_BackGroundColor;
}

UShort Style::GetWidth() const
{
	return m_width;
}

UShort Style::GetHeight() const
{
	return m_height;
}

UShort Style::GetMinWidth() const
{
	return m_minWidth;
}

UShort Style::GetMinHeight() const
{
	return m_minHeight;
}

UShort Style::GetMaxWidth() const
{
	return m_maxWidth;
}

UShort Style::GetMaxHeight() const
{
	return m_maxHeight;
}

#pragma endregion

#pragma endregion

#pragma region ButtonStyle

#pragma region Ctor

ButtonStyle::ButtonStyle(
	const string name, UShort width, UShort height,
	Vector2D contentPos,
    WORD brdColor, 
	WORD backColor, 
	WORD Foreground,	
	UShort minWidth,
	UShort minHeight, UShort maxWidth, UShort maxHeight
	) : 
	Style(name, width, height, brdColor, backColor, minWidth, minHeight, maxWidth, maxHeight),
	m_Foreground(Foreground),
	m_ContentPosition(contentPos)
	
{

}

#pragma endregion

#pragma region Getters

WORD ButtonStyle::GetForeground()const
{
	return m_Foreground;
}

Vector2D ButtonStyle::GetContentPosition()const
{
	return m_ContentPosition;
}

#pragma endregion

#pragma endregion

#pragma region PanelStyle
#pragma region Ctor

PanelStyle::PanelStyle(
	const string name, UShort width, UShort height,
	Vector2D ChildsPosition,
	Vector2D HeaderPos,
	WORD brdColor,
	WORD backColor,
	WORD Foreground,
	UShort minWidth,
	UShort minHeight, UShort maxWidth, UShort maxHeight
) : m_ChildPostion(ChildsPosition), m_HeaderPosition(HeaderPos),
Style(name, width, height, brdColor, backColor, minWidth, minHeight
	, maxWidth, maxHeight)
{}



#pragma endregion

#pragma region Getters

Vector2D PanelStyle::GetChildPosition()const
{
	return m_ChildPostion;
}

Vector2D PanelStyle::GetHeaderPosition()const
{
	return m_HeaderPosition;
}

#pragma endregion


#pragma endregion



#pragma endregion

#pragma region UIControl definitions

#pragma region UI Control

#pragma region Ctors

UIControl::UIControl(const string& name, Vector2D position,const string &content,
	bool visibility) :
	m_Name(name), m_position(position), m_Content(content), m_visibility(visibility)
{
	m_Idlast++;

	m_Id = m_Idlast;
}

#pragma endregion

#pragma region Getters

bool UIControl::GetVisibility()const
{
	return m_visibility;
}

Vector2D UIControl::GetPosition() const
{
	return m_position;
}

string UIControl::GetName()const
{
	return m_Name;
}

const long int & UIControl::GetId()const
{
	return m_Id;
}

string UIControl::GetContent()const
{
	return m_Content;
}

#pragma endregion

#pragma region Setters

void UIControl::SetVisibility(bool& visibility)
{
	m_visibility = visibility;
}

void UIControl::SetPosition(Vector2D& newPosition)
{
	m_position = newPosition;
}


void UIControl::SetContent(const string newContent)
{
	m_Content = newContent;
}

#pragma endregion

#pragma region Functions

#pragma endregion


#pragma endregion

#pragma region Button

#pragma region Ctors

Button::Button(const string& name, Vector2D position, ButtonStyle style, const string& content,
	bool visibility)
	: UIControl::UIControl(name, position, content, visibility), m_style(style) {}

#pragma endregion

#pragma region Getters
ButtonStyle Button::GetStyle()const
{
	return m_style;
}
#pragma endregion

#pragma region Seters
void Button::SetStyle(ButtonStyle style)
{
	m_style = style;
}
#pragma endregion



#pragma region Functions
void Button::Render()const
{	
	auto v = GetPosition();

	DrawRect(v[0], v[1], this->GetStyle().GetWidth(),
		this->GetStyle().GetHeight(), GetStyle().GetBrdColor(), GetStyle().GetBackColor());
	
	auto pos = GetStyle().GetContentPosition();
		
	auto cv = v + pos;

	SetCursorPosition(cv[0], cv[1]);

	PrintColorMsg(GetContent(), GetStyle().GetForeground());
		
	SetCursorPosition(0,0);
}
#pragma endregion


#pragma endregion

#pragma region Static definitions

long int UIControls::UIControl::m_Idlast = 0;

#pragma endregion

#pragma region Panel

#pragma region ctors

Panel::Panel(const string& name, Vector2D position, PanelStyle style, const string& content,
	bool visibility) 
	:UIControl(name, position, content, visibility), m_style(style) {}

#pragma endregion

#pragma region Getters

PanelStyle Panel::GetStyle()const
{
	return m_style;
}

#pragma endregion

#pragma region Setters

void Panel::SetStyle(PanelStyle &style)
{
	m_style = style;
}

#pragma endregion

#pragma region CRUD Functions

const UIControl* Panel::GetChildren(unsigned int& size)const
{
	size = m_Children.size();

	return m_Children[0];
}

const UIControl& Panel::GetChild(const long int& Id)const
{
	for (auto c : m_Children)
		if (c->GetId() == Id)
			return *c;
}

const UIControl* Panel::GetChild(const string& name)const
{
	for (auto c : m_Children)
		if (c->GetName() == name)
			return c;
}

void Panel::AddChild(UIControl* child)
{
	m_Children.push_back(child);
}

void Panel::EditChild(const long int& childId, UIControl *newChild)
{
	for (auto c : m_Children)
	{
		if (c->GetId() == childId)
			c = newChild;
	}
}

void Panel::EditChild(const string& elemName, UIControl *newChild)
{
	for (auto c : m_Children)
	{
		if (c->GetName() == elemName)
			c = newChild;
	}
}

void Panel::RemoveChild(const long int& childId)
{
	size_t size = m_Children.size();

	size_t pos = -1;

	for (size_t i = 0; i < size; ++i)
	{
		pos = m_Children[i]->GetId() == childId ? i : -1;
	}

	if (pos != -1)
		m_Children.erase(m_Children.begin() + pos);
}

void Panel::RemoveChild(const string& elemName)
{
	size_t size = m_Children.size();

	size_t pos = -1;

	for (size_t i = 0; i < size; ++i)
	{
		pos = m_Children[i]->GetName() == elemName ? i : -1;
	}

	if (pos != -1)
		m_Children.erase(m_Children.begin() + pos);
}


#pragma endregion

#pragma region Functions

void Panel::Render() const
{
	
}

#pragma endregion



#pragma endregion


#pragma endregion

#pragma region ConsoleUI definitions

#pragma region Ctors

ConsoleUIController::ConsoleUIController(HANDLE &console)
{
	ConsoleFuncs::Init(console);
}

ConsoleUIController::~ConsoleUIController()
{
	delete m_instance;
}

#pragma endregion


#pragma region Functions

#pragma region Initializatiion

ConsoleUIController* const ConsoleUIController::Initialize(HANDLE &console)
{
	if (m_instance == nullptr)
		m_instance = new ConsoleUIController(console);

	return m_instance;
}

#pragma endregion

#pragma region Functions

void ConsoleUIController::Draw()
{
	for (auto c : m_WindowControlls)
		if(c->GetVisibility())
		c->Render();
}

void ConsoleUIController::AddUIControl(UIControls::UIControl *newChild)
{
	m_WindowControlls.push_back(newChild);
}

void ConsoleUIController::EditUIControl(const long int& childId, UIControl *newChild)
{

}

void ConsoleUIController::EditUIControl(const string& elemName, UIControl *newChild)
{

}

void ConsoleUIController::RemoveUIControl(const long int& childId)
{

}

void ConsoleUIController::RemoveUIControl(const string& elemName)
{

}

#pragma endregion

#pragma region Satic Definitions

ConsoleUIController* ConsoleUI::ConsoleUIController::m_instance = nullptr;

#pragma endregion


#pragma endregion


#pragma endregion 
