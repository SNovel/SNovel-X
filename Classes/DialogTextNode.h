#ifdef TEST_DIALOG_TEXT_NODE \
	|| DEBUG_ALL

#pragma once
#include "cocos2d.h"

USING_NS_CC;

struct DialogTextData
{
public:


	DialogTextData();
	std::string text;
	std::string name;
	int textNo; 
	int scenarioNo;
	int selectionNo;
};

class DialogTextNode:public Ref
{
public:
	static DialogTextNode* getInstance();
//	
	std::vector<DialogTextData*> _dialogTextDatum;
	
	//������
	int scenarioCount;
	
	int selectionNo;
	DialogTextData* getDialogTextData(const std::string& scnarioID);

private:
	DialogTextNode();

	int _dataCount;

	//�½ڿ�ʼ��ƫ����
	std::vector<int> _selectionBegin;

	//���볡������е����жԻ����뻺��
	void loadDatum(int SceneNo);

	//��ǰ�������
	int _currentScenario;
};

#endif