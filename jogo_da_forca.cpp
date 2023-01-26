//PROTÓTIPO DE UMA JOGO DA FORCA
//JOGO ADAPTADO AO IDIOMA PORTUGUÊS PODENDO RECEBER PALAVRAS COM ACENTO GRÁFICOS

/*CABEÇALHO*/
#include<iostream>
#include<string>
#include<sstream>
#include<array>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<vector>
using namespace std;

//FUNÇÃO PRINCIPAL DO JOGO DA FORCA
void hangman(string palavra_secreta, int& erros){
//VARIÁVEIS
string palpite, nome;
size_t pos;
//PROCEDIMENTOS EXECUTÁVEIS
//ENTRADA DE DADOS
stringstream(palavra_secreta)>>nome;

//INICIALIZANDO A STRING CIFRADA
string nome_secreto(nome.length(), '*');
cout<<nome_secreto<<".\n";

//REMOVENDO HÍFENS E APOSTRÓFOS
//HÍFEN
palpite="-";
pos=nome.find(palpite);
if(pos>nome_secreto.length()){
pos=0;
                             }
else{
nome_secreto.replace(pos, palpite.length(), palpite);
//Substituindo multíplas ocorrências
while(string::npos>(pos=nome.find(palpite, pos))){ 
nome_secreto.replace(pos, palpite.length(), palpite);
++pos;
                                                  };
cout<< nome_secreto<<"\n";
    };
//APOSTRÓFO
palpite="'";
pos=nome.find(palpite);
if(pos>nome_secreto.length()){
pos=0;
                             }
else{
nome_secreto.replace(pos, palpite.length(), palpite);
//Substituindo multíplas ocorrências
while(string::npos>(pos=nome.find(palpite, pos))){ 
nome_secreto.replace(pos, palpite.length(), palpite);
++pos;
                                                  };
cout<< nome_secreto<<"\n";
    };

do{
//RECEBENDO DADOS DO USUÁRIO
start:
cout<<"Digite uma letra que está na palavra: ";
cin>>palpite;
pos=nome.find(palpite);

//EM CASO DE NÃO DETECÇÃO DE LETRAS RESETAMOS A VARIÁVEL DE CONTAGEM
if(pos>nome_secreto.length()){
pos=0;
erros++;
if(erros>4){
cout<<"Você cometeu 5 erros!!!\n";
return;
           };
goto start;
                             };

nome_secreto.replace(pos, palpite.length(), palpite);

//Substituindo multíplas ocorrências de uma mesma letra
while(string::npos>(pos=nome.find(palpite, pos))){ 
nome_secreto.replace(pos, palpite.length(), palpite);
++pos;

                                                  };
cout<< nome_secreto<<"\n";
  }while(nome_secreto!=nome);
};

int main(){
//SEMENTE PARA A GERAÇÃO DE NÚMEROS ALEÁTORIOS
srand(time(NULL));
//APRESENTAÇÃO
cout<<"Seja bem vindo ao jogo da forca!!!\n\nTemos uma palavra secreta que você deve adivinhar.\n\n5 erros o desclassificam.\n\nBoa sorte!!!\n";

//ABRINDO ARQUIVOS CONTENDO UMA LISTA DE PALAVRAS
ifstream arquivo;
arquivo.open("palavra.txt");

//VARIÁVEIS
int key, error;
string chosen_word, line;
vector<string> dictionary;

//CRIANDO UMA LISTA DE PALAVRAS
if(arquivo){
cout<<"OK!\nSe prepare!!!\n";
while(arquivo.eof()==false){
getline(arquivo, line);
dictionary.push_back(line);
                           };
           }
else{
cout<<"Erro ao ler o arquivo!\nFim de programa.\n";
exit(0);
    };

//ESCOLHENDO UMA PALAVRA ALEATORIAMENTE
key=rand()%dictionary.size();
chosen_word=dictionary[key];

//AJUSTANDO A VARIÁVEL DE CONTAGEM DE ERROS
error=0;

//INVOCANDO A FUNÇÃO PRINCIPAL DO JOGO
hangman(chosen_word, error);

//ENCERRANDO O JOGO
if(error<5)
cout<<"Parabéns!!!\n";
cout<<"A palavra secreta é "<<chosen_word<<".\n";
cout<<"Obrigado por jogar!!!\n";
return 0;
} 
