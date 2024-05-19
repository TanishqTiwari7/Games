#include <iostream>
#include <ctime>

char a;
char g;

int main()
{
    do
    {
        char userin();
        char comp();
        // userin();
        // comp();

        char input, com;
        input = userin();
        com = comp();

        if (input == com)
        {
            std::cout << "its a tie!\n";
        }

        else if ((input == 'r') && (com == 's'))
        {
            std::cout << "you win!\n";
        }
        else if ((input == 'p') && (com == 'r'))
        {
            std::cout << "you win!\n";
        }
        else if ((input == 's') && (com == 'p'))
        {
            std::cout << "you win!\n";
        }

        else if ((input == 'p') && (com == 's'))
        {
            std::cout << "you loose!\n";
        }
        else if ((input == 's') && (com == 'r'))
        {
            std::cout << "you loose!\n";
        }
        else if ((input == 'r') && (com == 'p'))
        {
            std::cout << "you loose!\n";
        }

        std::cout << "\n\nwant to play this game ? (Y/N)\n";
        std::cin >> a, g;

        std::cout << "\n\n\n\t*********************************************************************************\n\n\n";
    } while ((a == 'y') || (g == 'Y'));
}

char userin()
{
    char input;
    std::cout << "\t\t\t\tROCK PAPER SCISSORS\n";
    std::cout << "\t\t\t\t*******GAME********\n\n";
    do
    {
        std::cout << "choose any of the actions:\n";
        std::cout << "choose the letter\n";
        std::cout << "1. 'r' for rock\n";
        std::cout << "2. 'p' for paper\n";
        std::cout << "3. 's' for scissors\n";
        std::cin >> input;
        if ((input != 'r') && (input != 'p') && (input != 's'))
        {
            std::cout << "enter the correct letter!\n";
        }
    } while ((input != 'r') && (input != 'p') && (input != 's'));
    return input;
}

char comp()
{
    srand(time(NULL));

    char com;
    int compu;
    compu = (rand() % 3) + 1;

    if (compu == 1)
    {
        com = 'r';

        std::cout << "the computer choose ' r '\n";
    }

    if (compu == 2)
    {
        com = 'p';
        std::cout << "the computer choose ' p '\n";
    }

    if (compu == 3)
    {
        com = 's';
        std::cout << "the computer choose ' s '\n";
    }

    return com;
}