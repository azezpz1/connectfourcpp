#include <exception>
#include <iostream>
#include <string>
using namespace std;

class InvalidBoardState : public exception
{
  public:
    InvalidBoardState(int expected_x_length, int expected_y_length, long state_length)
    {
        expected_x_length = expected_x_length;
        expected_y_length = expected_y_length;
        state_length = state_length;
    };

  private:
    int expected_x_length;
    int expected_y_length;
    long state_length;

    virtual const char *what() const throw()
    {
        string expected_length = to_string(expected_x_length * expected_y_length);
        string valid_length = to_string(state_length);
        string return_str = "An Invalid Board State. Given board state was ";
        return_str += expected_length;
        return_str += " long. But the allowed board state is ";
        return_str += valid_length;
        return return_str.c_str();
    }
};

class Board
{
  private:
    int x_length = 6;
    int y_length = 7;

    Board(string state_str)
    {
    }

    bool is_valid_state_length(string state)
    {
        long state_length = state.length();
        if (state_length != x_length * y_length)
        {
            // Invalid board state
            throw InvalidBoardState(x_length, y_length, state_length);
        }
    }
};
