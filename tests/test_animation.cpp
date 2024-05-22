#define BOOST_TEST_MODULE animations

#include "include/animations.h"

#include <boost/test/included/unit_test.hpp>

#include <stdexcept>

BOOST_AUTO_TEST_CASE( DefaultCtorReturnSteadyAndSlow )
{
    ANIMATION aAnim;
    BOOST_CHECK( aAnim.Type() == ANIMATION_TYPE::STEADY );
    BOOST_CHECK( aAnim.Speed() == ANIMATION_SPEED::SLOW );
}


/*********************
 * Test cases for type
 *********************/

BOOST_AUTO_TEST_CASE( GetOFFAnimation )
{
    ANIMATION aAnim( "off" );
    BOOST_CHECK( aAnim.Type() == ANIMATION_TYPE::OFF );
}


BOOST_AUTO_TEST_CASE( GetSTEADYAnimation )
{
    ANIMATION aAnim( "steady" );
    BOOST_CHECK( aAnim.Type() == ANIMATION_TYPE::STEADY );
}

BOOST_AUTO_TEST_CASE( GetBREATHAnimation )
{
    ANIMATION aAnim( "breath" );
    BOOST_CHECK( aAnim.Type() == ANIMATION_TYPE::BREATH );
}

BOOST_AUTO_TEST_CASE( Ctor_Throw_Exception_On_Wrong_Type_String )
{
    BOOST_CHECK_THROW( ANIMATION( "Breath" ), std::invalid_argument );
}


/*********************
 * Test cases for speed
 *********************/

BOOST_AUTO_TEST_CASE( GetSLOWAnimation )
{
    ANIMATION aAnim( "breath", "slow" );
    BOOST_CHECK( aAnim.Type() == ANIMATION_TYPE::BREATH );
    BOOST_CHECK( aAnim.Speed() == ANIMATION_SPEED::SLOW );
}

BOOST_AUTO_TEST_CASE( GetMEDIUMSpeed )
{
    ANIMATION aAnim( "breath", "medium" );
    BOOST_CHECK( aAnim.Type() == ANIMATION_TYPE::BREATH );
    BOOST_CHECK( aAnim.Speed() == ANIMATION_SPEED::MEDIUM );
}

BOOST_AUTO_TEST_CASE( GetFASTAnimation )
{
    ANIMATION aAnim( "breath", "fast" );
    BOOST_CHECK( aAnim.Type() == ANIMATION_TYPE::BREATH );
    BOOST_CHECK( aAnim.Speed() == ANIMATION_SPEED::FAST );
}

BOOST_AUTO_TEST_CASE( Ctor_Throw_Exception_On_Wrong_Speed_String )
{
    BOOST_CHECK_THROW( ANIMATION( "off", "Slow" ), std::invalid_argument );
}