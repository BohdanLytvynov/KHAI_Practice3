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

WORD UIControls::Colors::GREEN = FOREGROUND_GREEN;

WORD UIControls::Colors::CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE;

WORD UIControls::Colors::RED = FOREGROUND_RED;

WORD UIControls::Colors::PURPLE = FOREGROUND_RED | FOREGROUND_BLUE;

WORD UIControls::Colors::LIGHTBLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;

WORD UIControls::Colors::LIGHTGREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY;

WORD UIControls::Colors::LIGHTCYAN = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;

WORD UIControls::Colors::LIGHTRED = FOREGROUND_RED | FOREGROUND_INTENSITY;

WORD UIControls::Colors::LIGHTPURPLE = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;

WORD UIControls::Colors::YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

WORD UIControls::Colors::ORANGE = FOREGROUND_RED | FOREGROUND_GREEN;

/// <summary>
/// Background colors
/// </summary>

WORD UIControls::Colors::WhiteBack = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE |

BACKGROUND_INTENSITY;

WORD UIControls::Colors::BLACKBack = 0;

WORD UIControls::Colors::GREYBack = BACKGROUND_INTENSITY;

WORD UIControls::Colors::LIGHTGRAYBack = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;

WORD UIControls::Colors::BLUEBack = BACKGROUND_BLUE;

WORD UIControls::Colors::GREENBack = BACKGROUND_GREEN;

WORD UIControls::Colors::CYANBack = BACKGROUND_GREEN | BACKGROUND_BLUE;

WORD UIControls::Colors::REDBack = BACKGROUND_RED;

WORD UIControls::Colors::PURPLEBack = BACKGROUND_RED | BACKGROUND_BLUE;

WORD UIControls::Colors::LIGHTBLUEBack = BACKGROUND_BLUE | BACKGROUND_INTENSITY;

WORD UIControls::Colors::LIGHTGREENBack = BACKGROUND_GREEN | BACKGROUND_INTENSITY;

WORD UIControls::Colors::LIGHTCYANBack = BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;

WORD UIControls::Colors::LIGHTREDBack = BACKGROUND_RED | BACKGROUND_INTENSITY;

WORD UIControls::Colors::LIGHTPURPLEBack = BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY;

WORD UIControls::Colors::YELLOWBack = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;

WORD UIControls::Colors::ORANGEBack = BACKGROUND_RED | BACKGROUND_GREEN;

#pragma endregion

#pragma region Styles definitions

#pragma region UIContentStyle definition

#pragma region Ctor

UIContentStyle::UIContentStyle(Vector2D contentPosition, WORD contentForeground)
	: m_ContentPosition(contentPosition), m_Foreground(contentForeground) {}

#pragma endregion

#pragma region Getters

WORD UIContentStyle::GetForeground()const
{
	return m_Foreground;
}

Vector2D UIContentStyle::GetContentPosition()const
{
	return m_ContentPosition;
}

#pragma endregion


#pragma endregion

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

#pragma region Setters

void Style::SetWidth(UShort width)
{
	m_width = width;
}

void Style::SetHeight(UShort height)
{
	m_height = height;
}

void Style::SetMinWidth(UShort minWidth)
{
	m_minWidth = minWidth;
}

void Style::SetMinHeight(UShort minHeight)
{
	m_minHeight = minHeight;
}

void Style::GetMaxWidth(UShort maxWidth)
{
	m_maxWidth = maxWidth;
}

void Style::GetMaxHeight(UShort maxHeight)
{
	m_maxHeight = maxHeight;
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
	UIContentStyle(contentPos, Foreground)
	
{

}

#pragma endregion

#pragma endregion

#pragma region PanelStyle
#pragma region Ctor

PanelStyle::PanelStyle(
	const string name, UShort width, UShort height,
	Vector2D ChildsPosition,
	Vector2D HeaderPos,
	UShort interval,
	WORD brdColor,
	WORD backColor,
	WORD Foreground,
	UShort minWidth,
	UShort minHeight, UShort maxWidth, UShort maxHeight
) : 
Style(name, width, height, brdColor, backColor, minWidth, minHeight
	,maxWidth, maxHeight), UIContentStyle(HeaderPos, Foreground),
	m_ChildPostion(ChildsPosition), m_Interval(interval)
{}

#pragma endregion

#pragma region Getters

UShort PanelStyle::GetInterval()const
{
	return m_Interval;
}

Vector2D PanelStyle::GetChildPosition()const
{
	return m_ChildPostion;
}

#pragma endregion


#pragma endregion

#pragma region TextBlockSyle

#pragma region Ctor
TextBlockStyle::TextBlockStyle(const string name, UShort width, UShort height,
	Vector2D contentPos,
	WORD brdColor,
	WORD backColor,
	WORD Foreground,
	UShort minWidth,
	UShort minHeight, UShort maxWidth, UShort maxHeight) 
	: Style(name, width, height, brdColor, backColor, minWidth, minHeight
		, maxWidth, maxHeight), UIContentStyle(contentPos, Foreground)
	
{

}
#pragma endregion


#pragma endregion

#pragma region TableRowStyle

#pragma region Ctor

TableRowStyle::TableRowStyle(const string name, UShort width, UShort height, WORD brdColor,
	WORD backColor, UShort minWidth,
	UShort minHeight, UShort maxWidth, UShort maxHeight, UShort horOffset) :
	m_HorOffset(horOffset),
	Style(name, width, height, brdColor, backColor, minWidth, minHeight, maxWidth, maxHeight)
{

}

#pragma endregion

#pragma region Getters

UShort TableRowStyle::GetHorOffset()const
{
	return m_HorOffset;
}

#pragma endregion

#pragma region Setters

void TableRowStyle::SetHorOffset(const UShort &horOffset)
{
	m_HorOffset = horOffset;
}

#pragma endregion

#pragma endregion

#pragma endregion

#pragma region UIControl definitions

#pragma region UI Control

#pragma region Ctors

UIControl::UIControl(const string& name, Vector2D position,const string &content,
	bool visibility, Style* style) :
	m_Name(name), m_position(position), m_Content(content), m_visibility(visibility),
	m_stylePtr(style)
{
	m_Idlast++;

	m_Id = m_Idlast;	
}

#pragma endregion

#pragma region Getters

Style* UIControl::GetStylePtr()
{
	return m_stylePtr;
}

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

void UIControl::SetStylePtr(Style *ptr)
{
	m_stylePtr = ptr;
}

void UIControl::SetVisibility(bool& visibility)
{
	m_visibility = visibility;
}

void UIControl::SetPosition(Vector2D& newPosition)
{
	m_position = newPosition;
}


void UIControl::SetContent(const string &newContent)
{
	m_Content = newContent;
}

#pragma endregion

#pragma endregion

#pragma region Button

#pragma region Ctors

Button::Button(const string& name, Vector2D position, ButtonStyle style, const string& content,
	bool visibility)
	: UIControl::UIControl(name, position, content, visibility, &style)
{
	
}

#pragma endregion

#pragma region Getters
ButtonStyle* Button::GetStyle()
{
	return reinterpret_cast<ButtonStyle*>(UIControl::GetStylePtr());
}

#pragma endregion

#pragma region Seters
void Button::SetStyle(ButtonStyle *style)
{
	UIControl::SetStylePtr(style);
}
#pragma endregion



#pragma region Functions
void Button::Render()
{	
	auto v = GetPosition();
	
	auto style = this->GetStyle();

	DrawRect(v[0], v[1], style->GetWidth(),
		style->GetHeight(), style->GetBrdColor(), style->GetBackColor());
	
	auto pos = GetStyle()->GetContentPosition();
		
	auto cv = v + pos;

	SetCursorPosition(cv[0], cv[1]);

	PrintColorMsg(GetContent(), style->GetForeground());
		
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
	:UIControl(name, position, content, visibility, &style)
{

}

#pragma endregion

#pragma region Getters

PanelStyle* Panel::GetStyle()
{
	return reinterpret_cast<PanelStyle*>(UIControl::GetStylePtr());
}

#pragma endregion

#pragma region Setters

void Panel::SetStyle(PanelStyle *style)
{
	UIControl::SetStylePtr(style);
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
		{
			*c = *newChild;

			break;
		}
		
	}
}

void Panel::EditChild(const string& elemName, UIControl *newChild)
{
	for (auto c : m_Children)
	{
		if (c->GetName() == elemName)
		{
			*c = *newChild;
			
			break;
		}
			
	}
}

void Panel::RemoveChild(const long int& childId)
{
	size_t size = m_Children.size();

	size_t pos = -1;

	for (size_t i = 0; i < size; ++i)
	{
		if (m_Children[i]->GetId() == childId)
		{
			pos = i;
			break;
		}
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
		if (m_Children[i]->GetName() == elemName)
		{
			pos = i;
			break;
		}
	}

	if (pos != -1)
		m_Children.erase(m_Children.begin() + pos);
}


#pragma endregion

#pragma region Functions

void Panel::Render()
{
	PanelStyle *style = this->GetStyle();

	Vector2D Globpos = this->GetPosition();

	ConsoleGraphics::DrawRect(Globpos[0], Globpos[1], style->GetWidth(),
		style->GetHeight(), style->GetBrdColor(), style->GetBackColor());
	
	Vector2D calcHeaderPos = Globpos + style->GetContentPosition();

	ConsoleFuncs::SetCursorPosition(calcHeaderPos[0], calcHeaderPos[1]);

	ConsoleFuncs::PrintColorMsg(this->GetContent(), style->GetForeground());

	Vector2D calcChildPos = Globpos + style->GetChildPosition();
	
	UShort height = 0;

	for (UIControl* c : m_Children)
	{
		if (c->GetVisibility())
		{
			c->SetPosition(calcChildPos);
									
			c->GetStylePtr()->SetWidth(style->GetWidth() - style->GetChildPosition()[0] * 2);

			c->Render();

			calcChildPos += Vector2D(0, c->GetStylePtr()->GetHeight()/2 + style->GetInterval());
		}
	}

	ConsoleFuncs::SetCursorPosition(0,0);
			
}

#pragma endregion



#pragma endregion

#pragma region TextBlock

#pragma region Ctor

TextBlock::TextBlock(const string& name, Vector2D position, TextBlockStyle style, const string& content,
	bool visibility) : UIControl(name, position, content, visibility, &style)
{

}

#pragma endregion

#pragma region Getters

TextBlockStyle* TextBlock::GetStyle()
{
	return reinterpret_cast<TextBlockStyle*>(UIControl::GetStylePtr());
}

#pragma endregion

#pragma region Setters

void TextBlock::SetStyle(TextBlockStyle *newStyle)
{
	UIControl::SetStylePtr(newStyle);
}

#pragma endregion


#pragma region Functions

void TextBlock::Render()
{
	auto v = GetPosition();

	auto style = this->GetStyle();

	DrawRect(v[0], v[1], style->GetWidth(),
		style->GetHeight(), style->GetBrdColor(), style->GetBackColor());

	auto pos = GetStyle()->GetContentPosition();

	auto cv = v + pos;

	SetCursorPosition(cv[0], cv[1]);

	PrintColorMsg(GetContent(), style->GetForeground());

	SetCursorPosition(0, 0);
}

#pragma endregion



#pragma endregion

#pragma region TableRow

#pragma region Ctor

TableRow::TableRow(const string& name, Vector2D position, TableRowStyle style,
	const string& content,
	bool visibility) : UIControl(name, position, content, visibility, &style)
{
}

#pragma endregion

#pragma region CRUD Functions

void TableRow::AddUIControl(UIControl* control)
{
	if (control == nullptr)
		return;

	m_Cells.push_back(control);	
}

void TableRow::RemoveUIControl(const string& elemName)
{
	if (elemName.empty())
		return;

	int index = -1;
	size_t length = m_Cells.size();

	for (size_t i = 0; i < length; i++)
	{
		if (m_Cells[i]->GetName() == elemName)
		{
			index = i;
			break;
		}
	}

	if(index != -1)
		m_Cells.erase(m_Cells.begin() + index);
}

void TableRow::RemoveUIControl(const long int& id)
{	
	int index = -1;
	size_t length = m_Cells.size();

	for (size_t i = 0; i < length; i++)
	{
		if (m_Cells[i]->GetId() == id)
		{
			index = i;
			break;
		}
	}

	if (index != -1)
		m_Cells.erase(m_Cells.begin() + index);
}

UIControl* TableRow::GetUIControls(size_t& size)
{
	size = m_Cells.size();

	return m_Cells[0];
}

#pragma endregion

#pragma region Getters

TableRowStyle* TableRow::GetStyle()
{
	return reinterpret_cast<TableRowStyle*>(UIControl::GetStylePtr());
}

#pragma endregion

#pragma region Setters

#pragma endregion


#pragma region Functions

void TableRow::Render()
{
	TableRowStyle* Currstyle = this->GetStyle();

	Vector2D position = this->GetPosition();

	Vector2D newPosition;
		
	auto horOffset = Currstyle->GetHorOffset();
	int i = 0;
	for (UIControl* UIctrl : m_Cells)
	{
		if (UIctrl == nullptr)
			return;
		
		if (UIctrl->GetVisibility())
		{
			newPosition = position + Vector2D(((UIctrl->GetStylePtr()->GetWidth() + horOffset) * i), 0);

			UIctrl->SetPosition(newPosition);

			UIctrl->Render();
		}

		i++;
	}			
}

#pragma endregion


#pragma endregion


#pragma endregion

#pragma region ConsoleUI definitions

#pragma region Functions

void ConsoleUIController::Draw()
{
	for (auto c : m_WindowControlls)
		if (c->GetVisibility())
			c->Render();
}

void ConsoleUIController::AddUIControl(UIControls::UIControl* newChild)
{
	m_WindowControlls.push_back(newChild);
}

void ConsoleUIController::EditUIControl(const long int& childId, UIControl* newChild)
{
	for (auto c : m_WindowControlls)
	{
		if (c->GetId() == childId)
		{
			*c = *newChild;
		}
	}
}

void ConsoleUIController::EditUIControl(const string& elemName, UIControl* newChild)
{
	for (auto c : m_WindowControlls)
	{
		if (c->GetName() == elemName)
		{
			*c = *newChild;

			break;
		}
	}
}

void ConsoleUIController::RemoveUIControl(const long int& childId)
{
	size_t pos = -1;

	size_t size = m_WindowControlls.size();

	for (size_t i = 0; i < size; ++i)
	{
		if (m_WindowControlls[i]->GetId() == childId)
		{
			pos = i;
			break;
		}

		if (pos != -1)
			m_WindowControlls.erase(m_WindowControlls.begin() + pos);

	}
}

void ConsoleUIController::RemoveUIControl(const string& elemName)
{
	size_t pos = -1;

	size_t size = m_WindowControlls.size();

	for (size_t i = 0; i < size; ++i)
	{
		if (m_WindowControlls[i]->GetName() == elemName)
		{
			pos = i;
			break;
		}

		if (pos != -1)
			m_WindowControlls.erase(m_WindowControlls.begin() + pos);

	}
}

UIControl* ConsoleUIController::GetControls(size_t& size)
{
	size = m_WindowControlls.size();

	return m_WindowControlls[0];
}

#pragma endregion

#pragma region Ctors

ConsoleUIController::ConsoleUIController(HANDLE &console)
{
	ConsoleFuncs::Init(console);
}

ConsoleUIController::~ConsoleUIController()
{
	if (m_instance != nullptr)
	{
		size_t size = 0;

		UIControl* cntrl1 = m_instance->GetControls(size);

		for (size_t i = 0; i < size; i++)
		{
			try
			{
				if((cntrl1 + i) != nullptr)
					delete (cntrl1 + i);//Try to release resources if Heap was used to store UIControls
			}
			catch (const std::exception&)
			{
			}			
		}

		delete m_instance;
	}

	
}

void ConsoleUIController::Dispose()
{	
	m_instance->~ConsoleUIController();
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

#pragma region Satic Definitions

ConsoleUIController* ConsoleUI::ConsoleUIController::m_instance = nullptr;

#pragma endregion


#pragma endregion


#pragma endregion 
