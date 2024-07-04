#include <iostream>
#include <locale.h>
#include <stdbool.h> //biblioteca para o uso do system("cls")
#include <cstdlib> //bliblioteca para o uso do exit();

using namespace std;

   char palavra[60], chute[1], forca[60], p_usada[60], dica[60];
   int opc, difi, i, i1, tamanho, dtamanho, vidas, acertos,errou,cdica;
   bool acerto;
    
   void inicio ();
   void dificuldade ();
   void facil();
   void ganhou();
   void perdeu();
   bool chuteRepetido(char caracter);
 

int main(){

    setlocale(LC_ALL,"portuguese_Brazil");

    
    inicio();
    dificuldade();
   


    return 0;
}



void inicio(){

    cout<<"JOGO DA FORCA V2.0 "<<endl;
    cout<<"===================="<<endl;
    cout<<"Criador: IsaqueTADS"<<endl;
    cout<<"Isaque Rodrigues Alves\n "<<endl;

    cout<<"Instragam:\n@isaquetads \n@isaque_rodriguesdev\n\n "<<endl;
    system("pause");
    system("cls");


}

void dificuldade(){
    system("cls");

    cout<<"DIFICULDADE DO JOGO !\n "<<endl;

    cout<<"[1] Facil  [3] Dificil"<<endl;
    cout<<"[2] Normal [ ] INSANOO"<<endl;
    cout<<"[5] Sair "<<endl;
    cout<<"Escolha uma das opções acima: "<<endl;
    cin>>difi;

    while(difi == 5){
        system("cls");

        cout<<"DESISTIU NÉ ;-; ;-; ;-; "<<endl;

        exit(0);
    }
    
    switch(difi){

        case 1:

        facil();
        
    }

}

void facil (){
   
    setlocale(LC_ALL,"portuguese_Brazil");

        system("cls");

         i = 0;
         i1 = 1;
         tamanho = 0;
         acertos = 0;
         acerto = false;
         vidas = 10;
         errou = 0;

         cout << "Qual a palavra que o jogador vai adivinhar? "<<endl;
         cin>>palavra;
         system("cls");
         cout << "A palavra que você escolheu é?  Ex:(cidade, animal, frute, etc...) "<<endl;
         cin>>dica;
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
            /*Aqui os dois vetores s[ao prenchidos até o tamanho 60, porém ao decorrer do código
            apenas o tamanho da palavra secreta será exibida */

         }
         
         while((vidas > 0) && (acertos < tamanho))
         {
           if(cdica = 5 == errou) {

                cout<<"Dica: "<<dica<<endl;

            }
           
            cout<<"Vidas restante: "<<vidas<<endl;

            cout<<"A palavra tem-"<<tamanho<<"-caracter"<<endl;

            cout<<"Palavras usadas: ";

        for( i = 0; i < 60; i ++){
            if(p_usada[i] != '-'){
                cout<<p_usada[i]<<"-";
            }
            //Esse bloco mostra na tela as palavras que o jogador utilizou.
        }

     
            cout<<"\n";

            cout << "  _______       \n";
            cout << " |/      |      \n";
            cout << " |      " << (errou >= 1 ? '(' : ' ') << (errou >= 2 ? '_' : ' ') << (errou >= 3 ? ')' : ' ') << "  \n";
            cout << " |      " << (errou >= 4 ? '\\' : ' ') << (errou >= 5 ? '|' : ' ') << (errou >= 6 ? '/' : ' ') << "  \n";
            cout << " |       " << (errou >= 7 ? '|' : ' ') << "     \n";
            cout << " |      " << (errou >= 8 ? '/' : ' ') << " " << (errou >= 9 ? '\\' : ' ') << "   \n";
            cout << " |              \n";
            cout << "_|___  ";
            for(i = 0; i < tamanho; i ++)
            {
                
            cout<<forca[i];

            } // esse for exibe os chutes se for certo.

            

            cout<<"\n"<<endl;
            cout<<"Chute uma letra: "<<endl;
            cin>>chute;
            
            system("cls");

            if (chuteRepetido(chute[0])){ //recebe uma resposta booleana da função chuteRepetido(), true a palavra é repetida, false é valida.

                cout<<"Palavra repetida!!\nPerdeu uma vida para ficar esperto <3\n "<<endl;
                vidas --;
                errou ++;

            }else { 

                p_usada[i1 ++] = chute[0]; // atribui para o vetor usadas todos caracter do vetor chute na posição 0.

                for(i = 0; i < tamanho; i ++)
                {

                    if (palavra[i] == chute[0]){
                        acerto = true;
                        forca[i] = palavra[i];
                        acertos ++;

                    }
                    //esse for verifica se a letra está na palavra secreta, e se estive coloca a letra no lugar certo.

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

bool chuteRepetido(char caracter){ // recebe informação do chute do jogo.
    for( i = 0; i <60; i ++) {

        if ( p_usada[i] == caracter){
            
            return true;//chute repetido.
        }
        
    }

    return false; //chute valido.


}

void ganhou (){

    setlocale(LC_ALL,"portuguese_Brazil");

         cout<<"Parabens você acertou!! "<<endl;
         cout<<"       ___________      \n";
         cout<<"      '._==_==_=_.'     \n";
         cout<<"      .-\\:      /-.    \n";
         cout<<"     | |:.     | |    \n";
         cout<<"      '-|:.     |-'     \n";
         cout<<"        \\::.    /      \n";
         cout<<"         '::. .'        \n";
         cout<<"                      \n";
         cout<<"         _.' '._        \n";
         cout<<"        '-------'       \n\n";

         cout<<"Jogar novamente? "<<endl;
         cout<<"[1] jogar novamnete "<<endl;
         cout<<"[2] Sair "<<endl;        
         cin>>opc;

             if (opc == 1)
            {

                    dificuldade();

            }else if( opc == 2) 
            {
                system("cls");
                cout<<"Obrigado por jogar meu jogo v3 "<<endl;

                exit(0); //indica que o progama se encerrou, biblioteca cstdlib
                    
            }
    
}

void perdeu (){

    setlocale(LC_ALL,"portuguese_Brazil");

        cout<<"Poxa você perdeu e foi enfocardo ;-;-; ";
        cout<<"A palavra era: "<<palavra<<endl;
            
        cout<<"    _______________         \n";
        cout<<"   /               \\       \n"; 
        cout<<"  /                 \\      \n";
        cout<<"//                   \\/\\  \n";
        cout<<"\\|   XXXX     XXXX   | /   \n";
        cout<<" |   XXXX     XXXX   |/     \n";
        cout<<" |   XXX       XXX   |      \n";
        cout<<" |                   |      \n";
        cout<<" \\__      XXX      __/     \n";
        cout<<"   |\\     XXX     /|       \n";
        cout<<"   | |           | |        \n";
        cout<<"   | I I I I I I I |        \n";
        cout<<"   |  I I I I I I  |        \n";
        cout<<"   \\_             _/       \n";
        cout<<"     \\_         _/         \n";
        cout<<"       \\_______/           \n\n";


        cout<<"Jogar novamente? "<<endl;
        cout<<"[1] jogar novamente "<<endl;
        cout<<"[2] Sair "<<endl;
        cin>>opc;

         if (opc == 1)
         {

            dificuldade();

         }else{
                   
           system("cls");
           cout<<"Obrigado por jogar meu jogo v3 "<<endl;

           exit(0); //indica que o progama se encerrou, biblioteca cstdlib

         }

           
         
         
}   