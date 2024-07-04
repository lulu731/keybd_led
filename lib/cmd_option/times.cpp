#include "include/times.h"

#include <vector>
#include <cassert>
#include <stdexcept>

TIMES::TIMES( const std::string& aOption ) : COMMAND_OPTION( aOption )
{
    try
    {
        std::vector<std::string> Tokens;
        size_t                   pos = 0;
        size_t                   pos2 = m_Option.find_first_of( ',', pos );
        while( pos2 != std::string::npos )
        {
            Tokens.push_back( m_Option.substr( pos, pos2 - pos ) );
            pos = pos2 + 1;
            pos2 = m_Option.find_first_of( ',', pos );
        }
        Tokens.push_back( m_Option.substr( pos, m_Option.size() - pos ) );

        m_Times = new std::vector<int>;
        for( const std::string& Token : Tokens )
        {
            m_Times->push_back( std::stoi( Token ) );
        }

        assert( m_Times->size() == Tokens.size() );

        for( auto i : *m_Times )
        {
            if( i < 0 || i > 100 )
            {
                throw std::invalid_argument( "Bad times argument" );
            }
        }
    }
    catch( const std::invalid_argument& e )
    {
        throw e;
    }
}

TIMES::~TIMES()
{
}

std::vector<int>* TIMES::Times()
{
    return m_Times;
}