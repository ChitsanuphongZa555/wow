int readPosition(int Track, int noise) {  //อ่านค่า Position
  unsigned char i, online = 0;
  unsigned long avg = 0;
  unsigned int sum = 0;
  static int last_value = 0;
  ReadCalibrate();
  for (i = 0; i < NUM_SENSORS; i++) {
    int values = F[i];
    if (values > Track) {
      online = 1;
    }
    if (values > noise) {
      avg += (long)(values) * (i * 1000);
      sum += values;
    }
  }
  if (!online) {
    if (last_value < (NUM_SENSORS - 1) * 1000 / 2) {
      return 0;
    } else {
      return (NUM_SENSORS - 1) * 1000;
    }
  }
  last_value = avg / sum;
  return last_value;
}

void PID(int Speed, float Kp, float Kd) {  // คำสั่ง PID
  int Pos = readPosition(250, 50);
  int Error = Pos - 3500;
  int PID_Value = (Kp * Error) + (Kd * (Error - LastError));
  LastError = Error;
  int LeftPower = Speed + PID_Value;
  int RightPower = Speed - PID_Value;
  if (LeftPower > 255) LeftPower = 255;
  if (LeftPower < 0) LeftPower = -100;
  if (RightPower > 255) RightPower = 255;
  if (RightPower < 0) RightPower = -100;
  Motor(LeftPower, RightPower);
}

void TrackCross(int Speed, float Kp, float Kd, char select) {  // PID เช็คแยก
  while (1) {
    PID(Speed, Kp, Kd);
    ReadCalibrate();
    if (F[2] > 550 && F[5] > 550) {
      break;
    }
  }

  if (select == 's') {
    MotorStop();
  } else if (select == 'p') {
    Motor(Speed, Speed);
    delay(100);
  } else if (select == 'l') {
    TurnLeft();
  } else if (select == 'r') {
    TurnRight();
  } else if (select == 'a') {
    TurnAround();
  }
}

void TrackTime(int Speed, float Kp, float Kd, int TotalTime) {  // Trackเส้นตามเวลาที่กำหนด
  unsigned long StartTime = millis();
  unsigned long EndTime = StartTime + TotalTime;
  while (millis() <= EndTime) {
    PID(Speed, Kp, Kd);
  }
}
void extra_eye() {
  while (1) {
    ReadSensor();
    if (F[7] < 300 || F[6] < 300) {
      // MotorStop();
      TurnLeft();
      TrackTime(150, 0.06, 0.9, 1000);
      break;
    }
  }
}
void eye(int Speed, float Kp, float Kd) {  // PID เช็คแยก
  while (1) {
    PID(Speed, Kp, Kd);
    ReadCalibrate();
    if (digitalRead(A0) == 0) {
      // MotorStop();
      Motor(0, 120);
      delay(210);
      Motor(255, 80);
      delay(300);
      Motor(120, 80);
      delay(20);
      break;
    }
  }
}
void eyel(int Speed, float Kp, float Kd, char select) {  // PID เช็คแยก
  while (1) {
    PID(Speed, Kp, Kd);
    ReadCalibrate();
    if (digitalRead(A0) == 0) {
      // Motor(0, 120);
      // delay(200);
      // Motor(120, 0);
      // delay(235);
      // Motor(120, 120);
      // delay(650);
      // Motor(60, 120);
      // delay(350);
      break;
    }
  }
  if (select == 's') {
    MotorStop();
  } else if (select == 'p') {
    Motor(Speed, Speed);
    delay(100);
  } else if (select == 'l') {
    TurnLeft();
  } else if (select == 'r') {
    TurnRight();
  }
}

void eyer(int Speed, float Kp, float Kd, char select) {  // PID เช็คแยก
  while (1) {
    PID(Speed, Kp, Kd);
    ReadCalibrate();
    if (F[2] > 550 && F[5] > 550 || digitalRead(A0) == 0) {
      Motor(120, 0);
      delay(225);
      Motor(0, 120);
      delay(248);
      Motor(120, 120);
      delay(125);
      Motor(0, 120);
      delay(230);
      TrackCross(100, 0.03, 0.7, 'select');
      break;
    }
  }
  if (select == 's') {
    MotorStop();
  } else if (select == 'p') {
    Motor(Speed, Speed);
    delay(100);
  } else if (select == 'l') {
    TurnLeft();
  } else if (select == 'r') {
    TurnRight();
  }
}


void TrackCrossOmaga(int Speed, float Kp, float Kd, char select) {  // PID เช็คแยก
  while (1) {
    PID(Speed, Kp, Kd);
    ReadCalibrate();
    if (F[6] > 450 && F[5] > 450) {
      break;
    }
  }
  if (select == 's') {
    MotorStop();
  } else if (select == 'p') {
    Motor(Speed, Speed);
    delay(100);
  } else if (select == 'l') {
    TurnLeft();
  } else if (select == 'r') {
    TurnRight2();
  }
}

void TrackCrossOmaga2(int Speed, float Kp, float Kd, char select) {  // PID เช็คแยก
  while (1) {
    PID(Speed, Kp, Kd);
    ReadCalibrate();
    if (F[2] > 450 && F[5] > 450) {
      break;
    }
  }
  if (select == 's') {
    MotorStop();
  } else if (select == 'p') {
    Motor(Speed, Speed);
    delay(100);
  } else if (select == 'l') {
    TurnLeft();
  } else if (select == 'r') {
    TurnRight2();
  }
}

void TrackCrossOmaga3(int Speed, float Kp, float Kd, char select) {  // PID เช็คแยก
  while (1) {
    PID(Speed, Kp, Kd);
    ReadCalibrate();
    if (F[2] > 450 && F[1] > 450) {
      break;
    }
  }
  if (select == 's') {
    MotorStop();
  } else if (select == 'p') {
    Motor(Speed, Speed);
    delay(100);
  } else if (select == 'l') {
    TurnLeft2();
  } else if (select == 'r') {
    TurnRight2();
  }
}
void degree90(int Speed, float Kp, float Kd) {  // PID เช็คแยก
  while (1) {
    PID(Speed, Kp, Kd);
    ReadCalibrate();
    Motor(0, 120);
    delay(200);
    break;
  }
}
void onelineleftorright(int Speed, float Kp, float Kd, char select) {  // PID เช็คแยก
  while (1) {
    PID(Speed, Kp, Kd);
    ReadCalibrate();
    if (F[1] > 550 && F[2] > 550 || F[7] > 550 && F[6] > 550) {
      break;
    }
  }
  if (select == 'l') {
    TurnLeft();
    TrackTime(150, 0.05, 0.5, 100);
  } else if (select == 'r') {
    TurnRight();
    TrackTime(150, 0.05, 0.5, 100);
  } else if (select == 'p'){
    Motor(Speed, Speed);
    delay(100);
  }else if (select == 's'){
    MotorStop();
  }
}