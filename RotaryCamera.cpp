#include "RotaryCamera.h"

//class RotaryCamera {
//public:
//	RotaryCamera(uint8_t pin);
//	void init();
//	void rotate(int8_t angle);
//private:
//	uint8_t m_angle;
//	Servo m_driver;
//	uint8_t m_pinl;
//};

int8_t defAngle = 90;

RotaryCamera::RotaryCamera()
{
	timer.start();
}

void RotaryCamera::init(uint8_t pin)
{
	m_driver.attach(pin);
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
		if (timer.elapsed() > 30)
		{
			m_angle += m_lastangle;
			timer.start();
			m_lastangle = m_angle;
		}
	}
	
	m_driver.write(constrain(angle, 0, 180));
}
