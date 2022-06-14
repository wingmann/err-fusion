#ifndef WINGMANN_ERRFUSION_RESULT_H
#define WINGMANN_ERRFUSION_RESULT_H

#include "ResultBase.h"

namespace Wingmann::ErrFusion
{
	template<typename T, typename E, typename EWrapper = Error<E>>
	class Result : public ResultBase<T, E>
	{
	protected:
		T value;
		EWrapper error;
		bool isValid;

	public:
		explicit Result(T correctValue, E errorValue, bool valid)
			: value{correctValue},
			  error{errorValue},
			  isValid{valid}
		{
		}

		virtual ~Result() = default;

	public:
		explicit operator bool() const override
		{
			return this->isValid;
		}

	public:
		T GetValue() const override
		{
			return this->value;
		}

		E GetError() const override
		{
			return static_cast<Error<E>>(this->error).Get();
		}
	};
}

#endif // WINGMANN_ERRFUSION_RESULT_H
