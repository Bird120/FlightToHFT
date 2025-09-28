//
// Created by bird on 24/09/25.
//

#ifndef UPMOVING_HPP
#define UPMOVING_HPP

#include "Board.hpp"
#include "Utilities.hpp"
#include <SFML/Graphics.hpp>

struct Upmoving
{
  Upmoving(float groundX_, float groundY_): groundX(groundX_), groundY(groundY_){}
  //Board board();
  bool upmoving = false;
  bool getMoving() const;

  //default || down
  float groundX;
  float groundY; // sol (y position)

  //up
  float seuil_ = 270.f;
  float sizePlayer = 140.f;


  // board check
  Board* currentboard_;
  Board* getBoard();
  bool availableBoard =  false;
  bool getAvailableBoard() const;


  float velocityY = 0.f;       // vertical speed
  float getVelocity() const;


  float gravity = 2000.f;       // speed in down(always positive)


  void setGravity(float value);
  float getGravity() { return gravity;}

  void setGroundY(float value);

  float getGroundY(){return groundY;}
  float getGroundX(){return groundX;}
  void keyPressed(const float& value);


};






#endif //UPMOVING_HPP
