#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void displayCurrentProgress(const std::string& word, const std::vector<char>& correctGuesses) {
    for (char letter : word) {
        if (std::find(correctGuesses.begin(), correctGuesses.end(), letter) != correctGuesses.end()) {
            std::cout << letter << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

bool isWordGuessed(const std::string& word, const std::vector<char>& correctGuesses) {
    for (char letter : word) {
        if (std::find(correctGuesses.begin(), correctGuesses.end(), letter) == correctGuesses.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string word = "programacao"; // A palavra a ser adivinhada
    std::vector<char> correctGuesses;
    std::vector<char> incorrectGuesses;
    int maxIncorrectGuesses = 6;

    std::cout << "Bem-vindo ao jogo da forca!" << std::endl;

    while (incorrectGuesses.size() < maxIncorrectGuesses && !isWordGuessed(word, correctGuesses)) {
        std::cout << "\nPalavra: ";
        displayCurrentProgress(word, correctGuesses);

        std::cout << "Chutes incorretos: ";
        for (char letter : incorrectGuesses) {
            std::cout << letter << " ";
        }
        std::cout << std::endl;

        std::cout << "Chute uma letra: ";
        char guess;
        std::cin >> guess;

        if (std::find(word.begin(), word.end(), guess) != word.end()) {
            if (std::find(correctGuesses.begin(), correctGuesses.end(), guess) == correctGuesses.end()) {
                correctGuesses.push_back(guess);
            } else {
                std::cout << "Você já acertou essa letra!" << std::endl;
            }
        } else {
            if (std::find(incorrectGuesses.begin(), incorrectGuesses.end(), guess) == incorrectGuesses.end()) {
                incorrectGuesses.push_back(guess);
            } else {
                std::cout << "Você já chutou essa letra incorretamente!" << std::endl;
            }
        }
    }

    if (isWordGuessed(word, correctGuesses)) {
        std::cout << "\nParabéns! Você adivinhou a palavra: " << word << std::endl;
    } else {
        std::cout << "\nVocê perdeu! A palavra era: " << word << std::endl;
    }

    return 0;
}