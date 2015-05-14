#if defined(TEST_SAMPLE_SCENE) \
 || defined(DEBUG_ALL)

/**
 *
 *  You can modify and use this source freely
 *  only for the development of application related Live2D.
 *
 *  (c) Live2D Inc. All rights reserved.
 */


#include "cocos2d.h"
//#include "SceneCtrl.h"
class SampleScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    
	virtual void onEnter();
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void menuChangeCallback(cocos2d::Ref* pSender);
	
	// implement the "static node()" method manually
    CREATE_FUNC(SampleScene);
	
	//SceneCtrl* _sceneCtrl;
};

#endif // __SAMPLE_SCENE_H__
