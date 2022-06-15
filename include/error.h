#ifndef WINGMANN_ERR_FUSION_ERROR_H
#define WINGMANN_ERR_FUSION_ERROR_H

#include "error_wrapper.h"

#include <string>
#include <utility>

namespace wingmann::ef {

template<typename E>
class error : public error_wrapper<E> {
	E error_{};

public:
	error() = default;
	explicit error(E error_value) : error_{ error_value} { }
	~error() override = default;

public:
	E get() override { return error_; }
};

} // namespace wingmann::ef

#endif // WINGMANN_ERR_FUSION_ERROR_H
