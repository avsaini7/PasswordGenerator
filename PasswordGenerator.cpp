#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class PasswordGenerator {
public:
    PasswordGenerator(int length) : length(length) {
        std::srand(std::time(0));
    }

    std::string generatePassword() {
        const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";

        std::string password;
        for (int i = 0; i < length; ++i) {
            int randomIndex = std::rand() % characters.length();
            password += characters[randomIndex];
        }

        return password;
    }

private:
    int length;
};

int main() {
    int passwordLength;

    std::cout << "Enter the length of the password: ";
    std::cin >> passwordLength;

    if (passwordLength <= 0) {
        std::cout << "Invalid password length. Please enter a positive number.\n";
        return 1;
    }

    PasswordGenerator passwordGenerator(passwordLength);
    std::string generatedPassword = passwordGenerator.generatePassword();

    std::cout << "Generated Password: " << generatedPassword << std::endl;

    return 0;
}
