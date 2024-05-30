#include "pch.h"
#include "../20240530_TDD_Baseball/baseball.cpp"

#include <stdexcept>

class BaseballFixture : public testing::Test {
public:
	Baseball game;
	void AssertIlligalArgument(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e)
		{
			// PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	AssertIlligalArgument("12");
	AssertIlligalArgument("12s");
	AssertIlligalArgument("121");
}
