//#include <getopt.h>
#include <vector>

#include <iostream> // printf
#include <string.h>
#include <unistd.h>

#include <hidapi/hidapi_libusb.h>

//extern int optind;

void print_error( const int res );

void send_buffer( hid_device* handle, const unsigned char* buf);


int main( int argc, char* argv[] )
{
	const char* options = "c:a:"; // kbd (c)olor, (a)nimation
    char* color = nullptr;
	char* animation = nullptr;
	int c;
	/*while ( c = getopt( argc, argv, options ))
	{
		switch ( c )
		{
		case 'c':
			color = optarg;
			break;
		case 'a':
			animation = optarg;
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
	}*/

	int res;

	hid_device *handle;

	// Open ms-1565 device using VID, PID.
	handle = hid_open( 0x1462, 0x1601, NULL );
	if ( !handle ) {
		const wchar_t *error = hid_error( NULL );
		printf( "Unable to open device\n" );
		printf( "%ls", error );
 		return EXIT_FAILURE;
	}

	std::vector<unsigned char> buf( 64 );
	buf.assign( { 2, 1, 15 });
	send_buffer( handle, buf.data() ); // All kbd zones to be configured

//	memset( buf, 0, 64 );
	for ( int i = 1; i < argc; i++ )
	{
		const char* arg = argv[i];
		buf[i-1] = atoi( arg );
	}
	// 2 2 1 50 0 0 0 15 1 0 0 255 255 255

	send_buffer( handle, buf.data() );

    hid_exit();

	return EXIT_SUCCESS;
}


void print_error( const int res )
{
	if ( res == -1 )
	{
		const wchar_t* error = hid_error( NULL );
		printf( "%ls", error );
	}
}


void send_buffer( hid_device* handle, const unsigned char* buf)
{
	int res = hid_send_feature_report( handle, buf, 64 );
	print_error( res );
}
