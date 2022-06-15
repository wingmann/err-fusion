#include "err_fusion.h"

#include "gtest/gtest.h"

using namespace wingmann::ef;
using namespace wingmann::ef::err_kind;

Result<int, IOError> get_an_error()
{
	return Err<int, IOError>{IOError::PermissionDenied};
}

Result<int, IOError> get_correct_value()
{
	return Ok<int, IOError>{8080};
}

TEST(err_fusion, handling_error_value)
{
	std::string actual;
	std::string expected = "Permission denied";

	if (auto result = get_an_error(); !result) {
		switch (result.get_error()) {
		case IOError::NotFound:
			actual = "Not found";
			break;
		case IOError::PermissionDenied:
			actual = "Permission denied";
			break;
		default:
			actual = "Other error";
			break;
		}
	}
	EXPECT_EQ(expected, actual);
}

TEST(err_fusion, using_correct_value)
{
	if (auto result = get_correct_value(); result) {
		EXPECT_EQ(8080, result.get_value());
	}
}
