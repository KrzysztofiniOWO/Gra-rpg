#pragma once
#include "RpgCommands.hpp"
#include <vector>

class RpgViewer
{

  RpgCommands& game;

public:
  RpgViewer(RpgCommands& game);

  void display() const;
  // Display our main board
};