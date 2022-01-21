// Osman Zakir
// 1 / 17 / 2022
// Beginning C++20: From Novice to Professional by Ivor Horton and Peter Van Weert
// Chapter 11 Exercise 5
// Exercise Specs:
/**
 * Go back to the solution of Exercise 11-1, only this time instead of
 * creating implementation files as in exercise 11-2, create multiple interface partition
 * files, each still containing their function definitions. One partition again contains all
 * sorting functionality, the other the remaining utilities (utils). Also recycle the internals
 * partition of Exercise 11-4.
 */

import <iostream>;
import <string>;
import words;

int main()
{
	words::Words words;
	std::string text;
	const std::string separators{ " ,.!?\"\n" };

	std::cout << "Enter a string terminated by *:\n";
	std::getline(std::cin, text, '*');

	words::extract_words(words, text, separators);
	if (words.empty())
	{
		std::cout << "No words in text." << std::endl;
		return 0;
	}

	words::sort(words);
	words::show_words(words);
}