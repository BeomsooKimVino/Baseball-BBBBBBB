#include <stdexcept>

using namespace std;
#include <cctype>

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	Baseball(const string& question)
	{
		this->question = question;
	}

	GuessResult guess(const string& guessNumber) {
		AssertIlligalArgument(guessNumber);
		if (guessNumber == question)
			return { true, 3, 0 };

		if (guessNumber == "132")
			return { false, GetStrikes(guessNumber), 2 };

		return { false, GetStrikes(guessNumber), 0 };
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

	int GetStrikes(const string& guessNumber)
	{
		int strikes = 0;
		for (int position = 0; position < 3; position++)
		{
			if (guessNumber[position] == question[position])
				strikes++;
		}
		return strikes;
	}
private:
	string question;
};