#include "strategies.h"
#include "mods.h"
int main()
{
	char input;

	while (true) {
		std::cout << "Choose gamemode: \n Type F for Fast mode \n Type D for Detailed mode \n Type T for Tournament \n Type Q for Quit \n\n";
		std::cin >> input;
		switch (input)
		{
		case 'F':
			fastmode();
			break;
		case 'D':
			detailedmode();
			break;
		case 'T':
			tournament();
			break;
		case 'Q':
			return 0;
		default:
			MessageBoxA(0, ("Wrong command"), "ERROR", MB_ICONERROR);
			break;
		}
	}

	return 0;
}