#include "monty.h"
utils_t utils = {NULL, NULL, 0};

int	main(int ac, char **av)
{
	stack_t *stack = NULL;
	int line_content = 0;
	int read = 1;
	char    *buffer = NULL;

	if (ac = 2)
	{
		utils.fd = fopen(av[1], 'r');
		if (!utils.fd)
		{
			fprintf(stderr, "Error: Can't open file %s\n", av[1]);
			exit(1);
		}
		while (read > 1)
		{
			read = getline(&buffer, NULL, utils.fd);
			utils.content = buffer;
			line_content++;
			if (read > 0)
			{
				exec(buffer, &stack, line_content, utils.fd);
			}
			free(buffer);
		}
		close(utils.fd);
		free_struct(stack);
	}
	else
	{
		write(2, "USAGE: monty file\n", 19);
		exit(1);
	}
	return (0);
}



// If the file contains an invalid instruction : "L<line_number>: unknown instruction <opcode>\n" (exit 1)
//     - where is the line number where the instruction appears.
//     - Line numbers always start at 1
// The monty program runs the bytecodes line by line and stop if either:
//     - it executed properly every line of the file
//     - it finds an error in the file
//     - an error occured
// If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.