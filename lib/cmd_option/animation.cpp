#include "include/animation.h"

#include <string>
#include <map>
#include <stdexcept>
#include <cassert>

ANIMATION::ANIMATION( const std::string& aOption ) : CMD_OPTION_MAP( aOption )
{
    size_t pos2 = m_Option.find_first_of( ',', 0 );
    m_Type = m_Option.substr( 0, pos2 );
    m_Speed = m_Option.substr( pos2 + 1, m_Option.size() - pos2 - 1 );
    CheckKeyInMap( m_Type, Type_Map );
    CheckKeyInMap( m_Speed, Speed_Map );
}

ANIMATION_TYPE ANIMATION::Type() const
{
    return Type_Map.at( m_Type );
}

ANIMATION_SPEED ANIMATION::Speed() const
{
    return Speed_Map.at( m_Speed );
}