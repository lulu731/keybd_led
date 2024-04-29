#include "include/animations.h"

#include <string>
#include <map>

const std::map<std::string, ANIMATION> Anim_Map =
    {
        { "off", ANIMATION::OFF},
        { "steady", ANIMATION::STEADY},
        { "breath", ANIMATION::BREATH}
    };

ANIMATIONS::ANIMATIONS(const std::string aAnimation) : m_Animation( aAnimation )
{
}

ANIMATIONS::~ANIMATIONS()
{
}

ANIMATION ANIMATIONS::GetAnimation() const
{
    return Anim_Map.at( m_Animation );
}