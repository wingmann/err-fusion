#ifndef WINGMANN_ERR_FUSION_ERROR_H
#define WINGMANN_ERR_FUSION_ERROR_H

namespace wingmann::err_fusion {

template<typename E>
class Error {
    E error_;

public:
    Error() = delete;
    explicit Error(E error) { error_ = error; }
    virtual ~Error() = default;

public:
    virtual E get() { return error_; }
};

} // namespace wingmann::err_fusion

#endif // WINGMANN_ERR_FUSION_ERROR_H
