#include <iostream>
#include <string>

std::string atbash_encrypt(const std::string& text) {
    std::string encrypted_text = "";
    for (char c : text) {
        if (c >= 'a' && c <= 'z') {
            // Шифрование букв английского алфавита с помощью шифра Атбаш
            encrypted_text += 'z' - (c - 'a');
        } else if (c >= 'A' && c <= 'Z') {
            // Шифрование букв английского алфавита с помощью шифра Атбаш
            encrypted_text += 'Z' - (c - 'A');
        } else {
            // Оставляем символы, отличные от букв, без изменений
            encrypted_text += c;
        }
    }
    return encrypted_text;
}

int main() {
    std::string input_text;
    std::cout << "Enter text to encrypt: ";
    std::getline(std::cin, input_text);

    std::string encrypted_text = atbash_encrypt(input_text);
    std::cout << "Encrypted text: " << encrypted_text << std::endl;

    return 0;
}