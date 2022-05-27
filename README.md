# ErrFusion
Error handler for modern C++

### About
A simple implementation of an error handler that does not use exceptions.
It is based on two possible situations: you can return both an error and a valid value from the function.
It is possible to check when a value is returned from a function with operator bool.
Accordingly, if operator bool returns false, you can get an error using the get_error method.
It is preferable to use enumerations to create an error type.

### Examples

```cpp
enum class NetworkErrorKind {
    NotFound,
    Disconnected
};
```
```cpp
#include "err_fusion.h"

using namespace wingmann;

err_fusion::Result<int, err_fusion::Error<NetworkErrorKind>> get_error()
{
    return err_fusion::Error{NetworkErrorKind::NotFound};
}

err_fusion::Result<int, err_fusion::Error<NetworkErrorKind>> get_correct()
{
    return 8080;
}
```
```cpp
#include <iostream>

int main()
{
    auto result = get_error();
    if (!result) {
        switch (result.get_error().value().get()) {
        case NetworkErrorKind::NotFound:
            std::cout << "Resource not found";
            break;
        case NetworkErrorKind::Disconnected:
            std::cout << "Disconnected";
            break;
        }
    }
    
    result = get_correct();
    if (result) {
        std::cout << result.get().value();
    }
    
    
    return 0;
}
```
