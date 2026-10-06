#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the command and its arguments
typedef struct
{
    char *args[64];  // Arguments / words entered by the user
    int count;        // Number of words
} Command;

// Function to parse the input line
void parse_command(char *line, Command *cmd)
{
    cmd->count = 0;

    char *token = strtok(line, " \t");

    while (token != NULL && cmd->count < 63)
    {
        cmd->args[cmd->count] = token;
        cmd->count++;

        token = strtok(NULL, " \t");
    }

    // The argument list must end with NULL
    cmd->args[cmd->count] = NULL;
}

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    Command cmd;

    while (1)
    {
        printf("shellforge$ ");
        fflush(stdout);

        // Read input
        if (getline(&line, &len, stdin) == -1)
        {
            break;
        }

        // Remove trailing newline
        if (strlen(line) > 0 && line[strlen(line) - 1] == '\n')
        {
            line[strlen(line) - 1] = '\0';
        }

        // Parse the command
        parse_command(line, &cmd);

        // Skip empty input
        if (cmd.count == 0)
        {
            continue;
        }

        // Exit command
        if (strcmp(cmd.args[0], "exit") == 0)
        {
            break;
        }

        printf("Structure Log -> command : %s | Arguments found: %d\n",
               cmd.args[0], cmd.count - 1);
    }

    // Free allocated memory
    free(line);

    return 0;
}
