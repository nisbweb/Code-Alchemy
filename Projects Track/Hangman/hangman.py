import random
import os

def load_words(filename):
    if os.path.exists(filename):
        with open(filename, 'r') as file:
            words = [line.strip().lower() for line in file.readlines()]
        return words
    else:
        print(f"{filename} not found!")
        return []

def choose_word(category):
    if category == 'animals':
        words = load_words('animals.txt')
    elif category == 'movies':
        words = load_words('movies.txt')
    else:
        print("Invalid category. Please choose 'animals' or 'movies'.")
        return None

    if words:
        return random.choice(words)
    return None

# Function to display the current state of the word
def display_word(word, guessed_letters):
    display = [letter if letter in guessed_letters else '_' for letter in word]
    return ' '.join(display)

# Driver Function to run the Hangman game
def hangman():
    print("Welcome to Hangman!")
    category = input("Choose a category (animals/movies): ").lower()

    word = choose_word(category)
    if not word:
        print("No words found for this category.")
        return

    guessed_letters = set()
    incorrect_guesses = 0
    max_incorrect_guesses = 6  # Number of allowed incorrect guesses

    print("\nLet's start the game!")

    while incorrect_guesses < max_incorrect_guesses:
        print(f"\nWord: {display_word(word, guessed_letters)}")
        print(f"Guessed letters: {' '.join(guessed_letters)}")
        print(f"Incorrect guesses left: {max_incorrect_guesses - incorrect_guesses}")

        guess = input("Guess a letter: ").lower()

        if len(guess) != 1 or not guess.isalpha():
            print("Please enter a valid single letter.")
            continue

        if guess in guessed_letters:
            print("You've already guessed this letter.")
            continue

        guessed_letters.add(guess)

        if guess in word:
            print("Good guess!")
            if all(letter in guessed_letters for letter in word):
                print(f"\nCongratulations! You've guessed the word: {word}")
                break
        else:
            incorrect_guesses += 1
            print("Incorrect guess!")

    if incorrect_guesses == max_incorrect_guesses:
        print(f"\nGame over! The word was: {word}")


if __name__ == "__main__":
    hangman()
