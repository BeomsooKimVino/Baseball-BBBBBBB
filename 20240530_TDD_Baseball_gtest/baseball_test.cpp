#include "pch.h"
#include "../20240530_TDD_Baseball/baseball.cpp"

#include <stdexcept>

TEST(BaseballGame, ThrowExceptionWhenInputLenghtIsUnmached) {
	Baseball game;
	EXPECT_THROW(game.guess("12"), std::length_error);
}