#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
int count;
int tentativas = 1;
int numeroJogador;

//Criei um struct q randomiza a senha para maior organizacao do codigo;
struct senhaRandom{
    int digito1 = (rand() % 6) + 1;
    int digito2 = (rand() % 6) + 1;
    int digito3 = (rand() % 6) + 1;
    int digito4 = (rand() % 6) + 1;
    int numeroFinal = digito1 * 1000 + digito2 * 100 + digito3 * 10 + digito4;
};

//struct para tratar o numero jogado pelo usuario
struct numeroJogado
{
     int primeiroDigitoJ;
     int segundoDigitoJ;
     int terceiroDigitoJ;
     int quartoDigitoJ;
     
};


//funcao q trata o numero jogado pelo usuario, separando os digitos
numeroJogado trataNumeroJogador(int numeroJogador){

    numeroJogado njr;
    njr.primeiroDigitoJ = numeroJogador / 1000;
    njr.segundoDigitoJ = (numeroJogador - njr.primeiroDigitoJ *1000)/ 100;
    njr.terceiroDigitoJ = (numeroJogador - (njr.primeiroDigitoJ * 1000 + njr.segundoDigitoJ * 100))/10;
    njr.quartoDigitoJ = numeroJogador - (njr.primeiroDigitoJ * 1000 + njr.segundoDigitoJ * 100 + njr.terceiroDigitoJ * 10);

    return njr;

}




void jogoDaSenha(){
   
    //chama as variaveis do struct
    senhaRandom senhaRandom;
    

    int numeroJogador;
    cin >> numeroJogador;
    
    
    if (numeroJogador == senhaRandom.numeroFinal){
        cout << "Você ganhou!";
    } else {
       
        while(tentativas <= 10){
                while(count <= 4 ){
                    
                    numeroJogado nj = trataNumeroJogador(numeroJogador);

                    if(tentativas < 10){
                        
                        if(numeroJogador == senhaRandom.numeroFinal){
                            cout << "voce venceu!";
                            break;
                        } else{    
                            //verifica se o primeiro digito e compativel com qualquer um dos 4 digitos da senha
                            if (nj.primeiroDigitoJ == senhaRandom.digito1)
                            {
                                cout << "o";
                                
                            } else if(nj.primeiroDigitoJ == senhaRandom.digito2 or nj.primeiroDigitoJ == senhaRandom.digito3 or nj.primeiroDigitoJ == senhaRandom.digito4){
                                cout << "x";
                            }else{
                                cout << "_";
                            }
                            
                            //verifica se o segundo digito e compativel com qualquer um dos 4 digitos da senha
                            if(nj.segundoDigitoJ == senhaRandom.digito2){
                                cout << "o";
                               
                            }else if (nj.segundoDigitoJ == senhaRandom.digito1 or nj.segundoDigitoJ == senhaRandom.digito3 or nj.segundoDigitoJ == senhaRandom.digito4)
                            {
                                cout << "x";
                            }else{
                                cout << "_";
                            }
        

                            //verifica se o terceiro digito e compativel com qualquer um dos 4 digitos da senha
                            if(nj.terceiroDigitoJ == senhaRandom.digito3){
                                cout << "o";
                                
                            }else if (nj.terceiroDigitoJ == senhaRandom.digito1 or nj.terceiroDigitoJ == senhaRandom.digito2 or nj.terceiroDigitoJ == senhaRandom.digito4)
                            {
                                cout << "x";
                            }else{
                                cout << "_";
                            }
        
                            //verifica se o quarto digito e compativel com qualquer um dos 4 digitos da senha
                            if(nj.quartoDigitoJ == senhaRandom.digito4){
                                cout << "o" << endl;
                               
                            }else if (nj.quartoDigitoJ == senhaRandom.digito1 or nj.quartoDigitoJ == senhaRandom.digito2 or nj.quartoDigitoJ == senhaRandom.digito3)
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