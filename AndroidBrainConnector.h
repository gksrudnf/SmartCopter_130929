#pragma once
#include <Arduino.h>
#include <math.h>

#define BAUD_RATE 9600

/* Note
 데이터는 하나의 모터별로 수신해야한는가? 아니면 4개의 모터값을 모두다 수신받아야 하는가?
 4개의 모터는 아주 빈번하게 주기적으로 변경되어 전송되어진다. 즉, 4개의 값이 동시에 전송되는 것이 맞다.
*/
class AndroidBrainConnector
{
private:
	int* recv_data;

public:
	AndroidBrainConnector(void);
	~AndroidBrainConnector(void);

	/** Motor-Signal get **/
	int get_recv_data(int offset);

	/** Arduino Serial Library - Setting to start**/
	void init();

	/** protocol base-on data // 4byte
	 ** +---+---+---+---+
	 ** | 2 | 0 | -1| 2 |
	 ** +---+---+---+---+
	 ** return : decoded motor signal
	 **/
	boolean signal_read(void);
};

