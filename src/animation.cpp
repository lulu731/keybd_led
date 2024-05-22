#include "include/animation.h"

#include <string>
#include <map>
#include <stdexcept>
#include <cassert>

/**
 * @brief Maps string param to ANIMATION_TYPE enum
 */
const std::map<std::string, ANIMATION_TYPE> Type_Map{ { "off", ANIMATION_TYPE::OFF },
                                                      { "steady", ANIMATION_TYPE::STEADY },
                                                      { "breath", ANIMATION_TYPE::BREATH } };

/**
 * @brief Maps string param to ANIMATION_SPEED enum
 */
const std::map<std::string, ANIMATION_SPEED> Speed_Map{ { "slow", ANIMATION_SPEED::SLOW },
                                                        { "medium", ANIMATION_SPEED::MEDIUM },
                                                        { "fast", ANIMATION_SPEED::FAST } };

ANIMATION::ANIMATION( const std::string aType, const std::string aSpeed ) :
        m_Type( aType ), m_Speed( aSpeed )
{
    if( Type_Map.find( m_Type ) == Type_Map.end() )
    {
        const std::invalid_argument Except( m_Type + " argument is not in [off, breath, steady]." );
        throw Except;
    };
    if( Speed_Map.find( m_Speed ) == Speed_Map.end() )
    {
        const std::invalid_argument Except( m_Speed + " argument is not in [slow, medium, fast]." );
        throw Except;
    }
}


ANIMATION_TYPE ANIMATION::Type() const
{
    assert( m_Type == "off" || m_Type == "steady" || m_Type == "breath" );

    return Type_Map.at( m_Type );
}

ANIMATION_SPEED ANIMATION::Speed() const
{
    return Speed_Map.at( m_Speed );
}