def atbash_encode(text):
    # Создаем словари для шифрования
    alphabet = 'АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ'
    reverse_alphabet = alphabet[::-1]

    # Создаем строки для результата
    encrypted_text = ""

    # Пробегаемся по каждому символу введенного текста
    for char in text:
        if char.upper() in alphabet:
            # Находим соответствующий символ в обратном алфавите
            index = alphabet.index(char.upper())
            if char.isupper():
                encrypted_text += reverse_alphabet[index]
            else:
                encrypted_text += reverse_alphabet[index].lower()
        else:
            # Если символ не является буквой, добавляем его без изменений
            encrypted_text += char

    return encrypted_text

# Запрашиваем у пользователя текст для шифрования
user_input = input("Введите текст для шифрования: ")
encrypted_output = atbash_encode(user_input)
print("Зашифрованный текст:", encrypted_output)