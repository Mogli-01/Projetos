#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <random>
#include <ctime>
#include <cctype>
int MenuPrincipal();
void CriarSenha();
void guardarSenha(const std::string& servico, const std::string& user, const std::string& senha);
void adicionarSenhaManual();
void verSenhas();
std::string encriptar(const std::string& texto);
std::string desencriptar(const std::string& texto) ;
bool AdicionarTirarCaracteres()
int main (){
    //Verificar se existe password mestre
    if (!existePasswordMestre()) {
        std::cout << "Nenhuma password mestre encontrada.\n";
        criarPasswordMestre();
    }
    //Verificar password mestre
    if (!verificarPasswordMestre()) {
        return 0;
    }
    //Menu Principal
    int MenuP;
    do
    {
    MenuP = MenuPrincipal();
    switch (MenuP)
    {
    case 1:
        CriarSenha();
        break;
    case 2:
        adicionarSenhaManual();
        break;
    case 3:
        verSenhas();
        break;
    case 4:
        std::cout << "A sair..." << std::endl;
        return 0;
        break;
    default:
        break;
    }
} while (MenuP != 4);
}
//Função para adicionar ou retirar caracteres
bool AdicionarTirarCaracteres(){
    std::cout << "Deseja adicionar ou retirar o caractere? (A/T): ";
    char opcao;
    std::cin >> opcao;
    opcao = toupper(opcao);
    if(opcao == 'A') {
        return true;
    } else {
        return false;
    }
}
//Função para criar a password mestre
void criarPasswordMestre() {
    std::string pass1, pass2;
    do
    {
    std::cout << "Criar password mestre: ";
    std::cin >> pass1;
    std::cout << "Confirmar password mestre: ";
    std::cin >> pass2;
    // Verifica se as passwords coincidem
    if (pass1 != pass2) {
        std::cout << "As passwords nao coincidem!" << std::endl;
        std::cout << "Tente novamente." <<std::endl;
    }
    } while (pass1 != pass2);
    // Guarda a password mestre encriptada num ficheiro
    std::ofstream ficheiro("master.txt");
    ficheiro << encriptar(pass1);
    ficheiro.close();
    std::cout << "Password mestre criada com sucesso!" << std::endl;
}
//Função para verificar se existe a password mestre
bool existePasswordMestre() {
    std::ifstream ficheiro("master.txt");
    // Verifica se o ficheiro foi aberto com sucesso
    return ficheiro.good();
}
//Função para verificar a password mestre
bool verificarPasswordMestre() {
    // Lê a password mestre encriptada do ficheiro
    int tentativas = 1;
    std::ifstream ficheiro("master.txt");
    std::string guardadaEncriptada;
    std::string inserida;
    std::getline(ficheiro, guardadaEncriptada);
    ficheiro.close();
    // Desencripta a password guardada
    std::string guardada = desencriptar(guardadaEncriptada);
    do
    {
    std::cout << "Password mestre: ";
    std::cin >> inserida;
    // Compara a password inserida com a guardada
    if (inserida == guardada) {
        return true;
    } else {
        std::cout << "Password incorreta!" << std::endl;
        std::cout << "Tentativa " << tentativas << " de 3." << std::endl;
        if (tentativas == 2)
        {
            std::cout << "Ultima tentativa!" << std::endl;
            std::cout << "Se errar a ultima vez os dados serao perdidos!" << std::endl;
        }
        if (tentativas == 3)
        {
            std::cout << "Numero maximo de tentativas atingido!" << std::endl;
            std::cout << "A apagar todos os dados..." << std::endl;
            master.txt.clear();
            senhas.txt.clear();
            std::cout << "Dados apagados com sucesso!" << std::endl;
            return false;
        }
        tentativas++;
    }
    } while (inserida != guardada || tentativas < 3);
}
//Função para encriptar e desencriptar texto
std::string encriptar(const std::string& texto) {
    std::string resultado = texto;
    char chave = 'R';
    // Encriptação simples usando XOR
    for (char &c : resultado) {
        c ^= chave;
    }
    return resultado;
}
std::string desencriptar(const std::string& texto) {
    std::string resultado = texto;
    char chave = 'R';
    // A desencriptação é o mesmo processo da encriptação usando XOR
    for (char &c : resultado) {
        c ^= chave;
    }
    return resultado;
}
//Função para guardar a senha num ficheiro de texto
void guardarSenha(const std::string& servico, const std::string& user, const std::string& senha) {
    // Abre o ficheiro em modo de anexação ou seja, adiciona ao final do ficheiro
    std::ofstream ficheiro("senhas.txt", std::ios::app);
    if(ficheiro.is_open()) {
        // Escreve a senha encriptada no ficheiro
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
        std::cout << "Nenhuma senha guardada." << std::endl;
        return;
    }
    // Ler e desencriptar cada linha do ficheiro
    std::string linha;
    std::cout << std::endl << "Senhas guardadas:" << std::endl;
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
void CriarSenha(){
    //Gerador de numeros aleatorios
    std::mt19937 generator(time(nullptr));
    bool LetrasMaiusculas = false;
    bool LetrasMinusculas = false;
    bool LetrasMistas = false;
    bool Numeros = false;
    bool Sinais = false;
    bool Verificarn = false;
    char Menu;
    char Escolha;
    char Letras;
    bool Verificar = false;
    int carac;
    //Menu de seleção dos tipos de caracteres
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
    //Switch para selecionar os tipos de caracteres
    switch (Menu)
    {
    case 'A':
        //Submenu para selecionar o tipo de letras
        std::cout << "-----Letras-----" << std::endl;
        std::cout << "A - Maiusculas" << std::endl;
        std::cout << "B - Minusculas" << std::endl;
        std::cout << "C - Misto" << std::endl;
        std::cin >> Letras;
        Letras = toupper(Letras);
        //Switch para selecionar o tipo de letras
        switch (Letras)
        {
        case 'A':
            Verificar = AdicionarTirarCaracteres();
            if(Verificar) {
                LetrasMaiusculas = true;
                LetrasMinusculas = false;
                LetrasMistas = false;
            } else {
                LetrasMaiusculas = false;
                LetrasMinusculas = false;
                LetrasMistas = false;
            }
            break;
        case 'B':
            Verificar = AdicionarTirarCaracteres();
            if(Verificar) {
                LetrasMaiusculas = false;
                LetrasMinusculas = true;
                LetrasMistas = false;
            } else {
                LetrasMaiusculas = false;
                LetrasMinusculas = false;
                LetrasMistas = false;
            }
            break;
        case 'C':
            Verificar = AdicionarTirarCaracteres();
            if(Verificar) {
                LetrasMaiusculas = false;
                LetrasMinusculas = false;
                LetrasMistas = true;
            } else {
                LetrasMaiusculas = false;
                LetrasMinusculas = false;
                LetrasMistas = false;
            }
            break;
        default:
            break;
        }
        break;
    case 'B':
        Verificar = AdicionarTirarCaracteres();
        if(Verificar) {
            Numeros = true;
        } else {
            Numeros = false;
        }
        break;
    case 'C':
        Verificar = AdicionarTirarCaracteres();
        if(Verificar) {
            Sinais = true;
        } else {
            Sinais = false;
        }
        break;
    case 'D': 
    {
    std::string Maiusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string Minusculas = "abcdefghijklmnopqrstuvwxyz";
    std::string num  = "0123456789";
    std::string simbolos  = "!@#$%^&*()_+-=[]{}|;:',.<>?";
    //Mostrar os tipos escolhidos
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
    //Perguntar se quer alterar os tipos escolhidos
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
    //Variaveis para criar a senha
    std::string senha = "";
    std::string base  = "";
    //Embaralhar os caracteres
    std::shuffle(Maiusculas.begin(), Maiusculas.end(), generator);
    std::shuffle(Minusculas.begin(), Minusculas.end(), generator);
    std::shuffle(num.begin(), num.end(), generator);
    std::shuffle(simbolos.begin(), simbolos.end(), generator);
    //Adicionar pelo menos um caractere de cada tipo selecionado
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
    //Verificar se algum tipo de caractere foi selecionado
    if (base.empty()) {
        std::cout << "Erro!" << std::endl;
        std::cout << "Nenhum tipo de caractere selecionado!" << std::endl;
        break;
    }
    //Perguntar o tamanho da senha
    while (!Verificar)
    {
    carac = 0;
    Verificar = false;
    std::cout << "Quantos caracteres deseja que tenha a sua senha? ";
    std::cin >> carac;
    //Verificar o tamanho da senha
    if (carac <= 8)
    {
        std::cout << "A senha deve ser maior!" << std::endl;
        Verificarn = false;
    }
    if (carac >= 100)
    {
        std::cout << "A senha deve ser menor!" << std::endl;
        Verificarn = false;
    }else{
        Verificarn = true;
    }
    } 
    do
    {
    senha.clear();
    //Completar a senha até o tamanho desejado
    while (senha.length() < carac) {
        std::shuffle(base.begin(), base.end(), generator);
        senha += base[0];
    }
    //Embaralhar a senha final
    std::shuffle(senha.begin(), senha.end(), generator);
    //Mostrar a senha gerada
    std::cout << "Senha gerada: " << senha << std::endl;
    char guardar;
    std::cout << "Deseja guardar a senha? (S/N): ";
    std::cin >> guardar;
    guardar = toupper(guardar);
    if(guardar == 'S') {
    std::string servico, user;
    std::cout << "Serviço: "; 
    std::cin >> servico;
    std::cout << "Usuário/Email: "; 
    std::cin >> user;
    guardarSenha(servico, user, senha);
}else{
    do
    {
    
    guardar = ' ';
    std::cout << "Senha não guardada." << std::endl;
    std::cout << "Gerar nova senha?" << std::endl;
    std::cin >> guardar;
    guardar = toupper(guardar);
    switch (guardar)
    {
    case 'S':
        break;
    case 'N':
        return;
        break;
    default:
        std::cout << "Letra incorreta!" << std::endl;
        std::cout << "Insira uma letra diferente" << std::endl;
        break;
    }
    } while (guardar != 'N');
    guardar = ' ';
}
} while (guardar != 'N');
    //Resetar as variaveis para nova criação de senha
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