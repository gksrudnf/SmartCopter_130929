#include "Motor.h"
#include "AndroidBrainConnector.h"

/** 2013/09/30							 **/
/** Step1 - **/
AndroidBrainConnector brain_conn;
Motor front_motor;
Motor left_motor;
Motor right_motor;
Motor rear_motor;

void setup()
{
	brain_conn.init();

	front_motor.init(8);
	left_motor.init(9);
	right_motor.init(11);
	rear_motor.init(12);
}

void loop()
{
	if( brain_conn.signal_read() )
	{
		//if(brain_conn.get_recv_data(0)==127) - configure 

		//else - general 
		front_motor.speed_control(brain_conn.get_recv_data(0));
		left_motor.speed_control(brain_conn.get_recv_data(1));
		right_motor.speed_control(brain_conn.get_recv_data(2));
		rear_motor.speed_control(brain_conn.get_recv_data(3));
	}
}

/** 2013/09/29							 **/
/** Android(Brain) - Motor Class Testing **/
/*
AndroidBrainConnector brain_conn;
Motor front_motor;
void setup()
{
	brain_conn.init();

	front_motor.init(8);
}

void loop()
{
	if( brain_conn.signal_read() )
	{
		//3 = +20
		int val = brain_conn.get_recv_data(3);

		front_motor.speed_control(val);
	}
}
*/
/** 2013/09/29							 **/
/** Serial Contorl - Motor Class Testing **/
/*
String incomingString;
Motor m;

void setup()
{
	m.init(8);
	Serial.begin(9600);
		
	//m2.init();
}


void loop()
{
	if(Serial.available())
	{
		char ch = Serial.read();

		if(ch != 10)
		{
			incomingString += ch;		
		}
		else
		{
			Serial.println(incomingString);
			int val = incomingString.toInt();

			if (val == 1 )
			{
				Serial.println("SpeedUp!");
				m.SpeedUp();
				Serial.println(m.get_speed());
			}
			else if(val == 2)
			{
				Serial.println("SpeedDown!");
				m.SpeedDown();
				Serial.println(m.get_speed());
			}
			else
			{
				Serial.println(m.get_speed());
			}
			incomingString = "";
		}
	}
}
*/