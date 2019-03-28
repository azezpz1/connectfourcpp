#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "The board state must be specified." << std::endl;
    }

    string state = argv[1];
    cout << state << std::endl;

    return 0;
}