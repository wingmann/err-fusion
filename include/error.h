#ifndef WINGMANN_ERR_FUSION_ERROR_H
#define WINGMANN_ERR_FUSION_ERROR_H

#include "error_wrapper.h"

#include <string>
#include <utility>

namespace wingmann::err_fusion {

template<typename E>
class Error : public ErrorWrapper<E> {
    E error_{};

public:
    Error() = default;
    explicit Error(E error_value) { error_ = error_value; }
    
    ~Error() override = default;

public:
    E get() override { return error_; }
};

} // namespace wingmann::err_fusion

#endif // WINGMANN_ERR_FUSION_ERROR_H
