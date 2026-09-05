#pragma once
#include "KeyAction.h"

enum class SceneState
{
	None,
	OP,
	Play,
	Result
};

class SceneBase
{
protected:
	KeyAction* key;

public:

	SceneBase(KeyAction* arg_key) 
			: key(arg_key){};
	virtual ~SceneBase() {};

	virtual SceneState Input() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Sound() = 0;

};


// É}ÉNÉçÇÃíËã`---------------------------------------------

#define SCENECLASS(className)\
	className(KeyAction* arg_key);\
	SceneState Input()override;\
	void Update()override;\
	void Draw()override;\
	void Sound()override;

#define sCONSTRUCTOR(className)\
className::className(KeyAction* arg_key)\
				: SceneBase(arg_key)

#define sInput(className)\
SceneState className::Input()

#define sUpdate(className)\
void className::Update()

#define sDraw(className)\
void className::Draw()

#define sSound(className)\
void className::Sound()