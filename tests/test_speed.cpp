#define BOOST_TEST_MODULE anim_speed

#include "include/anim_speed.h"

#include <boost/test/included/unit_test.hpp>

#include <stdexcept>

BOOST_AUTO_TEST_CASE( DefaultCtorReturnSLOW )
{
    ANIM_SPEED aSpeed;
    BOOST_CHECK( aSpeed.Speed() == ANIMATION_SPEED::SLOW );
}

BOOST_AUTO_TEST_CASE( GetSLOWAnimation )
{
    ANIM_SPEED aSpeed( "slow" );
    BOOST_CHECK( aSpeed.Speed() == ANIMATION_SPEED::SLOW );
}

BOOST_AUTO_TEST_CASE( GetMEDIUMSpeed )
{
    ANIM_SPEED aSpeed( "medium" );
    BOOST_CHECK( aSpeed.Speed() == ANIMATION_SPEED::MEDIUM );
}

BOOST_AUTO_TEST_CASE( GetFASTAnimation )
{
    ANIM_SPEED aSpeed( "fast" );
    BOOST_CHECK( aSpeed.Speed() == ANIMATION_SPEED::FAST );
}

BOOST_AUTO_TEST_CASE( Ctor_Throw_Exception_On_Wrong_String )
{
    BOOST_CHECK_THROW( ANIM_SPEED( "Slow" ), std::invalid_argument );
}