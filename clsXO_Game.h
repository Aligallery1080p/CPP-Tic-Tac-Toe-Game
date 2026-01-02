#pragma once
#include <iostream>
#include <vector>
#include "clsPlayer.h"
#include "D:/Programming/Programming Advices/Course 11/Project2_MS/clsInputValidate.h"
using namespace std;

class clsXO_Game
{
private:
	clsPlayer Player1;
	clsPlayer Player2;
	int _XOArray[3][3];
	string _WinnerName;
	short _TurnNumber = 0;

	void _SetPlayersChoices(short Player1Choice)
	{
		short Player2Choice = (Player1Choice == 1) ? 2 : 1;

		Player1.SetPlayerGameChoice(Player1Choice);
		Player2.SetPlayerGameChoice(Player2Choice);
	}

	short _ReadPlayerChoice(string Message, short From, short To)
	{
		cout << Message;
		short PlayerChoice = clsInputValidate::ReadNumberBetween(From, To, "Wrong Number, Enter Again: ");
		return PlayerChoice;
	}

	void _ReadPlayersXOGameChoice(string Message, short From, short To)
	{
		_SetPlayersChoices(_ReadPlayerChoice(Message, From, To));
	}

	void _PrepareXOArray()
	{
		short Counter = 1;

		for (short i = 0; i < 3; i++)
		{
			for (short j = 0; j < 3; j++)
			{
				_XOArray[i][j] = Counter;
				Counter++;
			}
		}
	}

	void _PrintXOArray()
	{
		cout << "\n\n ";

		for (short i = 0; i < 3; i++)
		{
			for (short j = 0; j < 3; j++)
			{
				if (_XOArray[i][j] > 0)
					cout << "\t  " << _XOArray[i][j];
				else if (_XOArray[i][j] == -1)
					cout << "\t  X";
				else
					cout << "\t  O";
			}
			cout << "\n ";
		}
	}

	bool _CheckAvailableChoice(short PlayerChoice, short NewValue)
	{
		for (short i = 0; i < 3; i++)
		{
			for (short j = 0; j < 3; j++)
			{
				if (_XOArray[i][j] == PlayerChoice)
				{
					_XOArray[i][j] = NewValue;
					return true;
				}
			}
		}
		
		return false;
	}

	void _Player1Turn()
	{
		short value = (Player1.PlayerGameChoice == 1) ? -1 : -2;
		bool IsAvailableChoice = false;

		do
		{
			short PlayerChoice = _ReadPlayerChoice("\nPlease enter your Choice [1 to 9]: ", 1, 9);
			IsAvailableChoice = _CheckAvailableChoice(PlayerChoice, value);

		} while (!IsAvailableChoice);

		_WinnerName = _CheckWinner("Player1", value);
		_TurnNumber++;
	}

	void _Player2Turn()
	{
		short value = (Player2.PlayerGameChoice == 1) ? -1 : -2;
		bool IsAvailableChoice = false;

		do
		{
			short PlayerChoice = _ReadPlayerChoice("\nPlease enter your Choice [1 to 9]: ", 1, 9);
			IsAvailableChoice = _CheckAvailableChoice(PlayerChoice, value);

		} while (!IsAvailableChoice);

		_WinnerName = _CheckWinner("Player2", value);
		_TurnNumber++;
	}

	string _CheckWinner(string PlayerName, short value)
	{
		bool RowWin;

		for (short i = 0; i < 3; i++)
		{
			RowWin = true;
			for (short j = 0; j < 3; j++)
			{
				if (_XOArray[i][j] != value)
				{
					RowWin = false;
					break;
				}

			}

			if (RowWin)
				return PlayerName;
		}

		for (short i = 0; i < 3; i++)
		{         
			RowWin = true;
			for (short j = 0; j < 3; j++)
			{
				if (_XOArray[j][i] != value)
				{
					RowWin = false;
					break;
				}
			}

			if (RowWin)
				return PlayerName;
		}

		if (_XOArray[1][1] == value)
		{
			if (_XOArray[0][0] == value)
			{ 
				if (_XOArray[2][2] == value)
					return PlayerName;
		
			}

			if (_XOArray[0][2] == value)
			{
				if (_XOArray[2][0] == value)
					return PlayerName;

			}
		}

		return "NoOne";
	}

public:
	void StartGame()
	{
		char PlayAgain = false;

		do
		{
			system("cls");
			_TurnNumber = 0;
			_WinnerName = "NoOne";
			_ReadPlayersXOGameChoice("\nWhat do you want to play with? [1: X, 2: O]? ", 1, 2);
			_PrepareXOArray();

			do
			{
				system("cls");
				_PrintXOArray();

				cout << "\n\nPlayer1 Turn";
				_Player1Turn(); // 1
				if (_WinnerName == "Player1")
					break;

				if (_TurnNumber == 9)
					break;

				cout << "\n\nPlayer2 Turn";
				_Player2Turn(); // 2
				if (_WinnerName == "Player2")
					break;

			} while (_WinnerName == "NoOne");

			system("cls");
			_PrintXOArray();

			if (_WinnerName == "NoOne")
				cout << "\n\nIt's a Draw! No Winner\n";
			else
				cout << "\n\n" << _WinnerName << " Won the Game\n";

			cout << "\nDo you want to play again? ";
			cin >> PlayAgain;

		} while (toupper(PlayAgain) == 'Y');
	}

};

