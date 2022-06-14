#ifndef WINGMANN_ERRFUSION_ERR_H
#define WINGMANN_ERRFUSION_ERR_H

#include "Result.h"

namespace Wingmann::ErrFusion
{
	template<typename T, typename E, typename EWrapper = Error<E>>
	class Err : public Result<T, E, EWrapper>
	{
	public:
		explicit Err(E errorValue) : Result<T, E, EWrapper>(T(), errorValue, false)
		{
		}
	};
}

#endif // WINGMANN_ERRFUSION_ERR_H
