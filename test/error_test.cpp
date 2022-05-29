#include "err_fusion.h"
#include "error_kind.h"

#include "gtest/gtest.h"

using namespace wingmann::ef;
using namespace wingmann::ef::err_kind;

auto get_an_error()
{
    return err<int, IOError>(IOError::PermissionDenied);
}

auto get_correct_value()
{
    return ok<int, IOError>(8080);
}

TEST(err_fusion, error)
{
    std::string actual;
    const std::string expected = "Permission denied";

    auto result = get_an_error();
    if (!result) {
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

TEST(err_fusion, correct)
{
    auto result = get_correct_value();
    if (result)
        EXPECT_EQ(8080, result.get());
}
