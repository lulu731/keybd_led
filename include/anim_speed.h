#ifndef ANIM_SPEED_H
#define ANIM_SPEED_H

#include <string>

/**
 * @brief Speed enumeration
 */
enum class SPEED
{
    SLOW,
    MEDIUM,
    FAST
};

/**
 * @brief Used to manage speed of animation
 */
class ANIM_SPEED
{
private:
    const std::string m_Speed;

public:
    /**
     * @brief Constructor
     * @param aSpeed should be in [slow, medium, fast]
     * @throws std::invalid_argument if constructor argument is not in [slow, medium, fast]
     */
    ANIM_SPEED( const std::string aSpeed = "slow" );

    /**
     * @brief Returns current speed
     * @return SPEED enum value
     * @retval SPEED::OFF
     * @retval SPEED::STEADY
     * @retval SPEED::BREATH
     */
    SPEED Speed() const;
};

#endif // ANIM_SPEED_H