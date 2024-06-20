#ifndef CMD_OPTION_H
#define CMD_OPTION_H

#include <string>

class COMMAND_OPTION
{
protected:
    std::string m_Option;

public:
    COMMAND_OPTION( const std::string aOption );
};

#endif // CMD_OPTION_H