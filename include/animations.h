#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include <map>
#include <string>

/**
 * Animation enumeration
 */
enum class ANIMATION_TYPE
{
    OFF = 0,
    STEADY = 1,
    BREATH = 2
};

/**
 * @brief Used to manage animations
 */
class ANIMATIONS
{
private:
    std::string m_Animation;

public:
    /**
     * @brief Constructor
     * @param aAnimation should be in [off, breath, steady]
     * @throws std::invalid_argument if constructor argument is not in [off, breath, steady]
     */
    ANIMATIONS( const std::string aAnimation = "steady" );

    /**
     * @brief Returns current animation
     * @return ANIMATION_TYPE enum value
     * @retval ANIMATION_TYPE::OFF
     * @retval ANIMATION_TYPE::STEADY
     * @retval ANIMATION_TYPE::BREATH
     */
    ANIMATION_TYPE Animation() const;
};

#endif // ANIMATIONS_H