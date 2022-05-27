#ifndef WINGMANN_ERR_FUSION_RESULT_H
#define WINGMANN_ERR_FUSION_RESULT_H

#include "error.h"

namespace wingmann::err_fusion {

template<typename T, typename E>
class Result {
    T value_;
    E error_;
    bool is_valid_{};

private:
    Result() = default;

public:
    static Result ok(T value)
    {
        Result box;
        box.value_ = value;
        box.is_valid_ = true;
        return box;
    }

    static Result error(E error_value)
    {
        Result box;
        box.error_ = error_value;
        box.is_valid_ = false;
        return box;
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
        return error_;
    }

    template<typename F> inline
    auto bind(F f) -> decltype(f(value_))
    {
        using type = decltype(f(value_));
        return (*this ? f(value_) : type::error(error_));
    }
};

template<typename T, typename E> inline
Result<T, E> Ok(T value)
{
    return Result<T, E>::ok(value);
}

template<typename T, typename E> inline
Result<T, E> Err(E error_value)
{
    return Result<T, E>::error(error_value);
}

} // namespace wingmann::err_fusion

#endif // WINGMANN_ERR_FUSION_RESULT_H
