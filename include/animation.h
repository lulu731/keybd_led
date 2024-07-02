#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include "include/cmd_option_map.h"

#include <map>
#include <string>

/**
 * Type enumeration
 */
enum class ANIMATION_TYPE
{
    OFF = 0,
    STEADY = 1,
    BREATH = 2
};

/**
 * @brief Speed enumeration
 */
enum class ANIMATION_SPEED
{
    SLOW,
    MEDIUM,
    FAST
};


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


/**
 * @brief Used to manage animations
 */
class ANIMATION : public CMD_OPTION_MAP
{
private:
    std::string m_Type;
    std::string m_Speed;

public:
    /**
     * @brief Constructor
     * @param aOption Animation type and speed should be separated by comma
     * @throws std::invalid_argument if one of constructor argument is not in [off, breath, steady] or [slow, medium, fast]
     */
    ANIMATION( const std::string& aOption = "steady,slow" );

    /**
     * @brief Returns current animation type
     * @return ANIMATION_TYPE enum value
     * @retval ANIMATION_TYPE::OFF
     * @retval ANIMATION_TYPE::STEADY
     * @retval ANIMATION_TYPE::BREATH
     */
    ANIMATION_TYPE Type() const;

    /**
     * @brief Returns current speed
     * @return ANIMATION_SPEED enum value
     * @retval ANIMATION_SPEED::SLOW
     * @retval ANIMATION_SPEED::MEDIUM
     * @retval ANIMATION_SPEED::FAST
     */
    ANIMATION_SPEED Speed() const;
};

#endif // ANIMATIONS_H