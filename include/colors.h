#ifndef COLORS_H
#define COLORS_H

#include "include/cmd_option_map.h"

#include <vector>
#include <map>
#include <string>

const std::vector<unsigned char> WHITE = { 255, 255, 255 };
const std::vector<unsigned char> RED = { 255, 0, 0 };
const std::vector<unsigned char> GREEN = { 0, 255, 0 };
const std::vector<unsigned char> BLUE = { 0, 0, 255 };

const std::map<const std::string, const std::vector<unsigned char>> Colors = { { "white", WHITE },
                                                                               { "red", RED },
                                                                               { "green", GREEN },
                                                                               { "blue", BLUE } };


/**
 * @brief Stores list of colors as a vector of strings
 */
typedef std::vector<std::string> COLORS_LIST;

/**
 * @brief Class to store colors
 * @param aColors formatted as a string with colors separated by commas, for example "white,red,green,white"
 * @throw std::invalid_argument if colors are not in [white, red, green, blue]
 * @example COLORS( "red" )
 */
class COLORS : public CMD_OPTION_MAP
{
private:
    COLORS_LIST m_ColorsList;

    void SetColorsList();

public:
    /**
     * @brief Constructor
     * @param aColors formatted as a string with colors separated by commas, for example "white,red,green,white"
     * @throw std::invalid_argument if color is not in [white, red, green, blue]
     * @example COLORS( "red,white" )
     */
    COLORS( const std::string aColors );

    /**
     * @brief Returns list of colors
     * @return COLORS_LIST
     * @example COLORS( "red" ).GetList()
     * @retval COLORS_LIST { "white", "red", "green", "blue", ... }
     */
    const COLORS_LIST& GetList() const;
};

#endif // COLORS_H