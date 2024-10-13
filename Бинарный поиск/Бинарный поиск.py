import random

def binary_search(lst, search_item):
    low = 0
    high = len(lst) - 1
    search_res = False

    while low <= high and not search_res:
        middle = (low + high) // 2
        guess = lst[middle]
        if guess == search_item:
            search_res = True
        if guess > search_item:
            high = middle - 1
        else:
            low = middle + 1
    return search_res

# Запрашиваем у пользователя размер массива
while True:
    try:
        size = int(input("Введите размер массива: "))
        if size <= 0:
            print("Размер массива должен быть положительным числом. Пожалуйста, попробуйте еще раз.")
            continue
        break
    except ValueError:
        print("Ошибка: введите целое число.")

# Создаем и заполняем массив случайными числами
lst = [random.randint(0, 100) for _ in range(size)]

# Выводим сгенерированный массив
print("Сгенерированный массив:", lst)

# Сортируем массив
lst.sort()

# Запрашиваем у пользователя число для поиска
value = int(input("Введите искомое число: "))
result = binary_search(lst, value)
if result:
    print("Элемент найден!")
else:
    print("Элемент не найден.")
