#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int number1, number2, number_of_goals, sum = 0;
    cout << "Vvedite chislo golov:\n> ";
    cin >> number_of_goals;
    for (int i = 0; i < number_of_goals; i++)
    {
        cout << "Vvedite resultat " << i + 1 << "-ogo gola:\nKomanda 1:\n> ";
        cin >> number1;
        cout << "Komanda 2:\n> ";
        cin >> number2;
        sum = sum + number1 + number2;
    }
    cout << "Resultat: " << sum << endl;
    system("pause");
    return 0;
}