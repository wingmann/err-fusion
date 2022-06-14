#ifndef WINGMANN_ERRFUSION_ERRORWRAPPER_H
#define WINGMANN_ERRFUSION_ERRORWRAPPER_H

namespace Wingmann::ErrFusion
{
	template<typename E>
	class ErrorWrapper
	{
	public:
		ErrorWrapper() = default;
		virtual ~ErrorWrapper() = default;

	public:
		virtual E Get() = 0;
	};
}

#endif // WINGMANN_ERRFUSION_ERRORWRAPPER_H
