#include "memory_manager.h"
#include <stdlib.h>

static unsigned char *matrix;

// Public methods.
void engine_memory_manager_malloc()
{
	// Example 100 bytes.
	unsigned char size = 100;

	if( NULL == matrix )
	{
		matrix = malloc( size * sizeof( unsigned char ) );
		matrix[ 17 ] = 17;
	}
}
void engine_memory_manager_free()
{
	if( NULL == matrix )
	{
		free( matrix );
		matrix = NULL;
	}
}