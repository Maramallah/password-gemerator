#include <bits/stdc++.h>

using namespace std;
void println(char x, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << x;
    }
    cout << endl;
}
void WelcomeMessage()
{
    println('*', 100);
    std::cout << "                         Welcome to the Password Generator!" << endl;
    std::cout << "                Generate secure and random passwords with various options  " << endl;
    println('*', 100);
}

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
char RandomCletter() {

    char x = (char)RandomNumber(65, 90);
    return x;

}
char RandomSletter() {

    char x = (char)RandomNumber(97, 122);
    return x;

}
char randomchar()
{
    char x = (char)RandomNumber(33, 38);
    return x;
}
int asklength()
{
    int length;
    println('-', 20);
    do
    {
        cout << "Enter length of the password (should be at least 8) : ";
        cin >> length;
        if (length < 8)
        {
            cout << "Please enter a valid length (at least 8)." << endl;
        }
    } while (length < 8);

    return length;
}

void RandomPassword(int length, int case0, int case1)
{

    string password = " ";
    int x;
    for (int i = 0; i < length; i++)
    {
        if (case0 == case1)
        {
            x = 1;
        }
        else {
            x = RandomNumber(case0, case1);
        }

        switch (x) {
        case 1:
        {
            password += (char)RandomNumber(48, 57);
            break;
        }
        case 2:
        {
            password += randomchar();
            break;
        }
        case 3:
        {
            password += RandomCletter();
            break;
        }
        case 4:
        {
            password += RandomSletter();
            break;
        }

        }
    }
    println('-', 50);
    cout << "Your Password is : " << password << endl;
    println('-', 50);
}

void Ask()
{
    int length, choice = 0, exit = 0;
    WelcomeMessage();

    do
    {
        cout << "              1- Generate a password with a mix of numbers and characters" << endl;
        cout << "              2- Generate a password with only numbers" << endl;
        cout << "              3- Generate a password with only characters" << endl;
        cout << "              4- Generate a password with only letters" << endl;

        println('-', 100);
        cout << "Enter your choice : ";
        cin >> choice;
        while (choice < 1 || choice > 4)
        {
            cout << "Invalid choice. Please enter a valid option (1-4)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter your choice : ";
            cin >> choice;
        }

        length = asklength();




        switch (choice)
        {
        case 1:

            RandomPassword(length, 1, 4);
            break;

        case 2:

            RandomPassword(length, 1, 1);
            break;

        case 3:

            RandomPassword(length, 2, 4);
            break;

        case 4:

            RandomPassword(length, 3, 4);
            break;

        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }


        cout << "DO u want another password ? [1] YES [2] NO : ";
        cin >> exit;
        while (exit != 1 && exit != 2)
        {
            cout << "Please enter a valid choice (1 or 2): ";
            cin >> exit;
        }
        println('*', 100);
    } while (exit != 2);


    cout << "                          Thanks for using our program " << endl;
    println('*', 100);
}


int main()
{
    srand((unsigned)time(NULL));
    Ask();


    return 0;
}
