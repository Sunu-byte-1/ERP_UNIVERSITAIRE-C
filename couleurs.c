#include <windows.h>
#include "couleurs.h"

void couleur(int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}