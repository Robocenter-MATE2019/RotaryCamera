#pragma once

#include <Arduino.h>
#include <Servo.h>
#include "Timer.h"

class RotaryCamera {
public:
	RotaryCamera();
	void init(int8_t pin);
	void rotate(int8_t angle);
	~RotaryCamera();
private:
	Timer timer;
	uint8_t m_angle;
	Servo m_driver;
	uint8_t m_pinl; // Почему pinl??? 
	int8_t m_lastangle = 0;
};
