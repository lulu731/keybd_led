#define BOOST_TEST_MODULE colors

#include "include/colors.h"

#include <boost/test/included/unit_test.hpp>

#include <stdexcept>

void Check_List_Equal( const COLORS& aColors, const COLORS_LIST& aList )
{
    auto aIterator = aList.begin();

    BOOST_REQUIRE_EQUAL( aColors.GetList().size(), aList.size() );
    for ( auto i = aColors.GetList().begin(); i != aColors.GetList().end(); i++)
    {
        BOOST_CHECK_EQUAL( *i, *aIterator );
        aIterator++;
    }
}

BOOST_AUTO_TEST_CASE( Get_White )
{
    COLORS_LIST aColorsList { "white" };
    COLORS aColors( "white" );

    Check_List_Equal( aColors, aColorsList );
}

BOOST_AUTO_TEST_CASE( Get_Color_List )
{
    COLORS_LIST aColorsList { "white", "red", "green", "white"};
    COLORS aColors( "white,red,green,white" );

    Check_List_Equal( aColors, aColorsList );
}

BOOST_AUTO_TEST_CASE( Ctor_Throw_Exception_On_Wrong_Arg )
{
    BOOST_CHECK_THROW ( COLORS( "White" ), std::invalid_argument );
}