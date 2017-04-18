#include "ccolor.h"

int main()
{
	Edit e;
	e.setPosition(7, 3);
	e.setLength(6);
	e.setText("Ala");
	e.setTextColor(Edit::White);
	e.setBackgroundColor(Edit::Red);
	e.display();
	std::string s = e.getText();
	e.userText();
	s = e.getText();
	e.display();

	std::cout << "A" << red << "l" << green << "a" << blue << "ma" << white << "kota\n";
	std::cout << setColor(FOREGROUND_RED | BACKGROUND_BLUE) << "Witaj" << setColor(16) << "swiecie\n";

	return 0;
}