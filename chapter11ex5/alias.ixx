export module words:alias;

import <vector>;
import <string>;
import <memory>;

export namespace words
{
	using Words = std::vector<std::shared_ptr<std::string>>;
}