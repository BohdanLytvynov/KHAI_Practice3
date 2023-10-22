#ifndef CONSOLEUI_H

#define CONSOLEUI_H

#include"Console.h"
#include"VectorMath.h"


using namespace std;

using namespace VectorMath;

#pragma region Type defs

typedef unsigned short UShort;

#pragma endregion


namespace UIControls
{		
	class Colors
	{
	public:
		static WORD White;

		static WORD BLACK;

		static WORD GREY;

		static WORD LIGHTGRAY;

		static WORD BLUE;

		static WORD ORANGE;

		static WORD WhiteBack;

		static WORD BLACKBack;

		static WORD GREYBack;

		static WORD LIGHTGRAYBack;

		static WORD BLUEBack;

		static WORD ORANGEBack;
	};
	
	/// <summary>
	/// Controls styling of the UI Elements
	/// </summary>
	class Style 
	{
	private:

		string m_Name;

		void virtual Abs() = 0;

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
		
		Style(const string name, UShort width, UShort height, WORD brdColor, WORD backColor, UShort minWidth,
			UShort minHeight, UShort maxWidth, UShort maxHeight);

#pragma endregion

#pragma region Getters

		string GetName()const;

		WORD GetBrdColor()const;

		WORD GetBackColor()const;

		UShort GetWidth() const;

		UShort GetHeight() const;

		UShort GetMinWidth() const;

		UShort GetMinHeight() const;

		UShort GetMaxWidth() const;

		UShort GetMaxHeight() const;

#pragma endregion

#pragma region Setters

		void SetWidth(UShort width);

		void SetHeight(UShort height);

		void SetMinWidth(UShort minWidth);

		void SetMinHeight(UShort minHeight);

		void GetMaxWidth(UShort maxWidth);

		void GetMaxHeight(UShort maxHeight);

#pragma endregion


	};

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

	class ButtonStyle : public Style, public UIContentStyle
	{
	private:

		void Abs() override {}
	public:
#pragma region Ctor
		
		ButtonStyle(const string name, UShort width, UShort height,
			Vector2D contentPos = Vector2D(1, 1),
		    WORD brdColor = Colors::GREY | Colors::LIGHTGRAYBack,
			WORD backColor = Colors::WhiteBack,
			WORD Foreground = Colors::BLACKBack | Colors::White,			
			UShort minWidth = 0,
			UShort minHeight = 0, UShort maxWidth = 0, UShort maxHeight = 0);

#pragma endregion

	};

	class PanelStyle : public Style, public UIContentStyle
	{
	private:
		
		Vector2D m_ChildPostion;

		UShort m_Interval;

		void Abs() override {}

	public:

#pragma region Ctors
				
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

		Vector2D GetChildPosition()const;

		UShort GetInterval()const;

#pragma endregion


	};

	/// <summary>
	/// Base class for all the UI Controls
	/// </summary>
	class UIControl
	{
	private:

		Style *m_stylePtr;//Ptr to current style

		bool m_visibility;//Controls UI Element Visisbility

		string m_Content;//Content of UI Element

		std::string m_Name;//Name of the Current UI Element

		static long int m_Idlast;//Id of the last added element;

		long int m_Id;//Id of the Current UI Element

		Vector2D m_position;//Position of the control with respect to global coords				

	public:

#pragma region Ctors
				
		UIControl(const string &name, Vector2D position, const string &content, bool visibility
			);

#pragma endregion

#pragma region Getters

		bool GetVisibility()const;

		Vector2D GetPosition() const;

		string GetName()const;
		
		const UIControl* GetChildren(unsigned int &size)const;

		const UIControl& GetChild(const long int &Id)const;

		const UIControl& GetChild(const string &name)const;

		const long int & GetId()const;

		string GetContent() const;

		Style* GetStylePtr();

		void SetStylePtr(Style* ptr);

#pragma endregion

#pragma region Setters

		void SetVisibility(bool &newVisibility);

		void SetPosition(Vector2D& newPosition);
				
		void AddChild(UIControl &child);

		void EditChild(const long int &childId, UIControl newChild);

		void RemoveChild(const long int& childId);

		void EditChild(const string &elemName, UIControl newChild);

		void RemoveChild(const string& elemName);

		void SetContent(const string newContent);

#pragma endregion

		virtual void Render() const = 0;

	};
		
	class Panel : public UIControl
	{
		private:
			vector<UIControl*> m_Children;

			PanelStyle m_style;
			
		public:

#pragma region Ctors
			Panel();

			Panel(const string& name, Vector2D position, PanelStyle style, 
				const string& header,
				bool visibility);
#pragma endregion

#pragma region Getters
			PanelStyle GetStyle()const;			
#pragma endregion

#pragma region Setters
			void SetStyle(PanelStyle& newStyle);
#pragma endregion



#pragma region CRUD Functions
			
			const UIControl* GetChildren(unsigned int& size)const;
			
			const UIControl& GetChild(const long int& Id)const;

			const UIControl* GetChild(const string& name)const;
					
			void AddChild(UIControl* child);

			void EditChild(const long int& childId, UIControl *newChild);

			void EditChild(const string& elemName, UIControl *newChild);

			void RemoveChild(const long int& childId);

			void RemoveChild(const string& elemName);

#pragma endregion

#pragma region Functions

			void Render() const override;

#pragma endregion



	};

	class Button : public UIControl
	{
	private:
		ButtonStyle m_style;
		
	public:
		void Render() const override;
#pragma region Ctors

		Button();

		Button(const string& name, Vector2D position, ButtonStyle style, const string& content,
			bool visibility);

#pragma endregion

#pragma region Getters
		ButtonStyle GetStyle()const;

#pragma endregion

#pragma region Setters
		void SetStyle(ButtonStyle style);
#pragma endregion



	};
}

namespace ConsoleUI
{
	class Cursor
	{

	};

	class ConsoleUIController
	{
	private:
		vector<UIControls::UIControl*> m_WindowControlls;//Vector that holds UI Controlls

		Cursor m_cursor;

		static ConsoleUIController* m_instance;

#pragma region Ctor

		ConsoleUIController(HANDLE &console);

		~ConsoleUIController();

#pragma endregion
		
	public:

		static ConsoleUIController*const Initialize(HANDLE &console);

		void Draw();

		void AddUIControl(UIControls::UIControl* newChild);

		void EditUIControl(const long int& childId, UIControls::UIControl *newChild);

		void RemoveUIControl(const long int& childId);

		void EditUIControl(const string& elemName, UIControls::UIControl *newChild);

		void RemoveUIControl(const string& elemName);
		
	};	
}

#endif // !CONSOLEUI_H

