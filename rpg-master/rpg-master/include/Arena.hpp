#pragma once
#include "Character.hpp"
#include "Monsters.hpp"
#include <iostream>

class Arena
{

  Character& character;
  Monster& monster;

public:
  Arena(Character& character, Monster& monster);

  void fight();
  // Character and random monster fight
};