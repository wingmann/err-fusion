# ErrFusion
error handler for modern C++

### About
A simple implementation of an error handler that does not use exceptions.
It is based on two possible situations: you can return both an error and a valid value from the function.
It is possible to check when a value is returned from a function with operator bool.
Accordingly, if operator bool returns false, you can get an error using the get_error method.
It is preferable to use enumerations to create an error type.

### Examples

```cpp
#include "err_fusion.h"
#include "error_kind.h"

#include <iostream>

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

int main()
{
    auto result = get_error();
    if (!result) {
        switch (result.get_error()) {
        case io::IOError::NotFound:
            std::cout << "Resource not found";
            break;
        case io::IOError::PermissionDenied:
            std::cout << "Permission denied";
            break;
        default:
            std::cout << "Other error";
            break;
        }
    }
    
    result = get_correct();
    if (result) {
        std::cout << result.get();
    }
    return 0;
}
```
