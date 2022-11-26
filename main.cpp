#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

int health = 10, hunger = 10, weak = 0, bal = 150;

int portal()
{

    int result = (bal * 420 + weak - hunger * 2) * 2;
    return result;
}

int randomNumber(int min, int max)
{
    srand(time(NULL));
    int num = min + rand() % (max - min + 1);
    return num;
}

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    string name = "Money Mod game", ver = "beta 0.1.0";

    int selectMain, select;

    cout << "| Welcome to the " + name + " [" + ver + "]" << endl;
    cout << "| 1. Начать новую игру" << endl << "| 2. Настройки графики" << endl << "| 3. Выйти" << endl;
    cin >> selectMain;
    if (selectMain == 1)
    {
        while (true)
        {
            if (health <= 0)
            {
                cout << "| ты умер от балезни....." << endl;
                Sleep(3000);
                exit(0);
            } else if (hunger <= 0)
            {
                cout << "| ты умер от голада...." << endl;
                Sleep(3000);
                exit(0);
            } else if (weak >= 10)
            {
                cout << "| ты умер от таго что не смог держать груз на работе...." << endl;
                Sleep(3000);
                exit(0);
            }

            if (health > 10)
                health = 10;
            if (hunger > 10)
                hunger = 10;
            if (weak < 0)
                weak = 0;

            system("cls");
            cout << "| Ваша статистика:\n| "
            << health << " Здоровья | "
            << hunger << " Сытости | "
            << weak << " Усталости | "
            << "Баланс " << bal << "$\n| ---------------------------" << endl;
            cout << "| Выберите один из вариантов: " << endl;
            cout << "| 1. Пойти в магазин\n| 2. Пойти на работа\n| 3. Пойти на сон\n| 4. Выйти в окно\n| 5. Пойти в аптека\n| 6. Открыть портал в мир заработка (6666$)" << endl;
            cin >> select;
            switch (select)
            {
                case 1:
                    system("cls");
                    if (bal > 0)
                    {
                        system("cls");
                        int randomHunger = randomNumber(2, 4);
                        int randomWeak = randomNumber(2, 4);
                        int trata = randomNumber(75, 350);

                        if (trata > bal)
                        {
                            trata = bal;
                        }

                        bal -= trata;
                        hunger += randomHunger;
                        weak += randomWeak;

                        cout << "| Вы пошли в магаз и потратили " << trata << "$\n| Ваш баланс теперь: " << bal << "$" << endl;
                        Sleep(4000);
                    } else
                    {
                        system("cls");
                        cout << "| У тебя нет денег ИДИОТ" << endl;
                        Sleep(4000);
                    }
                    break;
                case 2: {
                    system("cls");
                    int randTime = randomNumber(4, 13);
                    int randomMoney = randomNumber(150, 650);
                    int randomHunger = randomNumber(2, 4);
                    int randomWeak = randomNumber(3, 5);
                    int randomHealth = randomNumber(2, 3);

                    cout << "| Вы работаете..." << endl;

                    Sleep(randTime * 1000);
                    bal += randomMoney;
                    hunger -= randomHunger;
                    weak += randomWeak;
                    health -= randomHealth;

                    cout << "| Вы поработали " << randTime << " часов и заработали " << randomMoney << "$\n| Ваш баланс: " << bal << "$" << endl;

                    Sleep(4000);
                    break;
                }
                case 3:
                {
                    system("cls");
                    int randomTime = randomNumber(5, 9);
                    int randomWeak = randomNumber(3, 10);
                    int randomHunger = randomNumber(2, 3);

                    hunger -= randomHunger;
                    weak -= randomWeak;

                    cout << "| Вы спите... ZZZzzzzzzzz..." << endl;
                    Sleep(randomTime * 1000);
                    cout << "| Вы поспали " << randomTime << " часов! Теперь ваша усталость уменьшилась на - " << randomWeak << endl;

                    Sleep(4000);
                    break;
                }
                case 4:
                    system("cls");
                    cout << "| гейм овер...." << endl;
                    Sleep(4000);
                    exit(0);
                    break;
                case 5:
                {
                    system("cls");

                    int randomHealth = randomNumber(2, 9);
                    int randomWeak = randomNumber(2, 3);
                    int trata = randomNumber(50, 250);

                    if (trata > bal)
                    {
                        trata = bal;
                    }
                    bal -= trata;

                    health += randomHealth;
                    weak += randomWeak;

                    cout << "| Вы идете в аптеку" << endl;
                    Sleep(2000);
                    cout << "| Вы купили лекарства, потратив " << trata << "$ и вылечили себя\n| Ваш баланс теперь: " << bal << "$" << endl;
                    Sleep(4000);
                    break;
                }
                case 6:
                    system("cls");
                    if (bal > 6666) {
                            if (portal() <= 0) {
                                cout << "| Ваш баланс ушел в минус. ГЕЙМ ОВЕР" << endl;
                                Sleep(4000);
                                break;
                            } else {
                                cout << "| " << portal() << "$ заработано в портале.\n| Игра пройдена!!!" << endl;
                                cout << "| Оригинальная игра сделана: \n| Cattyn\n| winmeta.h\n| https://github.com/cattyngmd/MoneyGame" << endl;
                                cout << "| Портировано на C++: winmeta.h" << endl;
                                Sleep(10000);
                                exit(0);
                            }

                    } else
                    {
                        cout << "| Недостаточно денег чтобы войти в портал мира денег." << endl;
                        Sleep(4000);
                        break;
                    }

            }
        }
    } else if(selectMain == 2)
    {
        system("cls");
        cout << "| No!!!" << endl;
        Sleep(3000);
    }
    return 0;
}
