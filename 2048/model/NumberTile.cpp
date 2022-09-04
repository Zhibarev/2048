#include "NumberTile.hh"

#include "GameBoard.hh"
#include <iomanip>
#include <iostream>

Coords operator+(Coords lhs, Coords rhs)
{
    return std::make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}

NumberTile::NumberTile(int value, Coords coords, GameBoard* board):
    value_(value), coords_(coords), board_(board), is_merged_(false), is_blocked_(false)
{
}

NumberTile::~NumberTile()
{
}

void NumberTile::print(int width)
{
    std::cout << "|" << std::setw(width - 1) << value_;
}

bool NumberTile::move(Coords direction, const int goal_val)
{
    Coords curr_loc = coords_;
    Coords new_loc = coords_ + direction;
    while( is_on_board( new_loc ) )
    {
        NumberTile* curr = board_->get_item(curr_loc);
        NumberTile* dest = board_->get_item(new_loc);
        if (curr->is_blocked_ || dest->is_blocked_)
            return false;
        if( dest->value_ == 0 )
        {
            dest->value_ = curr->value_;
            dest->is_merged_ = curr->is_merged_;
            curr->value_ = 0;
            curr->is_merged_ = false;
        }
        else if( dest->value_ == curr->value_ and
                 not dest->is_merged_ and
                 not curr->is_merged_ )
        {
            dest->value_ = 2 * curr->value_;
            curr->value_ = 0;
            dest->is_merged_ = true;
            return dest->value_ == goal_val;
        }
        curr_loc = new_loc;
        new_loc = dest->coords_ + direction;
    }
    return false;
}

bool NumberTile::new_value(int new_val, bool set_for_nonempty)
{
    if (is_blocked_)
        return false;
    if (!set_for_nonempty) {
        if( value_ == 0 )
        {
            value_ = new_val;
            return true;
        }
        return false;
    } else {
        value_ = new_val;
        return true;
    }
}

int NumberTile::get_value() const
{
    return value_;
}

bool NumberTile::is_empty()
{
    return value_ == 0;
}

void NumberTile::reset_turn()
{
    is_merged_ = false;
}

void NumberTile::set_block(bool is_blocked)
{
    is_blocked_ = is_blocked;
}

bool NumberTile::is_on_board(Coords coords)
{
    return coords.first >= 0 and coords.first < board_->get_size() and
           coords.second >= 0 and coords.second < board_->get_size();
}
