#include <iostream>

int	main(int argc, char **argv)
{
	char	ch;
	int		i, j;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				ch = argv[i][j];
				if (islower(ch) == 1 && isalpha(ch) == 1)
				{
					ch = toupper(ch);
					std::cout << ch;
				}
				else
					std::cout << ch;
				j++;
			}
			if (argv[i + 1])
				std::cout << " ";
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
