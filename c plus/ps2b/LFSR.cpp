/*
  Emmanuel Rosario
*/
#include <iostream>
#include <cmath>
#include "LFSR.hpp"
using namespace std;

// constructor to create LFSR with the given initial seed and tap
//which accepts a C++ String of 1 and 0 characters
LFSR::LFSR(std::string seed, int t)
{
   _seed = seed;
   _tap = t;
  
}
      
//int step() function of zero args which returns an int that will be a zero or a one
//instead of implementing the toString method
int LFSR::step()
{
   
  int seed_s = _seed.size();
  int bit_front = _seed[0];
  int tap_ = _seed[seed_s-_tap-1];
  int bit = bit_front ^ tap_;
  std::string _bit;
  _bit = std::to_string(bit);
  _seed.erase(0,1);
  // std::cout<<"erase"<<_seed<<std::endl;
  _seed += _bit;
  // std::cout<<"add  "<<_seed<<std::endl;
  return bit;
  
}
   
//call step() function and returns k-bit integer
int LFSR::generate(int k)
{
  int s = 0;
 
  for(int i= k;i>0; i--)
    {
      if(step() == 1)
      s += pow(2,i-1);
    }
  return s;

}

std::ostream& operator<<(std::ostream& out, LFSR& lsfr)
{
  out << lsfr._seed;
    return out;
}
