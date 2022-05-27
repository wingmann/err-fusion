#include "err_fusion.h"

#include "gtest/gtest.h"

using namespace wingmann;

enum class NetworkErrorKind {
    NotFound,
    Disconnected
};

err_fusion::Result<int, err_fusion::Error<NetworkErrorKind>> get_error()
{
    return err_fusion::Error{NetworkErrorKind::NotFound};
}

err_fusion::Result<int, err_fusion::Error<NetworkErrorKind>> get_correct()
{
    return 8080;
}

TEST(err_fusion, common_1)
{
    auto result = get_error();
    int expected_error;

    if (!result) {
        switch (result.get_error().value().get()) {
        case NetworkErrorKind::NotFound:
            expected_error = 0;
            break;
        case NetworkErrorKind::Disconnected:
            expected_error = 1;
            break;
        default:
            expected_error = 2;
            break;
        }
    }
    EXPECT_EQ(expected_error, 0);
}

TEST(err_fusion, common_2)
{
    auto result = get_correct();

    if (result)
        EXPECT_EQ(8080, result.get().value());
}
