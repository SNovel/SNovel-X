#pragma once

#define TEST_SCRIPT_ENGINE
#if defined(TEST_SCRIPT_ENGINE) \
	|| defined(DEBUG_ALL)
#define TEST_SCRIPT_ENGINE


#include <deque>
#include <string>
#include "Core\Chapter.h"
#include "cocos2d.h"


using cocos2d::RefPtr;
using std::string;

namespace SNovel
{
	//class Scene;
	/*
	 * ScriptEngine: 
	 * ʹ��ʱ�뽫�����Scene��  //�Ҳ�������ν��
	 */
	class ScriptEngine
	{
	public:
		string ScriptFilePath = "/AVGPart/Resources/ScenarioScripts/";
	    //Scene::SceneStatus& getStatus() { return _currentScene->Status; }
		static ScriptEngine* getInstance();
		//void addCommand(OpCommand op);
		//void loadScript(const char* file);
		void run(RefPtr<Chapter> scene);
		void jumpToScenario(string scenarioName);
		//void phrase(shared_ptr<Chapter> scene);
		void nextCommand();
		void excuteCommand();

		Chapter::ChapterStatus& getStatus() { return _currentChapter->Status; }
		//bool isWaitTouch() { return _waitTouch; }
	private:
		cocos2d::Node* _gameNode;
		//vector<shared_ptr<AbstractTag>> _opTags;
		//unordered_map<string, int> _scenarioDict;
		RefPtr<Chapter> _currentChapter;
		//KAGPhraser* _phraser;

		ScriptEngine();
		~ScriptEngine();
		//void resetEngine();
		
		//schedule
		void onRun();

		//ʹ��cocos����Ϣת��ϵͳ
		void onClickContinue(cocos2d::EventCustom* pEvent);
		//void OnClickContinue(Message* pMessage);
		//std::deque<OpCommand> _opLines;
		//std::deque<OpCommand> _scenarioLines;

		//int getLastedLineID();

		//int _currentLine;
		//int _currentScenario;

		//bool _waitTouch = false;
		//bool _hideTextBox = true;

		//bool _hasTextBoxToHide = false;
		//void onCommandFinish(EventCustom* pEvent);
		//void onWaitTouch();
	};
}
#endif