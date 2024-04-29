#define BOOST_TEST_MODULE animations

#include "include/animations.h"

#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE( GetOFFAnimation )
{
    ANIMATION aAnim( "off" );
    BOOST_CHECK( aAnim.GetAnimation() == ANIMATION_ENUM::OFF );
}

BOOST_AUTO_TEST_CASE( GetSTEADYAnimation )
{
    ANIMATION aAnim( "steady" );
    BOOST_CHECK( aAnim.GetAnimation() == ANIMATION_ENUM::STEADY );
}

BOOST_AUTO_TEST_CASE( GetBREATHAnimation )
{
    ANIMATION aAnim( "breath" );
    BOOST_CHECK( aAnim.GetAnimation() == ANIMATION_ENUM::BREATH );
}
