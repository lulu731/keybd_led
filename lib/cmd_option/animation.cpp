#include "include/animation.h"

#include "include/helper.h"

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
    CheckKeyInMap( m_Type, Type_Map );
    CheckKeyInMap( m_Speed, Speed_Map );
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