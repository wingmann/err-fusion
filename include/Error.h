#ifndef WINGMANN_ERRFUSION_ERROR_H
#define WINGMANN_ERRFUSION_ERROR_H

#include "ErrorWrapper.h"

#include <string>
#include <utility>

namespace Wingmann::ErrFusion
{
	template<typename E>
	class Error : public ErrorWrapper<E>
	{
	private:
		E error_{};

	public:
		Error() = default;

		explicit Error(E error_value)
		{
			error_ = error_value;
		}

		~Error() override = default;

	public:
		E Get() override
		{
			return error_;
		}
	};
}

#endif // WINGMANN_ERRFUSION_ERROR_H
