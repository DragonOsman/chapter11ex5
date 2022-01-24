export module words:utils;
export import :alias;

import <iostream>;
import <string>;
import <vector>;
import <memory>;
import <format>;

std::size_t max_word_length(const words::Words& words);

export namespace words
{
	void extract_words(Words& words, const std::string& text,
		const std::string& separators);

	void show_words(const Words& words);
}

void words::extract_words(words::Words& words, const std::string& text,
	const std::string& separators)
{
	std::size_t start{ text.find_first_not_of(separators) };

	while (start != std::string::npos)
	{
		std::size_t end = text.find_first_of(separators, start + 1);
		if (end == std::string::npos)
		{
			end = text.length();
		}
		words.push_back(std::make_shared<std::string>(text.substr(start, end - start)));
		start = text.find_first_not_of(separators, end + 1);
	}
}

void words::show_words(const words::Words& words)
{
	const std::size_t field_width{ max_word_length(words) + 1 };
	const std::size_t words_per_line{ 8 };
	std::cout << std::format("{:{}}", *words[0], field_width);

	std::size_t words_in_line{};
	for (std::size_t i{ 1 }; i < words.size(); ++i)
	{ // Output newline when initial letter changes or after 8 per line
		if ((*words[i])[0] != (*words[i - 1])[0] || ++words_in_line == words_per_line)
		{
			words_in_line = 0;
			std::cout << std::endl;
		}
		std::cout << std::format("{:{}}", *words[i], field_width);
	}
	std::cout << std::endl;
}