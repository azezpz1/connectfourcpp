#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "The board state must be specified." << endl;
        return 1;
    }

    string state = argv[1];
    cout << state << endl;

    return 0;
}