#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
#include <stdarg.h>
#include <errno.h>
#include "queries.h"

#define QUERY_SIZE 256

#define BUFFER_SIZE 80

static void print_result(MYSQL_RES *result);
/* Prints error message and exits */
static void error_fatal (char *format, ...);
static void print_instructions();
static MYSQL_RES* run_query(char *query, MYSQL *connection);


int main (int argc, char **argv){
	MYSQL *connection;
	MYSQL_RES *result;
	char query[QUERY_SIZE];	
	char buffer[BUFFER_SIZE];
	connection = mysql_init (NULL);

	char command = ' ';
	unsigned id1, id2;
	printf("Attempting to connect to db...\n");
	if (mysql_real_connect
		(connection, "localhost", "root", "root", "poslovni_oglasi", 0, NULL,
		0) == NULL)
			error_fatal ("Connection error. %s\n", mysql_error (connection));

	printf("Success!\n");
	print_instructions();
	do {
		scanf("%c", &command);
		if(command == 'j'){
			queriesSelectAllOglas(query);
			result = run_query(query, connection);
			print_result(result);
			mysql_free_result (result);
		}
		else if(command == 'p'){
			printf("Insert user id:");
			scanf("%u", &id1);
			printf("\n");
			queriesSelectPrijavaForUser(query, id1);
			result = run_query(query, connection);
			print_result(result);
			mysql_free_result (result);
		}
		else if(command == 'd'){
			printf("Insert user id: ");
			scanf("%u", &id1);
			printf("\n");
			printf("Insert job ad id: ");
			scanf("%u", &id2);
			printf("\n");
			queriesDeletePrijava(query, id1, id2);
			result = run_query(query, connection);
			print_result(result);
			mysql_free_result(result);
		}
		else if(command == 'a'){
			printf("Insert user id: ");
			scanf("%u", &id1);
			printf("\n");
			printf("Insert job ad id: ");
			scanf("%u", &id2);
			printf("\n");
			queriesInsertPrijava(query, id1, id2);
			result = run_query(query, connection);
			print_result(result);
			mysql_free_result(result);	
		}
		else if(command == 'i'){
			print_instructions();
		}
		else if(command == 'u'){
			queriesInsertKorisnik(query, "Korisnik", "Lozinka", "mejl@mejl.com");
			result = run_query(query, connection);
			print_result(result);
			mysql_free_result(result);		
		}
		else if(command == 'o'){
			queriesInsertOglas(query);
			result = run_query(query, connection);
			print_result(result);
			mysql_free_result(result);	
		}
		else if(command == 'k'){
			queriesSelectAllKorisnik(query);
			result = run_query(query, connection);
			print_result(result);
			mysql_free_result(result);		
		}
		else if(command != 'q' && command != '\n'){
			printf("Unknown command, enter i for instructions\n");
		}
	}
	while(command != 'q');

	mysql_close (connection);
	exit(EXIT_SUCCESS);
}

static void print_result(MYSQL_RES *result){
	if(result) {
		MYSQL_FIELD *field = mysql_fetch_field (result);
		MYSQL_ROW row;
		int numberOfColumns = mysql_num_fields (result);
		int i;
		/* Header */
		for (i = 0; i < numberOfColumns; i++)
			printf ("%20.15s", field[i].name);
		printf ("\n");
		/* Values */
		while ((row = mysql_fetch_row (result)) != 0){
			for (i = 0; i < numberOfColumns; i++)
				printf ("%20.15s", row[i]);
			printf ("\n");
		}
	}
	else printf("Nothing to print\n");
}

static void error_fatal (char *format, ...){
	va_list arguments;
	va_start (arguments, format);
	vfprintf (stderr, format, arguments);
	va_end (arguments);
	exit (EXIT_FAILURE);
}

static void print_instructions(){
	printf("'j'' to get all jobs\n");
	printf("'p' to get all job applications for a user\n");
	printf("'d' to delete an application\n");
	printf("'u' to insert a user\n");
	printf("'a' to insert a job application\n");
	printf("'o' to insert an ad\n");
	printf("'i' to print this\n");
	printf("'k' to get all users\n");
	printf("'q' to quit\n");
}

static MYSQL_RES* run_query(char* query, MYSQL* connection){
	if (mysql_query (connection, query) != 0)
		error_fatal ("Query error %s\n", mysql_error (connection));

	return mysql_use_result (connection);
}