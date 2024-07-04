#define BOOST_TEST_MODULE times

#include "include/times.h"

#include <boost/test/included/unit_test.hpp>

#include <stdexcept>
#include <vector>

BOOST_AUTO_TEST_CASE( DefaultCtorReturnsZero )
{
    TIMES             aTimes;
    std::vector<int>* Times = aTimes.Times();
    BOOST_CHECK( aTimes.Times()->size() == 1 );
    BOOST_CHECK( aTimes.Times()->at( 0 ) == 0 );
    delete Times;
}

BOOST_AUTO_TEST_CASE( SizeShouldBeSix )
{
    TIMES             aTimes( "0,10,20,40,50,100" );
    std::vector<int>* Times = aTimes.Times();
    BOOST_CHECK( aTimes.Times()->size() == 6 );
    BOOST_CHECK( aTimes.Times()->at( 3 ) == 40 );
    delete Times;
}


/** Tests constructor throwing exception **/

bool CheckExceptionMessage( const std::invalid_argument& e )
{
    const std::string ExceptionMessage = e.what();
    return ExceptionMessage == "Bad times argument";
}

BOOST_AUTO_TEST_CASE( CtorThrowExceptionOnWrongTime )
{
    BOOST_CHECK_EXCEPTION( TIMES( "0,110" ), std::invalid_argument, CheckExceptionMessage );
}


bool TrueExceptionMessage( const std::invalid_argument& e )
{
    return true;
}

BOOST_AUTO_TEST_CASE( CtorThrowExceptionOnTimeNotInt )
{
    BOOST_CHECK_EXCEPTION( TIMES( "0,abc" ), std::invalid_argument, TrueExceptionMessage );
}