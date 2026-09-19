#include "PreAlert.h"
#include "Dxlib.h"

void PreAlert::Init()
{
    pre = 20;
}


bool PreAlert::Lottery()
{

    return GetRand(99) < pre;
}
