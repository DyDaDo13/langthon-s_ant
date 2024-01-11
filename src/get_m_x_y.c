#include "../inc/langton.h"

void	get_m_x_y(t_data *data, int x, int y)
{
	int		i = 0;
	while (data->mouse_posx < x)
	{
		data->mouse_posx += 8;
		i++;
	}
	data->mouse_posx = i - 1;
	i = 0;
	while (data->mouse_posy < y)
	{
		data->mouse_posy += 8;
		i++;
	}
	data->mouse_posy = i - 1;
	i = 0;
	data->image__posx = (data->mouse_posx * 8);
	data->image__posy = (data->mouse_posy * 8);
}