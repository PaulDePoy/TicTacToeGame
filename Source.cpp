#include <iostream>
#include <ctime>
#include <random>

using namespace std;

void updateBoard();

void playerChoice();
void aiChoice();

void ChooseTeam();

void restartGame(bool &startingPlayer);

bool checkIfWon();

bool checkIfTie();

bool checkForFreeSpace();

char aiTeam;
char playerTeam;

char slots[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

bool gameDone = 0;

short playerLastChoice;

int main()
{
	ChooseTeam();

	srand(time(0));

	bool playerMovesFirst = rand() % 2;

	// Display Variables at Startup if Debug Mode is Enabled
#ifdef _DEBUG
	cout << "playerMovesFirst = " << playerMovesFirst << "\n\n";
#endif

	do
	{
		// Only Allow the Player to Choose if Free Spaces are Available to Choose From...
		if (checkForFreeSpace() && checkIfTie() == 0 && checkIfWon() == 0)
		{
			if (playerMovesFirst == 1)
				playerChoice();
			else
				aiChoice();
		}

		if (checkIfTie())
		{
			restartGame(playerMovesFirst);
			continue;
		}

		if (checkIfWon())
		{
			restartGame(playerMovesFirst);
			continue;
		}

		// Only Allow the AI to Choose if Free Spaces are Available to Choose From...
		if (checkForFreeSpace() && checkIfTie() == 0 && checkIfWon() == 0)
		{
			if (playerMovesFirst)
				aiChoice();
			else
				playerChoice();
		}

		// Checks to see the current value of the gameDone variable, but only if you are compiling in debug mode.
#ifdef _DEBUG
		cout << "gameDone: " << gameDone << endl;

		// Waits for user input before continuing to loop again, to give the user a chance to read debug variables before system("cls") runs again.
		cin.get();
#endif

	} while (gameDone == 0);

	return 0;
}

void restartGame(bool &startingPlayer)
{
	cout << "Do you want to play again? Type 'Y' for yes, and 'N' for no.\n\n";

	char playAgain;

	cin >> playAgain;

	if (playAgain == 'Y' || playAgain == 'y')
	{
		// Only clear the screen if in release mode for debugging purposes.
#ifndef _DEBUG
		system("cls");
#endif

		ChooseTeam();

		for (int i = 0; i < 9; i++)
		{
			slots[i] = ' ';
		}

		startingPlayer = rand() % 2;

#ifdef _DEBUG
		cout << "playerMovesFirst updated to: " << startingPlayer << "\n\n";
#endif
	}

	else if (playAgain == 'N' || playAgain == 'n')
	{
		gameDone = 1;
	}

	else
	{
		cout << "Invalid response. Quitting the game.\n";
	}

}

void ChooseTeam()
{
	bool playerTeamChoice;

	cout << "Do you want to play as O's (0) or X's (1)?\n";

	do
	{
		cin >> playerTeamChoice;

		if (playerTeamChoice > 1 || playerTeamChoice < 0)
		{
			cout << "Invalid choice; type 0 to play as O's or 1 to play as X's.";
		}

	} while (playerTeamChoice > 1 || playerTeamChoice < 0);

	if (playerTeamChoice == 0)
	{
		aiTeam = 'X';
		playerTeam = 'O';
		cout << "You are playing as O's!\n";
	}

	if (playerTeamChoice == 1)
	{
		aiTeam = 'O';
		playerTeam = 'X';
		cout << "You are playing as X's!\n";
	}

}

void playerChoice()
{
	updateBoard();

	short playerMove;

	bool playerMoveDone = 0;

	do
	{
		cout << "Where do you want to move? Type a number: 1-9.\n";

		cin >> playerMove;

		if (slots[playerMove - 1] == ' ')
		{
			slots[playerMove - 1] = playerTeam;
			playerLastChoice = playerMove - 1;
			playerMoveDone = 1;
		}
		else
		{
			cout << "Invalid move. Try another.\n";
		}

	} while(playerMoveDone == 0);

	updateBoard();
}

void aiChoice()
{
	updateBoard();

	if (slots[4] == ' ')
	{
		slots[4] = aiTeam;
		return;
	}

	if (playerLastChoice == 0)
	{
		if (slots[8] == ' ')
		{
			slots[8] = aiTeam;
		}
		else
		{
			do
			{
				short index = rand() % 9 - 1;

				if (slots[index] == ' ')
				{
					slots[index] = aiTeam;
					return;
				}
			} while (true);
		}
	}
	if (playerLastChoice == 1)
	{
		if (slots[7] == ' ')
		{
			slots[7] = aiTeam;
		}
		else
		{
			do
			{
				short index = rand() % 9 - 1;

				if (slots[index] == ' ')
				{
					slots[index] = aiTeam;
					return;
				}
			} while (true);
		}
	}
	if (playerLastChoice == 2)
	{
		if (slots[6] == ' ')
		{
			slots[6] = aiTeam;
		}
		else
		{
			do
			{
				short index = rand() % 9 - 1;

				if (slots[index] == ' ')
				{
					slots[index] = aiTeam;
					return;
				}
			} while (true);
		}
	}
	if (playerLastChoice == 3)
	{
		if (slots[5] == ' ')
		{
			slots[5] = aiTeam;
		}
		else
		{
			do
			{
				short index = rand() % 9 - 1;

				if (slots[index] == ' ')
				{
					slots[index] = aiTeam;
					return;
				}
			} while (true);
		}
	}
	if (playerLastChoice == 4)
	{
		do
		{
			short index = rand() % 9 - 1;

			if (slots[index] == ' ')
			{
				slots[index] = aiTeam;
				return;
			}
		} while (true);
	}
	if (playerLastChoice == 5)
	{
		if (slots[3] == ' ')
		{
			slots[3] = aiTeam;
		}
		else
		{
			do
			{
				short index = rand() % 9 - 1;

				if (slots[index] == ' ')
				{
					slots[index] = aiTeam;
					return;
				}
			} while (true);
		}
	}
	if (playerLastChoice == 6)
	{
		if (slots[2] == ' ')
		{
			slots[2] = aiTeam;
		}
		else
		{
			do
			{
				short index = rand() % 9 - 1;

				if (slots[index] == ' ')
				{
					slots[index] = aiTeam;
					return;
				}
			} while (true);
		}
	}
	if (playerLastChoice == 7)
	{
		if (slots[1] == ' ')
		{
			slots[1] = aiTeam;
		}
		else
		{
			do
			{
				short index = rand() % 9 - 1;

				if (slots[index] == ' ')
				{
					slots[index] = aiTeam;
					return;
				}
			} while (true);
		}
	}
	if (playerLastChoice == 8)
	{
		if (slots[0] == ' ')
		{
			slots[0] = aiTeam;
		}
		else
		{
			do
			{
				short index = rand() % 9 - 1;

				if (slots[index] == ' ')
				{
					slots[index] = aiTeam;
					return;
				}
			} while (true);
		}
	}

	updateBoard();
}

bool checkForFreeSpace()
{
	for (int i = 0; i < 9; i++)
	{
		if (slots[i] == ' ')
		{
			return true;
		}
	}

	return false;
}

bool checkIfWon()
{

	if (slots[0] == slots[1] && slots[1] == slots[2] && slots[0] != ' ')
	{
		if (slots[0] == playerTeam)
		{
			cout << "The player wins! Game Over!\n";
		}

		if (slots[0] == aiTeam)
		{
			cout << "The computer wins! Game Over!\n";
		}

		return true;
	}

	if (slots[0] == slots[3] && slots[3] == slots[6] && slots[0] != ' ')
	{
		if (slots[0] == playerTeam)
		{
			cout << "The player wins! Game Over!\n";
		}

		if (slots[0] == aiTeam)
		{
			cout << "The computer wins! Game Over!\n";
		}

		return true;
	}

	if (slots[0] == slots[4] && slots[4] == slots[8] && slots[0] != ' ')
	{
		if (slots[0] == playerTeam)
		{
			cout << "The player wins! Game Over!\n";
		}

		if (slots[0] == aiTeam)
		{
			cout << "The computer wins! Game Over!\n";
		}

		return true;
	}

	if (slots[3] == slots[4] && slots[4] == slots[5] && slots[3] != ' ')
	{
		if (slots[3] == playerTeam)
		{
			cout << "The player wins! Game Over!\n";
		}

		if (slots[3] == aiTeam)
		{
			cout << "The computer wins! Game Over!\n";
		}

		return true;
	}

	if (slots[6] == slots[7] && slots[7] == slots[8] && slots[6] != ' ')
	{
		if (slots[6] == playerTeam)
		{
			cout << "The player wins! Game Over!\n";
		}

		if (slots[6] == aiTeam)
		{
			cout << "The computer wins! Game Over!\n";
		}

		return true;
	}

	if (slots[1] == slots[4] && slots[4] == slots[7] && slots[1] != ' ')
	{
		if (slots[1] == playerTeam)
		{
			cout << "The player wins! Game Over!\n";
		}

		if (slots[1] == aiTeam)
		{
			cout << "The computer wins! Game Over!\n";
		}

		return true;
	}

	if (slots[2] == slots[5] && slots[5] == slots[8] && slots[2] != ' ')
	{
		if (slots[2] == playerTeam)
		{
			cout << "The player wins! Game Over!\n";
		}

		if (slots[2] == aiTeam)
		{
			cout << "The computer wins! Game Over!\n";
		}

		return true;
	}

	if (slots[2] == slots[4] && slots[4] == slots[6] && slots[2] != ' ')
	{
		if (slots[2] == playerTeam)
		{
			cout << "The player wins! Game Over!\n";
		}

		if (slots[2] == aiTeam)
		{
			cout << "The computer wins! Game Over!\n";
		}

		return true;
	}

	return false;
}

bool checkIfTie()
{
	bool Row1Unwinnable = 0;
	bool Row2Unwinnable = 0;
	bool Row3Unwinnable = 0;
	bool Column1Unwinnable = 0;
	bool Column2Unwinnable = 0;
	bool Column3Unwinnable = 0;

	if ((slots[0] == 'X' && slots[1] == 'O') || (slots[0] == 'O' && slots[1] == 'X')
		|| (slots[1] == 'X' && slots[2] == 'O') || (slots[1] == 'O' && slots[2] == 'X')
		|| (slots[0] == 'X' && slots[2] == 'O') || (slots[0] == 'O' && slots[2] == 'X'))
	{
		Row1Unwinnable = 1;
	}

	if ((slots[3] == 'X' && slots[4] == 'O') || (slots[3] == 'O' && slots[4] == 'X')
		|| (slots[4] == 'X' && slots[5] == 'O') || (slots[4] == 'O' && slots[5] == 'X')
		|| (slots[3] == 'X' && slots[5] == 'O') || (slots[3] == 'O' && slots[5] == 'X'))
	{
		Row2Unwinnable = 1;
	}

	if ((slots[6] == 'X' && slots[7] == 'O') || (slots[6] == 'O' && slots[7] == 'X')
		|| (slots[7] == 'X' && slots[8] == 'O') || (slots[7] == 'O' && slots[8] == 'X')
		|| (slots[6] == 'X' && slots[8] == 'O') || (slots[6] == 'O' && slots[8] == 'X'))
	{
		Row3Unwinnable = 1;
	}

	if ((slots[0] == 'X' && slots[3] == 'O') || (slots[0] == 'O' && slots[3] == 'X')
		|| (slots[3] == 'X' && slots[6] == 'O') || (slots[3] == 'O' && slots[6] == 'X')
		|| (slots[0] == 'X' && slots[6] == 'O') || (slots[0] == 'O' && slots[6] == 'X'))
	{
		Column1Unwinnable = 1;
	}

	if ((slots[1] == 'X' && slots[4] == 'O') || (slots[1] == 'O' && slots[4] == 'X')
		|| (slots[4] == 'X' && slots[7] == 'O') || (slots[4] == 'O' && slots[7] == 'X')
		|| (slots[1] == 'X' && slots[7] == 'O') || (slots[1] == 'O' && slots[7] == 'X'))
	{
		Column2Unwinnable = 1;
	}

	if ((slots[2] == 'X' && slots[5] == 'O') || (slots[2] == 'O' && slots[5] == 'X')
		|| (slots[5] == 'X' && slots[8] == 'O') || (slots[5] == 'O' && slots[8] == 'X')
		|| (slots[2] == 'X' && slots[8] == 'O') || (slots[2] == 'O' && slots[8] == 'X'))
	{
		Column3Unwinnable = 1;
	}


#ifdef _DEBUG
	cout << "Checking to see if there is a tie...\n\n";

	if (Row1Unwinnable == 1)
	{
		cout << "Row 1 is unwinnable!\n\n";
	}

	if (Row2Unwinnable == 1)
	{
		cout << "Row 2 is unwinnable!\n\n";
	}

	if (Row3Unwinnable == 1)
	{
		cout << "Row 3 is unwinnable!\n\n";
	}

	if (Column1Unwinnable == 1)
	{
		cout << "Column 1 is unwinnable!\n\n";
	}

	if (Column2Unwinnable == 1)
	{
		cout << "Column 2 is unwinnable!\n\n";
	}

	if (Column3Unwinnable == 1)
	{
		cout << "Column 3 is unwinnable!\n\n";
	}
#endif

	if (Row1Unwinnable && Row2Unwinnable && Row3Unwinnable && Column1Unwinnable && Column2Unwinnable && Column3Unwinnable)
	{
		cout << "No more moves are possible; the game is a tie!\n\n";
		return true;
	}

	else
		return false;
}

void updateBoard()
{
	// Only clear the screen if in release mode for debugging purposes.
#ifndef _DEBUG
	system("cls");
#endif

	// Draw a grid that resembles a tic-tac-toe board.
	cout << "____" << slots[0] << "____|____" << slots[1] << "____|____" << slots[2] << "____" << endl;
	cout << "____" << slots[3] << "____|____" << slots[4] << "____|____" << slots[5] << "____" << endl;
	cout << "    " << slots[6] << "    |    " << slots[7] << "    |    " << slots[8] << "\n\n\n";
}