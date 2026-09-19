#include "PreAlert.h"
#include "Dxlib.h"

void PreAlert::Init()
{
    pre = 20;
    pre_img = LoadGraph("image/pre.png");
    pre_posy = -900;
}

void PreAlert::Start()
{
    active = true;
    end = false;
    pre_posy = -900;
}


bool PreAlert::Lottery()
{

    return GetRand(99) < pre;
}


void PreAlert::Update()
{
    if (!active) return;
    pre_posy += 100;
    if (pre_posy >= 200)
    {
        pre_posy = 200;
        active = false;
        end = true;
    }
}

void PreAlert::Draw()
{
    DrawGraph(100, pre_posy, pre_img, TRUE);
}

void PreAlert::Reset()
{
    active = false;
    end = false;
    pre_posy = -900;
}


bool PreAlert::End()
{
    if (end)
    {
        end = false;
        return true;
    }

    return false;
}