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

		static inline Vector3 Zero() {
			return Vector3{ 0.0f, 0.0f, 0.0f };
		}

		static inline Vector3 One() {
			return Vector3{ 1.0f, 1.0f, 1.0f};
		}
	};
}