package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	// Инициализация генератора случайных чисел
	rand.Seed(time.Now().UnixNano())

	// Запрос размера массива
	var size int
	for {
		fmt.Print("Введите размер массива (положительное целое число): ")
		_, err := fmt.Scan(&size)
		if err != nil || size <= 0 {
			fmt.Println("Некорректный ввод. Пожалуйста, введите положительное целое число.")
			continue
		}
		break // Выход из цикла, если ввод корректный
	}

	// Создание и заполнение массива
	array := make([]int, size)
	for i := 0; i < size; i++ {
		array[i] = rand.Intn(101) // Случайные числа от 0 до 100
	}

	// Вывод сгенерированного массива
	fmt.Println("Сгенерированный массив:", array)

	// Сортировка массива (алгоритм сортировки пузырьком)
	for i := 0; i < len(array)-1; i++ {
		for j := 0; j < len(array)-i-1; j++ {
			if array[j] > array[j+1] {
				array[j], array[j+1] = array[j+1], array[j] // Обмен значений
			}
		}
	}

	// Запрос искомого числа
	var target int
	fmt.Print("Введите число, которое нужно найти в массиве: ")
	_, err := fmt.Scan(&target)
	if err != nil {
		fmt.Println("Некорректный ввод.")
		return
	}

	// Реализация бинарного поиска
	found := false
	left, right := 0, len(array)-1
	for left <= right {
		mid := left + (right-left)/2
		if array[mid] == target {
			found = true
			break
		} else if array[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	// Вывод результата
	if found {
		fmt.Println("Элемент найден!")
	} else {
		fmt.Println("Элемент не найден.")
	}
}
