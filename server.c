#include <netinet/in.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080
#define MAX_EXEC_ARGS_COUNT 10
#define MAX_EXEC_ARGS_LENGTH 10
#define MAX_PASSWORDS_COUNT 128

#define MAX_ENTRY_LENGTH 150
#define MAX_PASSWORD_LENGTH 50

#define ENTRY_RESOURCE 0
#define ENTRY_NICKNAME 1
#define ENTRY_PASSWORD 2

typedef char** entry_t;

char** parse_command(char* command, char* delim)
{
    char** res = (char**)malloc(MAX_EXEC_ARGS_COUNT*sizeof(char*));
    for (int i = 0; i < MAX_EXEC_ARGS_COUNT; i++)
        res[i] = (char*)malloc(MAX_EXEC_ARGS_LENGTH*sizeof(char));
    char* tmp = strdup(command);
    char* tok = strtok(tmp, delim);
    res[0] = tok;
    for (int i = 1; tok != NULL; i++)
    {
        tok = strtok(NULL, delim);
        res[i] = tok;
    }    
    return res;
}

char* get_password_entry(char* resource, char* nickname)
{
	unsigned char passwords_count = 1;
	FILE* fd = fopen("passwords.txt", "r");
	entry_t* registration_entries = 
		(entry_t*)malloc(sizeof(entry_t)*passwords_count);
	char* registration_entry_str = 
		(char*)malloc(sizeof(char)*MAX_ENTRY_LENGTH);
	char* password = NULL;
	while(fgets(registration_entry_str, MAX_ENTRY_LENGTH, fd) != NULL)
	{
		registration_entries[passwords_count - 1] = 
			parse_command(registration_entry_str, " ");
		registration_entries = 
			realloc(registration_entries, sizeof(entry_t)*(++passwords_count));
	}

	for (unsigned char i = 0; i < passwords_count - 1; i++)
	{
		if (strcmp(registration_entries[i][ENTRY_RESOURCE], resource) == 0 &&
			strcmp(registration_entries[i][ENTRY_NICKNAME], nickname) == 0)
			{
				password = registration_entries[i][ENTRY_PASSWORD];
				password[strlen(password ) - 1] = '\0';
			}
	}
	free(registration_entry_str);
	free(registration_entries);
	return password;
}

int main(int argc, char const* argv[])
{



	printf("Password: %s\n", get_password_entry("google.com", "psareff"));
	printf("Password: %s\n", get_password_entry("google.com", "mstr_i"));
	printf("Password: %s\n", get_password_entry("google.com", "ilyapsareff"));
}

