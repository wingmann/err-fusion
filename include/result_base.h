#ifndef WINGMANN_ERR_FUSION_RESULT_BASE_H
#define WINGMANN_ERR_FUSION_RESULT_BASE_H

#include "error.h"

namespace wingmann::ef {

template<typename T, typename E>
class result_base {
public:
	result_base() = default;
	virtual ~result_base() = default;

public:
	virtual explicit operator bool() const = 0;

public:
	virtual T get_value() const = 0;
	virtual E get_error() const = 0;
};

} // namespace wingmann::ef

#endif // WINGMANN_ERR_FUSION_RESULT_BASE_H
