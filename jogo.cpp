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











int main(){

    int continuar;
    cout << "Seja bem-vindo ao jogo da senha. By João Gabriel & Arthur." << endl;
    cout << "Digite 1 para continuar ou 2 para sair." << endl;
    cin >> continuar;
    if (continuar == 2){}
    if(continuar == 1){
        cout << "Você terá 10 tentativas para advinhar a senha de 4 digitos." << endl;
        cout << "Digite 1 para prosseguir." <<  endl;
        jogoDaSenha();
    }
}