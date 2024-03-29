#include "../inc/langton.h"

char	**damed_map2(char **str, char c, char r)
{
	int		i = -1;
	int		j;
	int		detector = 1;

	while (str[++i])
	{
		j = 0;
		while(str[i][j])
		{
			if (detector == 1)
				str[i][j] = c;
			else
				str[i][j] = r;
			detector *= -1;
			j++;
		}
		detector *= -1;
	}
	return (str);
}

int	damed_map(t_data *data)
{
	char	*temp;
	data->map = damed_map2(data->map, '1', '0');
	draw_map(data->map, data);
	data->gen = -1;
	data->gen++;
	temp = ft_itoa(data->gen);
	mlx_string_put(data->mlx, data->win, 6, 12, -200, temp);
	free(temp);
	temp = ft_itoa(data->rule);
	mlx_string_put(data->mlx, data->win, 6, 28, 2000, temp);
	free(temp);
	return (0);
}

char	**random_map2(char **str, t_data *data, char c, char r)
{
	int	count = ((data->map_height * data->map_width) / 2);
	int	i = 0;
	int	j = 0;

	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((rand() % 4) == 1)
			{
				if (str[i][j] == c)
					str[i][j] = r;
				else
					str[i][j] = c;
				count--;
			}
			j++;
		}
		i++;
	}
	i = 0;
	return (str);
}

int	random_map(t_data *data)
{
	char	*temp;
	reset(data);
	data->map = random_map2(data->map, data, '1', '0');
	draw_map(data->map, data);
	data->gen = -1;
	data->gen++;
	temp = ft_itoa(data->gen);
	mlx_string_put(data->mlx, data->win, 6, 12, -200, temp);
	free(temp);
	temp = ft_itoa(data->rule);
	mlx_string_put(data->mlx, data->win, 6, 28, 2000, temp);
	free(temp);
	return (0);
}
