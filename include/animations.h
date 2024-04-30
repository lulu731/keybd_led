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

const std::map<const std::string, const ANIMATION> Animations = { { "off", ANIMATION::OFF },
                                                                  { "steady", ANIMATION::STEADY },
                                                                  { "breath", ANIMATION::BREATH } };

/**
 * @brief Used to manage animations
 */
class ANIMATIONS
{
private:
    std::string m_Animation;

public:
    ANIMATIONS( const std::string aAnimation );
    ~ANIMATIONS();

    /**
     * @brief Returns current animation
     * @return ANIMATION enum value
     */
    ANIMATION GetAnimation() const;
};

#endif // ANIMATIONS_H