#include <iostream>
#include <unordered_map>

void exibirMenuPrincipal() {
    std::cout << "\nMENU PRINCIPAL\n";
    std::cout << "-------------------------\n";
    std::cout << "/registro\n";
    std::cout << "/login\n";
    std::cout << "/bem-vindo\n";
    std::cout << "/sair\n";
    std::cout << "-------------------------\n";
    std::cout << "Escolha uma opcao: ";
}

int main() {
    std::unordered_map<std::string, std::string> user;
    std::string loggedUser;  
    while (true) {
        exibirMenuPrincipal();
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "/registro") {
            std::string username, password;
            std::cout << "\nDigite o nome do seu usuario: ";
            std::cin >> username;
            std::cout << "\nDigite sua senha: ";
            std::cin >> password;

            if (user.find(username) != user.end()) {
                std::cout << "\nUsuário já registrado. Por favor, escolha outro nome de usuario.\n";
            } else {
                user[username] = password;
                std::cout << "\nRegistro bem-sucedido para o usuario: " << username << "\n";
            }
        } else if (cmd == "/login") {
            std::string username, password;
            std::cout << "\nDigite o nome de usuario: ";
            std::cin >> username;
            std::cout << "\nDigite a senha: ";
            std::cin >> password;

            auto it = user.find(username);
            if (it != user.end() && it->second == password) {
                std::cout << "\nLogin bem-sucedido. Bem-vindo, " << username << "!\n";
                loggedUser = username; 
            } else {
                std::cout << "\nLogin falhou. Verifique seu nome de usuario e senha.\n";
            }
        } else if (cmd == "/bem-vindo") {
            if (!loggedUser.empty()) {
                std::cout << "\nSeja bem-vindo " << loggedUser << "!\n";
            } else {
                std::cout << "\nNenhum usuario logado. Faça o login primeiro.\n";
            }
        } else if (cmd == "/sair") {
            std::cout << "\nAtividade Encerrada.\n";
            break;
        } else {
            std::cout << "\nComando invalido, tente novamente.\n";
        }
    }

    return 0;
}
