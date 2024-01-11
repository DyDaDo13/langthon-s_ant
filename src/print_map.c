#include "../inc/langton.h"

void	print_map(char **map)
{
	int		i = -1;
	while(map[++i])
		printf("%s\n", map[i]);
}