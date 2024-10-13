package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Функция для шифрования текста с помощью шифра Атбаш для русского алфавита
func atbashCipher(input string) string {
	var result strings.Builder
	for _, char := range input {
		// Проверка на заглавные буквы
		if char >= 'А' && char <= 'Я' {
			result.WriteRune('Я' - (char - 'А'))
		} else if char >= 'а' && char <= 'я' {
			result.WriteRune('я' - (char - 'а'))
		} else {
			result.WriteRune(char) // оставляем символ без изменений
		}
	}
	return result.String()
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Print("Введите текст для шифрования(от А до Я): ")
	input, _ := reader.ReadString('\n')

	// Убираем перенос строки
	input = strings.TrimSpace(input)

	encrypted := atbashCipher(input)

	fmt.Println("Зашифрованный текст:", encrypted)
}
