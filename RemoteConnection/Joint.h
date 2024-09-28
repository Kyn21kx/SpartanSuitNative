#pragma once
#include "../Math/Vector3.h"
namespace SpartanSuit {

	class Joint {
	public:

		[[nodiscard]] const Vector3& GetPosition() const noexcept;
		[[nodiscard]] const Vector3& GetRotation() const noexcept;

	private:
		Vector3 m_position;
		Vector3 m_rotation;
	};

}
