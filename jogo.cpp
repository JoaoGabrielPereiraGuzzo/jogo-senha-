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

    

    int numeroJogador;
    cin >> numeroJogador;
    
    
    if (numeroJogador == numeroFinal){
        cout << "Você ganhou!";
    } else {
       
        while(tentativas <= 10){
                while(count <= 4 ){
                    
                    int primeiroDigitoJ = numeroJogador / 1000;
                    int segundoDigitoJ = (numeroJogador - primeiroDigitoJ *1000)/ 100;
                    int terceiroDigitoJ = (numeroJogador - (primeiroDigitoJ * 1000 + segundoDigitoJ * 100))/10;
                    int quartoDigitoJ = numeroJogador - (primeiroDigitoJ * 1000 + segundoDigitoJ * 100 + terceiroDigitoJ * 10);
                    
                    if(tentativas < 10){
                        
                        if(numeroJogador == numeroFinal){
                            cout << "voce venceu!";
                            break;
                        } else{    
                            //verifica se o primeiro digito e compativel com qualquer um dos 4 digitos da senha
                            if (primeiroDigitoJ == digito1)
                            {
                                cout << "o";
                                
                            } else if(primeiroDigitoJ == digito2 or primeiroDigitoJ == digito3 or primeiroDigitoJ == digito4){
                                cout << "x";
                            }else{
                                cout << "_";
                            }
                            
                            //verifica se o segundo digito e compativel com qualquer um dos 4 digitos da senha
                            if(segundoDigitoJ == digito2){
                                cout << "o";
                               
                            }else if (segundoDigitoJ == digito1 or segundoDigitoJ == digito3 or segundoDigitoJ == digito4)
                            {
                                cout << "x";
                            }else{
                                cout << "_";
                            }
        
        
                            //verifica se o terceiro digito e compativel com qualquer um dos 4 digitos da senha
                            if(terceiroDigitoJ == digito3){
                                cout << "o";
                                
                            }else if (terceiroDigitoJ == digito1 or terceiroDigitoJ == digito2 or terceiroDigitoJ == digito4)
                            {
                                cout << "x";
                            }else{
                                cout << "_";
                            }
        
                            //verifica se o quarto digito e compativel com qualquer um dos 4 digitos da senha
                            if(quartoDigitoJ == digito4){
                                cout << "o" << endl;
                               
                            }else if (quartoDigitoJ == digito1 or quartoDigitoJ == digito2 or quartoDigitoJ == digito3)
                            {
                                cout << "x" << endl;
                            }else{
                                cout << "_" << endl;
                            }
                                tentativas++;
                                cin >> numeroJogador;
                        }
                        }else{
                            cout << "Voce perdeu burrao";
                            break;
                        }   
                }
            break;
        }
    }


}



int main(){

    int continuar;
    cout << "Seja bem-vindo ao jogo da senha. By João Gabriel & Arthur." << endl;
    cout << "Digite 1 para continuar ou 2 para sair." << endl;
    cin >> continuar;
    if(continuar == 1){
        cout << "Você terá 10 tentativas para advinhar a senha de 4 digitos." << endl;
        cout << "Boa sorte!!" << endl;
        jogoDaSenha();
    }
}