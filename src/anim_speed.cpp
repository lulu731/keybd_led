#include "include/anim_speed.h"

#include <string>
#include <map>
#include <stdexcept>


const std::map<std::string, SPEED> Speed_Map{ { "slow", SPEED::SLOW },
                                              { "medium", SPEED::MEDIUM },
                                              { "fast", SPEED::FAST } };


ANIM_SPEED::ANIM_SPEED( const std::string aSpeed ) : m_Speed( aSpeed )
{
    if( Speed_Map.find( m_Speed ) == Speed_Map.end() )
    {
        const std::invalid_argument Except( m_Speed + " argument is not in [slow, medium, fast]." );
        throw Except;
    }
}


SPEED ANIM_SPEED::Speed() const
{
    return Speed_Map.at( m_Speed );
}