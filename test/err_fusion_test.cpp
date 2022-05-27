#include "err_fusion.h"
#include "error_kind.h"

#include "gtest/gtest.h"

using namespace wingmann::err_fusion;
using namespace wingmann::err_fusion::error_kind;

auto get_error()
{
    return Err<int, io::IOError>(io::IOError::NotFound);
}

auto get_correct()
{
    return Ok<int, io::IOError>(8080);
}

TEST(err_fusion, error)
{
    auto result = get_error();
    int expected_error;

    if (!result) {
        switch (result.get_error()) {
        case io::IOError::NotFound:
            expected_error = 0;
            break;
        case io::IOError::PermissionDenied:
            expected_error = 1;
            break;
        default:
            expected_error = 2;
            break;
        }
    }
    EXPECT_EQ(expected_error, 0);
}

TEST(err_fusion, correct)
{
    auto result = get_correct();
    if (result)
        EXPECT_EQ(8080, result.get());
}
