#include "GamePlay.h"
GamePlay::GamePlay()
{
	pausehi = false;
}
GamePlay::~GamePlay()
{

}
void GamePlay:: Random()
{
	InitRandomizer();

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			A[i][j] = rand() % 5;
			
		}
	}
}
void GamePlay:: DisplayRand()
{
	for (int row = 300, x = 0; row <= 700; row += 80, x++)
	{
		for (int column = 700, y = 0; column >= 300; column -= 80, y++)
		{

			setX(row);
			setY(column);
			if (A[x][y] == 0)
			{
				DisplaySquare2();
			}
			else if (A[x][y] == 1)
			{
				DisplayTriangle1();
			}
			else if (A[x][y] == 2)
			{
				DisplayTriangle2();
			}
			else if (A[x][y] == 3)
			{
				DisplayRoundRec();
			}
			else if (A[x][y] == 4)
			{
				DisplaySquare1();
			}
		}
	}
}
void GamePlay::LinesDraw()
{
	//DrawLine(925 , 120 , 925, 925, 5, colors[RED]);
	for (int i = 0; i < 7; i++)
	{
      DrawLine(280 + (80 * i), 280, 280 + (80 * i), 760, 5, colors[rand()%50]);
	}
	//DrawLine(120, 120, 120, 920, 5, colors[MEDIUM_TURQUOISE]);



	//DrawLine(120, 120, 920, 120, 5, colors[MEDIUM_TURQUOISE]);
	for (int i = 0; i < 7 ; i++)
	{
		DrawLine(280, 280 + (80 * i), 760, 280 + (80 * i), 5, colors[rand() % 50]);
	}
	//DrawLine(120, 920, 920, 920, 5, colors[MEDIUM_TURQUOISE]);
}

void GamePlay::Disapear()
{
	//moves--;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (i < 6 && (A[i][j] == A[i + 1][j] && A[i][j] == A[i + 2][j]))
			{
				A[i][j] = -1;
				A[i + 1][j] = -1;
				A[i + 2][j] = -1;
				score++;

				if (A[i][j] == A[i + 3][j])
				{
					A[i + 3][j] = -1;
					score++;

					if (A[i][j] == A[i + 4][j])
					{
						A[i + 4][j] = -1;
						score++;

					}
				}
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (j < 6 && (A[i][j] == A[i][j + 1] && A[i][j] == A[i][j + 2]))
			{
				A[i][j] = -1;
				A[i][j + 1] = -1;
				A[i][j + 2] = -1;
				score++;

				if (A[i][j] == A[i][j + 3])
				{
					A[i][j + 3] = -1;
					score++;

					if (A[i][j] == A[i][j + 4])
					{
						A[i][j + 4] = -1;
						score++;

					}
				}
			}
		}
	}
}
void GamePlay::Drop()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (A[i][j] == -1)
			{
				for (int k = i; k < 5; k++)
				{
					A[k][j] = A[k + 1][j];
				}
				A[5][j] = rand() % 5;
			}
		}
	}
}
void GamePlay::Slide(int a1, int b1, int a2, int b2)
{
	int Arzi;
	cout << "a2:" << a2 << "a1:" << a1 << "b2:" << b2 << "b1:" << b1 << endl;

	if ((a2 - a1 == 1 && b2 == b1) || (a2 - a1 == -1 && b1 == b2) || (b2 - b1 == 1 && a1 == a2) || (b2 - b1 == -1 && a1 == a2))
	{
		if ((A[b2][a2] == A[b1][a1 - 1] && A[b2][a2] == A[b1][a1 - 2]) || (A[b2][a2] == A[b1][a1 + 1] && A[b2][a2] == A[b1][a1 - 1]) ||
			(A[b2][a2] == A[b1 + 1][a1] && A[b2][a2] == A[b1 - 1][a1]) || (A[b2][a2] == A[b1][a1 + 1] && A[b2][a2] == A[b1][a1 + 2]) ||

			(A[b1][a1] == A[b2 + 1][a2] && A[b1][a1] == A[b2 + 2][a2]) || (A[b1][a1] == A[b2 - 1][a2] && A[b1][a1] == A[b2 - 2][a2]) ||
			(A[b1][a1] == A[b2][a2 + 1] && A[b1][a1] == A[b2][a2 + 2]) || (A[b1][a1] == A[b2][a2 - 1] && A[b1][a1] == A[b2][a2 - 2]) ||

			(A[b2][a2] == A[b1 + 1][a1] && A[b2][a2] == A[b1 + 2][a1]) || (A[b2][a2] == A[b1 - 1][a1] && A[b2][b2] == A[b1 - 2][a1]) ||
			(A[b1][a1] == A[b2 + 1][a2] && A[b1][a1] == A[b2 - 1][a2]) || (A[b1][a1] == A[b2][a2 + 1] && A[b1][a1] == A[b2][a2 - 1]))
		{
			Arzi = A[b1][a1];
			A[b1][a1] = A[b2][a2];
			A[b2][a2] = Arzi;
			Disapear();
			Drop();
		}
		
	}
}

void GamePlay::setpausehi(bool x)
{
	pausehi = x;
}
int GamePlay::getpausehi()
{
	return pausehi;
}
void GamePlay::setscore(int a)
{
	score = a;
}
int GamePlay::getscore()
{
	return score;
}
void GamePlay::TimeLimit()
{
	timelimit--;
}
void GamePlay::setlimit(int a)
{
	timelimit = a;
}
int GamePlay::getlimit()
{
	return timelimit;
}