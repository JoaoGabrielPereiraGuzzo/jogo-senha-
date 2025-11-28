#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
int count;
int tentativas = 1;
int numeroJogador;

void jogoDaSenha(){
   //criar funcao randomizador de senha
    int digito1 = (rand() % 6) + 1;
    int digito2 = (rand() % 6) + 1;
    int digito3 = (rand() % 6) + 1;
    int digito4 = (rand() % 6) + 1;
    int numeroFinal = digito1 * 1000 + digito2 * 100 + digito3 * 10 + digito4;

    //funcao de verificacao numero jogador 

    int numeroJogador;
    cin >> numeroJogador;
    int primeiroDigitoJ = numeroJogador / 1000;
    int segundoDigitoJ = (numeroJogador - primeiroDigitoJ *1000)/ 100;
    int terceiroDigitoJ = (numeroJogador - (primeiroDigitoJ * 1000 + segundoDigitoJ * 100))/10;
    int quartoDigitoJ = numeroJogador - (primeiroDigitoJ * 1000 + segundoDigitoJ * 100 + terceiroDigitoJ * 10);
    int numeroJFinal = primeiroDigitoJ * 1000 + segundoDigitoJ * 100 + terceiroDigitoJ * 10 + quartoDigitoJ;
    
    if (numeroJogador==numeroFinal){
        cout << "Você ganhou!";
    }else{
        for(count = 0; tentativas <= 10; tentativas++){
            while (count <= 4){
                if(digito1 == primeiroDigitoJ and tentativas <= 10){
                    count++;
                    tentativas++;
                    cin >> numeroJogador;
                }if(digito2 == segundoDigitoJ){
                    count++;
                    tentativas++;
                    cin >> numeroJogador;
                }if(digito3 == terceiroDigitoJ){
                    count++;
                    tentativas++;
                    cin >> numeroJogador;
                }if (digito4 == quartoDigitoJ){
                    count++;
                    tentativas++;
                    cin>> numeroJogador;
                }

            }
        }
    }
}

void Cabecalho() {
    cout << "=====================================\n";
    cout << "          JOGO DA SENHA\n";
    cout << "     Descubra a senha secreta!\n";
    cout << "         Digitos de 1 a 6\n";
    cout << "=====================================\n";
}

void Menu() {
    cout << "\n------ MENU ------\n";
    cout << "1 - Iniciar o jogo\n";
    cout << "2 - Ajuda\n";
    cout << "3 - Sair\n";
    cout << "Escolha: ";
}

void Ajuda() {
    cout << "\n========== AJUDA ==========\n";
    cout << "O computador gera uma senha de 4 digitos (1 a 6).\n";
    cout << "Voce tem 10 tentativas para adivinhar.\n\n";
    cout << "Feedback por tentativa:\n";
    cout << "- Digitos corretos e na posicao correta\n";
    cout << "- Digitos corretos mas na posicao errada\n";
    cout << "============================\n\n";
}

void mostrarEntradaTentativa(int tentativa) {
    cout << "\n-------------------------------------\n";
    cout << " Tentativa " << tentativa << " de 10\n";
    cout << " Digite 4 digitos (1 a 6): ";
}

void mostrarFeedback(int acertosPosicao, int acertosValor) {
    cout << "\n--- FEEDBACK ---\n";
    cout << "Posicao correta: " << acertosPosicao << "\n";
    cout << "Cor correta na posicao errada: " << acertosValor << "\n";
    cout << "-----------------\n";
}

void Vitoria() {
    cout << "\n=====================================\n";
    cout << "      PARABENS! VOCE DESCOBRIU!\n";
    cout << "=====================================\n";
}

void Derrota() {
    cout << "\n=====================================\n";
    cout << "        FIM DE JOGO!\n";
    cout << "  Suas tentativas acabaram.\n";
    cout << "=====================================\n";
}

int main(){
    int opcao;

    Cabecalho();

    Menu();
    cin >> opcao;

    if (opcao == 2) {
        Ajuda();
        Menu();
        cin >> opcao;
    }

    if (opcao == 1) {
        cout << "\nGerando senha secreta...\n";
        cout << "(senha invisivel para o jogador)\n";

        // A partir daqui seria a logica do jogo (não incluida)
        cout << "\n--- INTERFACE DO JOGO ATIVADA ---\n";

        // Exemplo visual de 10 tentativas
        int tentativa = 1;
        while (tentativa <= 10) {

            // Interface para entrada
            mostrarEntradaTentativa(tentativa);

            // Aqui o programador inseriria a lógica:
            int d1, d2, d3, d4;
            cin >> d1 >> d2 >> d3 >> d4;

            // Feedback visual (valores fictícios)
            int acertosPosicao = 0;
            int acertosValor = 0;

            // Apenas visual (na logica real seriam calculados)
            mostrarFeedback(acertosPosicao, acertosValor);

            tentativa++;
        }

        Derrota(); 
    }

    if (opcao == 3) {
        cout << "\nSaindo do jogo...\n";
    }

    return 0;
}