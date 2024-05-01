#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include <map>
#include <string>

/**
 * Animation enumeration
 */
enum class ANIMATION
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
    ANIMATIONS( const std::string aAnimation );

    /**
     * @brief Returns current animation
     * @return ANIMATION enum value
     * @retval ANIMATION::OFF
     * @retval ANIMATION::STEADY
     * @retval ANIMATION::BREATH
     */
    ANIMATION GetAnimation() const;
};

#endif // ANIMATIONS_H