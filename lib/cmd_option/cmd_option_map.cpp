#include "include/cmd_option_map.h"

#include <string>
#include <map>
#include <vector>

CMD_OPTION_MAP::CMD_OPTION_MAP( const std::string aOption ) : COMMAND_OPTION( aOption )
{
}

template <class MAP>
void CMD_OPTION_MAP::CheckKeyInMap( const std::string& aKey, const MAP& aMap )
{
    assert( !aMap.empty() );

    if( aMap.find( aKey ) == aMap.end() )
    {
        std::string MapSet = "[";
        for( auto it = aMap.cbegin(); it != aMap.cend(); ++it )
        {
            MapSet += it->first + ", ";
        };
        MapSet.erase( MapSet.rfind( "," ) );
        MapSet += "]";
        throw std::invalid_argument( "Argument -" + aKey + "- is not in " + MapSet );
    }
}

template void
CMD_OPTION_MAP::CheckKeyInMap<std::map<const std::string, const std::vector<unsigned char>>>(
        const std::string&, const std::map<const std::string, const std::vector<unsigned char>>& );