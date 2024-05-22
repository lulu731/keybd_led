#include "include/animations.h"

#include <string>
#include <map>
#include <stdexcept>
#include <cassert>

/**
 * @brief Maps string param to ANIMATION_TYPE enum
 */
const std::map<std::string, ANIMATION_TYPE> Anim_Map{ { "off", ANIMATION_TYPE::OFF },
                                                 { "steady", ANIMATION_TYPE::STEADY },
                                                 { "breath", ANIMATION_TYPE::BREATH } };


ANIMATIONS::ANIMATIONS( const std::string aAnimation ) : m_Animation( aAnimation )
{
    if ( Anim_Map.find( m_Animation ) == Anim_Map.end() )
    {
        const std::invalid_argument Except( m_Animation + " argument is not in [off, breath, steady]." );
        throw Except;
    }
}


ANIMATION_TYPE ANIMATIONS::Animation() const
{
    assert( m_Animation == "off" || m_Animation == "steady" || m_Animation == "breath" );

    return Anim_Map.at( m_Animation );
}