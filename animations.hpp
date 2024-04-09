#ifndef ANIMATIONS_HPP
#define ANIMATIONS_HPP

#include <map>
#include <string>

const unsigned char OFF = 0;
const unsigned char STEADY = 1;
const unsigned char BREATH = 2;

const std::map<const std::string, const unsigned char> Animations =
    { { "off", OFF }, { "steady", STEADY }, { "breath", BREATH } };

#endif // ANIMATIONS_HPP