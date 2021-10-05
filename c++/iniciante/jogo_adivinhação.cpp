#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int gen_random(){
  srand((unsigned) time(0));
  int randomNumber;
  for (int index = 0; index < 10; index++) {
    randomNumber = (rand() % 100) + 1;
}
return randomNumber;
}

bool isNumeric(string str) {
   for (int i = 0; i < str.length(); i++)
      if (isdigit(str[i]) == false)
         return false;
      return true;
}

int main (){

std::cout << "**************************************" << std::endl;
std::cout << "*Bem vindo ao jogo  da adivinhacao!!!*" << std::endl;
std::cout << "**************************************" << std::endl;

bool jogando = true;
int rodada = 1;
const int NUMERO_SECRETO = gen_random();
int pontos = 100;
int taxa_erro = 20;


while (jogando == true){


    if(pontos == 0 ){
        std::cout << "Você perdeu todos os pontos... tente novamente!" << std::endl;
        jogando = false;
        break;
    }

    std::cout << rodada << " rodada" << std::endl;
    string chute_str;

    if (rodada < 2){
        std::cout << "Digite seu chute: ";
        std::cin >> chute_str;
    }
    else{
        std::cout << "Digite seu próximo chute: ";
        std::cin >> chute_str;
    }

    bool check_input = isNumeric(chute_str);

    if (check_input == true && pontos > 0){

        rodada++;
        int chute = stoi(chute_str);
        int resto = abs(chute - NUMERO_SECRETO);
        bool acertou = chute == NUMERO_SECRETO;
        bool menor_que = chute < NUMERO_SECRETO;
        bool maior_que = chute > NUMERO_SECRETO;


        if(menor_que)
        {
          std::cout << std::endl; 
          std::cout << "O seu chute: " << chute << " foi menor do que o número secreto, agora você tem " << pontos-taxa_erro << " pontos" << std::endl; 
          pontos = pontos - taxa_erro; 
          std::cout << "======================================"<< std::endl; 
          std::cout << std::endl;}

        else if(maior_que)
        {
         std::cout << std::endl; 
         std::cout << "O seu chute: " << chute << " foi maior do que o número secreto, agora você tem " << pontos-20 << " pontos" <<  std::endl; 
         pontos = pontos - taxa_erro; 
         std::cout << "======================================"<< std::endl; 
         std::cout << std::endl;}

        else if (acertou) {std::cout << "Parabéns! você acertou e ganhou com " << pontos << " pontos!!!" << std::endl; jogando = false;}

    }
  
    else if(check_input == false && pontos > 0){
        std::cout << "Chute um número !" << std::endl;
    }
}
}
