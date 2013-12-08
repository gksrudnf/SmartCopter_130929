#include "Motor.h"


Motor::Motor()
{
	
}


Motor::~Motor(void)
{
	lib.detach();
}

void Motor::init(int _pin)
{
	pin = _pin;
	lib.attach(pin);
	
	max_speed = SPEED_MAX_STEP;
	min_speed = SPEED_MIN_STEP;
	cur_speed = SPEED_MIN_STEP;

	//1. 모터전원 연결이 정상적이다는 가정!
	//2. 모터전원 연결이 정상이라면 음악이 재생된다.
	//delay(1000);
	lib.write(20);
}


void Motor::SpeedUp()
{
	if( cur_speed >= SPEED_MAX_STEP)
	{
		//speed-step over..
		//cur_speed = SPEED_MIN_STEP;
	}
	else
	{
		cur_speed += 1;
		lib.write(cur_speed);
	}
}

void Motor::SpeedDown()
{
	if( cur_speed <= SPEED_MIN_STEP)
	{
		//speed-step 
		//cur_speed = SPEED_MAX_STEP;
	}
	else
	{
		cur_speed -= 1;
		lib.write(cur_speed);
	}
}

int Motor::get_speed()
{
	return cur_speed;
}

void Motor::speed_control(int step)
{
	if( step >= 0)
	{
		for(int i=0; i<step; i++)
			SpeedUp();
	}
	else
	{
		for(int i=0; i<abs(step); i++)
			SpeedDown();
	}
}


/** remove object **/
void Motor::pin_blink_check()
{
	pinMode(12, OUTPUT);

	digitalWrite(pin, HIGH);
	delay(500);
	digitalWrite(pin, LOW);
	delay(500);
}