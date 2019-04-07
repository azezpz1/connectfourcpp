#include <iostream>
#include <string>
using namespace std;

main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "The board state must be specified." << endl;
        return 1;
    }

    string state = argv[1];
    int state_length = state.length();
    cout << "Board state length is: " << state_length << endl;
    cout << "Board state is: " << state << endl;

    return 0;
}