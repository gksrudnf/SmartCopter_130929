#include "AndroidBrainConnector.h"


AndroidBrainConnector::AndroidBrainConnector(void)
{
	recv_data = new int[4];
}


AndroidBrainConnector::~AndroidBrainConnector(void)
{
	free(recv_data);
}

void AndroidBrainConnector::init(void)
{
	Serial.begin(BAUD_RATE);
}

boolean AndroidBrainConnector::signal_read(void)
{
	if(Serial.available())
	{
		char buf[4];
		int read_cnt, index;
		
		for(int index=0; index<4; index++)
			recv_data[index] = 0;

		read_cnt = Serial.readBytes(buf, 4);	
		if( read_cnt != 4)
		{
			//error..
		}
		else
		{
			//Recived Data
			for(int index=0; index<4; index++)
				recv_data[index] = buf[index];
		}

		return true;
	}
	else
		return false;
}

int AndroidBrainConnector::get_recv_data(int offset)
{
	return recv_data[offset];
}
