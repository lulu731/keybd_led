#define BOOST_TEST_MODULE animations

#include "include/animation.h"

#include <boost/test/included/unit_test.hpp>

#include <stdexcept>

BOOST_AUTO_TEST_CASE( DefaultCtorReturnSteadyAndSlow )
{
    ANIMATION aAnim;
    BOOST_CHECK( aAnim.Type() == ANIMATION_TYPE::STEADY );
    BOOST_CHECK( aAnim.Speed() == ANIMATION_SPEED::SLOW );
}


BOOST_AUTO_TEST_CASE( GetOFF_MEDIUM_Animation )
{
    ANIMATION aAnim( "off,medium" );
    BOOST_CHECK( aAnim.Type() == ANIMATION_TYPE::OFF );
    BOOST_CHECK( aAnim.Speed() == ANIMATION_SPEED::MEDIUM );
}


BOOST_AUTO_TEST_CASE( GetSTEADY_Animation )
{
    ANIMATION aAnim( "steady,slow" );
    BOOST_CHECK( aAnim.Type() == ANIMATION_TYPE::STEADY );
}


BOOST_AUTO_TEST_CASE( Ctor_Throw_Exception_On_Wrong_Type_String )
{
    BOOST_CHECK_THROW( ANIMATION( "Breath,slow" ), std::invalid_argument );
}


BOOST_AUTO_TEST_CASE( GetSLOWAnimation )
{
    ANIMATION aAnim( "breath,slow" );
    BOOST_CHECK( aAnim.Type() == ANIMATION_TYPE::BREATH );
    BOOST_CHECK( aAnim.Speed() == ANIMATION_SPEED::SLOW );
}

BOOST_AUTO_TEST_CASE( GetMEDIUMSpeed )
{
    ANIMATION aAnim( "breath,medium" );
    BOOST_CHECK( aAnim.Type() == ANIMATION_TYPE::BREATH );
    BOOST_CHECK( aAnim.Speed() == ANIMATION_SPEED::MEDIUM );
}

BOOST_AUTO_TEST_CASE( GetFASTAnimation )
{
    ANIMATION aAnim( "breath,fast" );
    BOOST_CHECK( aAnim.Type() == ANIMATION_TYPE::BREATH );
    BOOST_CHECK( aAnim.Speed() == ANIMATION_SPEED::FAST );
}

bool CheckExceptionMessage( const std::invalid_argument& e )
{
    const std::string ExceptionMessage = e.what();
    return ExceptionMessage == "Argument -Slow- is not in [fast, medium, slow]";
}

BOOST_AUTO_TEST_CASE( Ctor_Throw_Exception_On_Wrong_Speed_String )
{
    BOOST_CHECK_EXCEPTION( ANIMATION( "off,Slow" ), std::invalid_argument, CheckExceptionMessage );
}