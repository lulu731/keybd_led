#define BOOST_TEST_MODULE animations

#include "include/animations.h"

#include <boost/test/included/unit_test.hpp>

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
