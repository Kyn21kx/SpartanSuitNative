#pragma once
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