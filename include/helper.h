#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <stdexcept>
#include <cassert>

/**
 * @brief Checks if a given key exists in a map container and throws an exception if it does not.
 *
 * @tparam MAP The type of the map.
 * @param aKey The key to check for existence in the map.
 * @param aMap The map to check for the key.
 *
 * @throws std::invalid_argument If the key does not exist in the map.
 */
template <typename MAP>
void CheckKeyInMap( const std::string& aKey, const MAP& aMap )
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

#endif // HELPER_H