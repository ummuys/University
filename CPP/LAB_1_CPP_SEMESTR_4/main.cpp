#include "knapsack_problem.hpp"
#include "LCS.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string RESET = "\033[0m"; 


//Knapsack_problem_exented data
//vector<Item> Items{ Item{"water",3,10}, Item{"book",1,3}, Item{"food",2,9}}; // 5 weight
//vector<Item> Items{ Item{"water",3,10}, Item{"book",1,3}, Item{"food",2,9}}; // 6 weight
//vector<Item> Items{ Item{ "water",3,10 }, Item{ "book",1,3 }, Item{ "food",2,9 }, Item{ "jacket",2,100 }, Item{ "camera",1,6 } };* // weight 5;
//vector<Item> Items{ Item{ "water",3,10 }, Item{ "book",1,3 }, Item{ "food",2,9 }, Item{ "jacket",2,100 }, Item{ "camera",1,6 } };* // weight 6;
//vector<Item> Items{ Item{ "water",3,10 }, Item{ "book",1,3 }, Item{ "food",2,9 }, Item{ "jacket",2,5 }, Item{ "camera",1,6 } };* // weight 6;


void testcase_knapsack_problem();
void testcase_knapsack_problem_user_data();
void testcase_LCS_problem();
void testcase_LCS_problem_user_data();
void testcase_LCS_exented_problem();
void plotNtimesM(int maxN, int maxM, int width, int height);
void plotNtimesMtimesH(int maxM, int maxN, int maxH, int width, int height);

int main() {
	//testcase_knapsack_problem();
    //testcase_LCS_problem();
    //testcase_LCS_exented_problem();
    //vector<Item> Items{ Item{"water",3,10}, Item{"book",1,3}, Item{"food",2,9}};
    //vector<Item> Items{ Item{ "water",3,10 }, Item{ "book",1,3 }, Item{ "food",2,9 }, Item{ "jacket",2,100 }, Item{ "camera",1,6 } };*
    /*cout << knapsack_problem_extended(Items, 5).name;*/
    return 0;
}
void testcase_LCS_exented_problem() {
    system("cls");
    cout << "LCS_extended problem -> O(n * m * h), n - lenght first word, m - lenght second word, h - lenght third word" << endl << endl;
    cout << "----|First testcase|----\n";
    string exmp1_word1 = "FISH";
    string exmp1_word2 = "FOSH";
    string exmp1_word3 = "FASH";
    cout << "Input data: " << endl << endl;
    cout << "First word -> " << exmp1_word1 << endl;
    cout << "Second word -> " << exmp1_word2 << endl;
    cout << "Third word -> " << exmp1_word3 << endl << endl;
    cout << "Correct answer: 3\n";
    cout << "Current answer: " << LCS_extended(exmp1_word1, exmp1_word2, exmp1_word3) << endl;

    cout << endl;

    cout << "----|Second testcase|----\n";
    string exmp2_word1 = "83217";
    string exmp2_word2 = "8213807";
    string exmp2_word3 = "683147";
    cout << "Input data: " << endl << endl;
    cout << "First word -> " << exmp2_word1 << endl;
    cout << "Second word -> " << exmp2_word2 << endl;
    cout << "Third word ->" << exmp2_word3 << endl << endl;
    cout << "Correct answer: 3\n";
    cout << "Current answer: " << LCS_extended(exmp2_word1, exmp2_word2, exmp2_word3) << endl;

    plotNtimesMtimesH(4,4,4,20,15);
}
void testcase_LCS_problem() {
    system("cls");
    cout << "LCS problem -> O(n * m), n - lenght first word, m - lenght second word" << endl << endl;
    cout << "----|First testcase|----\n";
    string exmp1_word1 = "Fish";
    string exmp1_word2 = "Fosh";
    cout << "Input data: " << endl << endl;
    cout << "First word -> " << exmp1_word1 << endl;
    cout << "Second word -> " << exmp1_word2 << endl << endl;
    cout << "Correct answer: 3\n";
    cout << "Current answer: " << LCS(exmp1_word1, exmp1_word2) << endl;

    cout << endl;

    cout << "----|Second testcase|----\n";
    string exmp2_word1 = "83217";
    string exmp2_word2 = "82138107";
    cout << "Input data: " << endl << endl;
    cout << "First word -> " << exmp2_word1 << endl;
    cout << "Second word -> " << exmp2_word2 << endl << endl;
    cout << "Correct answer: 4\n";
    cout << "Current answer: " << LCS(exmp2_word1, exmp2_word2) << endl;
    cout << endl;

    plotNtimesM(6, 6, 20, 15);

  /*  cout << endl;
    cout << "Do you wanna write your data?\n1)Yes\n2)No\n\n>>";
    int answer;
    cin >> answer;
    if (answer == 1) testcase_LCS_problem_user_data();
    else if (answer == 2) return;
    else {
        system("cls");
        cout << "You write a incorrect answer\n";
        return;
    }*/

}
void testcase_LCS_problem_user_data() {
    system("cls");
    cout << "=====LCS problem=====" << endl << endl;
    cout << "----|Write your data|----\n";
    cout << "First word -> ";
    string word1;
    cin >> word1;
    cout << "Second word -> ";
    string word2;
    cin >> word2;
    system("cls");
    cout << "LCS problem -> O(n * m), n - lenght first word, m - lenght second word" << endl << endl;
    cout << "----|Your testcase|----\n";
    cout << "Input data: " << endl << endl;
    cout << "First word -> " << word1 << endl;
    cout << "Second word -> " << word2 << endl << endl;
    cout << "Current answer: " << LCS(word1, word2) << endl;
    cout << endl;
    plotNtimesM(6, 6, 20, 15);

    cout << endl;
    cout << "Do you wanna write your data again?\n1)Yes\n2)No\n\n>>";
    int answer;
    cin >> answer;
    if (answer == 1) testcase_LCS_problem_user_data();
    else if (answer == 2) return;
    else {
        system("cls");
        cout << "You write a incorrect answer\n";
        return;
    }
}
void testcase_knapsack_problem() {
    system("cls");
	cout << "Knapsack problem -> O(n * M), n - amount of items, M - max weight" << endl << endl;
	cout << "----|First testcase|----\n";
    vector<Item> Items1{ Item{"water",3,10}, Item{"book",1,3}, Item{"food",2,9}, Item{"jacket",2,5}, Item{"camera",1,6} };
    unsigned int max_weight1 = 6;
    cout << "Input data: " << endl << endl;
    for (int i = 0; i < Items1.size(); i++) { 
        cout << "Name item -> " << Items1[i].name << endl;
        cout << "Weight item -> " << Items1[i].weight << endl;
        cout << "Cost item -> " << Items1[i].cost << endl;
        cout << endl;
    }
	cout << "Correct answer: camera, food, water\n";
	cout << "Current answer: " << knapsack_problem(Items1, max_weight1).name << endl;

	cout << endl;

	cout << "----|Second testcase|----\n";
	vector<Item> Items2{ Item{"gitara",1,1500},Item{"laptop",3,2000},Item{"tape recorder",4,3000} };
	unsigned int max_weight2 = 4;
    cout << "Input data: " << endl << endl;
    for (int i = 0; i < Items2.size(); i++) {
        cout << "Name item -> " << Items2[i].name << endl;
        cout << "Weight item -> " << Items2[i].weight << endl;
        cout << "Cost item -> " << Items2[i].cost << endl;
        cout << endl;
    }
    cout << "Correct answer: gitara, laptop \n";
	cout << "Current answer: " << knapsack_problem(Items2, max_weight2).name << endl;
	
	cout << endl;

    plotNtimesM(6, 6, 20, 15);
}
void testcase_knapsack_problem_user_data() {
    system("cls");
    cout << "=====Knapsack problem=====" << endl << endl;
    cout << "----|Write your data|----\n";
    int c_items;
    cout << "How many items we have? -> ";
    cin >> c_items;
    if (c_items < 0) {
        system("cls");
        cout << "You write a incorrect answer\n";
        return;
    }
    vector<Item> Items;
    for (int i = 0; i < c_items; i++) {
        string name_item;
        cout << "Write name for item -> ";
        cin >> name_item;

    }
    
    cout << endl;
    cout << "Do you wanna write your data again?\n1)Yes\n2)No\n\n>>";
    int answer;
    cin >> answer;
    if (answer == 1) testcase_LCS_problem_user_data();
    else if (answer == 2) return;
    else {
        system("cls");
        cout << "You write a incorrect answer\n";
        return;
    }
}
void plotNtimesM(int maxN, int maxM, int width, int height) {
    int maxValue = maxN * maxM;
    vector<vector<string>> plot(height, vector<string>(width, " "));

    // Заполняем матрицу plot
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            double n = (double)x / (width - 1) * maxN;
            double m = (double)y / (height - 1) * maxM;
            double value = n * m;
            double normalizedValue = value / maxValue;

            string color = RESET;
            char symbol = ' ';

            if (normalizedValue > 0.8) {
                color = RED;
                symbol = '#';
            }
            else if (normalizedValue > 0.6) {
                color = YELLOW;
                symbol = '*';
            }
            else if (normalizedValue > 0.4) {
                color = GREEN;
                symbol = '+';
            }
            else if (normalizedValue > 0.2) {
                color = CYAN;
                symbol = '.';
            }

            plot[height - 1 - y][x] = color + symbol + RESET;
        }
    }

    // Рисуем ПОВЕРНУТЫЙ график С ОСЯМИ

    // Рисуем график (повернутый) вместе с осью Y (вертикальной)
    for (int x = width - 1; x >= 0; --x) {
        // Метка оси Y (только для maxM и 0) - очень простой вариант
        if (x == width - 1) {
            cout << setw(4) << maxM << " "; // Верхняя метка
        }
        else if (x == 0) {
            cout << setw(4) << "0" << " ";   // Нижняя метка
        }
        else {
            cout << setw(4) << " " << " ";   // Пробелы для остальной части оси
        }

        // Рисуем столбец графика
        for (int y = 0; y < height; ++y) {
            cout << plot[y][x];
        }
        cout << endl;
    }

    // Рисуем ось X (горизонтальную)
    cout << setw(6) << " "; // Отступ для оси Y
    for (int i = 0; i < width; ++i) {
        cout << "--";
    }
    cout << endl;
    cout << setw(6) << "0 "; // Метка начала оси X
    cout << setw(width * 2 - 1) << maxN << endl; // Метка конца оси X (выравнивание!)

}
void plotNtimesMtimesH(int maxM, int maxN, int maxH, int width, int height) {
    int maxValue = maxM * maxN * maxH;

    vector<vector<string>> plot(height, vector<string>(width, " "));

    // Заполняем "график"
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            double m = (double)x / (width - 1) * maxM;
            double n = (double)y / (height - 1) * maxN;
            double h = (double)maxH / 2.0; // Фиксированное значение H (среднее)

            double value = m * n * h;
            double normalizedValue = value / maxValue;

            string color = RESET;
            char symbol = ' ';

            if (normalizedValue > 0.8) {
                color = RED;
                symbol = '#';
            }
            else if (normalizedValue > 0.6) {
                color = YELLOW;
                symbol = '*';
            }
            else if (normalizedValue > 0.4) {
                color = GREEN;
                symbol = '+';
            }
            else if (normalizedValue > 0.2) {
                color = CYAN;
                symbol = '.';
            }

            plot[height - 1 - y][x] = color + symbol + RESET;
        }
    }

    // Выводим график, выровненный по правому краю

    //  Находим ширину консоли (это сложно сделать кроссплатформенно,
    //  поэтому просто задаем ее константой)
    const int consoleWidth = 80;  // Предполагаемая ширина консоли

    //  Вычисляем левый отступ, чтобы выровнять график по правому краю
    int leftPadding = consoleWidth - width;


    // Выводим график
    for (int y = height - 1; y >= 0; --y) {
        // Выводим левый отступ
        cout << setw(leftPadding) << ""; // Заполняем пробелами

        for (int x = 0; x < width; ++x) {
            cout << plot[y][x];
        }
        cout << endl;
    }
}
