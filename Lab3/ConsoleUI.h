#ifndef CONSOLEUI_H

#define CONSOLEUI_H

#include"Console.h"
#include"VectorMath.h"

#pragma region Type defs

typedef unsigned short UShort;

#pragma endregion

namespace UIControls
{	
	using namespace std;

	using namespace VectorMath;

	/// <summary>
	/// Colors static class holder
	/// </summary>
	class Colors
	{
	public:
		static WORD White;

		static WORD BLACK;

		static WORD GREY;

		static WORD LIGHTGRAY;

		static WORD BLUE;

		static WORD GREEN;

		static WORD CYAN;

		static WORD RED;

		static WORD PURPLE;

		static WORD LIGHTBLUE;

		static WORD LIGHTGREEN;

		static WORD LIGHTCYAN;

		static WORD LIGHTRED;

		static WORD LIGHTPURPLE;

		static WORD YELLOW;

		static WORD ORANGE;
		/// <summary>
		/// BackGround Fonts
		/// </summary>
		static WORD WhiteBack;

		static WORD BLACKBack;

		static WORD GREYBack;

		static WORD LIGHTGRAYBack;

		static WORD BLUEBack;

		static WORD GREENBack;

		static WORD CYANBack;

		static WORD REDBack;

		static WORD PURPLEBack;

		static WORD LIGHTBLUEBack;

		static WORD LIGHTGREENBack;

		static WORD LIGHTCYANBack;

		static WORD LIGHTREDBack;

		static WORD LIGHTPURPLEBack;

		static WORD YELLOWBack;

		static WORD ORANGEBack;
	};
	
	/// <summary>
	/// Controls styling of the UI Elements
	/// </summary>
	class Style 
	{

	private:

		string m_Name;//Style's name

		void virtual Abs() = 0;//Virtual function that makes class Style ABSTRACT

#pragma region Colors

		WORD m_BorderColor;//Border Color of the UI Control

		WORD m_BackGroundColor;//Background color of the UI Control
				
#pragma endregion

#pragma region Size
		UShort m_width;//Width of the UI Control

		UShort m_height;//Height of the UI Control

		UShort m_minWidth;//min Width of the UI Control

		UShort m_maxWidth;//max Width of the UI Control

		UShort m_minHeight;//min Height of the UI Control

		UShort m_maxHeight;//max Height of the UI Control
#pragma endregion

	public:

#pragma region Ctor
		/// <summary>
		/// Main ctor
		/// </summary>
		/// <param name="name">-Name of the style</param>
		/// <param name="width">-Width of the element</param>
		/// <param name="height">-Height of the element</param>
		/// <param name="brdColor">-Border color of the element</param>
		/// <param name="backColor">-Background color of the element</param>
		/// <param name="minWidth">-Min width of the element</param>
		/// <param name="minHeight">-Min height of the element</param>
		/// <param name="maxWidth">-Max width of the element</param>
		/// <param name="maxHeight">-Max height of the element</param>
		Style(const string name, UShort width, UShort height, WORD brdColor, WORD backColor, UShort minWidth,
			UShort minHeight, UShort maxWidth, UShort maxHeight);

#pragma endregion

#pragma region Getters
		/// <summary>
		/// Gets copy of the StyleName
		/// </summary>
		/// <returns>Copy of the StyleName</returns>
		string GetName()const;

		/// <summary>
		/// Gets copy of the Border color
		/// </summary>
		/// <returns>Copy of the Border color</returns>
		WORD GetBrdColor()const;

		/// <summary>
		/// Gets the copy of the Background color
		/// </summary>
		/// <returns>Copy of the Background color</returns>
		WORD GetBackColor()const;

		/// <summary>
		/// Gets the copy of the width value
		/// </summary>
		/// <returns>Copy of the width value</returns>
		UShort GetWidth() const;

		/// <summary>
		/// Gets the copy of the height value
		/// </summary>
		/// <returns>Copy of the height value</returns>
		UShort GetHeight() const;

		/// <summary>
		/// Gets the copy of the Min Width value
		/// </summary>
		/// <returns>Copy of the Min Width value</returns>
		UShort GetMinWidth() const;

		/// <summary>
		/// Get the copy of the Min Height value
		/// </summary>
		/// <returns>Copy of the Min Height value</returns>
		UShort GetMinHeight() const;

		/// <summary>
		/// Gets the copy of the Max Width value
		/// </summary>
		/// <returns>The copy of the Max Width value</returns>
		UShort GetMaxWidth() const;

		/// <summary>
		/// Gets the copy of the Max Height value
		/// </summary>
		/// <returns>The copy of the Max height value</returns>
		UShort GetMaxHeight() const;

#pragma endregion

#pragma region Setters
		/// <summary>
		/// Sets new width value
		/// </summary>
		/// <param name="width">New width value</param>
		void SetWidth(UShort width);
		/// <summary>
		/// Set new height value
		/// </summary>
		/// <param name="height">New height value</param>
		void SetHeight(UShort height);

		/// <summary>
		/// Set new Min width value
		/// </summary>
		/// <param name="minWidth">New Min width value</param>
		void SetMinWidth(UShort minWidth);

		/// <summary>
		/// Set new Min height value
		/// </summary>
		/// <param name="minHeight">Min height value</param>
		void SetMinHeight(UShort minHeight);

		/// <summary>
		/// Set new Max width value
		/// </summary>
		/// <param name="maxWidth"></param>
		void GetMaxWidth(UShort maxWidth);

		/// <summary>
		/// Set new Max Height value
		/// </summary>
		/// <param name="maxHeight"></param>
		void GetMaxHeight(UShort maxHeight);

#pragma endregion


	};
	/// <summary>
	/// Base style for elements that can contain content
	/// </summary>
	class UIContentStyle
	{
	private:
		WORD m_Foreground;

		Vector2D m_ContentPosition;

		virtual void Abs() = 0;
	public:
#pragma region Ctor
		UIContentStyle(Vector2D contentPosition, WORD contentForeground);
#pragma endregion

#pragma region Getters

		WORD GetForeground()const;

		Vector2D GetContentPosition()const;

#pragma endregion

	};

	//Base Class for All TextBlocks
	class TextBlockStyle : public Style, public UIContentStyle
	{
	private:

		void Abs() override {};

	public:

#pragma region Ctor

		TextBlockStyle(const string name, UShort width, UShort height,
			Vector2D contentPos = Vector2D(1, 1),
			WORD brdColor = Colors::GREY | Colors::LIGHTGRAYBack,
			WORD backColor = Colors::WhiteBack,
			WORD Foreground = Colors::BLACKBack | Colors::White,
			UShort minWidth = 0,
			UShort minHeight = 0, UShort maxWidth = 0, UShort maxHeight = 0);

#pragma endregion

	};

	/// <summary>
	/// Base Style for all buttons
	/// </summary>
	class ButtonStyle : public Style, public UIContentStyle
	{
	private:

		void Abs() override {}//Overriding the virtual function of class style
	public:
#pragma region Ctor
		/// <summary>
		/// Main ctor
		/// </summary>
		/// <param name="name">-Style name</param>
		/// <param name="width">-Width of the element</param>
		/// <param name="height">-Heigth of the element</param>
		/// <param name="contentPos">-Position of the Button's content</param>
		/// <param name="brdColor">-Border color oh the element</param>
		/// <param name="backColor">-Background color of the element</param>
		/// <param name="Foreground">-Foreground color of the element's content</param>
		/// <param name="minWidth">-Min Width of the element</param>
		/// <param name="minHeight">-Min height of the element</param>
		/// <param name="maxWidth">-Max width of the element</param>
		/// <param name="maxHeight">-Max height of the element</param>
		ButtonStyle(const string name, UShort width, UShort height,
			Vector2D contentPos = Vector2D(1, 1),
		    WORD brdColor = Colors::GREY | Colors::LIGHTGRAYBack,
			WORD backColor = Colors::WhiteBack,
			WORD Foreground = Colors::BLACKBack | Colors::White,			
			UShort minWidth = 0,
			UShort minHeight = 0, UShort maxWidth = 0, UShort maxHeight = 0);

#pragma endregion

	};
	/// <summary>
	/// Base style for elements that can contain children elements
	/// </summary>
	class PanelStyle : public Style, public UIContentStyle
	{
	private:
		
		Vector2D m_ChildPostion;//Relative position of all the children

		UShort m_Interval;//Inerval between elements

		void Abs() override {}//Overriding of the function from class Style

	public:

#pragma region Ctors
		/// <summary>
		/// Main ctor
		/// </summary>
		/// <param name="name">-Styles name</param>
		/// <param name="width">-Width of the element</param>
		/// <param name="height">-Height of the element</param>
		/// <param name="ChildsPosition">-Position of the Children elements</param>
		/// <param name="HeaderPos">-Position of the header</param>
		/// <param name="interval">-Interval between children elements</param>
		/// <param name="brdColor">-Border color of the element</param>
		/// <param name="backColor">-Background color of the element</param>
		/// <param name="HeaderForeground">-Foreground color of the header</param>
		/// <param name="minWidth">-Min Width of the element</param>
		/// <param name="minHeight">-Min height of the element</param>
		/// <param name="maxWidth">-Max Width of the element</param>
		/// <param name="maxHeight">-Max Height of the element</param>
		PanelStyle(const string name, UShort width, UShort height,
			Vector2D ChildsPosition, 
			Vector2D HeaderPos = Vector2D(1, 1),
			UShort interval = 1,
			WORD brdColor = Colors::GREY | Colors::LIGHTGRAYBack,
			WORD backColor = Colors::WhiteBack,
			WORD HeaderForeground = Colors::BLACKBack | Colors::White,
			UShort minWidth = 0,
			UShort minHeight = 0, UShort maxWidth = 0, UShort maxHeight = 0);

#pragma endregion

#pragma region Getters
		/// <summary>
		/// Gets the copy of the Child;s position
		/// </summary>
		/// <returns>Copy of the child's position</returns>
		Vector2D GetChildPosition()const;

		/// <summary>
		/// Gets the interval between children
		/// </summary>
		/// <returns>The interval between children</returns>
		UShort GetInterval()const;

#pragma endregion


	};

	class TableRowStyle : public Style
	{
	private:
		void Abs() override {};

		UShort m_HorOffset;

	public:

#pragma region Ctor

		TableRowStyle(const string name,  
			UShort horOffset = 0,
			WORD brdColor = Colors::GREY | Colors::LIGHTGRAYBack, 
			WORD backColor = Colors::WhiteBack, UShort minWidth = 0 ,
			UShort minHeight = 0, UShort maxWidth = 0, UShort maxHeight = 0
			);

#pragma endregion

#pragma region Getters

		UShort GetHorOffset() const;

#pragma endregion

		void SetHorOffset(const UShort& horOffset);
	};

	class DataTableStyle : public Style, public UIContentStyle
	{
	private:
		void Abs() {}

		UShort m_VertOffset;

	public:
#pragma region Ctor

		DataTableStyle(const string name,
			UShort vertOffset,
			Vector2D HeaderPos = Vector2D(1, 1),
			WORD brdColor = Colors::GREY | Colors::LIGHTGRAYBack,
			WORD backColor = Colors::WhiteBack,
			WORD Foreground = Colors::BLACKBack | Colors::White,			
			UShort minWidth = 0,
			UShort minHeight = 0, UShort maxWidth = 0, UShort maxHeight = 0);

#pragma endregion

#pragma region Getters

		UShort GetVertOffset() const;

#pragma endregion

#pragma region Setters

		void SetVertOffset(const UShort& vertOffset);

#pragma endregion


	};

	/// <summary>
	/// Base class for all the UI Controls
	/// </summary>
	class UIControl
	{
	private:

		Style *m_stylePtr;//Ptr to current style (Usage of the Polymorphism)

		bool m_visibility;//Controls UI Element Visisbility

		string m_Content;//Content of UI Element

		std::string m_Name;//Name of the Current UI Element

		static long int m_Idlast;//Id of the last added element;

		long int m_Id;//Id of the Current UI Element

		Vector2D m_position;//Position of the control with respect to global coords				
			
	public:

#pragma region Ctors
		/// <summary>
		/// Main ctor
		/// </summary>
		/// <param name="name">-Name of the control</param>
		/// <param name="position">-Global position of the control</param>
		/// <param name="content">-Content's control</param>
		/// <param name="visibility">-Visibility of the control</param>
		UIControl(const string &name, Vector2D position, const string &content, bool visibility,
			Style *style);

		UIControl();

#pragma endregion

#pragma region Getters
		/// <summary>
		/// Gets the copy of the Visibility of the element
		/// </summary>
		/// <returns>Copy of the element's Visibility</returns>
		bool GetVisibility()const;

		/// <summary>
		/// Gets the copy of the elemnt Position
		/// </summary>
		/// <returns>The copy of the element's position</returns>
		Vector2D GetPosition() const;

		/// <summary>
		/// Gets the copy fo the element's name
		/// </summary>
		/// <returns>Copy of the elements name</returns>
		string GetName()const;
						
		/// <summary>
		/// Gets the Id of the current element
		/// </summary>
		/// <returns>ref to const current Elelment's id</returns>
		const long int & GetId()const;
		/// <summary>
		/// Gets the copy of the content
		/// </summary>
		/// <returns>The copy of the content</returns>
		string GetContent() const;

		/// <summary>
		/// Gets the pointer to the Base Style Class
		/// </summary>
		/// <returns>POinter to the base style class</returns>
		Style *GetStylePtr();
		
#pragma endregion

#pragma region Setters

		void SetName(const string& name);

		void SetVisibility(bool& visibility);

		void SetPosition(Vector2D& newPosition);
									
		void SetContent(const string &newContent);

		/// <summary>
		/// Sets the pointer to the Base Style Class
		/// </summary>
		/// <param name="ptr">Pointer to the Base Style Class</param>
		void SetStylePtr(Style* ptr);

#pragma endregion
		/// <summary>
		/// Method for rendering of the UIElement
		/// </summary>
		virtual void Render() = 0;

	protected:
		void Build(const string& name, Vector2D position, const string& content, bool visibility,
			Style* style);

	};
	
	/// Panel UI Element, Used to store child elements
	class Panel : public UIControl
	{
		private:
			vector<UIControl*> m_Children;//Collection of poiners on UIControls
						
		public:

#pragma region Ctors
			
			/// <summary>
			/// main Ctor
			/// </summary>
			/// <param name="name">-Panel name</param>
			/// <param name="position">-Panel's position</param>
			/// <param name="style">-Panel's style</param>
			/// <param name="header">-Panel's header content</param>
			/// <param name="visibility">-Visibility of the panel</param>
			Panel(const string& name, Vector2D position, PanelStyle *style, 
				const string& header,
				bool visibility);
#pragma endregion

#pragma region Getters
			/// <summary>
			/// Gets the copy of the panel's style
			/// </summary>
			/// <returns>The copy of the panel's style</returns>
			PanelStyle* GetStyle();			
#pragma endregion

#pragma region Setters
			/// <summary>
			/// Set new panel style
			/// </summary>
			/// <param name="newStyle">New panel style</param>
			void SetStyle(PanelStyle *newStyle);
#pragma endregion

#pragma region CRUD Functions
			/// <summary>
			/// Gets children of the Panel
			/// </summary>
			/// <param name="size">Children count</param>
			/// <returns>Pointer on the const of the first children element</returns>
			const UIControl* GetChildren(unsigned int& size)const;

			/// <summary>
			/// Gets child by Id
			/// </summary>
			/// <param name="Id"></param>
			/// <returns>Ref on the const of the child element</returns>
			const UIControl& GetChild(const long int& Id)const;

			const UIControl* GetChild(const string& name)const;
			/// <summary>
			/// Adds the child to the panel's collection
			/// </summary>
			/// <param name="child">Pointer to child for adding</param>
			void AddChild(UIControl* child);
			
			/// <summary>
			/// Edits child according to its id
			/// </summary>
			void EditChild(const long int& childId, UIControl *newChild);

			/// <summary>
			/// Edits child according to its name
			/// </summary>
			void EditChild(const string& elemName, UIControl *newChild);

			/// <summary>
			/// Removes child according to it's Id
			/// </summary>
			void RemoveChild(const long int& childId);

			/// <summary>
			/// Removes child according to it's name
			/// </summary>
			void RemoveChild(const string& elemName);

#pragma endregion

#pragma region Functions
			/// <summary>
			/// Used to render Panel and children UI elements
			/// </summary>
			void Render() override;

#pragma endregion

	};
	//Button class
	class Button : public UIControl
	{
			
	public:
		/// <summary>
		/// Used to render Buttons
		/// </summary>
		void Render() override;
#pragma region Ctors
		/// <summary>
		/// Main ctor
		/// </summary>
		Button(const string& name, Vector2D position, ButtonStyle *style, const string& content,
			bool visibility);

#pragma endregion

#pragma region Getters
		/// <summary>
		/// Gets the copy to the Buttons Style
		/// </summary>
		ButtonStyle *GetStyle();

#pragma endregion

#pragma region Setters
		/// <summary>
		/// Sets new Button Style
		/// </summary>
		void SetStyle(ButtonStyle* style);
#pragma endregion

	};

	class TableRow;

	class Printer
	{
	
	public:
		virtual void Print(WORD &Foreground) = 0;
	};

	class FloatPrecisionPrinter : public Printer
	{
	private:
		float m_value;		

		void (*m_UpdtOutputStream)(std::ostream& outputStream);
	public:

#pragma region Ctor

		FloatPrecisionPrinter( const float &value,
			void (*UpdtOutputStream)(std::ostream & outputStream));
			
#pragma endregion

#pragma region Getters
		float GetValue();
#pragma endregion

#pragma region Setters
		void SetValue(const float &value);
#pragma endregion


#pragma region Functions

		void Print(WORD &foreground)override;

#pragma endregion

	};

	class TextBlock : public UIControl
	{
	private:
		Printer *m_printer;

	public:

#pragma region Ctor
		TextBlock();

		TextBlock(const string& name, Vector2D position, TextBlockStyle *style, const string& content,
			bool visibility);

		TextBlock(const string& name, Vector2D position, TextBlockStyle *style, Printer *printer,
			bool visibility);
#pragma endregion

#pragma region Getters

		TextBlockStyle* GetStyle();

#pragma endregion

#pragma region Setters

		void SetStyle(TextBlockStyle* newStyle);

#pragma endregion

#pragma region Functions

		void Render() override;

		void Build(const string& name, Vector2D position, TextBlockStyle style, const string& content,
			bool visibility);

		void Build(const string& name, Vector2D position, TextBlockStyle style, Printer* printer,
			bool visibility);

#pragma endregion
		
	};

	class DataTable : public UIControl
	{
	private:

		vector<TableRow*> m_tableRows;

	public:
#pragma region Ctor

		DataTable(const string& name, Vector2D position, DataTableStyle *style,
			const string& tableHeader,
			bool visibility);

#pragma endregion

#pragma region Getters

		DataTableStyle* GetStyle();		

#pragma endregion

#pragma region Setters

		void SetStyle(DataTableStyle* newStyle);

#pragma endregion


#pragma region CRUD Operations

		void AddTableRow(TableRow* tblRow);

		void RemoveTableRow(const int long& id);

		void RemoveTableRow(const string& name);

#pragma endregion

#pragma region Functions

		void Render() override;

#pragma endregion

		
	};

	class TableRow : public UIControl
	{
	private:
		vector<UIControl*> m_Cells;

	public:
#pragma region Ctor
		TableRow();

		TableRow(const string& name, Vector2D position, TableRowStyle* style,			
			bool visibility);
#pragma endregion

#pragma region CRUD Functions
		void AddUIControl(UIControl *control);

		void RemoveUIControl(const string& elemName);

		void RemoveUIControl(const long int &id);

		vector<UIControl*> &GetAllCells();

#pragma endregion

		void Render() override;

		void Build(const string& name, Vector2D position, TableRowStyle style,
			bool visibility);

#pragma region Getters

		TableRowStyle* GetStyle();
		
#pragma endregion

#pragma region Setters

		void SetStyle(TableRowStyle* newStyle);

#pragma endregion


	};
}

namespace ConsoleUI
{
	//Not implemented yet
	class Cursor
	{

	};
	//main UI controller Controlls rendering and interactions
	class ConsoleUIController
	{
	private:
		vector<UIControls::UIControl*> m_WindowControlls;//Vector that holds pointers to UI Controlls;

		Cursor m_cursor;//Cursor type(Not implemented Yet)

		static ConsoleUIController* m_instance;//Pointer to the current instance of the Singltone
		
	public:
		//Init Singletone instance and get pointer to it
		static ConsoleUIController*const Initialize(HANDLE &console);

		static void Dispose();

		//Draw all the UI elements
		void Draw();
		//Add UI control
		void AddUIControl(UIControls::UIControl* newChild);
		//Edit UI Control
		void EditUIControl(const long int& childId, UIControls::UIControl *newChild);
		//Remove UI Control
		void RemoveUIControl(const long int& childId);
		//Edit UI Control
		void EditUIControl(const string& elemName, UIControls::UIControl *newChild);
		//Remove UI Control
		void RemoveUIControl(const string& elemName);

		UIControls::UIControl* GetControls(size_t &size);

	private:
#pragma region Ctor
		//Private ctor Initializes Console functions Library
		ConsoleUIController(HANDLE& console);
		//Destructor removes singletone instance from the memory
		~ConsoleUIController();

#pragma endregion
		
	};	
}

#endif // !CONSOLEUI_H

