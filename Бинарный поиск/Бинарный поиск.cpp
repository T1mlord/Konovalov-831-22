#include <iostream>
#include <vector>
#include <cstdlib> // для std::rand() и std::srand()
#include <ctime>   // для std::time()
#include <limits>  // для std::numeric_limits
#include <algorithm> // для std::sort

using namespace std;

int main() {
    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(0)));

    int size;
    // Запрашиваем у пользователя размер массива
    while (true) {
        cout << "Введите размер массива: ";
        cin >> size;

        if (cin.fail() || size <= 0) {
            // Если ввод некорректен, очищаем поток и продолжаем запрашивать
            cin.clear(); // сбрасываем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очищаем буфер
            cout << "Ошибка: введите положительное целое число." << endl;
        } else {
            break; // Если ввод корректен, выходим из цикла
        }
    }

    // Создаем и заполняем массив случайными числами
    vector<int> lst(size);
    for (int i = 0; i < size; i++) {
        lst[i] = rand() % 101; // случайное число от 0 до 100
    }

    // Выводим сгенерированный массив
    cout << "Сгенерированный массив: ";
    for (int num : lst) {
        cout << num << " ";
    }
    cout << endl;

    // Сортируем массив для бинарного поиска
    sort(lst.begin(), lst.end());

    int value;
    cout << "Введите искомое число: ";
    cin >> value;

    // Реализация бинарного поиска
    bool found = false;
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int middle = (low + high) / 2;
        int guess = lst[middle];

        if (guess == value) {
            found = true;
            break;
        }
        if (guess > value) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }

    // Выводим результат поиска
    if (found) {
        cout << "Элемент найден!" << endl;
    } else {
        cout << "Элемент не найден." << endl;
    }

    return 0;
}
