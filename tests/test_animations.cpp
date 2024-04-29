#define BOOST_TEST_MODULE animations

#include "include/animations.h"

#include <boost/test/included/unit_test.hpp>

#include <stdexcept>

BOOST_AUTO_TEST_CASE( GetOFFAnimation )
{
    ANIMATIONS aAnim( "off" );
    BOOST_CHECK( aAnim.GetAnimation() == ANIMATION::OFF );
}

BOOST_AUTO_TEST_CASE( GetSTEADYAnimation )
{
    ANIMATIONS aAnim( "steady" );
    BOOST_CHECK( aAnim.GetAnimation() == ANIMATION::STEADY );
}

BOOST_AUTO_TEST_CASE( GetBREATHAnimation )
{
    ANIMATIONS aAnim( "breath" );
    BOOST_CHECK( aAnim.GetAnimation() == ANIMATION::BREATH );
}

BOOST_AUTO_TEST_CASE( Throw_Exception_On_Wrong_String )
{
    ANIMATIONS aAnim( "Breath" );
    BOOST_CHECK_THROW ( aAnim.GetAnimation(), std::invalid_argument );
}
