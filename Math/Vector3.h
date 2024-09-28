#pragma once
namespace SpartanSuit {
	struct [[nodiscard]] Vector3 {
		union 
		{
			struct {
				float x, y, z;
			};
		};

		Vector3() = default;
		
		Vector3(float x, float y, float z);

		static inline constexpr Vector3 Zero() {
			return Vector3(0, 0, 0);
		}

		static inline constexpr Vector3 One() {
			return Vector3(1, 1, 1);
		}
	};
}