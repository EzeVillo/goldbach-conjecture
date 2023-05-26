#include <array>
#include <iostream>

using namespace std;

#define smallestPrimeNumber 2

bool isPrimeNumber(int);
array<int, 2> goldbachConjecture(int);

int main()
{
    for (int i = 4; i < 1000; i = i + 2)
    {
        array<int, 2> solution;
        solution = goldbachConjecture(i);
        cout << i << " = " << solution[0] << " + " << solution[1] << endl;
    }
}

bool isPrimeNumber(int number)
{
    if (number < smallestPrimeNumber)
        return false;

    for (int i = smallestPrimeNumber; i < number; i++)
        if (number % i == 0)
            return false;

    return true;
}

array<int, 2> goldbachConjecture(int number)
{
    if (number < 4)
        throw range_error("number must not be less than 4.");

    if (number % 2 != 0)
        throw invalid_argument("number must not be odd.");

    for (int i = smallestPrimeNumber; i <= number - smallestPrimeNumber; i++)
        if (isPrimeNumber(i) && isPrimeNumber(number - i))
            return {i, number - i};

    throw bad_exception();
}