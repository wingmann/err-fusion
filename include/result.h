#ifndef WINGMANN_ERR_FUSION_RESULT_H
#define WINGMANN_ERR_FUSION_RESULT_H

#include "error.h"

#include <string>

namespace wingmann::ef {

template<typename T, typename E, typename EWrapper = Error<E>>
class Result {
    T value_;
    EWrapper error_;
    bool is_valid_;

private:
    explicit Result(T value) : value_{value}, is_valid_{true} { }
    explicit Result(E error_value) : error_{error_value}, is_valid_{} { }

public:
    static Result ok(T value)
    {
        return Result{value};
    }

    static Result error(E error_value)
    {
        return Result{error_value};
    }

public:
    explicit operator bool() const
    {
        return is_valid_;
    }

    T get() const
    {
        return value_;
    }

    E get_error() const
    {
        return static_cast<Error<E>>(error_).get();
    }

    template<typename F> inline
    auto bind(F f) -> decltype(f(value_))
    {
        using type = decltype(f(value_));
        return (*this ? f(value_) : type::error(error_));
    }
};

template<typename T, typename E, typename EWrapper = Error<E>>
inline Result<T, E, EWrapper> ok(T value)
{
    return Result<T, E, EWrapper>::ok(value);
}

template<typename T, typename E, typename EWrapper = Error<E>>
inline Result<T, E, EWrapper> err(E error_value)
{
    return Result<T, E, EWrapper>::error(error_value);
}

} // namespace wingmann::ef

#endif // WINGMANN_ERR_FUSION_RESULT_H
