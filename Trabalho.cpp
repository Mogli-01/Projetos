#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <random>
#include <ctime>
#include <cctype>
int MenuPrincipal();
std::string CriarSenha();
void guardarSenha(const std::string& servico, const std::string& user, const std::string& senha);
void adicionarSenhaManual();
void verSenhas();
std::string encriptar(const std::string& texto);
std::string desencriptar(const std::string& texto) ;
int main (){
    //Menu Principal
    int MenuP;
    do
    {
    MenuP = MenuPrincipal();
    //Variavel para guardar a senha criada e limpa
    std::string Senha = "";
    switch (MenuP)
    {
    case 1:
        Senha = CriarSenha();
        break;
    case 2:
        adicionarSenhaManual();
        break;
    case 3:
        verSenhas();
        break;
    case 4:
        return 0;
        break;
    default:
        break;
    }
} while (MenuP != 4);
}
std::string encriptar(const std::string& texto) {
    std::string resultado = texto;
    char chave = 'K';

    for (char &c : resultado) {
        c ^= chave;
    }
    return resultado;
}
std::string desencriptar(const std::string& texto) {
    std::string resultado = texto;
    char chave = 'K';

    for (char &c : resultado) {
        c ^= chave;
    }
    return resultado;
}
//Função para guardar a senha num ficheiro de texto
void guardarSenha(const std::string& servico, const std::string& user, const std::string& senha) {
    std::ofstream ficheiro("senhas.txt", std::ios::app);
    if(ficheiro.is_open()) {
        ficheiro << encriptar(servico) << encriptar(" | ") << encriptar(user) << encriptar(" | ") << encriptar(senha) << std::endl;
        ficheiro.close();
        std::cout << "Senha guardada com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao abrir o ficheiro!" << std::endl;
    }
}
//Função para ver as senhas guardadas
void verSenhas(){
std::ifstream ficheiro("senhas.txt");
    if (!ficheiro.is_open()) {
        std::cout << "Nenhuma senha guardada.\n";
        return;
    }

    std::string linha;
    std::cout << "\nSenhas guardadas:\n";

    while (std::getline(ficheiro, linha)) {
        std::string limpa = desencriptar(linha);
        std::cout << limpa << std::endl;
    }

    ficheiro.close();
}
//Função para adicionar senha manualmente
void adicionarSenhaManual(){
    std::string servico, user, senha;

    std::cout << "Serviço: ";
    std::cin >> servico;

    std::cout << "Utilizador/Email: ";
    std::cin >> user;

    std::cout << "Senha: ";
    std::cin >> senha;

    guardarSenha(servico, user, senha);
}
//Função do Menu Principal
int MenuPrincipal(){
    int Opcao;
    std::cout << "Oque deseja fazer?" << std::endl;
    std::cout << "1 - Criar nova senha" << std::endl;
    std::cout << "2 - Adicionar senha manualmente" << std::endl;
    std::cout << "3 - Ver senhas guardadas" << std::endl;
    std::cout << "4 - Sair" << std::endl;
    std::cin >> Opcao;
    return Opcao;
}
//Função para criar a senha
std::string CriarSenha(){
    std::mt19937 generator(time(nullptr));
    bool LetrasMaiusculas = false;
    bool LetrasMinusculas = false;
    bool LetrasMistas = false;
    bool Numeros = false;
    bool Sinais = false;
    bool Verificar = false;
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
    Escolha = ' ';
    while (Escolha != 'S' && Escolha != 'N')
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
    }
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
    while (!Verificar)
    {
    carac = 0;
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
    }else{
        Verificar = true;
    }
    } 
    
    while (senha.length() < carac) {
        std::shuffle(base.begin(), base.end(), generator);
        senha += base[0];
    }

    std::shuffle(senha.begin(), senha.end(), generator);

    std::cout << "Senha gerada: " << senha << std::endl;
    char guardar;
    std::cout << "Deseja guardar a senha? (S/N): ";
    std::cin >> guardar;
    if(toupper(guardar) == 'S') {
    std::string servico, user;
    std::cout << "Serviço: "; 
    std::cin >> servico;
    std::cout << "Usuário/Email: "; 
    std::cin >> user;
    guardarSenha(servico, user, senha);
}

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