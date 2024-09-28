#include "Joint.h"

using namespace SpartanSuit;

const Vector3& SpartanSuit::Joint::GetPosition() const noexcept
{
    return this->m_position;
}

const Vector3& SpartanSuit::Joint::GetRotation() const noexcept
{
    return this->m_rotation;
}
