#include "include/animations.h"

#include <string>
#include <map>
#include <stdexcept>
#include <cassert>

/**
 * @brief Maps string param to ANIMATION enum
 */
const std::map<std::string, ANIMATION> Anim_Map{ { "off", ANIMATION::OFF },
                                                 { "steady", ANIMATION::STEADY },
                                                 { "breath", ANIMATION::BREATH } };

ANIMATIONS::ANIMATIONS( const std::string aAnimation ) : m_Animation( aAnimation )
{
    if ( m_Animation != "off" && m_Animation != "steady" && m_Animation != "breath" )
    {
        const std::string           What{ m_Animation + " argument is not [off, breath, steady]." };
        const std::invalid_argument Except( What );
        throw Except;
    }
}

ANIMATIONS::~ANIMATIONS()
{
}

ANIMATION ANIMATIONS::GetAnimation() const
{
    assert( m_Animation == "off" || m_Animation == "steady" || m_Animation == "breath" );

    return Anim_Map.at( m_Animation );
}