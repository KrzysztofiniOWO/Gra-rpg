#include "Character.hpp"
#include "Monsters.hpp"
#include "RpgCommands.hpp"
#include "RpgControl.hpp"
#include "RpgViewer.hpp"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

std::unique_ptr<Character> CreateCharacter(std::string chara)
{
  if (chara == "warrior")
  {
    return std::make_unique<warrior>();
  }
  else if (chara == "hunter")
  {
    return std::make_unique<hunter>();
  }
  else
  {
    return std::make_unique<mage>();
  }
}

int main()
{

  std::string wczytywanie;
  std::cout << "Czy chcesz wczytać ostatnią gre? [tak, nie]" << std::endl;
  std::cin >> wczytywanie;

  if (wczytywanie == "tak")
  {
    std::fstream plik;
    plik.open("dane.txt", std::ios::in);

    int w;
    plik >> w;

    int h;
    plik >> h;

    std::string chara;
    plik >> chara;

    std::unique_ptr<Character> character = CreateCharacter(chara);

    int gold;
    plik >> gold;

    int princess;
    plik >> princess;

    std::string word;
    std::string words;

    for (int a = 0; a < h * w; a++)
    {
      plik >> word;
      words = words + word;
    }

    plik.close();


    RpgCommands board(w, h, *character);
    RpgViewer viewer(board);
    RpgControl game(board, viewer, words, gold, princess);
    game.play();
  }
  else
  {
    std::string chara;
    std::cout << "select your class [warrior, hunter, mage]" << std::endl;
    std::cin >> chara;

    std::string words = "A";


    std::unique_ptr<Character> character = CreateCharacter(chara);
    RpgCommands board(11, 11, *character);
    RpgViewer viewer(board);
    RpgControl game(board, viewer, words, 0, 0);
    game.play();
  }
  
  return 0;
}