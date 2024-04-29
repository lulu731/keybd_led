#include "include/animations.h"

#include <string>

ANIMATION::ANIMATION(const std::string aAnimation) : m_Animation( aAnimation )
{
}

ANIMATION::~ANIMATION()
{
}

ANIMATION_ENUM ANIMATION::GetAnimation() const
{
    return ANIMATION_ENUM::OFF;
}