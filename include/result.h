#ifndef WINGMANN_ERR_FUSION_RESULT_H
#define WINGMANN_ERR_FUSION_RESULT_H

#include <optional>

namespace wingmann::err_fusion {

template<typename T, typename E>
class Result {
    std::optional<T> result_;
    std::optional<E> error_;

public:
    Result() = delete;

    Result(T result)
    {
        result_ = result;
        error_ = std::nullopt;
    }

    Result(E error)
    {
        error_ = error;
        result_ = std::nullopt;
    }

    virtual ~Result() = default;

public:
    explicit operator bool() { return result_.has_value(); }

    std::optional<T> get() { return *result_; }
    std::optional<E> get_error() { return *error_; }
};

} // namespace wingmann::err_fusion

#endif // WINGMANN_ERR_FUSION_RESULT_H
