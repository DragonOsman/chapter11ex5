export module words:sort;
export import :alias;

import <iostream>;

void sort(words::Words& words, std::size_t start, std::size_t end);
void swap(words::Words& words, std::size_t first, std::size_t second);

export namespace words
{
	void sort(Words& words);
}

void words::sort(words::Words& words)
{
	if (!words.empty())
	{
		::sort(words, 0, words.size() - 1);
	}
}

void sort(words::Words& words, std::size_t start, std::size_t end)
{
	// start index must be less than end index for 2 or more elements
	if (!(start < end))
	{
		return;
	}

	// Choose middle address to partition set
	// And swap middle address with start
	swap(words, start, (start + end) / 2);

	std::size_t current{ start };
	for (std::size_t i{ start + 1 }; i <= end; i++)
	{
		// Is word word less than chosen word?
		if (*words[i] < *words[start])
		{
			// Yes, so swap to the left
			swap(words, ++current, i);
		}
	}

	// Swap chosen and last swapped words
	swap(words, start, current);

	// Sort left subset if exists
	if (current > start)
	{
		sort(words, start, current - 1);
	}

	// Sort right subset if exists
	if (end > current + 1)
	{
		sort(words, current + 1, end);
	}
}