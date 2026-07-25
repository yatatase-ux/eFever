#pragma once


class SceneBase
{
protected:

public:

	SceneBase() {};
	~SceneBase() {};

	virtual void Input() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Sound() = 0;

};


// É}ÉNÉçÇÃíËã`---------------------------------------------

#define SCENECLASS(className)\
	className();\
	void Input()override;\
	void Update()override;\
	void Draw()override;\
	void Sound()override;

#define sCONSTRUCTOR(className)\
className::className()

#define sInput(className)\
void className::Input()

#define sUpdate(className)\
void className::Update()

#define sDraw(className)\
void className::Draw()

#define sSound(className)\
void className::Sound()