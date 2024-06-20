#ifndef CMD_OPTION_MAP_H
#define CMD_OPTION_MAP_H

#include "include/cmd_option.h"

#include <string>
#include <stdexcept>
#include <cassert>

class CMD_OPTION_MAP : public COMMAND_OPTION
{
protected:
    /**
     * @brief Checks if a given key exists in a map container and throws an exception if it does not.
     *
     * @tparam MAP The type of the map.
     * @param aKey The key to check for existence in the map.
     * @param aMap The map to check for the key.
     *
     * @throws std::invalid_argument If the key does not exist in the map.
     */

public:
    CMD_OPTION_MAP( const std::string aOption );

    template <class MAP>
    void CheckKeyInMap( const std::string& aKey, const MAP& aMap );
};

#endif // CMD_OPTION_MAP_H
