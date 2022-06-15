#ifndef WINGMANN_ERR_FUSION_ERROR_WRAPPER_H
#define WINGMANN_ERR_FUSION_ERROR_WRAPPER_H

namespace wingmann::ef {

template<typename E>
class error_wrapper {
public:
	error_wrapper() = default;
	virtual ~error_wrapper() = default;

public:
	virtual E get() = 0;
};

} // namespace wingmann::ef

#endif // WINGMANN_ERR_FUSION_ERROR_WRAPPER_H
