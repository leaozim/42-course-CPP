
# include <iostream>
# include <stdlib.h>
# include <cctype>

# define ERROR "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

void	its_time_to_scream(char *the_scream) {
	for (int i = 0; the_scream[i] != '\0'; i++)
		the_scream[i] = toupper(the_scream[i]);
	std::cout << the_scream;
}

void voice_amplifier(char **the_scream, int num_arg) {
	for (int i = 1; i < num_arg; i++)
	{
		its_time_to_scream(the_scream[i]);
		if (i != num_arg -1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	check_argc(int argc) {
	if (argc == 1) {
		std::cout << ERROR << std::endl;
 		exit (0);
	}
}

int	main(int argc, char **argv) {

	check_argc(argc);
	voice_amplifier(argv, argc);
	return (0);
}
