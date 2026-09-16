#pragma once
#include "KeyAction.h"
#include "Int2.h"

class PlayerBase
{
protected:
	KeyAction* key;

	Int2 selectCell;

public:
	PlayerBase(KeyAction* arg_key)
	:key(arg_key){};

	virtual bool Input() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Sound() = 0;

	virtual Int2 GetSelectCell() = 0;
};

#define PlayerClass(className)\
	className(KeyAction* arg_key);\
	bool Input()override;\
	void Update()override;\
	void Draw()override;\
	void Sound()override;\
	Int2 GetSelectCell()override;

#define PlayerConstructor(className)\
className::className(KeyAction* arg_key)\
				:PlayerBase(arg_key)

#define PlayerInput(className)\
bool className::Input()

#define PlayerUpdate(className)\
void className::Update()

