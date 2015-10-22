#pragma once

#include "Debug\TestMacro.h"

#ifdef TEST_SYS_TAGS

#include <vector>

#include "Tags\AbstractTag.h"
#include "Tags\TagFactory.h"
#include "ScriptEngine\ScriptEngine.h"

#include "base\CCValue.h"
using cocos2d::Value;

/*
 * tag lists:
 * [scenario]
 * [s]
 * [select_new]
 * [select_show]
 * [jump] 
 * [wait]
*/

namespace SNovel
{
	/*
	* tag = scenario
	*
	* <desc>
	*  ��¼��������Ϊһ����Ƭ�Σ�����ת��ʵ��
	*
	* <sample>
	* *Demonstration(English)/START/1_Dialog
	*
	*/
	class ScenarioTag : public AbstractTag
	{
	public:
		ScenarioTag()
		{
			_vitalParams =  {
				"scenario"
			};
			/*  error C2593: 'operator =' is ambiguous?
			_defaultParams =  {
				{ "scenario", Value("") }
			};
			*/
			_defaultParams.insert({ "scenario", Value("") });
		}

		virtual void excute() override
		{
			Debug::logFormat("[Scenario]: {0}", Params["scenario"]);
			//Done By ScriptEngine
			/*
			if(Params.ContainsKey("scenario"))
			{
			string scenarioName = Params["scenario"];
			Engine.AddScenario(scenarioName);
			}*/

			AbstractTag::excute();
		}
	};
	extern TagRegitser<ScenarioTag> _scenarioTag;

	/*
	* tag = select_show
	*
	* <desc>
	* ��ʾ�ű�ǰ��[select_show]��ѡ��֫
	*
	* <sample>
	* [select_show]
	*
	*/
	/*
	class Select_showTag : public AbstractTag
	{
	public:
		Select_showTag()
		{
			//_defaultParams = {
			//};

			//_vitalParams = {
			//};
		}

	    virtual void excute() override
		{
			UIManager.Instance.ShowSelects();
			AbstractTag::excute();
		}
	};
	TagRegitser<Select_showTag> _select_showTag("select_show");
	*/
	/*
	* tag = select_new
	*
	* <desc>
	* �����µ�ѡ��֫
	*
	* <param>
	* @target: �������ת��Scenario��ǩ
	* @text:   ��ǩ����ʾ������
	*
	* <sample>
	* [select_new  target=*select_a1]Nico~[end]
	*
	*/
	/*
	class Select_newTag : public AbstractTag
	{
	public:
		Select_newTag()
		{
			_defaultParams = {
				{ "target", "" },
				{ "text", "" }
			};

			_vitalParams = {
				"target"
			};
		}

		virtual void excute() override
		{
			string target = Params["target"];
			UIManager.Instance.AddSelect("button", Params["text"]
										 , () = >
			{
				Engine.JumpToScenario(target);
				UIManager.Instance.ClearSelects();
			}
			);
			AbstractTag::excute();
		}

	};
	TagRegitser<Select_newTag> _select_newTag("select_new");
	*/
	/*
	* tag = jump
	*
	* <desc>
	* ��ת��Param["target"]��Scenario��
	*
	* <param>
	* @target: Target scenario to jump
	*
	* <sample>
	* *select_niko
	* [jump target=*select_niko]
	*
	*/

	class JumpTag : public AbstractTag
	{
		public:
		JumpTag()
		{
			_defaultParams.insert(
				{ "target", Value("") }
			);
				
			_vitalParams = {
				"target"
			};
		}
		virtual void excute() override
		{
			AbstractTag::excute();
		}
		virtual void after() override
		{
			Engine->jumpToScenario(Params["target"].asString());
			//Do Not CurrentLine + 1
			//base.After();
		}
	};
	extern TagRegitser<JumpTag> _jumpTag;

	/*
	* tag = wait
	*
	* <desc>
	* ��ָͣ��ʱ������
	*
	* <param>
	* @time:   ��Ҫ�ȴ���ʱ�䣬��λΪ��
	*
	* <sample>
	* [wait time=1000]
	*
	*/
    class WaitTag : public AbstractTag
	{
	public:
		WaitTag()
		{
			_defaultParams.insert(
				{ "time", Value(0) }
			);

			_vitalParams = {
				"time"
			};
		}

		virtual void excute() override
		{
			Debug::logFormat("Wait: {0}ms", Params["time"]);
			Engine->getStatus().EnableNextCommand = false;

			/* TODO: DelayToInvoke */
			//Engine->StartCoroutine(Util.DelayToInvoke(this.OnFinishAnimation, int.Parse(Params["time"]) / 1000f));
		}

		virtual void after() override
		{
			//Do Nothing
		}

		virtual void onFinishAnimation() override
		{
			Debug::log("Wait Finish!");
			Engine->getStatus().EnableNextCommand = true;
			Engine->nextCommand();
		}
	};
	extern TagRegitser<WaitTag> _waitTag;


	/*
	* tag = s
	*
	* <desc>
	* �ű����е��˴�ʱֹͣ
	*
	* <sample>
	*
	* [select num = 2]
	* [select_new  target=*select_a1]View from the beginning.[end]
	* [select_new  target=*select_a2]Finish this demo.[end]
	* [s]
	*
	*/
	class STag : public AbstractTag
	{
	public:
		STag()
		{
		}

		virtual void excute() override
		{
			AbstractTag::excute();

			Engine->getStatus().EnableClickContinue = false;
			Engine->getStatus().EnableNextCommand = false;
		}
	};	
	extern TagRegitser<STag> _sTag;
}

#endif