#pragma once
#include "../Math/Vector3.h"
#include <cstdint>

namespace SpartanSuit {
	struct MotionData {
		Vector3 acceleration;
		Vector3 eulerAngles;
		
		/// <summary>
		/// This provides a fail-proof way of transmitting data
		/// by assigning them in order in the device, and being able to
		/// reorder them once they get to the receiver.
		/// </summary>
		uint32_t recordingIndex;

		float deltaTime;
	};
}

