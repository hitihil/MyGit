#include <iostream>﻿
#include <cstdlib>
#include <ctime>

using namespace std;

int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

void displayHealth(int health)
{
    cout << "Здоровье: ";
    for (int i = 0; i < health; ++i) {
        cout << "#";
    }
    cout << " (" << health << ")" << endl;
}

int main()
{

    setlocale(LC_ALL, "Russian");

    srand(time(0));

    int playerHealth = 10;
    int computerHealth = 10;

    cout << "Сегодня 18 мая 6432 года, ровно 12 месяц назад на Земле случился апокалипсис в следствие взрыва на атомной станции.\nВсе живое обратилось в неживое. Выжили лишь те, кто успел попасть в бункер. По данным переписи число людей на земле\n составило порядка 6 - ти тысяч.\nСкитаясь по миру ты нашел информацию о том, что на севере есть поселение, которому удается выживать, их численность\n составляет 289 человек.\nСпустя 7 месяцев ты добрался до их лагеря. Местные жители отнеслилсь скептически к твоему визиту, им были не нужны новые жильцы.\nЧтобы доказать свою верность и готовность сотрудничать, а также показать свои навыки, силу и уровень подготовки тебе\n необходимо сразиться с лучшим бойцом лагеря - Маркусом, в переводе - Богом войны.\nДа здравствуют бойцы! Добро пожаловать на ринг, пусть победит сильнейший!" << endl << endl;

    while (playerHealth > 0 && computerHealth > 0)
    {
        cout << "Ваш ход: выберите действие (1 - удар левой рукой, 2 - удар правой рукой, 3 - удар ногой, 4 - блок): ";
        int playerMove;
        cin >> playerMove;

        int computerMove = random(1, 4);

        int hitResult1 = random(2, 12);
        int hitResult2 = random(2, 12);

        switch (playerMove) {
        case 1:
            cout << "Вы нанесли удар левой рукой!" << endl;
            if (hitResult1 < 5)
                cout << "Удар не достиг цели." << endl;
            else if (hitResult1 < 12 && computerMove != 4)
                computerHealth -= 1;
            else if (hitResult1 == 12)
            {
                cout << "Критическое попадание!" << endl;
                cout << "Критический удар пробивает блок!" << endl;
                computerHealth -= 2;
            }
            break;
        case 2:
            cout << "Вы нанесли удар правой рукой!" << endl;
            if (hitResult1 < 5)
                cout << "Удар не достиг цели." << endl;
            else if (hitResult1 < 12 && computerMove != 4)
                computerHealth -= 2;
            else if (hitResult1 == 12)
            {
                cout << "Критическое попадание!" << endl;
                cout << "Критический удар пробивает блок!" << endl;
                computerHealth -= 3;
            }
            break;
        case 3:
            cout << "Вы нанесли удар ногой!" << endl;
            if (hitResult1 < 5)
                cout << "Удар не достиг цели." << endl;
            else if (hitResult1 < 12 && computerMove != 4)
                computerHealth -= 3;
            else if (hitResult1 == 12)
            {
                cout << "Критическое попадание!" << endl;
                cout << "Критический удар пробивает блок!" << endl;
                computerHealth -= 4;
            }
            break;
        case 4:
            cout << "Вы поставили блок!" << endl;
            break;
        case 5:
            cout << "Активирован cheat - code!" << endl;
            cout << "В земле тебе удалось найти колбу с остатками целебного снадобья, теперь твое здоровье пополнится на 5 единиц!" << endl;
            playerHealth = playerHealth + 5;
            break;
        case 6:
            cout << "Активирован cheat - code!" << endl;
            cout << "Ты вспомнил неприметного мальчишку, который подошел к тебе перед боем и рассказал про слабое место Маркуса." << endl;
            cout << "Воспользовавшись этим ты лишил Маркуса 5 единиц здоровья!" << endl;
            computerHealth = computerHealth - 5;
            break;
        case 7:
            cout << "Активирован cheat - code!" << endl;
            cout << "В твоей голове появились сомнения о том, что ты хочешь примкнуть к лагерю людей. Твое решение - сдаться." << endl;
            playerHealth = 0;
            break;
        case 8:
            cout << "Активирован cheat - code!" << endl;
            cout << "Какой - то неведомой силой ты заставил Маркуса бояться тебя. Твой соперник понял, что ты ему не по плечу. Маркус сдался!" << endl;
            computerHealth = 0;
            break;
        default:
            cout << "Не делай глупостей! Соберись и сражайся!" << endl;
        }

        if (playerMove != 5 && playerMove != 6 && playerMove != 7 && playerMove != 8 && computerHealth > 0)
        {
            switch (computerMove) {
            case 1:
                cout << "Маркус нанес удар левой рукой!" << endl;
                if (hitResult2 < 5)
                    cout << "Удар не достиг цели." << endl;
                else if (hitResult2 < 12 && playerMove != 4)
                    playerHealth -= 1;
                else if (hitResult2 == 12)
                {
                    cout << "Критическое попадание!" << endl;
                    cout << "Критический удар пробивает блок!" << endl;
                    playerHealth -= 2;
                }
                break;
            case 2:
                cout << "Маркус нанес удар правой рукой!" << endl;
                if (hitResult2 < 5)
                    cout << "Удар не достиг цели." << endl;
                else if (hitResult2 < 12 && playerMove != 4)
                    playerHealth -= 2;
                else if (hitResult2 == 12)
                {
                    cout << "Критическое попадание!" << endl;
                    cout << "Критический удар пробивает блок!" << endl;
                    playerHealth -= 3;
                }
                break;
            case 3:
                cout << "Маркус нанес удар ногой!" << endl;
                if (hitResult2 < 5)
                    cout << "Удар не достиг цели." << endl;
                else if (hitResult2 < 12 && playerMove != 4)
                    playerHealth -= 3;
                else if (hitResult2 == 12)
                {
                    cout << "Критическое попадание!" << endl;
                    cout << "Критический удар пробивает блок!" << endl;
                    playerHealth -= 4;
                }
                break;
            case 4:
                cout << "Маркус поставил блок!" << endl;
                break;
            }
        }

        if (computerHealth <= 0)
        {
            cout << "Поздравляем! Ты победил!" << endl;
            break;
        }
        else if (playerHealth <= 0)
        {
            cout << "Ты проиграл! Маркус победил!" << endl;
            break;
        }

        cout << "Остаток здоровья:" << endl;
        cout << "Вы: ";
        displayHealth(playerHealth);
        cout << "Маркус: ";
        displayHealth(computerHealth);
        cout << endl;
    }

    return 0;
}
