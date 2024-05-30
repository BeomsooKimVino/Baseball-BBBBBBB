#include "pch.h"
#include "../20240530_TDD_Baseball/baseball.cpp"

#include <stdexcept>

class BaseballFixture : public testing::Test {
public:
	Baseball game{ "123" };
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

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);

}

TEST_F(BaseballFixture, ReturnSolvedResultIfNotMatchedNumber) {
	GuessResult result = game.guess("456");

	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(0, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnSolvedResultIf2Strikes) {
	GuessResult result = game.guess("124");

	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}
