/*
    Esta versão do jogo foi modificada para atender às demandas da UCE, como parte do trabalho sobre "A importância do aprendizado tecnológico e a introdução à informática". A oficina tem como objetivo transmitir conhecimentos sobre tecnologia para crianças de 9 a 11 anos. Portanto, adaptamos o jogo para uma versão mais simples, permitindo que elas compreendam que é possível criar jogos e despertar seu interesse pelo vasto mundo da informática.

    Nota: Versão específica para fins educacionais.

    Objetivo: Atender às demandas do trabalho da UCE.

    Criador: Isaque Rodrigues Alves

*/

#include <iostream>
#include <locale.h>
#include <stdbool.h> //biblioteca para o uso do system("cls")
#include <cstdlib> //bliblioteca para o uso do exit();
#include <cwchar> //biblioteca para aceitar caracter multibyte no C++
#include <ctime>  //biblioteca para o uso do clock(), CLOCKS_PER_SEC;
#include <unistd.h> //biblioteca para usar sleep();
#include <vector> //biblioteca para armazenar listas
#include <cstring> //biblioteca para strncpy


using namespace std;

   wchar_t palavra[60], chute[1], forca[60], p_usada[60], dica[60], trollin[60];
   char palavraSing[60];
   int opc, difi, i, i1, tamanho, dtamanho, vidas, acertos,errou,cdica,tempoMax,intime;
   bool acerto;
    
   void chamadaOne();
   void inicio ();
   void dificuldade ();
   void modfacil();
   void modNormal();
   void modDificil();
   void modInsano();
   void ganhou();
   void perdeu();
   bool chuteRepetido(wchar_t caracter);
   void checkTime(clock_t tempo_inicial, int tempoMax);
   void tempoEsgotado();
   void singleplayer();
   void singFacil();
   void singNormal();
   void singDificil();
   void singInsano();
   void singGanhou();
   void singPerdeu();
   void singTimeout();
   string escolherAleatorio();
   pair<string, string> BancodePalavras();



int main(){

    setlocale(LC_ALL,"portuguese.1252");
    
    inicio();

    chamadaOne();
   
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


void chamadaOne(){

    setlocale(LC_ALL,"portuguese");

    cout<<"MODO DE JOGO"<<endl;
    cout<<"[1]MultiPlayer"<<endl;
    cout<<"[2]SinglePlayer"<<endl;
    cout<<"Escolha uma das op��es acima!"<<endl;
    do{cin>>opc;

    if ( opc != 1 && opc !=2 ){
        system("cls");
        cout<<"[ERRO]Modo Inval�do "<<endl;
        cout<<"[1]MultiPlayer"<<endl;
        cout<<"[2]SinglePlayer"<<endl;
        cout<<"Escolha novamente !"<<endl;

        }

    }while ( opc != 1 && opc != 2);

    if ( opc == 1){

        dificuldade();
        
    }else if ( opc == 2){

        singleplayer();
        
    }

}

void dificuldade(){

    setlocale(LC_ALL,"portuguese");
    system("cls");
    
    wcout<<"DIFICULDADE DO JOGO !\n "<<endl;

    wcout<<"[1] Facil  [3] Dificil"<<endl;
    wcout<<"[2] Normal [4] INSANOO"<<endl;
    wcout<<"[5] Sair "<<endl;
    wcout<<"Escolha uma das op��es acima: "<<endl;
    do{ wcin>>difi;

    system("cls");

    wcout<<"[ERRO] DIGITO INV�LIDO !\nDigite novamente!\n "<<endl;

    wcout<<"[1] Facil  [3] Dificil"<<endl;
    wcout<<"[2] Normal [4] INSANOO"<<endl;
    wcout<<"[5] Sair "<<endl;
    wcout<<"Escolha uma das op��es acima: "<<endl;
    
    
    }while(difi != 1 && difi != 2 && difi !=3 && difi != 4 && difi != 5);

    switch(difi){

        case 1:

        modfacil();

        case 2:

        modNormal();

        case 3:

        modDificil();

        case 4:
        
        modInsano();
        
        case 5:

        system("cls");

        wcout<<"DESISTIU N� ;-; ;-; ;-; "<<endl;

        exit(0);

    }


}

void modfacil (){
   
    system("cls");
    
        i = 0;
        i1 = 1;
        tamanho = 0;
        acertos = 0;
        acerto = false;
        vidas = 10;
        errou = 0;
        cdica = 5;
        tempoMax = 180; 
        intime = 5;

        locale old_locale(locale::classic()); //salva o estado local

            setlocale(LC_ALL,"portuguese");

                wcout << "Qual a palavra que o jogador vai adivinhar? "<<endl;

            locale::global(old_locale);//volta para linguagem de escopo global.

                wcin>>palavra;
                system("cls");

            setlocale(LC_ALL,"portuguese");

                wcout << "A palavra que voc� escolheu �?  Ex:(cidade, animal, fruta, etc...) "<<endl;

            locale::global(old_locale);
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
        setlocale(LC_ALL,"portuguese");

            wcout<<"Voc� tem: "<<tempoMax / 60 << "m "<<tempoMax % 60<<"s "<<"para adivinhar a palavra"<<endl;
            wcout<<"O jogo come�a em: "<<endl;

        locale::global(old_locale); //volta para linguagem de escopo globa
        
        while( intime > 0 ){

            wcout << intime << "\r" << flush;

            sleep(1);

            intime --;

        }
        
        system("cls");

        clock_t tempo_inicial = clock(); // nessa parte do jogo estamos colocando no tempo inicial a informa��o do tempo em que o jogo come�ou a executar.

        while((vidas > 0) && (acertos < tamanho)) //loop principal onde roda o jogo.
        {  setlocale(LC_ALL,"portuguese.1252");
            checkTime( tempo_inicial, tempoMax); //manda info do tempo inicial, e o tempo max determinado no inicio da fun��o.
            
                if(cdica >= vidas) {

                        wcout<<"Dica: "<<dica<<endl;

                    }
                
                    wcout<<"Vidas restante: "<<vidas<<endl;

                    wcout<<"A palavra tem-"<<tamanho<<"-caracter"<<endl;

                    wcout<<"letras usadas: ";

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

                singGanhou();
            
            }else
            {

                
                singPerdeu();
            }   




}

void modNormal(){

   system("cls");
    
        i = 0;
        i1 = 1;
        tamanho = 0;
        acertos = 0;
        acerto = false;
        vidas = 6;
        errou = 0;
        cdica = 3;
        tempoMax = 120; 
        intime = 5;

        locale old_locale(locale::classic()); //salva o estado local

            setlocale(LC_ALL,"portuguese");

                wcout << "Qual a palavra que o jogador vai adivinhar? "<<endl;

            locale::global(old_locale);//volta para linguagem de escopo global.

                wcin>>palavra;
                system("cls");

            setlocale(LC_ALL,"portuguese");

                wcout << "A palavra que voc� escolheu �?  Ex:(cidade, animal, fruta, etc...) "<<endl;

            locale::global(old_locale);
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
        setlocale(LC_ALL,"portuguese");

            wcout<<"Voc� tem: "<<tempoMax / 60 << "m "<<tempoMax % 60<<"s "<<"para adivinhar a palavra"<<endl;
            wcout<<"O jogo come�a em: "<<endl;

        locale::global(old_locale); //volta para linguagem de escopo globa
        
        while( intime > 0 ){

            wcout << intime << "\r" << flush;

            sleep(1);

            intime --;

        }
        
        system("cls");

        clock_t tempo_inicial = clock(); // nessa parte do jogo estamos colocando no tempo inicial a informa��o do tempo em que o jogo come�ou a executar.

        while((vidas > 0) && (acertos < tamanho)) //loop principal onde roda o jogo.
        {  setlocale(LC_ALL,"portuguese.1252");
            checkTime( tempo_inicial, tempoMax); //manda info do tempo inicial, e o tempo max determinado no inicio da fun��o.
            
                if(cdica >= vidas) {

                        wcout<<"Dica: "<<dica<<endl;

                    }
                
                    wcout<<"Vidas restante: "<<vidas<<endl;

                    wcout<<"A palavra tem-"<<tamanho<<"-caracter"<<endl;

                    wcout<<"letras usadas: ";

                for( i = 0; i < 60; i ++){
                    if(p_usada[i] != '-'){
                        wcout<<p_usada[i]<<"-";
                    }
                    //Esse bloco mostra na tela as palavras que o jogador utilizou.
                }

            
                    wcout<<"\n";

                    wcout << "  _______       \n";
                    wcout << " |/      |      \n";
                    wcout << " |      " << (errou >= 1 ? '(' : ' ') << (errou >= 1 ? '_' : ' ') << (errou >= 1 ? ')' : ' ') << "  \n";
                    wcout << " |      " << (errou >= 2 ? '\\' : ' ') << (errou >= 2 ? '|' : ' ') << (errou >= 2 ? '/' : ' ') << "  \n";
                    wcout << " |       " << (errou >= 3 ? '|' : ' ') << "     \n";
                    wcout << " |      " << (errou >= 4 ? '/' : ' ') << " " << (errou >= 5 ? '\\' : ' ') << "   \n";
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

                singGanhou();
            
            }else
            {

                
                singPerdeu();
            }   

}

void modDificil(){
     system("cls");
    
        i = 0;
        i1 = 1;
        tamanho = 0;
        acertos = 0;
        acerto = false;
        vidas = 10;
        errou = 0;
        cdica = 5;
        tempoMax = 70; 
        intime = 5;

        locale old_locale(locale::classic()); //salva o estado local

            setlocale(LC_ALL,"portuguese");

                wcout << "Qual a palavra que o jogador vai adivinhar? "<<endl;

            locale::global(old_locale);//volta para linguagem de escopo global.

                wcin>>palavra;
                system("cls");

            setlocale(LC_ALL,"portuguese");

                wcout << "A palavra que voc� escolheu �?  Ex:(cidade, animal, fruta, etc...) "<<endl;

            locale::global(old_locale);
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
        setlocale(LC_ALL,"portuguese");

            wcout<<"Voc� tem: "<<tempoMax / 60 << "m "<<tempoMax % 60<<"s "<<"para adivinhar a palavra"<<endl;
            wcout<<"O jogo come�a em: "<<endl;

        locale::global(old_locale); //volta para linguagem de escopo globa
        
        while( intime > 0 ){

            wcout << intime << "\r" << flush;

            sleep(1);

            intime --;

        }
        
        system("cls");

        clock_t tempo_inicial = clock(); // nessa parte do jogo estamos colocando no tempo inicial a informa��o do tempo em que o jogo come�ou a executar.

        while((vidas > 0) && (acertos < tamanho)) //loop principal onde roda o jogo.
        {  setlocale(LC_ALL,"portuguese.1252");
            checkTime( tempo_inicial, tempoMax); //manda info do tempo inicial, e o tempo max determinado no inicio da fun��o.
            
                if(cdica >= vidas) {

                        wcout<<"Dica: "<<dica<<endl;

                    }
                
                    wcout<<"Vidas restante: "<<vidas<<endl;

                    wcout<<"A palavra tem-"<<tamanho<<"-caracter"<<endl;

                    wcout<<"letras usadas: ";

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

                singGanhou();
            
            }else
            {

                
                singPerdeu();
            }   


}

void modInsano(){
     system("cls");
    
        i = 0;
        i1 = 1;
        tamanho = 0;
        acertos = 0;
        acerto = false;
        vidas = 20;
        errou = 0;
        cdica = 0;
        tempoMax = 30; 
        intime = 5;

        locale old_locale(locale::classic()); //salva o estado local

            setlocale(LC_ALL,"portuguese");

                wcout << "Qual a palavra que o jogador vai adivinhar? "<<endl;

            locale::global(old_locale);//volta para linguagem de escopo global.

                wcin>>palavra;
                system("cls");

            setlocale(LC_ALL,"portuguese");

                wcout << "A palavra que voc� escolheu �?  Ex:(cidade, animal, fruta, etc...) "<<endl;

            locale::global(old_locale);
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
            trollin[i] = '-';
            /*Aqui os dois vetores s�o prenchidos at� o tamanho 60, por�m ao decorrer do c�digo
            apenas o tamanho da palavra secreta ser� exibida */

        }
        setlocale(LC_ALL,"portuguese");

            wcout<<"Voc� tem: "<<tempoMax / 60 << "m "<<tempoMax % 60<<"s "<<"para adivinhar a palavra"<<endl;
            wcout<<"O jogo come�a em: "<<endl;

        locale::global(old_locale); //volta para linguagem de escopo globa
        
        while( intime > 0 ){

            wcout << intime << "\r" << flush;

            sleep(1);

            intime --;

        }
        
        system("cls");

        clock_t tempo_inicial = clock(); // nessa parte do jogo estamos colocando no tempo inicial a informa��o do tempo em que o jogo come�ou a executar.

        while((vidas > 0) && (acertos < tamanho)) //loop principal onde roda o jogo.
        {  setlocale(LC_ALL,"portuguese.1252");
            checkTime( tempo_inicial, tempoMax); //manda info do tempo inicial, e o tempo max determinado no inicio da fun��o.
            
                if(cdica >= vidas) {

                        wcout<<"Dica: "<<dica<<endl;

                    }
                
                    wcout<<"Vidas restante: "<<vidas<<endl;

                    wcout<<"A palavra tem-"<<tamanho<<"-caracter"<<endl;

                    wcout<<"letras usadas: ";

                for( i = 0; i < 60; i ++){
                    if(trollin[i] != '-'){
                        wcout<<trollin[i]<<"-";
                    }
                    //Esse bloco mostra na tela as palavras que o jogador utilizou.
                }

                    wcout<<"\n";

                    wcout << "  _______       \n";
                    wcout << " |/      |      \n";
                    wcout << " |      " << (errou >= 1 ? '(' : ' ') << (errou >= 3 ? '_' : ' ') << (errou >= 6 ? ')' : ' ') << "  \n";
                    wcout << " |      " << (errou >= 9 ? '\\' : ' ') << (errou >= 12 ? '|' : ' ') << (errou >= 14 ? '/' : ' ') << "  \n";
                    wcout << " |       " << (errou >= 16 ? '|' : ' ') << "     \n";
                    wcout << " |      " << (errou >= 18 ? '/' : ' ') << " " << (errou >= 19 ? '\\' : ' ') << "   \n";
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

                    p_usada[i1 ++] = chute[0] ; // atribui para o vetor usadas todos caracter do vetor chute na posi��o 0.
                    trollin[i1] = 'X';

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

                singGanhou();
            
            }else
            {

                
                singPerdeu();
            }   

}


void singleplayer(){

 setlocale(LC_ALL,"portuguese");
      system("cls");
        
        wcout<<"DIFICULDADE DO JOGO !\n "<<endl;

        wcout<<"[1] Facil  [3] Dificil"<<endl;
        wcout<<"[2] Normal [4] INSANOO"<<endl;
        wcout<<"[5] Sair "<<endl;
        wcout<<"Escolha uma das op��es acima: "<<endl;
        do{ wcin>>difi;

        system("cls");

        wcout<<"[ERRO] DIGITO INV�LIDO !\nDigite novamente!\n "<<endl;

        wcout<<"[1] Facil  [3] Dificil"<<endl;
        wcout<<"[2] Normal [4] INSANOO"<<endl;
        wcout<<"[5] Sair "<<endl;
        wcout<<"Escolha uma das op��es acima: "<<endl;
        
        
        }while(difi != 1 && difi != 2 && difi !=3 && difi != 4 && difi != 5);

        switch(difi){

            case 1:

            singFacil();

            case 2:

            singNormal();

            case 3:

            singDificil();

            case 4:

            singInsano();
            
            case 5:

            system("cls");

            wcout<<"DESISTIU N� ;-; ;-; ;-; "<<endl;

            exit(0);

        }


}

void singFacil(){

    srand(time(0));

    system("cls");
    
        i = 0;
        i1 = 1;
        tamanho = 0;
        acertos = 0;
        acerto = false;
        vidas = 10;
        errou = 0;
        cdica = 5;
        tempoMax = 180; 
        intime = 5;
       
        
        pair<string, string> nomeElemento = BancodePalavras();

        memset(palavraSing, '\0', 60); // Inicializa todo vetor com '\0'
        strcpy(palavraSing, nomeElemento.first.c_str());


        char categoria[60];
        memset(categoria, '\0', 60);
        strcpy(categoria, nomeElemento.second.c_str());

    
      
        while ( palavraSing[i] != '\0'){

            i ++;
            tamanho ++;
            /*esse bloco verifica o tamanho da Sing, o \0 indica o fim da palavra, enquando n chegar nele da lopp
            e incrementa o tamanho*/
        }

        for(i = 0; i < 60; i++)
        {

            forca[i] = '_';
            p_usada[i] = '-';
            /*Aqui os dois vetores s�o prenchidos at� o tamanho 60, por�m ao decorrer do c�digo
            apenas o tamanho da palavra secreta ser� exibida */

        }
        locale old_locale(locale::classic()); //salva o estado local

        setlocale(LC_ALL,"portuguese");

            wcout<<"Voc� tem: "<<tempoMax / 60 << "m "<<tempoMax % 60<<"s "<<"para adivinhar a palavra"<<endl;
            wcout<<"O jogo come�a em: "<<endl;

        locale::global(old_locale); //volta para linguagem de escopo globa
        
        while( intime > 0 ){

            wcout << intime << "\r" << flush;

            sleep(1);

            intime --;

        }
        
        system("cls");

        clock_t tempo_inicial = clock(); // nessa parte do jogo estamos colocando no tempo inicial a informa��o do tempo em que o jogo come�ou a executar.

        while((vidas > 0) && (acertos < tamanho)) //loop principal onde roda o jogo.
        {  setlocale(LC_ALL,"portuguese.1252");
            checkTime( tempo_inicial, tempoMax); //manda info do tempo inicial, e o tempo max determinado no inicio da fun��o.
            
                
                wcout<<"Categoria: "<<categoria<<endl;

                wcout<<"Vidas restante: "<<vidas<<endl;

                wcout<<"A palavra tem-"<<tamanho<<"-caracter"<<endl;

                wcout<<"letras usadas: ";

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

                        if (palavraSing[i] == chute[0]){
                            acerto = true;
                            forca[i] = palavraSing[i];
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

                singGanhou();

            }else{

                singPerdeu();

            }





}

void singNormal(){

     srand(time(0));

    system("cls");
    
        i = 0;
        i1 = 1;
        tamanho = 0;
        acertos = 0;
        acerto = false;
        vidas = 6;
        errou = 0;
        cdica = 5;
        tempoMax = 120; 
        intime = 5;
       
        
        pair<string, string> nomeElemento = BancodePalavras();

        memset(palavraSing, '\0', 60); // Inicializa todo vetor com '\0'
        strcpy(palavraSing, nomeElemento.first.c_str());


        char categoria[60];
        memset(categoria, '\0', 60);
        strcpy(categoria, nomeElemento.second.c_str());

    
      
        while ( palavraSing[i] != '\0'){

            i ++;
            tamanho ++;
            /*esse bloco verifica o tamanho da Sing, o \0 indica o fim da palavra, enquando n chegar nele da lopp
            e incrementa o tamanho*/
        }

        for(i = 0; i < 60; i++)
        {

            forca[i] = '_';
            p_usada[i] = '-';
            /*Aqui os dois vetores s�o prenchidos at� o tamanho 60, por�m ao decorrer do c�digo
            apenas o tamanho da palavra secreta ser� exibida */

        }
        locale old_locale(locale::classic()); //salva o estado local

        setlocale(LC_ALL,"portuguese");

            wcout<<"Voc� tem: "<<tempoMax / 60 << "m "<<tempoMax % 60<<"s "<<"para adivinhar a palavra"<<endl;
            wcout<<"O jogo come�a em: "<<endl;

        locale::global(old_locale); //volta para linguagem de escopo globa
        
        while( intime > 0 ){

            wcout << intime << "\r" << flush;

            sleep(1);

            intime --;

        }
        
        system("cls");

        clock_t tempo_inicial = clock(); // nessa parte do jogo estamos colocando no tempo inicial a informa��o do tempo em que o jogo come�ou a executar.

        while((vidas > 0) && (acertos < tamanho)) //loop principal onde roda o jogo.
        {  setlocale(LC_ALL,"portuguese.1252");
            checkTime( tempo_inicial, tempoMax); //manda info do tempo inicial, e o tempo max determinado no inicio da fun��o.
            
                
                wcout<<"Categoria: "<<categoria<<endl;

                wcout<<"Vidas restante: "<<vidas<<endl;

                wcout<<"A palavra tem-"<<tamanho<<"-caracter"<<endl;

                wcout<<"letras usadas: ";

                for( i = 0; i < 60; i ++){
                    if(p_usada[i] != '-'){
                        wcout<<p_usada[i]<<"-";
                    }
                    //Esse bloco mostra na tela as palavras que o jogador utilizou.
                }

            
                    wcout<<"\n";

                    wcout << "  _______       \n";
                    wcout << " |/      |      \n";
                    wcout << " |      " << (errou >= 1 ? '(' : ' ') << (errou >= 1 ? '_' : ' ') << (errou >= 1 ? ')' : ' ') << "  \n";
                    wcout << " |      " << (errou >= 2 ? '\\' : ' ') << (errou >= 2 ? '|' : ' ') << (errou >= 2 ? '/' : ' ') << "  \n";
                    wcout << " |       " << (errou >= 3 ? '|' : ' ') << "     \n";
                    wcout << " |      " << (errou >= 4 ? '/' : ' ') << " " << (errou >= 5 ? '\\' : ' ') << "   \n";
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

                        if (palavraSing[i] == chute[0]){
                            acerto = true;
                            forca[i] = palavraSing[i];
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

                singGanhou();

            }else{

                singPerdeu();

            }



}

void singDificil(){

     srand(time(0));

    system("cls");
    
        i = 0;
        i1 = 1;
        tamanho = 0;
        acertos = 0;
        acerto = false;
        vidas = 10;
        errou = 0;
        cdica = 5;
        tempoMax = 70; 
        intime = 5;
       
        
        pair<string, string> nomeElemento = BancodePalavras();

        memset(palavraSing, '\0', 60); // Inicializa todo vetor com '\0'
        strcpy(palavraSing, nomeElemento.first.c_str());


        char categoria[60];
        memset(categoria, '\0', 60);
        strcpy(categoria, nomeElemento.second.c_str());

    
      
        while ( palavraSing[i] != '\0'){

            i ++;
            tamanho ++;
            /*esse bloco verifica o tamanho da Sing, o \0 indica o fim da palavra, enquando n chegar nele da lopp
            e incrementa o tamanho*/
        }

        for(i = 0; i < 60; i++)
        {

            forca[i] = '_';
            p_usada[i] = '-';
            /*Aqui os dois vetores s�o prenchidos at� o tamanho 60, por�m ao decorrer do c�digo
            apenas o tamanho da palavra secreta ser� exibida */

        }
        locale old_locale(locale::classic()); //salva o estado local

        setlocale(LC_ALL,"portuguese");

            wcout<<"Voc� tem: "<<tempoMax / 60 << "m "<<tempoMax % 60<<"s "<<"para adivinhar a palavra"<<endl;
            wcout<<"O jogo come�a em: "<<endl;

        locale::global(old_locale); //volta para linguagem de escopo globa
        
        while( intime > 0 ){

            wcout << intime << "\r" << flush;

            sleep(1);

            intime --;

        }
        
        system("cls");

        clock_t tempo_inicial = clock(); // nessa parte do jogo estamos colocando no tempo inicial a informa��o do tempo em que o jogo come�ou a executar.

        while((vidas > 0) && (acertos < tamanho)) //loop principal onde roda o jogo.
        {  setlocale(LC_ALL,"portuguese.1252");
            checkTime( tempo_inicial, tempoMax); //manda info do tempo inicial, e o tempo max determinado no inicio da fun��o.
            
                
                wcout<<"Categoria: "<<categoria<<endl;

                wcout<<"Vidas restante: "<<vidas<<endl;

                wcout<<"A palavra tem-"<<tamanho<<"-caracter"<<endl;

                wcout<<"letras usadas: ";

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

                        if (palavraSing[i] == chute[0]){
                            acerto = true;
                            forca[i] = palavraSing[i];
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

                singGanhou();

            }else{

                singPerdeu();

            }



}
   
void singInsano(){

     

    system("cls");
    
        i = 0;
        i1 = 1;
        tamanho = 0;
        acertos = 0;
        acerto = false;
        vidas = 20;
        errou = 0;
        cdica = 5;
        tempoMax = 30; 
        intime = 5;
       
        
        pair<string, string> nomeElemento = BancodePalavras();

        memset(palavraSing, '\0', 60); // Inicializa todo vetor com '\0'
        strcpy(palavraSing, nomeElemento.first.c_str());


        char categoria[60];
        memset(categoria, '\0', 60);
        strcpy(categoria, nomeElemento.second.c_str());

    
      
        while ( palavraSing[i] != '\0'){

            i ++;
            tamanho ++;
            /*esse bloco verifica o tamanho da Sing, o \0 indica o fim da palavra, enquando n chegar nele da lopp
            e incrementa o tamanho*/
        }

        for(i = 0; i < 60; i++)
        {

            forca[i] = '_';
            p_usada[i] = '-';
            /*Aqui os dois vetores s�o prenchidos at� o tamanho 60, por�m ao decorrer do c�digo
            apenas o tamanho da palavra secreta ser� exibida */

        }
        locale old_locale(locale::classic()); //salva o estado local

        setlocale(LC_ALL,"portuguese");

            wcout<<"Voc� tem: "<<tempoMax / 60 << "m "<<tempoMax % 60<<"s "<<"para adivinhar a palavra"<<endl;
            wcout<<"O jogo come�a em: "<<endl;

        locale::global(old_locale); //volta para linguagem de escopo global
        
        while( intime > 0 ){

            wcout << intime << "\r" << flush;

            sleep(1);

            intime --;

        }
        
        system("cls");

        clock_t tempo_inicial = clock(); // nessa parte do jogo estamos colocando no tempo inicial a informa��o do tempo em que o jogo come�ou a executar.

        while((vidas > 0) && (acertos < tamanho)) //loop principal onde roda o jogo.
        {  setlocale(LC_ALL,"portuguese.1252");
            checkTime( tempo_inicial, tempoMax); //manda info do tempo inicial, e o tempo max determinado no inicio da fun��o.
            
                
                wcout<<"Categoria: "<<categoria<<endl;

                wcout<<"Vidas restante: "<<vidas<<endl;

                wcout<<"A palavra tem-"<<tamanho<<"-caracter"<<endl;

                wcout<<"letras usadas: ";

                for( i = 0; i < 60; i ++){
                    if(p_usada[i] != '-'){
                        wcout<<trollin[i]<<"-";
                    }
                    //Esse bloco mostra na tela as palavras que o jogador utilizou.
                }

            
                    wcout<<"\n";

                    wcout << "  _______       \n";
                    wcout << " |/      |      \n";
                    wcout << " |      " << (errou >= 1 ? '(' : ' ') << (errou >= 3 ? '_' : ' ') << (errou >= 6 ? ')' : ' ') << "  \n";
                    wcout << " |      " << (errou >= 9 ? '\\' : ' ') << (errou >= 12 ? '|' : ' ') << (errou >= 14 ? '/' : ' ') << "  \n";
                    wcout << " |       " << (errou >= 16 ? '|' : ' ') << "     \n";
                    wcout << " |      " << (errou >= 18 ? '/' : ' ') << " " << (errou >= 19 ? '\\' : ' ') << "   \n";
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
                    trollin[i1] = 'X';
                    for(i = 0; i < tamanho; i ++)
                    {

                        if (palavraSing[i] == chute[0]){
                            acerto = true;
                            forca[i] = palavraSing[i];
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

                singGanhou();

            }else{

                singPerdeu();

            }



}

string escolherAleatorio( const vector<::string> & lista ){ // & passa dados por referencia n�o por valor. const n�o permite que a fun��o altere os dados.

    int indiceAleatorio = rand() % lista.size(); // rand() gera um numero entre 0 e o RAND_MAX,lista.size retorna a quantidade de elementos dentro da lista.
    // ent�o suponhamos rand() == 7 e lista.size() == 2, teriamos o m�dulo de 7 % 2 = 1, assim o indice aleatorio seria 1.

    return lista[indiceAleatorio]; // retorna um indice aleatorio. 

}

pair<string, string> BancodePalavras(){

   
    srand(time(nullptr)); // Inicializa o gerador de n�meros aleat�rios, para garantir que rand() gere um n�mero pseudoaleatorio a cada execu��o.

    vector<::string> categorias = {"Animais", "Frutas","Cidades_brasileira","Instrumentos"};
    vector<::string> nomeAnimais = {"elefante", "girafa", "cachorro", "gato", "leao", "tigre", "coelho", "cavalo", "cavalo", "panda", "pinguim","zebra", "macaco", "urso", "rinoceronte", "canguru", "gorila", "jacare", "sapo", "papagaio", "baleia", "polvo", "cisne", "tartaruga", "caranguejo", "raposa", "peixe_boi", "suricato", "golfinho", "aguia", "foca", "lobo", "panda_vermelho", "pinguim", "elefante_marinho", "leao_marinho", "tucano", "arara", "chimpanze", "puma", "jaguatirica", "tamandua", "texugo", "iaque", "anta", "orangotango", "gnu", "ovelha", "girino"};
    vector<::string> nomeFrutas = {"maca", "banana", "laranja", "morango", "melancia", "pera", "uva", "abacaxix", "manga", "limao", "abacate","acelora","amora","caju","caqui","caqui","carambola","cereja","coco","damasco","framboesa","goiaba","jabuticaba","jaca","kiwi","pera","pessego","pessego","pitaya","roma","tangerina"};
    vector<::string> nomeCidades = {"sao_paulo", "rio_de_janeiro", "brasilia", "salvador", "fortaleza", "belo_horizonte", "manaus", "curitiba", "recife", "porto alegre", "belem", "goiania", "campinas", "sao luis", "guarulhos", "sao goncalo", "maceio", "duque de caxias", "natal", "teresina", "campo grande", "joao pessoa", "sao_bernardo_do_campo", "osasco", "santo_andre", "jaboatao_dos_guararapes", "ribeirao_preto", "contagem", "sao_jose_dos_campos", "uberlandia", "sorocaba", "cuiaba", "feira_de_santana", "aracaju", "joinville", "londrina", "niteroi", "ananindeua", "belford_roxo", "campos_dos_goytacazes", "sao_joao_de_meriti", "carapicuiba", "ponta_grossa", "maua", "macapa", "vitoria", "montes claros"};
    vector<::string> nomeInstrumentos = {"violao", "guitarra", "piano", "bateria", "baixo", "violino", "saxofone", "flauta", "trompete", "teclado", "acordeao","ukulele", "clarinete", "gaita", "cello", "bandolim", "oboe", "cavaquinho", "bongo", "marimba", "harpa"};

    string categoriaEscolhida = escolherAleatorio(categorias); //manda para o seletor de indice aleatorio, para assim escolher uma categoria aleatoria.
    string nomeEscolhido;

    if ( categoriaEscolhida == "Animais"){ //esse bloco manda de acordo com a categoria escolhida aleatoriamente escolher dentro dessa categoria um nome.

        nomeEscolhido = escolherAleatorio(nomeAnimais); //aqui esta mandando por eemplo, escolher aleatoriamente dentro do vector nomeAnimais.

    }else if ( categoriaEscolhida == "Frutas"){
 
        nomeEscolhido = escolherAleatorio(nomeFrutas);

    }else if ( categoriaEscolhida == "Cidades_brasileira"){

        nomeEscolhido = escolherAleatorio(nomeCidades);
        
    }else if ( categoriaEscolhida == "Instrumentos"){

        nomeEscolhido = escolherAleatorio(nomeInstrumentos);
    }


    return make_pair(nomeEscolhido, categoriaEscolhida);

}

bool chuteRepetido(wchar_t caracter){ // recebe informa��o do chute do jogo.

        for( i = 0; i <60; i ++) {

            if ( p_usada[i] == caracter){
                
                return true;//chute repetido.
            }
            
        }

    return false; //chute valido.


}

void checkTime( clock_t tempo_inicial, int tempoMax){
    clock_t tempo_atual = clock(); //pega o tempo atual desde a execu��o do jogo.
    double tempo_decorrido = double(tempo_atual - tempo_inicial) / CLOCKS_PER_SEC; // gera o tempo decorrido, com tempo atual menos o inicial dividindo por quantidade de clocks por segundos.
    double tempo_restante = tempoMax - tempo_decorrido; //calcula o tempo restante, baseado no tempo maximo determinado menos o decorrido, ai da para saber quanto resta.

    int minutos = int( tempo_restante) / 60;  //sabendo quanto resta da para calcular minutos e segundos.
    int segundos = int (tempo_restante) % 60;

    wcout<<"Tempo restante: "<<minutos<<"m "<<segundos<< "s "<<endl; //mostra na tela o time.

    if ( tempo_decorrido >= tempoMax){ //bloco que verifica se o tempo j� excedeu o tempo maximo, caso sim ele vai levar o jogo para uma fun��o que vai terinar o jogo.

       if (palavra[0] != '\0'){

         tempoEsgotado();

         }else{

        singTimeout();

        }

    }
}

void tempoEsgotado(){

    system("cls");


        wcout << "TEMPO ESGOTADO "<<endl;
        wcout<<"A palavra era: "<<palavra<<endl;
        wcout << "  _____          __  __ ______      \n";
        wcout << " / ____|   /\\   |  \\/  |  ____|  \n";
        wcout << "| |  __   /  \\  | \\  / | |__   \n";
        wcout << "| | |_ | / /\\ \\ | |\\/| |  __|    \n";
        wcout << "| |__| |/ ____ \\| |  | | |____   \n";
        wcout << " \\_____/_/    \\_\\_|  |_|______| \n";

        wcout << "  _____      ________ _____  \n";
        wcout << " / __ \\ \\    / /  ____|  __ \\ \n";
        wcout << "| |  | \\ \\  / /| |__  | |__) | \n";
        wcout << "| |  | |\\ \\/ / |  __| |  _  /  \n";
        wcout << "|_|  | | \\  /  |  |___| \\ \\  \n";
        wcout << " \\____/   \\/   |______|_|  \\_\\ \n";

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
        

        wcout << "  _____          __  __ ______      \n";
        wcout << " / ____|   /\\   |  \\/  |  ____|  \n";
        wcout << "| |  __   /  \\  | \\  / | |__   \n";
        wcout << "| | |_ | / /\\ \\ | |\\/| |  __|    \n";
        wcout << "| |__| |/ ____ \\| |  | | |____   \n";
        wcout << " \\_____/_/    \\_\\_|  |_|______| \n";

        wcout << "  _____      ________ _____  \n";
        wcout << " / __ \\ \\    / /  ____|  __ \\ \n";
        wcout << "| |  | \\ \\  / /| |__  | |__) | \n";
        wcout << "| |  | |\\ \\/ / |  __| |  _  /  \n";
        wcout << "|_|  | | \\  /  |  |___| \\ \\  \n";
        wcout << " \\____/   \\/   |______|_|  \\_\\ \n";


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

 void singGanhou(){

    setlocale(LC_ALL,"portuguese");
         wcout<<"A palvra era: "<<palavraSing<<endl;
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

                singleplayer();

            }else if( opc == 2) 
            {
                system("cls");
                wcout<<"Obrigado por jogar meu jogo v3 "<<endl;

                exit(0); //indica que o progama se encerrou, biblioteca cstdlib
                    
            }


 }
void singPerdeu(){

    setlocale(LC_ALL,"portuguese");
    
        wcout<<"Poxa voc� perdeu e foi enfocardo ;-;-; ";
        wcout<<"A palavra era: "<<palavraSing<<endl;
        

        wcout << "  _____          __  __ ______      \n";
        wcout << " / ____|   /\\   |  \\/  |  ____|  \n";
        wcout << "| |  __   /  \\  | \\  / | |__   \n";
        wcout << "| | |_ | / /\\ \\ | |\\/| |  __|    \n";
        wcout << "| |__| |/ ____ \\| |  | | |____   \n";
        wcout << " \\_____/_/    \\_\\_|  |_|______| \n";

        wcout << "  _____      ________ _____  \n";
        wcout << " / __ \\ \\    / /  ____|  __ \\ \n";
        wcout << "| |  | \\ \\  / /| |__  | |__) | \n";
        wcout << "| |  | |\\ \\/ / |  __| |  _  /  \n";
        wcout << "|_|  | | \\  /  |  |___| \\ \\  \n";
        wcout << " \\____/   \\/   |______|_|  \\_\\ \n";

        wcout<<"Jogar novamente? "<<endl;
            wcout<<"[1] jogar novamente "<<endl;
            wcout<<"[2] Sair "<<endl;
            wcin>>opc;

            if (opc == 1)
            {

                singleplayer();

            }else{
                    
                system("cls");

                    wcout<<"Obrigado por jogar meu jogo v3 "<<endl;

                    exit(0); //indica que o progama se encerrou, biblioteca cstdlib

            }




}
void singTimeout(){
    
    system("cls");


        wcout << "TEMPO ESGOTADO "<<endl;
        wcout<<"A palavra era: "<<palavraSing<<endl;
        wcout << "  _____          __  __ ______      \n";
        wcout << " / ____|   /\\   |  \\/  |  ____|  \n";
        wcout << "| |  __   /  \\  | \\  / | |__   \n";
        wcout << "| | |_ | / /\\ \\ | |\\/| |  __|    \n";
        wcout << "| |__| |/ ____ \\| |  | | |____   \n";
        wcout << " \\_____/_/    \\_\\_|  |_|______| \n";

        wcout << "  _____      ________ _____  \n";
        wcout << " / __ \\ \\    / /  ____|  __ \\ \n";
        wcout << "| |  | \\ \\  / /| |__  | |__) | \n";
        wcout << "| |  | |\\ \\/ / |  __| |  _  /  \n";
        wcout << "|_|  | | \\  /  |  |___| \\ \\  \n";
        wcout << " \\____/   \\/   |______|_|  \\_\\ \n";
       

        wcout<<"Jogar novamente? "<<endl;
            wcout<<"[1] jogar novamente "<<endl;
            wcout<<"[2] Sair "<<endl;
            wcin>>opc;

            if (opc == 1)
            {

               singleplayer();

            }else{
                    
                system("cls");

                    wcout<<"Obrigado por jogar meu jogo v3 "<<endl;

                    exit(0); //indica que o progama se encerrou, biblioteca cstdlib

            }



    
}