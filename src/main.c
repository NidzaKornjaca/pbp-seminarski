#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
#include <stdarg.h>
#include <errno.h>

#define QUERY_SIZE 256

#define BUFFER_SIZE 80

static void print_result(MYSQL_RES *result);
/* Prints error message and exits */
static void error_fatal (char *format, ...);

int main (int argc, char **argv){
	MYSQL *connection;
	MYSQL_RES *result;	/* Promenljiva za result. */
	char query[QUERY_SIZE];	
	char buffer[BUFFER_SIZE];
	connection = mysql_init (NULL);

	if (mysql_real_connect
		(connection, "localhost", "root", "root", "poslovni_oglasi", 0, NULL,
		0) == NULL)
			error_fatal ("Greska u konekciji. %s\n", mysql_error (connection));

	sprintf (query, "select * from Oglas");

	if (mysql_query (connection, query) != 0)
		error_fatal ("Greska u upitu %s\n", mysql_error (connection));

	result = mysql_use_result (connection);

	print_result(result);

	mysql_free_result (result);
	mysql_close (connection);
	exit(EXIT_SUCCESS);
}

static void print_result(MYSQL_RES *result){
	MYSQL_FIELD *field = mysql_fetch_field (result);
	MYSQL_ROW row;
	int numberOfColumns = mysql_num_fields (result);
	int i;
	/* Header */
	for (i = 0; i < numberOfColumns; i++)
		printf ("%s\t", field[i].name);
	printf ("\n");
	/* Values */
	while ((row = mysql_fetch_row (result)) != 0){
		for (i = 0; i < numberOfColumns; i++)
			printf ("%s\t", row[i]);
		printf ("\n");
	}
}

static void error_fatal (char *format, ...){
	va_list arguments;
	va_start (arguments, format);
	vfprintf (stderr, format, arguments);
	va_end (arguments);
	exit (EXIT_FAILURE);
}