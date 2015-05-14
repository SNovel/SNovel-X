#ifdef TEST_DIALOG_PART_NODE \
	|| DEBUG_ALL
#define TEXT_DIALOG_PART_DATA


#pragma once
#include "cocos2d.h"
#include "DialogPartData.h"
#include "tinyxml2\tinyxml2.h"
USING_NS_CC;

/*
 *  ��ȡ�ű����������ﳡ����Ϣ������������
*/
class DialogPartNode:public Ref
{
public:
	DialogPartNode(const char* fileName);
	
	int getActionNumber() const { return _actionCounter; }
	
	/*
	 * ��ȡ��Ӧ��DATA���  
	 */
	DialogPartData* getAction(int actionNumber);

	void loadDialogPartDatum(const char *fileName);

	std::deque<DialogPartData*>& getDatum() { return _loadedDatum; }

	/*
	 * ��data������Ӧ��action�����붯������
	 */
	void pharseToAction();
private:
	std::deque<DialogPartData*> _loadedDatum;
	void readChildElement(tinyxml2::XMLElement* data);
	void readChildElement(tinyxml2::XMLElement* data, IXMLScriptedData* scriptedData);
	DialogPartData* partdata;
	int _actionCounter = 0;

	void pharseTextID(DialogPartData* data);
};

#endif