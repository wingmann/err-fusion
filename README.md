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
#include "err_fusion.h"

#include <iostream>

using namespace wingmann::ef;
using namespace wingmann::ef::err_kind;

auto get_an_error()
{
    return Err<int, IOError>{IoError::PermissionDenied};
}

auto get_correct_value()
{
    return Ok<int, IOError>{8080};
}

int main()
{
    if (auto result = get_an_error(); !result) {
        switch (result.get_error()) {
        case IOError::NotFound:
            std::cerr << "Resource not found";
            break;
        case IOError::PermissionDenied:
            std::cerr << "Permission denied";
            break;
        default:
            std::cerr << "Other error";
            break;
        }
    }
    
    if (auto result = get_correct_value(); result) {
        std::cout << result.get_value();
    }
    return 0;
}
```
