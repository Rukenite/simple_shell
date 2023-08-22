#include "main.h"

/**
 * _strtok - formats input into 'command options and arguments if any.
 *
 * @lineread: command inputed from shell
 * Return: ptr to formated command on success
 */
char **_strtok(char *lineread)
{
        char *cmd, **command, *copy;
        int i = 0, each_word = 0;

        copy = strdup(strtok(lineread, "\n"));
        cmd = strtok(lineread, " ");
        while (cmd)
        {
                each_word++;
                cmd = strtok(NULL, " ");
        }
        free(lineread);
        command = malloc((sizeof(char *) * each_word) + 1);
        i = 0;
        while(command[i])
        {
                command[i] = NULL;
                i++;
        }
        cmd = strtok(copy, " ");
        while (cmd)
        {
                command[i] = strdup(cmd);
                cmd = strtok(NULL, " ");
                i++;
        }
        free(copy);
        return (command);
}
