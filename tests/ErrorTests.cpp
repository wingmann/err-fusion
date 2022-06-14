#include "ErrFusion.h"
#include "ErrorKind.h"

#include "gtest/gtest.h"

using namespace Wingmann::ErrFusion;
using namespace Wingmann::ErrFusion::ErrorKind;

Result<int, IoError> GetAnError()
{
	return Err<int, IoError>(IoError::PermissionDenied);
}

Result<int, IoError> GetCorrectValue()
{
	return Ok<int, IoError>(8080);
}

TEST(ErrFusion, HandlingErrorValue)
{
	std::string actual;
	std::string expected = "Permission denied";

	auto result = GetAnError();

	if (!result)
	{
		switch (result.GetError())
		{
			case IoError::NotFound:
				actual = "Not found";
				break;
			case IoError::PermissionDenied:
				actual = "Permission denied";
				break;
			default:
				actual = "Other error";
				break;
		}
	}

	EXPECT_EQ(expected, actual);
}

TEST(ErrFusion, GettingCorrectValue)
{
	auto result = GetCorrectValue();

	if (result)
	{
		EXPECT_EQ(8080, result.GetValue());
	}
}
