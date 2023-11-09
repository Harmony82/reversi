#include "grid.h"

grid::grid()
{
	_grid_data = grid_data::NONE;
}
void grid::put_black()
{
	_grid_data = grid_data::BLACK;
}
void grid::put_white()
{
	_grid_data = grid_data::WHITE;
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