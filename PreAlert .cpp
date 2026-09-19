#include "PreAlert.h"
#include "Dxlib.h"
void PreAlert::SetProbability(PreAlertProbability pro)
{
    this->pro = pro;
}

bool PreAlert::Lottery()
{
    int probability = 0;

    switch (pro)
    {
    case PreAlertProbability::Pr20:
        probability = 20;
        break;

    case PreAlertProbability::Pr40:
        probability = 40;
        break;

    case PreAlertProbability::Pr70:
        probability = 70;
        break;

    case PreAlertProbability::Pr90:
        probability = 90;
        break;
    }

    return GetRand(99) < probability;
}
