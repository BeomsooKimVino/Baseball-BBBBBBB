#include <stdexcept>

using namespace std;
#include <cctype>

class Baseball {
public:
	void guess(const string& guessNumber) {
		AssertIlligalArgument(guessNumber);
	}
	void AssertIlligalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3)
			throw length_error("Must be three letters.");

		for (auto ch : guessNumber)
		{
			if (std::isdigit(ch) == false)
				throw std::invalid_argument("Must be number.");
		}

		if (IsDuplicatedNumber(guessNumber))
		{
			throw std::invalid_argument("Duplicated number in guessNumber.");
		}
	}
	bool IsDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}
};