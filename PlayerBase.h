#pragma once
#include "KeyAction.h"

class PlayerBase
{
protected:
	KeyAction* key;

public:
	PlayerBase(KeyAction* arg_key)
	:key(arg_key){};

	virtual void Input() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Sound() = 0;
};

#define PlayerClass(className)\
	className(KeyAction* arg_key);\
	void Input()override;\
	void Update()override;\
	void Draw()override;\
	void Sound()override;

#define PlayerConstructor(className)\
className::className(KeyAction* arg_key)\
				:PlayerBase(arg_key)

#define PlayerInput(className)\
void className::Input()

#define PlayerUpdate(className)\
void className::Update()

