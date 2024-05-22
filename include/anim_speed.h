#ifndef ANIM_SPEED_H
#define ANIM_SPEED_H

#include <string>

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
     * @return ANIMATION_SPEED enum value
     * @retval ANIMATION_SPEED::OFF
     * @retval ANIMATION_SPEED::STEADY
     * @retval ANIMATION_SPEED::BREATH
     */
    ANIMATION_SPEED Speed() const;
};

#endif // ANIM_SPEED_H