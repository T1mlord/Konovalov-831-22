def enigma_encrypt(text):
    #Таблицы роторов
    rotor1 = "ЕКМФЛГДКВЗНТОВЫХУСПАИБРЧЙ"
    rotor2 = "НТОВЫХУСПАИБРЧЙЕКМФЛГДКВЗ"
    rotor3 = "АИБРЧЙЕКМФЛГДКВЗНТОВЫХУСП"

    #Таблица рефлектора
    reflector = "ЙРУХКСЛДПХНГОКМИЭБФЗЦВВЖАТ"

    alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"

    encrypted_text = ""

    #Шифруем каждый символ в тексте
    for c in text:
        #Преобразуем символ в верхний регистр
        c = c.upper()

        #Проверяем, находится ли символ в русском алфавите
        if c in alphabet:
            #Находим позицию символа в алфавите
            pos = alphabet.index(c)

            #Шифруем символ с помощью ротора 1
            encrypted_char = rotor1[pos % len(rotor1)]

            #Шифруем символ с помощью ротора 2
            encrypted_char = rotor2[alphabet.index(encrypted_char)]

            #Шифруем символ с помощью ротора 3
            encrypted_char = rotor3[alphabet.index(encrypted_char)]

            #Шифруем символ с помощью рефлектора
            encrypted_char = reflector[alphabet.index(encrypted_char)]

            #Добавляем зашифрованный символ к результату
            encrypted_text += encrypted_char
        else:
            #Если символ не находится в русском алфавите, добавляем его к результату без изменений
            encrypted_text += c

    return encrypted_text

#Получаем текст от пользователя
text = input("Введите текст для шифрования: ")

#Шифруем текст с помощью шифра Энигма
encrypted_text = enigma_encrypt(text)

#Печатаем зашифрованный текст
print("Зашифрованный текст:", encrypted_text)
