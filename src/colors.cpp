#include "include/colors.h"

#include "include/helper.h"

#include <stdexcept>

COLORS::COLORS( const std::string aColors ) : m_Colors( aColors )
{
    SetColorsList();

    for( const auto& color : m_ColorsList )
        CheckKeyInMap( color, Colors );
}

void COLORS::SetColorsList()
{
    size_t pos = 0;
    size_t pos2 = m_Colors.find_first_of( ',', pos );
    while( pos2 != std::string::npos )
    {
        m_ColorsList.push_back( m_Colors.substr( pos, pos2 - pos ) );
        pos = pos2 + 1;
        pos2 = m_Colors.find_first_of( ',', pos );
    }
    m_ColorsList.push_back( m_Colors.substr( pos, m_Colors.size() - pos ) );
}

const COLORS_LIST& COLORS::GetList() const
{
    return const_cast<COLORS_LIST&>( m_ColorsList );
};