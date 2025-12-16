#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <cctype>
int main(){
    std::mt19937 generator(time(nullptr));
    bool LetrasMaiusculas = false;
    bool LetrasMinusculas = false;
    bool LetrasMistas = false;
    bool Numeros = false;
    bool Sinais = false;
    bool Verificar = true;
    char Menu;
    char Escolha;
    char Letras;
    int carac;
    do{ 
    Men:
    Menu = ' ';
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

    std::cout << "Tipos escolhidos:" << std::endl;
    if (LetrasMaiusculas)
    {
        std::cout << "Letras Maiusculas" << std::endl;
    }
    if (LetrasMinusculas)
    {
        std::cout << "Letras Minusculas" << std::endl;
    }
    if (LetrasMistas)
    {
        std::cout << "Letras Mistas" << std::endl;
    }
    if (Numeros)
    {
        std::cout << "Numeros" << std::endl;
    }
    if (Sinais)
    {
        std::cout << "Sinais" << std::endl;
    }
    do
    {
    Escolha = ' ';
    std::cout << "Deseja escolher outro ou retirar(S/N)?";
    std::cin >> Escolha;
    Escolha = toupper(Escolha);
    switch (Escolha)
    {
    case 'S':
        goto Men;
        break;
    case 'N':
        break;
    default:
        std::cout << "Letra invalida insira novamente!" << std::endl;
        break;
    }
    } while (Escolha != 'S' && Escolha != 'N');
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
    do
    {
    
    carac = ' ';
    Verificar = false;
    std::cout << "Quantos caracteres deseja que tenha a sua senha? ";
    std::cin >> carac;
    if (carac <= 8)
    {
        std::cout << "A senha deve ser maior!" << std::endl;
        Verificar = false;
    }
    if (carac >= 100)
    {
        std::cout << "A senha deve ser menor!" << std::endl;
        Verificar = false;
    }
    } while (!Verificar);
    
    while (senha.length() < carac) {
        std::shuffle(base.begin(), base.end(), generator);
        senha += base[0];
    }

    std::shuffle(senha.begin(), senha.end(), generator);

    std::cout << "Senha gerada: " << senha << std::endl;
    LetrasMaiusculas = false;
    LetrasMinusculas = false;
    LetrasMistas = false;
    Numeros = false;
    Sinais = false;
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
