#define BOOST_TEST_MODULE animations

#include "include/animations.h"

#include <boost/test/included/unit_test.hpp>

#include <stdexcept>

BOOST_AUTO_TEST_CASE( GetOFFAnimation )
{
    ANIMATIONS aAnim( "off" );
    BOOST_CHECK( aAnim.Animation() == ANIMATION_TYPE::OFF );
}

BOOST_AUTO_TEST_CASE( DefaultCtorReturnSteady )
{
    ANIMATIONS aAnim;
    BOOST_CHECK( aAnim.Animation() == ANIMATION_TYPE::STEADY );
}

BOOST_AUTO_TEST_CASE( GetSTEADYAnimation )
{
    ANIMATIONS aAnim( "steady" );
    BOOST_CHECK( aAnim.Animation() == ANIMATION_TYPE::STEADY );
}

BOOST_AUTO_TEST_CASE( GetBREATHAnimation )
{
    ANIMATIONS aAnim( "breath" );
    BOOST_CHECK( aAnim.Animation() == ANIMATION_TYPE::BREATH );
}

BOOST_AUTO_TEST_CASE( Ctor_Throw_Exception_On_Wrong_String )
{
    BOOST_CHECK_THROW( ANIMATIONS( "Breath" ), std::invalid_argument );
}
