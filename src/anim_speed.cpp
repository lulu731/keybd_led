#include "include/anim_speed.h"

#include <string>
#include <map>
#include <stdexcept>


const std::map<std::string, ANIMATION_SPEED> Speed_Map{ { "slow", ANIMATION_SPEED::SLOW },
                                              { "medium", ANIMATION_SPEED::MEDIUM },
                                              { "fast", ANIMATION_SPEED::FAST } };


ANIM_SPEED::ANIM_SPEED( const std::string aSpeed ) : m_Speed( aSpeed )
{
    if( Speed_Map.find( m_Speed ) == Speed_Map.end() )
    {
        const std::invalid_argument Except( m_Speed + " argument is not in [slow, medium, fast]." );
        throw Except;
    }
}


ANIMATION_SPEED ANIM_SPEED::Speed() const
{
    return Speed_Map.at( m_Speed );
}