#ifndef WINGMANN_ERR_FUSION_ERROR_WRAPPER_H
#define WINGMANN_ERR_FUSION_ERROR_WRAPPER_H

template<typename E>
class ErrorWrapper {
public:
    ErrorWrapper() = default;
    virtual ~ErrorWrapper() = default;

public:
    virtual E get() = 0;
};

#endif // WINGMANN_ERR_FUSION_ERROR_WRAPPER_H
