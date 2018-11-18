#include "RotaryCamera.h"

int8_t defAngle = 90; //так плохо. внеси в класс как static переменная или как просто член класса, и инициализируй в конструктукторе

RotaryCamera::RotaryCamera() // Должен принимать пин к которому должен атачиться переменная pinl
{
}

void RotaryCamera::init(int8_t pin) // init должна быть функция без аргументов
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
	if (angle != m_lastangle) //тернарным оператором выглядит красивее, почитай про них
	{
		m_lastangle = angle;
	}  // m_lastangle = angle != m_lastangle ? angle : m_lastangle
	if (timer.elapsed() > 30)
	{
		m_angle += m_lastangle;
		timer.start();
	}
	m_angle = constrain(m_angle, 25, 165); //внести в иф с таймером, ибо зачем дергать шим и что-то счиатать постоянно
	m_driver.write(m_angle); // Если что-то полезное происходит только после срабатываения таймера
}
