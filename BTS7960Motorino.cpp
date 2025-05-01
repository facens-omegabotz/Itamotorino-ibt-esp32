#include "BTS7960Motorino.h"

BTS7960Motorino::BTS7960Motorino(int pinRPWM_M1, int pinLPWM_M1, int pinRPWM_M2, int pinLPWM_M2)
  : _pinRPWM_M1(pinRPWM_M1), _pinLPWM_M1(pinLPWM_M1), _pinRPWM_M2(pinRPWM_M2), _pinLPWM_M2(pinLPWM_M2)
{
  pinMode(_pinRPWM_M1, OUTPUT);
  pinMode(_pinLPWM_M1, OUTPUT);
  pinMode(_pinRPWM_M2, OUTPUT);
  pinMode(_pinLPWM_M2, OUTPUT);
}

void BTS7960Motorino::setupPWM(int channelRPWM_M1, int channelLPWM_M1,
                               int channelRPWM_M2, int channelLPWM_M2,
                               int freq, int resolution)
{
  _channelRPWM_M1 = channelRPWM_M1;
  _channelLPWM_M1 = channelLPWM_M1;
  _channelRPWM_M2 = channelRPWM_M2;
  _channelLPWM_M2 = channelLPWM_M2;

  ledcSetup(_channelRPWM_M1, freq, resolution);
  ledcSetup(_channelLPWM_M1, freq, resolution);
  ledcSetup(_channelRPWM_M2, freq, resolution);
  ledcSetup(_channelLPWM_M2, freq, resolution);

  ledcAttachPin(_pinRPWM_M1, _channelRPWM_M1);
  ledcAttachPin(_pinLPWM_M1, _channelLPWM_M1);
  ledcAttachPin(_pinRPWM_M2, _channelRPWM_M2);
  ledcAttachPin(_pinLPWM_M2, _channelLPWM_M2);
}

void BTS7960Motorino::setSpeeds(int m1, int m2)
{
  m1 = constrain(m1, -255, 255);
  m2 = constrain(m2, -255, 255);

  if (m1 >= 0)
  {
    ledcWrite(_channelRPWM_M1, m1);
    ledcWrite(_channelLPWM_M1, 0);
  }
  else
  {
    ledcWrite(_channelRPWM_M1, 0);
    ledcWrite(_channelLPWM_M1, -m1);
  }

  if (m2 >= 0)
  {
    ledcWrite(_channelRPWM_M2, m2);
    ledcWrite(_channelLPWM_M2, 0);
  }
  else
  {
    ledcWrite(_channelRPWM_M2, 0);
    ledcWrite(_channelLPWM_M2, -m2);
  }
}