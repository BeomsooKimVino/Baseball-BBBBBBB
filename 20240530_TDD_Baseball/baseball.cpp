#include <stdexcept>

using namespace std;
#include <cctype>

class Baseball {
public:
	void guess(const string& guessNumber) {
		if (guessNumber.length() != 3)
			throw length_error("Must be three letters.");

		for (auto ch : guessNumber)
		{
			if (!std::isdigit(ch))
				throw std::invalid_argument("Must be number.");
		}
	}
};