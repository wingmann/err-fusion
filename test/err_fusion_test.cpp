#include "err_fusion.h"
#include "error_kind.h"

#include "gtest/gtest.h"

using namespace wingmann::err_fusion;
using namespace wingmann::err_fusion::error_kind;

auto get_error()
{
    return err<int, io::IOError>(io::IOError::PermissionDenied);
}

auto get_correct()
{
    return ok<int, io::IOError>(8080);
}

TEST(err_fusion, error)
{
    std::string actual;
    const std::string expected = "Permission denied";

    auto result = get_error();
    if (!result) {
        switch (result.get_error()) {
        case io::IOError::NotFound:
            actual = "Not found";
            break;
        case io::IOError::PermissionDenied:
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
    auto result = get_correct();
    if (result)
        EXPECT_EQ(8080, result.get());
}
