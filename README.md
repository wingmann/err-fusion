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

#include <iostream>

using namespace wingmann::ef;
using namespace wingmann::ef::err_kind;

auto get_an_error = []() {
    return err<int, io_error>{io_error::permission_denied};
};

auto get_correct_value = []() {
    return ok<int, io_error>{8080};
};

int main() {
    if (auto res = get_an_error(); !res) {
        switch (res.get_error()) {
        case io_error::not_found:
            std::cerr << "Resource not found";
            break;
        case io_error::permission_denied:
            std::cerr << "Permission denied";
            break;
        default:
            std::cerr << "Other error";
            break;
        }
    }
    
    if (auto res = get_correct_value(); res) {
        std::cout << res.get_value();
    }
    return 0;
}
```
