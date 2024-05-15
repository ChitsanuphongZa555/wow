#include <Adafruit_MCP3008.h>


#define NUM_SENSORS 8  //จำนวนเซนเซอร์
int F[NUM_SENSORS];
int REF[NUM_SENSORS];
int LastError;
int x = 0;
int sensor = A0;
Adafruit_MCP3008 adc;
//กลางวัน//
// int MinValue[NUM_SENSORS] = {297,239,349,340,222,240,311,261};
// int MaxValue[NUM_SENSORS] = {988,985,988,989,982,986,989,984};
//กลางคืน//
// int MinValue[NUM_SENSORS] = { 230, 164, 242, 254, 162, 192, 257, 186 };
// int MaxValue[NUM_SENSORS] = { 987, 982, 986, 987, 979, 986, 988, 980 };
//สนามเเข่ง///
// int MaxValue[NUM_SENSORS] = { 39, 37, 36, 36, 38, 37, 39,uy
///สนามเตรียม///
// int MaxValue[NUM_SENSORS] = {40,38,37,37,39,38,39,39};
// int MinValue[NUM_SENSORS] = {720,663,626,551,653,691,746,700};
//สนามซ้อม//
// int MaxValue[NUM_SENSORS] = { 42, 41, 38, 38, 40, 40, 41, 41 };
// int MinValue[NUM_SENSORS] = { 729, 696, 640, 591, 658, 693, 750, 698 };

// int MinValue[NUM_SENSORS] = { 192, 158, 203, 207, 141, 149, 163, 141 };
// int MaxValue[NUM_SENSORS] = { 990, 986, 988, 989, 983, 985, 989, 983 };
//now//
// int MinValue[NUM_SENSORS] = { 194, 178, 208, 234, 161, 147, 182, 161 };
// int MaxValue[NUM_SENSORS] = { 987, 984, 987, 988, 984, 984, 987, 982 };
//newสนาม//
// int MinValue[NUM_SENSORS] = { 172, 154, 186, 209, 133, 130, 168, 160 };
// int MaxValue[NUM_SENSORS] = { 992, 989, 991, 992, 989, 989, 991, 988 };
//newสนมสอง//
int MaxValue[NUM_SENSORS] = {157,140,160,158,136,131,172,147};
int MinValue[NUM_SENSORS] = {989,985,989,990,985,988,988,984};

void setup() {
  Serial.begin(9600);
  PHONG_begin();

  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  delay(100);
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  delay(100);
  Serial.println("ready");
  OK();
  Serial.println("OK");
  AutoRef();
  delay(500);
  // SerialF();
  // SerialCalibrate();
  // ShowCalibrate();

  // Motor(100, 100);
  // delay(1000);
  // MotorStop();

  // TrackTime(baseSpeed, Kp(ปรับขึ้นทีละ 0.01), Kd(ปรับขึ้นทีละ 0.1), delay(milli second))
  // r = right
  // l = left
  // p = pass
  // s = stop

  // TrackTime(100, 0.035, 0.7, 5000);

  ////
  //Test//
  // TrackCross(140, 0.035, 0.7, 'l');
  // TrackCross(140, 0.035, 0.7, 'l');
  // TrackCross(140, 0.035, 0.7, 'l');
  // TrackCross(150, 0.075, 0.99, 'r');
  // TrackCross(110, 0.045, 0.99, 'r');
  // TrackCross(110, 0.045, 0.99, 'l');
  // TrackCross(100, 0.03, 0.7, 'l');
  // TrackCross(100, 0.03, 0.7, 'r');
  // TrackCross(100, 0.03, 0.7, 'p');
  // TrackCross(100, 0.03, 0.7, 'r');
  // TrackCross(100, 0.03, 0.7, 'l');
  // TrackTime(210, 0.15, 0.99, 1250);
  // TrackTime(230, 0.15, 0.99, 300);
  // TrackTime(200, 0.13, 0.99, 6200);
  // TrackTime(150, 0.07, 0.99, 1000);
  // TrackTime(200, 0.13, 0.99, 6200);
  // TrackTime(210, 0.15, 0.99, 1550);

  // eye(100, 0.05, 0.9,'l');
  // TrackCross(100, 0.03, 0.7, 'r');
  // TrackCross(100, 0.03, 0.7, 'r');
  // TrackCross(100, 0.03, 0.7, 'r');

  //test 2 backup
  // TrackCross(120, 0.035, 0.75, 'r');
  // TrackCross(120, 0.035, 0.75, 'l');
  // TrackCross(120, 0.035, 0.75, 'p');
  // TrackCross(120, 0.035, 0.75, 'l');
  // TrackCross(150, 0.07, 0.99, 'l');
  // TrackCross(120, 0.035, 0.75, 'l');
  // TrackCross(120, 0.04, 0.75, 'l');
  // TrackTime(230, 0.015, 0.99, 800);
  // TrackTime(220, 0.175, 0.99, 200);
  // TrackTime(200, 0.015, 0.99, 6200);
  // TrackTime(150, 0.07, 0.99, 1000);
  // TrackTime(200, 0.015, 0.99, 6200);
  // TrackTime(210, 0.015, 0.99, 2500);
  // TrackTime(250, 0.015, 0.99, 2500);
  //

  //TEST2//
  // TrackCross(170, 0.06, 0.9, 'r');
  // TrackCross(150, 0.06, 0.9, 'l');
  // TrackCross(190, 0.06, 0.9, 'p');
  // TrackCross(200, 0.06, 0.9, 'l');
  // TrackCross(110, 0.09, 0.9, 'l');
  // TrackCross(190, 0.06, 0.9, 'l');
  // TrackCross(190, 0.06, 0.9, 'l');
  // TrackTime(220, 0.06, 0.9, 800);
  // TrackTime(230, 0.06, 0.9, 200);
  // TrackTime(240, 0.15, 0.9, 6200);
  // TrackTime(200, 0.09, 0.9, 2000);
  // TrackTime(240, 0.15, 0.9, 6200);
  // TrackTime(250, 0.06, 0.9, 1000);
  //
  //test3//
  // TrackCross(150, 0.06, 0.9, 'p');
  // TrackTime(240, 0.16, 1.9, 6050);
  // TrackTime(180, 0.06, 0.9, 1200);
  // TrackTime(200, 0.16, 1.7, 3500);
  // TrackTime(120, 0.06, 0.9, 2000);
  // TrackCross(250, 0.07, 0.9, 'r');
  // TrackCross(250, 0.07, 0.9, 'r');
  // TrackCross(250, 0.07, 0.9, 'r');
  // TrackCross(250, 0.07, 0.9, 'r');
  // TrackCross(250, 0.07, 0.9, 'r');
  // TrackCross(250, 0.07, 0.9, 'r');
  // TrackTime(250, 0.07, 0.9, 1500);
  //
  //test4//
  // TrackCross(180, 0.06, 0.95, 'p');
  // TrackTime(225, 0.075, 0.95, 750);
  // TrackTime(200, 0.06, 0.9, 2000);
  // TrackTime(230, 0.065, 0.95, 4000);
  // TrackTime(150, 0.06, 0.95, 1500);
  // TrackTime(220, 0.078, 0.95, 4200);
  // TrackTime(140, 0.065, 0.95, 1000);
  // TrackTime(250, 0.065, 0.95, 1000);
  // TrackCross(140, 0.07, 0.9, 'r');
  // TrackCross(200, 0.065, 0.9, 'r');
  // TrackCross(200, 0.065, 0.9, 'r');
  // TrackCross(200, 0.065, 0.9, 'r');
  // TrackCross(200, 0.065, 0.9, 'r');
  // TrackCross(200, 0.065, 0.9, 'r');
  // TrackTime(250, 0.075, 0.95, 1000);

  //testeye //
  // eye(150, 0.06, 0.9);
  // extra_eye();
  //eye//
  // TrackTime(200, 0.075, 1.0, 250);
  // TrackTime(220, 0.075, 1.0, 450);
  // eye(160, 0.035, 0.9);
  // extra_eye();
  // TrackTime(180, 0.055, 0.9, 2700);
  // TrackTime(240, 0.06, 0.9, 1800);
  // TrackTime(140, 0.075, 0.9, 1700);
  // TrackTime(240, 0.06, 0.9, 2100);
  // TrackTime(180, 0.055, 0.9, 2700);
  // TrackTime(200, 0.06, 0.9, 1000);
  // TrackTime(230, 0.06, 0.9, 500);
  // TrackTime(200, 0.075, 1.0, 500);
  // TrackTime(170, 0.06, 0.9, 500);
  // TrackCross(200, 0.6, 0.9, 'r');
  // TrackCross(150, 0.04, 0.9, 'l');
  // TrackCross(150, 0.04, 0.9, 'p');
  // TrackCross(140, 0.075, 0.9, 'l');
  // TrackTime(150, 0.06, 0.9, 1000);
  // TrackCross(150, 0.06, 0.9, 'l');
  // TrackCross(150, 0.06, 0.9, 'p');
  // TrackCross(150, 0.06, 0.9, 'l');
  // TrackCross(150, 0.06, 0.9, 'r');
  // TrackTime(200, 0.06, 0.9, 1000);
  //TESTWOW//
  // TrackTime(230, 0.06, 0.9, 1000);
  // TrackTime(210, 0.05, 0.9, 1000);
  // TrackTime(200, 0.06, 0.9, 500);
  // TrackTime(180, 0.05, 0.9, 4700);
  // TrackTime(150, 0.06, 0.9, 1350);
  // TrackTime(200, 0.06, 0.9, 3000);
  // TrackTime(220, 0.06, 0.9, 1000);
  // TrackTime(150, 0.05, 0.9, 1300);
  // TrackTime(200, 0.05, 0.9, 1000);
  // TrackCross(150, 0.06, 0.9, 'r');
  // TrackCross(180, 0.06, 0.9, 'l');
  // TrackCross(150, 0.06, 0.9, 'p');
  // TrackCross(150, 0.06, 0.9, 'l');
  // TrackTime(150, 0.06, 0.9, 2100);
  // TrackCross(150, 0.06, 0.9, 'l');
  // TrackCross(150, 0.06, 0.9, 'p');
  // TrackCross(150, 0.06, 0.9, 'l');
  // TrackCross(150, 0.06, 0.9, 'r');
  // TrackTime(230, 0.06, 0.9, 2000);
  //TESTWOWSECOUND//
  // TrackTime(250, 0.06, 0.9, 700);
  // TrackTime(220, 0.05, 0.9, 800);
  // TrackTime(150, 0.06, 0.9, 500);
  // TrackTime(160, 0.06, 0.9, 700);
  // TrackTime(180, 0.06, 0.9, 2500);
  // TrackTime(240, 0.06, 0.9, 1700);
  // TrackTime(150, 0.06, 0.9, 2000);
  // TrackTime(240, 0.06, 0.9, 2000);
  // TrackTime(180, 0.06, 0.9, 2500);
  // TrackTime(160, 0.06, 0.9, 800);
  // TrackTime(250, 0.06, 0.9, 300);
  // TrackTime(240, 0.06, 0.9, 300);
  // TrackTime(220, 0.06, 0.9, 300);
  // TrackTime(200, 0.06, 0.9, 300);
  // TrackCross(150, 0.06, 0.9, 'r');
  // TrackCross(180, 0.06, 0.9, 'l');
  // TrackCross(150, 0.06, 0.9, 'p');
  // TrackCross(150, 0.06, 0.9, 'l');
  // TrackTime(170, 0.065, 0.9, 1800);
  // TrackCross(150, 0.06, 0.9, 'l');
  // TrackCross(150, 0.06, 0.9, 'p');
  // TrackCross(150, 0.06, 0.9, 'l');
  // TrackCross(150, 0.06, 0.9, 'r');
  // TrackTime(230, 0.06, 0.9, 2000);
  //TEST??
  // TrackTime(250, 0.06, 0.9, 700);
  // TrackTime(220, 0.05, 0.9, 800);
  // TrackTime(150, 0.06, 0.9, 500);
  // TrackTime(160, 0.06, 0.9, 700);
  // TrackTime(180, 0.06, 0.9, 2500);
  // TrackTime(240, 0.06, 0.9, 1700);
  // TrackTime(150, 0.06, 0.9, 2000);
  // TrackTime(240, 0.06, 0.9, 2000);
  // TrackTime(180, 0.06, 0.9, 2500);
  // TrackTime(160, 0.06, 0.9, 800);
  // TrackTime(250, 0.06, 0.9, 300);
  // TrackTime(240, 0.06, 0.9, 300);
  // TrackTime(220, 0.06, 0.9, 300);
  // TrackTime(200, 0.06, 0.9, 300)
  // TrackCross(150, 0.06, 0.9, 'r');
  // TrackCross(170, 0.065, 0.95, 'l');
  // TrackCross(180, 0.065, 0.95, 'p');
  // TrackCross(180, 0.065, 0.95, 'l');
  // TrackTime(180, 0.07, 0.95, 1800);
  // TrackCross(180, 0.07, 0.95, 'l');
  // TrackCross(170, 0.07, 0.95, 'p');
  // TrackCross(170, 0.07, 0.95, 'l');
  // TrackCross(170, 0.07, 0.95, 'r');
  // TrackTime(230, 0.06, 0.9, 2000);
  //NEWTEST//
  // TrackCross(150, 0.045, 0.45, 'p');
  // TrackTime(160, 0.045, 0.45, 300);
  // TrackTime(250, 0.05, 0.5, 500);
  // TrackTime(170, 0.045, 0.45, 1500);
  //NEWสนาม//
  // TrackCross(170, 0.05, 0.5, 'p');
  // onelineleftorright(170, 0.05, 0.5, 'l');
  // TrackCross(170, 0.05, 0.5, 'p');
  // onelineleftorright(150, 0.05, 0.5, 'p');
  // onelineleftorright(150, 0.05, 0.5, 'p');
  // Motor(120, 120);
  // delay(100);
  // Motor(120, 0);
  // delay(200);
  // Motor(120, 120);
  // delay(50);
  // Motor(0, 120);
  // delay(200);
  // onelineleftorright(160, 0.05, 0.5, 'p');
  // TrackTime(170, 0.05, 0.5, 2000);
  //NEWสนามสอง//
TrackCross(170, 0.05, 0.5, 'p');
TrackCross(170, 0.05, 0.5, 'p');
TrackCross(170, 0.05, 0.5, 'p');
TrackCross(170, 0.05, 0.5, 'p');
TrackCross(170, 0.05, 0.5, 'p');
TrackCross(170, 0.05, 0.5, 'p');
  //ค่าที่นิ่งที่สุด//
  // TrackTime(160, 0.05, 0.5, 10000);
  // TrackTime(170, 0.05, 0.5, 2000);
  // TrackTime(170, 0.045, 0.45, 5000);
}
// TrackTime(140, 0.045, 0.5, 18000);
// TrackTime(150, 0.03, 0.9, 20000);
//TESTWOW//

void loop() {
  // ReadSensor();
  MotorStop();
  // TrackCross(140, 0.06, 0.9, 's');
  // TrackTime(100, 0.045, 0.6, 500);
}
