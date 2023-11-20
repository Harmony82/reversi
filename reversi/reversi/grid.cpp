#include "grid.h"

grid::grid()
{
	_grid_data = grid_data::NONE;
}
void grid::grid_put(grid_data color)
{
	_grid_data = color;
}
void grid::turnover()
{
	if (_grid_data == grid_data::BLACK)
	{
		_grid_data = grid_data::WHITE;
	}
	if (_grid_data == grid_data::WHITE)
	{
		_grid_data = grid_data::BLACK;
	}
}