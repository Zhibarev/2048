#ifndef GAMEBOARD_HH
#define GAMEBOARD_HH

#include "NumberTile.hh"
#include <vector>
#include <random>

// THE MODEL CODE IS DIFFERENT FROM THE REST OF THE PROJECT, LEFT AS IS FOR BACKWARD COMPATIBILITY.
const int SIZE = 4;
const int PRINT_WIDTH = 5;
const int NEW_VALUE = 2;
const int DEFAULT_GOAL = 2048;

class GameBoard
{
public:
    // Constructor
    GameBoard(int size = SIZE);

    // Destructor
    ~GameBoard();

    // Initializes the gameboard with nullptrs.
    void init_empty();

    // Initializes the random number generator and fills the gameboard
    // with random numbers.
    void fill(int seed);

    // Moves the number tiles in the gameboard, if possible (by calling
    // move method for each number tile).
    // Finally, resets turn of all number tiles.
    bool move(Coords dir, int goal);

    // Returns the element (number tile) in the given coordinates.
    NumberTile* get_item(Coords coords);

    // Activate removal mode
    void activate_removal_mode(unsigned steps_to_remove);

    // Deactivate removal mode
    void deactivate_removal_mode();

    // Block / unblock the number tile
    void set_tile_block(Coords coords, bool is_blocked);

    // Return the size of the gameboard
    int get_size() const;

    // Return the score of the game
    int get_score() const;

    // Draws a new location (coordinates) from the random number generator and
    // puts the NEW_VALUE on that location, unless check_if_empty is true and
    // the gameboard is full.
    void new_value(bool check_if_empty = true);

    // Returns true, if all the tiles in the game board are occupied,
    // otherwise returns false.
    bool is_full() const;

    // Prints the game board.
    void print() const;


private:
    // Internal structure of the game board
    std::vector<std::vector<NumberTile*>> board_;

    // Random number generator and distribution.
    std::default_random_engine randomEng_;
    std::uniform_int_distribution<int> distribution_;

    // Size of the gameboard
    int size_ = 0;

    // Game score, sum of all numbers
    int score_ = 0;

    // Variables related to the removal of a random tile.
    unsigned steps_to_remove_ = 0;
    unsigned steps_to_remove_counter_ = 0;
    bool is_removal_mode_ = false;
};

#endif // GAMEBOARD_HH
