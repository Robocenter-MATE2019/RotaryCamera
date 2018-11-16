#include "RotaryCamera.h"

int8_t defAngle = 90;

RotaryCamera::RotaryCamera()
{
}

void RotaryCamera::init(int8_t pin)
{
	m_driver.attach(pin);
	timer.start();
	m_driver.write(defAngle);
	m_angle = defAngle;
}

RotaryCamera::~RotaryCamera()
{
	m_driver.detach();
}

void RotaryCamera::rotate(int8_t angle)
{	
	if (angle != m_lastangle)
	{
		m_lastangle = angle;
	}
	if (timer.elapsed() > 30)
	{
		m_angle += m_lastangle;
		timer.start();
	}
	m_angle = constrain(m_angle, 25, 165);
	m_driver.write(m_angle);
}
