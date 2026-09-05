#pragma once

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

public:

	SceneBase() {};
	virtual ~SceneBase() {};

	virtual SceneState Input() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Sound() = 0;

};


// É}ÉNÉçÇÃíËã`---------------------------------------------

#define SCENECLASS(className)\
	className();\
	SceneState Input()override;\
	void Update()override;\
	void Draw()override;\
	void Sound()override;

#define sCONSTRUCTOR(className)\
className::className()

#define sInput(className)\
SceneState className::Input()

#define sUpdate(className)\
void className::Update()

#define sDraw(className)\
void className::Draw()

#define sSound(className)\
void className::Sound()