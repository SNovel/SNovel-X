#ifdef TEST_DIALOG_ACTION_CENTER \
	|| DEBUG_ALL

#pragma once
#include "ActionQueue.h"
#include "DialogActionCommand.h"
#include "DialogPartNode.h"
class DialogActionCenter
{
public:
	static DialogActionCenter* getInstance();

	void loadDialogPartDatum(const char *fileName);
private:
	DialogActionCenter();
	
	//���������е�һ������
	void pharseAction(DialogPartData* data);

	void onNextMessage(EventCustom* pEvent);

	EventListener* _listener;

	DialogPartNode* _node;
};
#endif