#ifndef WINGMANN_ERR_FUSION_RESULT_H
#define WINGMANN_ERR_FUSION_RESULT_H

#include "result_base.h"

namespace wingmann::ef {

template<typename T, typename E, typename EWrapper = Error<E>>
class Result : public ResultBase<T, E> {
	T value_;
	EWrapper error_;
	bool is_valid_;

public:
	explicit Result(T value, E error, bool is_valid)
		: value_{value},
		  error_{error},
		  is_valid_{is_valid}
	{
	}

	virtual ~Result() = default;

public:
	explicit operator bool() const override {
		return this->is_valid_;
	}

public:
	T get_value() const override { return this->value_; }
	E get_error() const override { return static_cast<Error<E>>(this->error_).get(); }
};

} // namespace wingmann::ef

#endif // WINGMANN_ERR_FUSION_RESULT_H
