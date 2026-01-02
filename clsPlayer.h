#pragma once

class clsPlayer
{
private:
	enum enPlayerGameChoice { X = 1, O = 2 };
	enPlayerGameChoice _PlayerGameChoice;

public:
	void SetPlayerGameChoice(short PlayerGameChoice)
	{
		_PlayerGameChoice = enPlayerGameChoice(PlayerGameChoice);
	}

	short GetPlayerGameChoice()
	{
		return short(_PlayerGameChoice);
	}
	__declspec(property(get = GetPlayerGameChoice, put = SetPlayerGameChoice)) short PlayerGameChoice;
};

