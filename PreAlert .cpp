#include "PreAlert.h"
#include "Dxlib.h"

void PreAlert::Init()
{
    pre = 20;
    pre_img = LoadGraph("image/pre.png");
    pre_posy = -300;
}


bool PreAlert::Lottery()
{

    return GetRand(99) < pre;
}


void PreAlert::Update()
{
    pre_posy += 5;
    if (pre_posy < 200)
    {
        pre_posy += 20;
    }
}

void PreAlert::Draw()
{
    DrawGraph(1280 / 2, pre_posy, pre_img, FALSE);
}