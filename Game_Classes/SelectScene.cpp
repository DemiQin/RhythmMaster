#include "SelectScene.h"
#include"cocostudio/CocoStudio.h"
#include"ui/CocosGUI.h"
#include"GameScene.h"
#include"Game2Scene.h"
#include"SimpleAudioEngine.h"

using namespace cocostudio::timeline;
using namespace CocosDenshion;

SelectScene::SelectScene()
{
}


SelectScene::~SelectScene()
{
}
Scene *SelectScene::createScene()
{
	auto scene = Scene::create();
	auto layer = SelectScene::create();
	scene->addChild(layer);
	return scene;
}
bool SelectScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto rootNode = CSLoader::createNode("SelectScene.csb");
	addChild(rootNode);
	//�ҵ�cocostudio���key4��ť
	Button* btn=(Button*)rootNode->getChildByName("key4Btn");
	Button* btn2 = (Button*)rootNode->getChildByName("key5Btn");
	//Ԥ���ر�������
	SimpleAudioEngine::getInstance()->preloadEffect("title_bgm.mp3");
	unsigned int id1 = SimpleAudioEngine::getInstance()->playEffect("title_bgm.mp3");
	btn->addClickEventListener([=](Ref*)
	{
		SimpleAudioEngine::getInstance()->stopEffect(id1);//ֹͣ��������
		Director::getInstance()->replaceScene(GameScene::createScene());
	});
	btn2->addClickEventListener([=](Ref*)
	{
		SimpleAudioEngine::getInstance()->stopEffect(id1);//ֹͣ��������
		Director::getInstance()->replaceScene(Game2Scene::createScene());
	});
	return true;
}