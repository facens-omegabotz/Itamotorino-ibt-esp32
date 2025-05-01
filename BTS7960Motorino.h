#ifndef BTS7960Motorino_h
#define BTS7960Motorino_h

#include "Arduino.h"

class BTS7960Motorino
{
public:
  BTS7960Motorino(int pinRPWM_M1, int pinLPWM_M1, int pinRPWM_M2, int pinLPWM_M2);
  void setupPWM(int channelRPWM_M1, int channelLPWM_M1,
                int channelRPWM_M2, int channelLPWM_M2,
                int freq = 1000, int resolution = 8);
  void setSpeeds(int m1, int m2);

private:
  int _pinRPWM_M1, _pinLPWM_M1;
  int _pinRPWM_M2, _pinLPWM_M2;
  int _channelRPWM_M1, _channelLPWM_M1;
  int _channelRPWM_M2, _channelLPWM_M2;
};

#endif // BTS7960Motorino_h