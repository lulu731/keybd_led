#include "include/colors.h"
#include "include/animations.h"

#include <vector>
#include <iostream> // printf
#include <string>

#include <string.h>
#include <unistd.h>

#include <hidapi/hidapi_libusb.h>

void print_error( const int aResult );

void send_buffer( hid_device* aHandle, const unsigned char* aBuf);

int main( int argc, char* argv[] )
{
	const char* Options = "c:a:"; // kbd (c)olor, (a)nimation
    char* Color = nullptr;
	char* Animation = nullptr;
	int c;
	while ( ( c = getopt( argc, argv, Options ) ) != -1)
	{
		switch ( c )
		{
		case 'c':
			Color = optarg;
			break;
		case 'a':
			Animation = optarg;
			break;
		case '?':
			if ( optopt == 'c' || optopt == 'a')
				fprintf( stderr, "Option -%c requires an argument.\n", optopt );
			else
				fprintf( stderr, "Unknown option character `\\x%x`.\n", optopt);
			return EXIT_FAILURE;
		default:
			abort();
		}
	}

	const int BUF_SIZE = 64;
	int Result;

	hid_device *Handle;
	// Open ms-1565 device using VID, PID.
	Handle = hid_open( 0x1462, 0x1601, NULL );
	if ( !Handle ) {
		const wchar_t *Error = hid_error( NULL );
		printf( "Unable to open device\n" );
		printf( "%ls", Error );
 		return EXIT_FAILURE;
	}

	std::vector<unsigned char> Buf;
	Buf.assign( { 2, 1, 15 });
	Buf.resize( BUF_SIZE, 0);
	send_buffer( Handle, Buf.data() ); // All kbd zones to be configured

	Buf.clear();

	if( Animation )
	{
		//Buf.assign( {2, 2, Animations.at( Animation ), 50, 0, 0, 0, 15, 1, 0, 0 } );
	}
	else
		Buf.assign( {2, 2, 1, 50, 0, 0, 0, 15, 1, 0, 0 } );

	if ( Color )
	{
		Buf.insert( Buf.end(), Colors.at(Color).cbegin(), Colors.at(Color).cend() );
		Buf.insert( Buf.end(), 100 );
		Buf.insert( Buf.end(), Colors.at(Color).cbegin(), Colors.at(Color).cend() );
	}

	Buf.resize( BUF_SIZE, 0 );
	send_buffer( Handle, Buf.data() );

    hid_exit();

	return EXIT_SUCCESS;
}


void print_error( const int aResult )
{
	if ( aResult == -1 )
	{
		const wchar_t* Error = hid_error( NULL );
		printf( "%ls", Error );
	}
}


void send_buffer( hid_device* aHandle, const unsigned char* aBuf)
{
	int Result = hid_send_feature_report( aHandle, aBuf, 64 );
	print_error( Result );
}