#ifndef ANIMATIONS_HPP
#define ANIMATIONS_HPP

#include <map>
#include <string>

enum class ANIMATION_ENUM { OFF = 0, STEADY = 1, BREATH = 2 };

const std::map<const std::string, const ANIMATION_ENUM> Animations =
    { { "off", ANIMATION_ENUM::OFF },
      { "steady", ANIMATION_ENUM::STEADY },
      { "breath", ANIMATION_ENUM::BREATH } };

class ANIMATION
{
private:
    std::string m_Animation;
public:
    ANIMATION(const std::string aAnimation);
    ~ANIMATION();
    ANIMATION_ENUM GetAnimation() const;
};

#endif // ANIMATIONS_HPP