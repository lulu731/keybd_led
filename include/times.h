#ifndef TIMES_H
#define TIMES_H

#include "include/cmd_option.h"

#include <string>
#include <vector>
#include <stdexcept>

class TIMES : public COMMAND_OPTION
{
private:
    std::vector<int>* m_Times;

public:
    TIMES( const std::string& aOption = "0" );
    ~TIMES();
    std::vector<int>* Times();
};

#endif // TIMES_H
