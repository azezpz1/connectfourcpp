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
public:
  Board(string state_str)
  {
    allowed_x_length = 6;
    allowed_y_length = 7;
    state_length = state_str.length();

    if (!is_valid_state_length(state_str) == true)
    {
      throw InvalidBoardState(allowed_x_length, allowed_y_length, state_length);
    }
  }

private:
  int allowed_x_length;
  int allowed_y_length;
  long state_length;

  bool is_valid_state_length(string state)
  {
    long state_length = state.length();
    if (state_length != allowed_x_length * allowed_y_length)
    {
      // Invalid board state
      return false;
    }

    return true;
  }
};
