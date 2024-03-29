#include "../inc/langton.h"

int	ft_stop(t_data *data)
{
	destroy_all_images(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_all(data);
	exit(1);
	return (0);
}

int	auto_algorithm(t_data *data)
{
	if (data->state == 1)
	{
		algorithm(data);
		wait_time(10);
	}
	return (0);
}

void	ft_display(t_data *data)
{
	char	*temp;
	data->x = 0;
	data->y = 0;
	data->bloc_posx = 0;
	data->bloc_posy = 0;
	data->gen = 0;
	data->state = 0;
	data->mlx = mlx_init();						// initialize the pointer mlx
	data->win = mlx_new_window(data->mlx, (data->map_width * 8), (data->map_height * 8), "Langton-s Ant"); //create a new window
	init_images(data);							// initialize all images
	draw_map(data->map, data);					// draw the map
	temp = ft_itoa(data->rule);
	mlx_string_put(data->mlx, data->win, 6, 28, 2000, temp);					// write the actual rule
	free(temp);
	temp = ft_itoa(data->gen);
	mlx_string_put(data->mlx, data->win, 6, 12, -200, temp);					// write the actual gen
	free(temp);
	mlx_hook(data->win, 3, (1L << 0) + (1L << 1), ft_key_check, data);			// hook for the keyboard entries
	mlx_hook(data->win, ButtonPress, (1L << 2), mouse_hook, data);
	mlx_loop_hook(data->mlx, &auto_algorithm, data);			// hook for the mouse location
	mlx_hook(data->win, 17, 0L, ft_stop, data);
	mlx_loop(data->mlx);														// loop
}

int	main(void)
{
	t_data	*data;								// initialize the structure "data"
	int		fd;									// initialize the file descriptor "fd"
	
	data = malloc(sizeof(t_data));				// malloc the data
	fd = open("map/map.txt", O_RDONLY);			// open the fd with "0_RDONLY" flag
	data->map = init_map(fd, data);				// put all the map (fd) inside a "char **"
	ft_display(data);							// start the display of the game
	return (0);
}
