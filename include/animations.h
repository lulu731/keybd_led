#ifndef ANIMATIONS_HPP
#define ANIMATIONS_HPP

#include <map>
#include <string>

enum class ANIMATION { OFF = 0, STEADY = 1, BREATH = 2 };

const std::map<const std::string, const ANIMATION> Animations =
    { { "off", ANIMATION::OFF },
      { "steady", ANIMATION::STEADY },
      { "breath", ANIMATION::BREATH } };

class ANIMATIONS
{
private:
    std::string m_Animation;
public:
    ANIMATIONS(const std::string aAnimation);
    ~ANIMATIONS();
    ANIMATION GetAnimation() const;
};

#endif // ANIMATIONS_HPP