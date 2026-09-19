#pragma once

enum class PreAlertProbability
{
	Pr20,
	Pr40,
	Pr70,
	Pr90
};

class PreAlert
{
private:
	PreAlertProbability pro;

public:
	void Init();

	void SetProbability(PreAlertProbability pro);

	bool Lottery();

};