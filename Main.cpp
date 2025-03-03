#include "includes/main.h"

int main(void)
{
	while (true)
		clsLoginScreen::ShowLoginScreen();

	return 0;
}
/*
	A circular reference in classes occurs when two or more classes depend on each other directly or indirectly,
	creating an infinite loop of dependencies.

*/
