#pragma once
#include <cstdint>

namespace SpartanSuit {
	enum class Error : int32_t {
		Ok,
		NetworkInitializationError,
		NetworkBindingError,
		OutOfBoundsError,
		TimeoutError,
		InternalError
	};
}
