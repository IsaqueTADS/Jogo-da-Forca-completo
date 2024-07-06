#include <iostream>
#include <locale.h>
#include <stdbool.h> //biblioteca para o uso do system("cls")
#include <cstdlib> //bliblioteca para o uso do exit();
#include <cwchar> //biblioteca para aceitar caracter multibyte no C++

using namespace std;

   wchar_t palavra[60], chute[1], forca[60], p_usada[60], dica[60];
   int opc, difi, i, i1, tamanho, dtamanho, vidas, acertos,errou,cdica;
   bool acerto;
    
   void inicio ();
   void dificuldade ();
   void facil();
   void ganhou();
   void perdeu();
   void CaracterMultiByte();
   bool chuteRepetido(wchar_t caracter);
 

int main(){
     void CaracterMultiByte();
    
    inicio();
    dificuldade();
   
    return 0;
}



void inicio(){

    wcout<<"JOGO DA FORCA V2.0 "<<endl;
    wcout<<"===================="<<endl;
    wcout<<"Criador: IsaqueTADS"<<endl;
    wcout<<"Isaque Rodrigues Alves\n "<<endl;

    wcout<<"Instragam:\n@isaquetads \n@isaque_rodriguesdev\n\n "<<endl;
    system("pause");
    system("cls");


}

void CaracterMultiByte(){

    setlocale(LC_ALL,"portuguese.1252");
    
}


void dificuldade(){

      system("cls");

    wcout<<"DIFICULDADE DO JOGO !\n "<<endl;

    wcout<<"[1] Facil  [3] Dificil"<<endl;
    wcout<<"[2] Normal [ ] INSANOO"<<endl;
    wcout<<"[5] Sair "<<endl;
    wcout<<"Escolha uma das op��es acima: "<<endl;
    wcin>>difi;

    while(difi == 5){
        system("cls");

        wcout<<"DESISTIU N� ;-; ;-; ;-; "<<endl;

        exit(0);
    }
    
    switch(difi){

        case 1:

        facil();
        
    }

}

void facil (){
   

        system("cls");

         i = 0;
         i1 = 1;
         tamanho = 0;
         acertos = 0;
         acerto = false;
         vidas = 10;
         errou = 0;

         wcout << "Qual a palavra que o jogador vai adivinhar? "<<endl;
         wcin>>palavra;
         system("cls");
         wcout << "A palavra que voc� escolheu �?  Ex:(cidade, animal, frute, etc...) "<<endl;
         wcin>>dica;
         system("cls");

         while(palavra[i] != '\0' )
         {

            i ++;
            tamanho ++;
            /*esse bloco verifica o tamanho da palavra, o \0 indica o fim da palavra, enquando n chegar nele da lopp
            e incrementa o tamanho*/
         }

         for(i = 0; i < 60; i++)
         {

            forca[i] = '_';
            p_usada[i] = '-';
            /*Aqui os dois vetores s�o prenchidos at� o tamanho 60, por�m ao decorrer do c�digo
            apenas o tamanho da palavra secreta ser� exibida */

         }
         
         while((vidas > 0) && (acertos < tamanho)) //loop principal onde roda o jogo.
         {
           if(cdica = 5 >= vidas) {

                wcout<<"Dica: "<<dica<<endl;

            }
           
            wcout<<"Vidas restante: "<<vidas<<endl;

            wcout<<"A palavra tem-"<<tamanho<<"-caracter"<<endl;

            wcout<<"Palavras usadas: ";

        for( i = 0; i < 60; i ++){
            if(p_usada[i] != '-'){
                wcout<<p_usada[i]<<"-";
            }
            //Esse bloco mostra na tela as palavras que o jogador utilizou.
        }

     
            wcout<<"\n";

            wcout << "  _______       \n";
            wcout << " |/      |      \n";
            wcout << " |      " << (errou >= 1 ? '(' : ' ') << (errou >= 2 ? '_' : ' ') << (errou >= 3 ? ')' : ' ') << "  \n";
            wcout << " |      " << (errou >= 4 ? '\\' : ' ') << (errou >= 5 ? '|' : ' ') << (errou >= 6 ? '/' : ' ') << "  \n";
            wcout << " |       " << (errou >= 7 ? '|' : ' ') << "     \n";
            wcout << " |      " << (errou >= 8 ? '/' : ' ') << " " << (errou >= 9 ? '\\' : ' ') << "   \n";
            wcout << " |              \n";
            wcout << "_|___  ";
            for(i = 0; i < tamanho; i ++)
            {
                
            wcout<<forca[i];

            } // esse for exibe os chutes se for certo.

            

            wcout<<"\n"<<endl;
            wcout<<"Chute uma letra: "<<endl;
            wcin>>chute;
            
            system("cls");

            if (chuteRepetido(chute[0])){ //recebe uma resposta booleana da fun��o chuteRepetido(), true a palavra � repetida, false � valida.

                wcout<<"Palavra repetida!!\nPerdeu uma vida para ficar esperto <3\n "<<endl;
                vidas --;
                errou ++;

            }else { 

                p_usada[i1 ++] = chute[0]; // atribui para o vetor usadas todos caracter do vetor chute na posi��o 0.

                for(i = 0; i < tamanho; i ++)
                {

                    if (palavra[i] == chute[0]){
                        acerto = true;
                        forca[i] = palavra[i];
                        acertos ++;

                    }
                    //esse for verifica se a letra est� na palavra secreta, e se estive coloca a letra no lugar certo.

                }
                

                if(!acerto){

                    vidas --;
                    errou ++;
                    //esse bloco serve para contabilizara as vidas, caso a pessoa erre vai diminuir a vida.
                    //serve tambem para incrementar o vlaor da variavel errou, assim podendo formar a forca.
                }

                acerto = false;
                system("cls");
    
            }

           

         }

         if(acertos == tamanho){

                ganhou();
         
         }else
         {

               
                perdeu();
         }   




}

bool chuteRepetido(wchar_t caracter){ // recebe informa��o do chute do jogo.

        for( i = 0; i <60; i ++) {

            if ( p_usada[i] == caracter){
                
                return true;//chute repetido.
            }
            
        }

    return false; //chute valido.


}

void ganhou (){
    
    setlocale(LC_ALL,"portuguese");
         wcout<<"Parabens voc� acertou!! "<<endl;
         wcout<<"       ___________      \n";
         wcout<<"      '._==_==_=_.'     \n";
         wcout<<"      .-\\:      /-.    \n";
         wcout<<"     | |:.     | |    \n";
         wcout<<"      '-|:.     |-'     \n";
         wcout<<"        \\::.    /      \n";
         wcout<<"         '::. .'        \n";
         wcout<<"                      \n";
         wcout<<"         _.' '._        \n";
         wcout<<"        '-------'       \n\n";

         wcout<<"Jogar novamente? "<<endl;
         wcout<<"[1] jogar novamnete "<<endl;
         wcout<<"[2] Sair "<<endl;        
         wcin>>opc;

             if (opc == 1)
            {

                    dificuldade();

            }else if( opc == 2) 
            {
                system("cls");
                wcout<<"Obrigado por jogar meu jogo v3 "<<endl;

                exit(0); //indica que o progama se encerrou, biblioteca cstdlib
                    
            }
    
}

void perdeu (){

    setlocale(LC_ALL,"portuguese");

        wcout<<"Poxa voc� perdeu e foi enfocardo ;-;-; ";
        wcout<<"A palavra era: "<<palavra<<endl;
            
        wcout<<"    _______________         \n";
        wcout<<"   /               \\       \n"; 
        wcout<<"  /                 \\      \n";
        wcout<<"//                   \\/\\  \n";
        wcout<<"\\|   XXXX     XXXX   | /   \n";
        wcout<<" |   XXXX     XXXX   |/     \n";
        wcout<<" |   XXX       XXX   |      \n";
        wcout<<" |                   |      \n";
        wcout<<" \\__      XXX      __/     \n";
        wcout<<"   |\\     XXX     /|       \n";
        wcout<<"   | |           | |        \n";
        wcout<<"   | I I I I I I I |        \n";
        wcout<<"   |  I I I I I I  |        \n";
        wcout<<"   \\_             _/       \n";
        wcout<<"     \\_         _/         \n";
        wcout<<"       \\_______/           \n\n";


        wcout<<"Jogar novamente? "<<endl;
        wcout<<"[1] jogar novamente "<<endl;
        wcout<<"[2] Sair "<<endl;
        wcin>>opc;

         if (opc == 1)
         {

            dificuldade();

         }else{
                   
           system("cls");
           wcout<<"Obrigado por jogar meu jogo v3 "<<endl;

           exit(0); //indica que o progama se encerrou, biblioteca cstdlib

         }

           
         
         
}   