#ifndef WINGMANN_ERR_FUSION_OK_H
#define WINGMANN_ERR_FUSION_OK_H

#include "result.h"

namespace wingmann::ef {

template<typename T, typename E, typename EWrapper = Error<E>>
class Ok : public Result<T, E, EWrapper> {
public:
	explicit Ok(T correctValue) : Result<T, E, EWrapper>(correctValue, E{}, true) { }
	~Ok() override = default;
};

} // namespace wingmann::ef

#endif // WINGMANN_ERR_FUSION_OK_H
