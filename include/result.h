#ifndef WINGMANN_ERR_FUSION_RESULT_H
#define WINGMANN_ERR_FUSION_RESULT_H

#include "result_base.h"

namespace wingmann::ef {

template<typename T, typename E, typename EWrapper = error<E>>
class result : public result_base<T, E> {
    T value_;
    EWrapper error_;
    bool valid_;

public:
    explicit result(T value, E error, bool valid) : value_{value}, error_{error}, valid_{valid} { }
    ~result() override = default;

public:
    explicit operator bool() const final { return this->valid_; }

public:
    T get_value() const final { return this->value_; }
    E get_error() const final { return static_cast<error<E>>(this->error_).get(); }
};

} // namespace wingmann::ef

#endif // WINGMANN_ERR_FUSION_RESULT_H
