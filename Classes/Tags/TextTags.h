#pragma once
#include "Debug\TestMacro.h"

#include "AbstractTag.h"
#include "ScriptEngine\ScriptEngine.h"
#include "TagFactory.h"
#include "Core\TextBoxesManager.h"
#ifdef TEST_TEXT_TAGS
/*
* tag lists:
* print
* settext
* setname
* current
* reg_textbox
* [l]
* [cm]
* [p]
* [r]
*/
namespace SNovel
{
	/*
	* tag = print
	*
	* <desc>
	* �������ı����е����
	*
	* <param>
	* @text:   ����ʾ���ı�
	*
	* <sample>
	* Hello,World[p]
	*/
	class PrintTag : public AbstractTag
	{
	public:
		PrintTag()
		{
			_vitalParams = {
				"text"
			};

			_defaultParams.insert(
				{ "text", Value("") }
			);
		}

		void excute() override
		{
			TextBoxesManager::getInstance()->printText(Params["text"].asString());
			AbstractTag::excute();
		}
		void after() override
		{
			//AbstractTag::after();
		}
	};
	extern TagRegitser<PrintTag> _printTag;
	

	/*
	* tag = settext
	*
	* <desc>
	* �����ı����ڵ����
	*
	* <param>
	* @text:       ����ʾ���ı�
	* @textbox:    �ı�������
	*
	* <sample>
	* [settext text=Sachi textbox=TextBox_Name]
	*/
	/*
	class SettextTag : public AbstractTag
	{
	public:
		SettextTag()
		{
			_vitalParams = {
				"text"
			};

			_defaultParams = {
				{ "text", ""},
				{ "textbox", "" }
			};

		}

		void excute() override
		{
			TextBoxesManager.Instance.SetText(Params);
			AbstractTag::excute();
		}
	};
	TagRegitser<SettextTag> _settextTag("settext");
	*/
	/*
	* tag = setname
	*
	* <desc>
	* ��ʾ����
	*
	* <sample>
	* #Sachi
	*/
	class SetnameTag : public AbstractTag
	{
	public:
		SetnameTag()
		{
			_vitalParams = {
				"text"
			};

			_defaultParams = decltype(_defaultParams){
				{ "text", Value("") }
			};
		}

		void excute() override
		{
			TextBoxesManager::getInstance()->setName(Params["text"].asString());
			AbstractTag::excute();
		}
	};
	extern TagRegitser<SetnameTag> _setnameTag;

	/*
	* tag = current
	*
	* <desc>
	* �л���ǰ��ʾ�����ı���
	*
	* <param>
	* @layer:  ���ı�������
	*
	* <sample>
	* [current layer=TextBox]
	*
	*/
	class CurrentTag : public AbstractTag
	{
	public:
		CurrentTag()
		{
			_vitalParams = {
				"layer"
			};

			_defaultParams = decltype(_defaultParams){
				{ "layer", Value("TextBox")}
			};
		}

		void excute() override
		{
			TextBoxesManager::getInstance()->current(Params);

			AbstractTag::excute();
		}
	};
	extern TagRegitser<CurrentTag> _currentTag;

	/*
	* tag = reg_textbox
	*
	* <desc>
	* ��textbox
	*
	* <param>
	* @objname:
	* @type:
	*
	* <sample>
	* [reg_textbox objname=TextBox_Name type=name]
	*
	*/
	//TODO: �����Ҫ�����
	/*
    class Reg_textboxTag : public AbstractTag
	{
	public:
		Reg_textboxTag()
		{
			_defaultParams = {
				{ "objname", "" },
				{ "type", "main" }
			};
			_vitalParams = {
				"objname"
			};
		}

		void excute() override
		{
			Debug::logFormat("[Register TextBox]");
			AbstractTag::excute();
			TextBox t = TextBoxesManager.Instance.GetTextBoxInScene(Params["name"]);
			if (t == nullptr)
			{
				Debug::logFormat("Can not find TestBox:{0}", Params["name"]);
				return;
			}
			if (Params["type"] == "main")
			{
				TextBoxesManager.Instance.CurrentMainTextBox = t;
			}
			else if (Params["type"] == "name")
			{
				TextBoxesManager.Instance.CurrentNameTextBox = t;
			}
		}
	};

	TagRegitser<Reg_textboxTag> _currentTag("reg_textbox");
	*/

	/* ********************* Message Tag ******************* */
	/*
	* tag = l
	*
	* <desc>
	* ��ͣ�ȴ�����
	*
	* <sample>
	* Hi,World.[l]
	*/
	class LTag : public AbstractTag
	{
	public:
		LTag()
		{
			_vitalParams = {};
			//_defaultParams = {};
		}

		void excute() override
		{
			//Do Nothing
			Debug::log("[l]");
			AbstractTag::excute();
		}
		void after() override 
		{
			Engine->getStatus().EnableNextCommand = false;
		}
	};
	extern TagRegitser<LTag> _lTag;
	

	/*
	* tag = cm
	*
	* <desc>
	* ������ı����е�����
	*
	* <sample>
	* [cm]
	*
	*/
	class CmTag : public  AbstractTag
	{
	public:
		CmTag()
		{
			_vitalParams = {};
			//_defaultParams = {};
		}

		void excute() override
		{
			TextBoxesManager::getInstance()->clearMessage();

			AbstractTag::excute();
		}
	};
	extern TagRegitser<CmTag> _cmTag;
	
	/*
	* tag = p
	*
	* <desc>
	* �����ǰ�ı������ݲ���ʾ�µ��ı�
	*
	* <sample>
	* Hello,World[p]
	*
	*/
	class PTag : public AbstractTag
	{
	public:
		PTag()
		{
			_vitalParams = {};
			//_defaultParams = {};
		}

		void before() override
		{
			AbstractTag::before();
			//    AbstractTag tag = TagFactory.CreateEmptyParamsTag("LTag", LineInScript);
			//   Engine.InsertCommandBefore(tag);
			//    Engine.SkipThisTag = true;
		}

		void excute() override
		{
			Debug::log("[p]");
			TextBoxesManager::getInstance()->clearMessage();
			AbstractTag::excute();
		}

		void after() override
		{
			Engine->getStatus().EnableNextCommand = false;
		}
	};
	extern TagRegitser<PTag> _pTag;
	

	/*
	* tag = r
	*
	* <desc>
	* �ڵ�ǰ�ı�����ʾ�����ϻ�����ʾ���ı�
	* Ĭ��Ϊ[r]
	*
	* <sample>
	* Hello,World[r]
	*
	*/
	class RTag : public AbstractTag
	{
	public: 
		RTag()
		{
			_vitalParams = {};
			//_defaultParams = {};
		}

		void before() override
		{
			AbstractTag::before();
			//    AbstractTag tag = TagFactory.CreateEmptyParamsTag("LTag", LineInScript);
			//    Engine.InsertCommandBefore(tag);
			//    Engine.SkipThisTag = true;
		}

		void excute() override
		{
			//CCLOG("[r]");
			Debug::log("[r]");
			TextBoxesManager::getInstance()->reline();
			AbstractTag::excute();
		}

		//void after() override
		//{
			//Engine->getStatus().EnableNextCommand = true;
		//}
	};
	extern TagRegitser<RTag> _rTag;

	/* ********************* Message Tag ******************* */
}
#endif
