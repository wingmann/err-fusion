#include "err_fusion.h"

#include "gtest/gtest.h"

using namespace wingmann::ef;
using namespace wingmann::ef::err_kind;

auto get_an_error = []()
{
	return err<int, io_error>{io_error::permission_denied};
};

auto get_correct_value = []()
{
	return ok<int, io_error>{8080};
};

TEST(err_fusion, handling_error_value)
{
	std::string actual;
	std::string expected = "Permission denied";

	if (auto res = get_an_error(); !res) {
		switch (res.get_error()) {
		case io_error::not_found:
			actual = "Not found";
			break;
		case io_error::permission_denied:
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
	if (auto res = get_correct_value(); res) {
		EXPECT_EQ(8080, res.get_value());
	}
}
