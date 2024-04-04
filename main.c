#include "monty.h"
utils_t utils = {NULL, NULL, 0, NULL};

/**
* main - monty code interpreter
* @ac: number of arguments
* @av: monty file location
* Return: 0 on success
*/
int	main(int ac, char **av)
{
	stack_t *stack = NULL;
	int line_content = 0;
	int read = 1;
	size_t	size = 0;
	FILE	*file;
	char    *buffer = NULL;

	if (ac == 2)
	{
		file = fopen(av[1], "r");
		utils.fd = file;
		if (!file)
		{
			fprintf(stderr, "Error: Can't open file %s\n", av[1]);
			exit(1);
		}
		while (read > 0)
		{
			read = getline(&buffer, &size, utils.fd);
			utils.content = buffer;
			line_content++;
			if (read > 0)
			{
				exec(buffer, &stack, line_content, file);
			}
		}
		free_struct(stack);
		fclose(file);
	}
	else
	{
		write(2, "USAGE: monty file\n", 18);
		exit(1);
	}
	return (0);
}

