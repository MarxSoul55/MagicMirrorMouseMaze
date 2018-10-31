//#include <cmath>
//
//#include "bug.h"
//#include "actor.h"
//#include "maze.h"
//
//using namespace std;
//
//
//Bug::Bug(int row_, int column_) : Actor(row_, column_, 0, '*') {};
//
//
//bool Bug::move(int level, Direction d, bool is_non_player_mouse, char & old)
//{
//	int start_row = get_row();
//	int start_col = get_column();
//	Cheese* target_cheese = get_maze()->searchCheese(level, start_row, start_col);
//	int target_row = target_cheese->get_row();
//	int target_col = target_cheese->get_col();
//	int row_diff = target_row - start_row;
//	int col_diff = target_col - start_col;
//	if (abs(row_diff) > abs(col_diff)) {
//		if (row_diff < 0 && get_maze()->get_char(level, get_row() - 1, get_column()) == ' ') {
//			set_position(get_row() - 1, get_column());
//		}
//		else if (row_diff > 0 && get_maze()->get_char(level, get_row() + 1, get_column()) == ' ') {
//			set_position(get_row() + 1, get_column());
//		}
//	}
//	else if (abs(row_diff) < abs(col_diff)) {
//		if (col_diff < 0 && get_maze()->get_char(level, get_row(), get_column() - 1) == ' ') {
//			set_position(get_row(), get_column() - 1);
//		}
//		else if (col_diff > 0 && get_maze()->get_char(level, get_row(), get_column() + 1) == ' ') {
//			set_position(get_row(), get_column() + 1);
//		}
//	}
//	//if (row_diff == 0)
//	//{
//	//	if (col_diff < 0)
//	//	{
//	//		if (col_diff != -1)
//	//			set_column(column + 1);
//	//		else
//	//			eat_cheese(row, column + 1);
//	//	}
//	//	else if (col_diff > 0)
//	//	{
//	//		if (col_diff != 1)
//	//			set_column(column - 1);
//	//		else
//	//			eat_cheese(row, column - 1);
//	//	}
//
//
//	//}
//
//	//if (col_diff == 0)
//	//{
//	//	if (row_diff < 0)
//	//	{
//	//		if (row_diff != -1)
//	//			set_row(row + 1);
//	//		else
//	//			eat_cheese(row + 1, column);
//	//	}
//	//	else if (col_diff > 0)
//	//	{
//	//		if (row_diff != 1)
//	//			set_row(row - 1);
//	//		else
//	//			eat_cheese(row - 1, column);
//	//	}
//	//}
//
//	return true;
//}
//
//void Bug::eat_cheese(Cheese * cheese)
//{
//	//	get_maze()->searchCheese(0, row, col)->decrease_remaining(1);
//}