#include "include/animations.h"

#include <string>
#include <map>
#include <stdexcept>

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
    try
    {
        return Anim_Map.at( m_Animation );
    }
    catch(const std::exception& e)
    {
        const std::string What{ m_Animation + " argument is not [off, breath, steady]. "
        + e.what() };
        const std::invalid_argument Except( What );
        throw Except;
    }
}