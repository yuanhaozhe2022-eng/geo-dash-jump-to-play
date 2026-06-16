#include <Wire.h>
#include <MPU6050.h>

//uses mpu6050
MPU6050 mpu;
bool jumped = false;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
}

void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  float accel_z = az / 16384.0;

  Serial.println(accel_z);

  if (accel_z > 1.5 && !jumped) {
    Serial.println("JUMP");
    jumped = true;
    delay(300);
  } else if (accel_z < 1.2) {
    jumped = false;
  }
}