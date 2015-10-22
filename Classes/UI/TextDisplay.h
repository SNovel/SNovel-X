//#include "Debug\TestMacro.h"
#define TEST_TEXT_DISPLAY
#if defined(TEST_TEXT_DISPLAY)


#pragma once
#include "cocos2d.h"
#include "ui\CocosGUI.h"

USING_NS_CC;

namespace SNovel
{
	/*
	 * TextDisplay
	 * �ı���Ⱦ
	 * ֧����Ч
	 */

	class TextDisplay: public cocos2d::Ref
	{
	public:
		enum class State
		{
			Rendering,
			Waiting
		};
		TextDisplay(ui::Text* uiText);
		~TextDisplay();
		//virtual bool init(ui::Text*);

		void startEffect(std::string& oldText, std::string& appendText, float showSpeed);

		//��ʾʣ�������ı�
		void displayTextRemain();

		bool isRendering() { return _state == State::Rendering; }
		bool isWaiting()   { return _state == State::Waiting; }

		ui::Text* getUIText() { return _uiText; }
	private:
		ui::Text* _uiText;

		State _state;
		

		//void displayTextRemain();
		std::string _renderingText;
		std::string _appendText;
		std::string _allText;
		std::string::iterator _currentShowCharIter;

		void onDisplayText(std::string text);

		//@param  text: the text that wants to add after the current text
		void onDisplayAddedText(float dt);
		//void startEffect(std::string& text, float showSpeed);
		
		void doingEffect(float dt);

		void displayFinish();
	};
}
#endif