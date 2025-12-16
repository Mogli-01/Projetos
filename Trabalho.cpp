#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <cctype>
    bool LetrasMaiusculas = false;
    bool LetrasMinusculas = false;
    bool LetrasMistas = false;
    bool Numeros = false;
    bool Sinais = false;
int main(){
    std::mt19937 generator(time(nullptr));
    char Menu;
    char Letras;
    int carac;
    do{ 
    std::cout << "-----Criador de Palavras Passes-----" << std::endl;
    std::cout << "A - Letras" << std::endl;
    std::cout << "B - Numeros" << std::endl;
    std::cout << "C - Sinais" << std::endl;
    std::cout << "D - Criar senha" << std::endl;
    std::cout << "Diga oque a sua senha terá:";
    std::cin >> Menu;
    Menu = toupper(Menu);
    switch (Menu)
    {
    case 'A':
        std::cout << "-----Letras-----" << std::endl;
        std::cout << "A - Maiusculas" << std::endl;
        std::cout << "B - Minusculas" << std::endl;
        std::cout << "C - Misto" << std::endl;
        std::cin >> Letras;
        Letras = toupper(Letras);
        switch (Letras)
        {
        case 'A':
            LetrasMaiusculas = true;
            LetrasMinusculas = false;
            LetrasMistas = false;
            break;
        case 'B':
            LetrasMaiusculas = false;
            LetrasMinusculas = true;
            LetrasMistas = false;
            break;
        case 'C':
            LetrasMaiusculas = false;
            LetrasMinusculas = false;
            LetrasMistas = true;
            break;
        default:
            break;
        }
        break;
    case 'B':
        Numeros = true;
        break;
    case 'C':
        Sinais = true;
        break;
    case 'D': 
    {
    std::string Maiusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string Minusculas = "abcdefghijklmnopqrstuvwxyz";
    std::string num  = "0123456789";
    std::string simbolos  = "!@#$%^&*()_+-=[]{}|;:',.<>?";

    std::string senha = "";
    std::string base  = "";

    std::shuffle(Maiusculas.begin(), Maiusculas.end(), generator);
    std::shuffle(Minusculas.begin(), Minusculas.end(), generator);
    std::shuffle(num.begin(), num.end(), generator);
    std::shuffle(simbolos.begin(), simbolos.end(), generator);




    if (LetrasMistas) {
    senha += Maiusculas[0];
    senha += Minusculas[0];
    base  += Maiusculas + Minusculas;
}

if (LetrasMaiusculas) {
    senha += Maiusculas[0];
    base  += Maiusculas;
}

if (LetrasMinusculas) {
    senha += Minusculas[0];
    base  += Minusculas;
}


    if (Numeros) {
        senha += num[0];
        base  += num;
    }

    if (Sinais) {
        senha += simbolos[0];
        base  += simbolos;
    }

    if (base.empty()) {
        std::cout << "Erro!" << std::endl;
        std::cout << "Nenhum tipo de caractere selecionado!" << std::endl;
        break;
    }

    std::cout << "Quantos caracteres deseja que tenha a sua senha? ";
    std::cin >> carac;
    while (senha.length() < carac) {
        std::shuffle(base.begin(), base.end(), generator);
        senha += base[0];
    }

    std::shuffle(senha.begin(), senha.end(), generator);

    std::cout << "Senha gerada: " << senha << std::endl;
}
    break;

        break;
    default:
        std::cout << "Letra incorreta!" << std::endl;
        std::cout << "Insira uma letra diferente" << std::endl;
        break;
    }
    } while (Menu != 'D');
}
