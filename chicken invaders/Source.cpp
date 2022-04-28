#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

char q[80][80];
int x = 20, y = 28, k, s = 0, l = 3;
int lvl = 6, le = 1;
char b, f = 49;

//Suprafata in care se joaca jocul este delimitata de caractere pentru a forma o tabla de joc
void game()
{
	{
		for (int i = 0; i <= 34; i++)
		{
			for (int j = 0; j <= 64; j++)
			{
				if (i == 0 || i == 34)q[i][j] = 196;
				else
				{
					if (j == 0 || j == 64) q[i][j] = 179;
					else

						if (q[i][j] != 42)q[i][j] = 32;


				}
			}
		}
		q[0][0] = 218;
		q[0][64] = 191;
		q[34][0] = 192;
		q[34][64] = 217;
	}




}
//nava formata din caractere din codul ascii, folosind variabilele x si y pentru generarea ei de la stanga la dreapta, de sus in jos

void nava(int &x, int &y)
{

	q[x][y] = 32;
	q[x][y + 1] = 32;
	q[x][y + 2] = 47;
	q[x][y + 3] = 92;
	q[x][y + 4] = 32;
	q[x][y + 5] = 32;

	q[x + 1][y] = 219;
	q[x + 1][y + 1] = 32;
	q[x + 1][y + 2] = 219;
	q[x + 1][y + 3] = 219;
	q[x + 1][y + 4] = 32;
	q[x + 1][y + 5] = 219;

	q[x + 2][y] = 32;
	q[x + 2][y + 1] = 219;
	q[x + 2][y + 2] = 219;
	q[x + 2][y + 3] = 219;
	q[x + 2][y + 4] = 219;
	q[x + 2][y + 5] = 32;

	q[x + 3][y] = 219;
	q[x + 3][y + 1] = 32;
	q[x + 3][y + 2] = 219;
	q[x + 3][y + 3] = 219;
	q[x + 3][y + 4] = 32;
	q[x + 3][y + 5] = 219;


}
//ascuderea cursorului de scriere pentru o afisare mai fluida si fara intreruperi
void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void afisare()
{
	int r;

	game();
	nava(x, y);

	r = (rand() % 60) + 1;

	//afisarea stelei daca (contorul) k se imparte exact la variabila lvl (intervalul de aparitie a unei noi stele pe tabla de joc
	if (k % lvl == 0) q[1][r] = 42;
	k++;
	//avansarea stelei pe verticala matricei
	for (int i = 32; i > 0; i--)
	{
		for (int j = 60; j > 0; j--)
		{
			if (q[i][j] == 42)
			{
				q[i + 1][j] = 42;
				q[i][j] = 32;

			}

		}

	}
	//monitorizarea scorului prin verificarea "stelelor" daca se afla in partea de jos a suprafetei de joc langa border
	for (int j = 60; j > 0; j--)
	{
		if (q[33][j] == 42)
		{
			q[33][j] = 32;
			s = s + 10;
			//trecerea la nivelul urmator prin verificarea variabile s (a scorului) prin impartirea exacta la 100
			/*
			f-variabila de tip caracter pentru tranzitia din timpul jocului
			le-variabila intreaga pentru afisarea scorului pe prima linie
			lvl-cresterea aparitiei de stele pe tabla de joc
			*/
			if (s % 100 == 0)
			{
				f++;
				le++;
				if (lvl != 1)lvl--;
			}
		}
	}




	//afisarea matriciei
	for (int i = 0; i <= 35; i++)
	{
		for (int j = 0; j <= 75; j++)
		{

			printf("%c", q[i][j]);

		}
		printf("\n");
	}
}

void miscare()
{
	//coliziunea cu stelele si miscarea navetei folosind 4 identificatori pentru cele 4 directii iar default pentru orice alta tasta
	switch (b)
	{
	case 97:
	{
		game();
		nava(x, y);

		for (int i = x; i <= x + 3; i++)
		{
			for (int j = y - 2; j <= y - 1; j++)
			{
				if (q[i][j] == 42)l--;
			}
		}
		for (int i = x - 1; i <= x - 1; i++)
		{
			for (int j = y - 1; j <= y + 2; j++)
			{
				if (q[i][j] == 42)l--;
			}
		}

		if (y > 2)
			y = y - 2;

	}
	break;

	case 100:
	{
		game();
		nava(x, y);
		for (int i = x; i <= x + 3; i++)
		{
			for (int j = y + 6; j <= y + 7; j++)
			{
				if (q[i][j] == 42)l--;
			}
		}
		for (int i = x - 1; i <= x - 1; i++)
		{
			for (int j = y + 3; j <= y + 6; j++)
			{
				if (q[i][j] == 42)l--;
			}
		}

		if (y < 57)
			y = y + 2;

	}
	break;

	case 119:
	{
		game();
		nava(x, y);
		for (int i = x - 2; i <= x - 1; i++)
		{
			for (int j = y; j <= y + 5; j++)
			{
				if (q[i][j] == 42)l--;
			}
		}
		if (q[x - 3][y + 2] == 42 || q[x - 3][y + 3] == 42)l--;
		if (x > 2)
			x = x - 2;

	}
	break;

	case 115:
	{
		game();
		nava(x, y);

		for (int i = x + 4; i <= x + 5; i++)
		{
			for (int j = y; j <= y + 5; j++)
			{
				if (q[i][j] == 42)l--;
			}
		}
		for (int i = x - 2; i <= x - 2; i++)
		{
			for (int j = y; j <= y + 5; j++)
			{
				if (q[i][j] == 42)l--;
			}
		}

		if (x < 30)
			x = x + 2;

	}
	default:
	{
		game();
		nava(x, y);
		for (int i = x - 2; i <= x - 2; i++)
		{
			for (int j = y; j <= y + 5; j++)
			{
				if (q[i][j] == 42)l--;
			}
		}


	}
	}
}

void level()
{
	//afisarea nivelului
	game();
	q[15][25] = 76;
	q[15][26] = 69;
	q[15][27] = 86;
	q[15][28] = 69;
	q[15][29] = 76;

	q[15][31] = f;
	for (int i = 0; i <= 35; i++)
	{
		for (int j = 0; j <= 75; j++)
		{

			printf("%c", q[i][j]);

		}
		printf("\n");
	}
}

int main()
{
	printf("        WELCOME\n");
	printf("\n       How to play?\n");
	printf("Try to dodge the stars and make points.\n");
	printf("You have 3 lives.\n");
	printf("Every 100 points get you to another level which is harder(until lvl 9 which is the hardest)\n");
	printf("\nControls:");
	printf("\n           W-up\n");
	printf("A-left    S-down    D-right\n");
	printf("Any other key will make the stars move but you stand in place.\n");
	printf("\nPress any key to continue.");
	getch();
	int a = 3;
	char c = 51;

	//introducerea in joc ( Game starts in 3..2..1..)

	while (a > 0)
	{
		system("cls");

		game();

		q[15][20] = 71;
		q[15][21] = 65;
		q[15][22] = 77;
		q[15][23] = 69;

		q[15][25] = 83;
		q[15][26] = 84;
		q[15][27] = 65;
		q[15][28] = 82;
		q[15][29] = 84;
		q[15][30] = 83;

		q[15][32] = 73;
		q[15][33] = 78;

		q[15][35] = c;

		for (int i = 0; i <= 35; i++)
		{
			for (int j = 0; j <= 75; j++)
			{

				printf("%c", q[i][j]);

			}
			printf("\n");
		}
		Sleep(1000);
		a--;
		c--;
	}

	while (l > 0)
	{
		//apelarea si afisarea de 3 ori a nivelului plus cresterea cu 1 a scorului pentru a evita afisarea de fiecare data cand jocul avanseaza pana cand scorul nu mai este divizibil cu 100
		int pp = 0;
		if (s % 100 == 0)
		{
			while (pp < 3)
			{
				system("cls");
				level();
				Sleep(500);
				pp++;
			}s++;
		}
		//revenirea scorului ca fiind multiplu de 10
		if (s == 11 || s == 111 || s == 211 || s == 311 || s == 411 || s == 511 || s == 611 || s == 711)s--;
		system("cls");

		printf("SCORE: %d                  LIVES: %d             LEVEL: %d       \n", s, l, le);

		afisare();



		b = getche();

		hidecursor();

		miscare();



	}
	//afisarea "game over"
	system("cls");
	game();

	q[15][25] = 71;
	q[15][26] = 65;
	q[15][27] = 77;
	q[15][28] = 69;

	q[15][30] = 79;
	q[15][31] = 86;
	q[15][32] = 69;
	q[15][33] = 82;

	for (int i = 0; i <= 35; i++)
	{
		for (int j = 0; j <= 75; j++)
		{

			printf("%c", q[i][j]);

		}
		printf("\n");
	}


	getch();
}