#include <iostream>
#include <string>

// Функция шифрования текста с помощью шифра Энигма
std::string enigmaEncrypt(const std::string& text) {
    // Таблицы замены для роторов
    const char rotor1[] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
    const char rotor2[] = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
    const char rotor3[] = "BDFHJLCPRTXVZNYEIWGAKMUSQO";

    // Таблица замены для рефлектора
    const char reflector[] = "YRUHQSLDPXNGOKMIEBFZCWVJAT";

    std::string encryptedText;

    // Шифруем каждый символ текста
    for (char c : text) {
        // Преобразуем символ в верхний регистр
        c = toupper(c);

        // Проверяем, является ли символ буквой
        if (c >= 'A' && c <= 'Z') {
            // Находим позицию символа в алфавите
            int pos = c - 'A';

            // Шифруем символ с помощью ротора 1
            char encryptedChar = rotor1[pos];

            // Шифруем символ с помощью ротора 2
            encryptedChar = rotor2[encryptedChar - 'A'];

            // Шифруем символ с помощью ротора 3
            encryptedChar = rotor3[encryptedChar - 'A'];

            // Шифруем символ с помощью рефлектора
            encryptedChar = reflector[encryptedChar - 'A'];

            // Добавляем зашифрованный символ к результату
            encryptedText += encryptedChar;
        } else {
            // Если символ не является буквой, добавляем его к результату без изменений
            encryptedText += c;
        }
    }

    return encryptedText;
}

int main() {
    // Вводим текст с клавиатуры
    std::string text;
    std::cout << "Введите текст для шифрования: ";
    std::getline(std::cin, text);

    // Шифруем текст с помощью шифра Энигма
    std::string encryptedText = enigmaEncrypt(text);

    // Выводим зашифрованный текст
    std::cout << "Зашифрованный текст: " << encryptedText << std::endl;

    return 0;
}
