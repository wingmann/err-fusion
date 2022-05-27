#include <optional>
#include <variant>
#include <exception>
#include <iostream>










Result<int, Error<NetworkErrorKind>> do_something()
{
    return Error{NetworkErrorKind::NotFound};
}

int main()
{
    auto result = do_something();

    if (result) {
        std::cout << result.get().value();
    }
    else {
        switch (result.get_error().value().get()) {
        case NetworkErrorKind::NotFound:
            std::cout << "Resource not found!";
            break;
        case NetworkErrorKind::StopConnection:
            std::cout << "Disconnected!";
            break;
        default:
            std::cout << "Unknown error!";
        }
    }
}
