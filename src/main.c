#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
#include <stdarg.h>
#include <errno.h>

#define QUERY_SIZE 256

#define BUFFER_SIZE 80

/* Prints error message and exits */
static void error_fatal (char *format, ...);

int main (int argc, char **argv){
	MYSQL *connection;
	char query[QUERY_SIZE];	
	char buffer[BUFFER_SIZE];
	connection = mysql_init (NULL);

	if (mysql_real_connect
		(connection, "localhost", "root", "root", "poslovni_oglasi", 0, NULL,
		0) == NULL)
			error_fatal ("Greska u konekciji. %s\n", mysql_error (connection));

	mysql_close (connection);
	exit(EXIT_SUCCESS);
}

static void error_fatal (char *format, ...){
	va_list arguments;
	va_start (arguments, format);
	vfprintf (stderr, format, arguments);
	va_end (arguments);
	exit (EXIT_FAILURE);
}