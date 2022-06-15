#ifndef WINGMANN_ERR_FUSION_ERR_H
#define WINGMANN_ERR_FUSION_ERR_H

#include "result.h"

namespace wingmann::ef {

template<typename T, typename E, typename EWrapper = Error<E>>
class Err : public Result<T, E, EWrapper> {
public:
	explicit Err(E errorValue) : Result<T, E, EWrapper>(T{}, errorValue, false) { }
	~Err() override = default;
};

} // namespace wingmann::ef

#endif // WINGMANN_ERR_FUSION_ERR_H
