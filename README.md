# ErrFusion
Error handler for modern C++

### About
A simple implementation of an error handler that does not use exceptions.
It is based on two possible situations: you can return both an error and a valid value from the function.
It is possible to check when a value is returned from a function with operator bool.
Accordingly, if operator bool returns false, you can get an error using the GetError method.
It is preferable to use enumerations to create an error type.

### Examples

```cpp
#include "ErrFusion.h"

#include <iostream>

using namespace Wingmann::ErrFusion;
using namespace Wingmann::ErrFusion::ErrorKind;

Result<int, IoError> GetAnError()
{
    return Err<int, IoError>{ IoError::PermissionDenied };
}

Result<int, IoError> GetCorrectValue()
{
    return Ok<int, IoError>{ 8080 };
}

int main()
{
    auto result = GetAnError();
    
    if (!result)
    {
        switch (result.GetError())
        {
            case IoError::NotFound:
                std::cerr << "Resource not found";
                break;
            case IoError::PermissionDenied:
                std::cerr << "Permission denied";
                break;
            default:
                std::cerr << "Other error";
                break;
        }
    }
    
    result = GetCorrectValue();
    
    if (result)
    {
        std::cout << result.GetValue();
    }
    
    return 0;
}
```
