#ifndef WINGMANN_ERRFUSION_OK_H
#define WINGMANN_ERRFUSION_OK_H

#include "Result.h"

namespace Wingmann::ErrFusion
{
	template<typename T, typename E, typename EWrapper = Error<E>>
	class Ok : public Result<T, E, EWrapper>
	{
	public:
		explicit Ok(T correctValue) : Result<T, E, EWrapper>(correctValue, E(), true)
		{
		}
	};
}

#endif // WINGMANN_ERRFUSION_OK_H
