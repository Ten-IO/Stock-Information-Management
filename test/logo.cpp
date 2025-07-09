#include <iostream>
#include <logo.h>

int main()
{

	// ANSI escape codes for colors
	const std::string RED = "\033[31m";
	const std::string GREEN = "\033[32m";
	const std::string YELLOW = "\033[33m";
	const std::string BLUE = "\033[34m";
	const std::string MAGENTA = "\033[35m";
	const std::string CYAN = "\033[36m";
	const std::string RESET = "\033[0m"; // Resets to default color
	for (int i = 0; i <= 255; ++i)
	{
		std::cout << "\033[48;5;" << i << "m  \033[0m";
	}
	std::cout << std::endl;
	std::cout << "Light: \u2591" << std::endl;	// ░
	std::cout << "Medium: \u2592" << std::endl; // ▒
	std::cout << "Dark: \u2593" << std::endl;	// ▓
	std::cout << "Solid: \u2588" << std::endl;	// █
	std::cout << "\033[38;5;240m\u2591"			// light gray + light shade
			  << "\033[38;5;244m\u2592"			// medium gray + medium shade
			  << "\033[38;5;248m\u2593"			// darker gray + dark shade
			  << "\033[0m" << std::endl;
	std::cout << "\033[38;5;196mBright red text\033[0m\n";
	std::cout << "\033[48;5;236mDark gray background\033[0m\n";
	std::cout << "\033[1;32mBold green text\033[0m\n";
	std::cout << "\033[4;34mUnderlined blue text\033[0m\n";
	std::cout << "\033[38;5;196mBright red text\033[0m\n";
	std::cout << "\033[48;5;236mDark gray background\033[0m\n";
	// 256 true colors
	for (int g = 0; g <= 255; g += 10)
	{
		std::cout << "\033[48;2;" << g << ";" << g << ";" << g << "m  \033[0m";
	}

	// start

	start();
	simpleStart();
	return 0;
}