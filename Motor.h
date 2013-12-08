#include <Arduino.h>
#include <Servo.h>

#define SPEED_MIN_STEP 60
#define SPEED_MAX_STEP 180

/* Note
������ �ӵ��� �Ѵܰ� �����θ� ������ �� �ְ��� ������
���ڱ� Ƣ�°��� �����ϱ� �����̴�..
*/
class Motor
{
private:
	/** Speed-Related **/
	int max_speed;
	int min_speed;
	int cur_speed;

	/** Arduino Board Pin**/
	int pin;

	/** Arduino Motor Library - Motor Controll.. **/
	Servo lib; 
	
public:
	
	Motor(void);
	~Motor(void);

	/** Value of class Set/Get **/
	int get_speed();

	/** initialize 
		Under normal circumstances, playing music. **/
	void init(int _pin);

	/** The speed of the motor is achieved by step. **/
	void SpeedUp();		
	void SpeedDown();

	/** If positive, the speed-up / If negative, the speed down **/
	void speed_control(int step);

	/** Testing LED **/
	void pin_blink_check();
};

