#ifndef COLORS_HPP
#define COLORS_HPP

#include <vector>
#include <map>
#include <string>

const std::vector<unsigned char> WHITE = { 255, 255, 255 };
const std::vector<unsigned char> RED = { 255, 0, 0 };
const std::vector<unsigned char> GREEN = { 0, 255, 0 };
const std::vector<unsigned char> BLUE = { 0, 0, 255 };

const std::map<const std::string, const std::vector<unsigned char>> Colors =
    {{ "white", WHITE }, { "red", RED }, { "green", GREEN }, { "blue", BLUE }};

#endif // COLORS_HPP
