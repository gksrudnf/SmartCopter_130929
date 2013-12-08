#pragma once
#include <Arduino.h>
#include <math.h>

#define BAUD_RATE 9600

/* Note
 �����ʹ� �ϳ��� ���ͺ��� �����ؾ��Ѵ°�? �ƴϸ� 4���� ���Ͱ��� ��δ� ���Ź޾ƾ� �ϴ°�?
 4���� ���ʹ� ���� ����ϰ� �ֱ������� ����Ǿ� ���۵Ǿ�����. ��, 4���� ���� ���ÿ� ���۵Ǵ� ���� �´�.
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

