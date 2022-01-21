import words;

import <iostream>;

std::size_t max_word_length(const words::Words& words)
{
	std::size_t max{};
	for (auto& pword : words)
	{
		if (max < pword->length())
		{
			max = pword->length();
		}
	}
	return max;
}

void swap(words::Words& words, std::size_t first, std::size_t second)
{
	auto temp{ words[first] };
	words[first] = words[second];
	words[second] = temp;
}