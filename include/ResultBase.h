#ifndef WINGMANN_ERRFUSION_RESULTBASE_H
#define WINGMANN_ERRFUSION_RESULTBASE_H

#include "Error.h"

namespace Wingmann::ErrFusion
{
	template<typename T, typename E>
	class ResultBase
	{
	public:
		virtual explicit operator bool() const = 0;

	public:
		virtual T GetValue() const = 0;
		virtual E GetError() const = 0;
	};
}

#endif // WINGMANN_ERRFUSION_RESULTBASE_H
