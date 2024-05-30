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

	GuessResult Guess(const string& guessNumber) {
		AssertIlligalArgument(guessNumber);
		if (IsCorrectAnswer(guessNumber))
			return CorrectAnswer;

		return { false, GetStrikes(guessNumber), GetBalls(guessNumber)};
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

private:
	bool IsDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

	bool IsCorrectAnswer(const string& guessNumber)
	{
		return guessNumber == question;
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

	int GetBalls(const string& guessNumber)
	{
		int balls = 0;
		for (int guessIdx = 0; guessIdx < 3; guessIdx++)
		{
			for (int questionIdx = 0; questionIdx < 3; questionIdx++)
			{
				if (guessIdx == questionIdx) continue;
				balls += (guessNumber[guessIdx] == question[questionIdx]) ? 1 : 0;
			}
		}
		return balls;
	}
	const GuessResult CorrectAnswer = { true, 3, 0 };

	string question;
};