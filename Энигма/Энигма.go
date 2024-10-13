package main

import (
	"fmt"
	"strings"
)

type Rotor struct {
	wiring   string
	position int
	notch    int // Позиция зацепления
}

func (r *Rotor) Rotate() {
	r.position = (r.position + 1) % 26
}

func (r *Rotor) Encode(input byte) byte {
	index := (int(input-'A') + r.position) % 26
	output := r.wiring[index]
	return (output-'A'-byte(r.position)+26)%26 + 'A'
}

func NewRotor(wiring string, notch int) *Rotor {
	return &Rotor{wiring: wiring, position: 0, notch: notch}
}

type Enigma struct {
	rotors []*Rotor
}

func NewEnigma(rotors []*Rotor) *Enigma {
	return &Enigma{rotors: rotors}
}

func (e *Enigma) EncodeMessage(message string) string {
	var encodedMessage string

	for _, char := range message {
		if char < 'A' || char > 'Z' {
			continue // проигнорируем не буквы
		}

		c := byte(char)
		for _, rotor := range e.rotors {
			c = rotor.Encode(c)
		}
		encodedMessage += string(c)

		// Поворот роторов после шифрования буквы
		e.rotors[0].Rotate()
		if e.rotors[0].position == e.rotors[0].notch {
			if len(e.rotors) > 1 {
				e.rotors[1].Rotate()
				if e.rotors[1].position == e.rotors[1].notch {
					if len(e.rotors) > 2 {
						e.rotors[2].Rotate()
					}
				}
			}
		}
	}

	return encodedMessage
}

func main() {
	// Настройка роторов
	rotor1 := NewRotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 16) // Первый ротор
	rotor2 := NewRotor("AJDKSIRUXBLHWTMCQGZNPYFVOE", 4)  // Второй ротор
	rotor3 := NewRotor("BDFHJLCPRTXVZNYEIWGAKMUSQO", 21) // Третий ротор

	enigma := NewEnigma([]*Rotor{rotor1, rotor2, rotor3})

	var input string
	fmt.Println("Введите слово для шифрования (только заглавные буквы A-Z):")
	fmt.Scan(&input)

	// Преобразуем ввод в верхний регистр и удаляем пробелы
	input = strings.ToUpper(strings.TrimSpace(input))

	// Зашифровка введенного слова
	encoded := enigma.EncodeMessage(input)
	fmt.Printf("Зашифрованное сообщение: %s\n", encoded)
}
