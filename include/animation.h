#ifndef ANIMATIONS_H
#define ANIMATIONS_H

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
 * @brief Used to manage animations
 */
class ANIMATION
{
private:
    std::string m_Type;
    std::string m_Speed;

    void ThrowInvalidArgument( const std::string& aMessage );

public:
    /**
     * @brief Constructor
     * @param aAnimation should be in [off, breath, steady]
     * @throws std::invalid_argument if constructor argument is not in [off, breath, steady]
     */
    ANIMATION( const std::string aType = "steady", const std::string aSpeed = "slow" );

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