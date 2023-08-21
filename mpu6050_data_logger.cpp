#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <unistd.h>
#include <time.h>

#define MPU6050_I2C_ADDRESS 0x68
#define ACCEL_XOUT_H        0x3B
#define ACCEL_XOUT_L        0x3C
#define ACCEL_YOUT_H        0x3D
#define ACCEL_YOUT_L        0x3E
#define ACCEL_ZOUT_H        0x3F
#define ACCEL_ZOUT_L        0x40

void delayMillis(unsigned int millis) {
    struct timespec sleepTime;
    sleepTime.tv_sec = millis / 1000;
    sleepTime.tv_nsec = (millis % 1000) * 1000000;
    nanosleep(&sleepTime, NULL);
}

int main(void) {
    wiringPiSetup();
    
    int fd = wiringPiI2CSetup(MPU6050_I2C_ADDRESS);
    if (fd == -1) {
        fprintf(stderr, "Failed to initialize I2C communication.\n");
        return 1;
    }
    
    FILE *file = fopen("mpu6050_data.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file for writing.\n");
        return 1;
    }
    
    fprintf(file, "Timestamp(ms)\tAccel_X\tAccel_Y\tAccel_Z\n");
    
    while (1) {
        int accel_x = (wiringPiI2CReadReg8(fd, ACCEL_XOUT_H) << 8) | wiringPiI2CReadReg8(fd, ACCEL_XOUT_L);
        int accel_y = (wiringPiI2CReadReg8(fd, ACCEL_YOUT_H) << 8) | wiringPiI2CReadReg8(fd, ACCEL_YOUT_L);
        int accel_z = (wiringPiI2CReadReg8(fd, ACCEL_ZOUT_H) << 8) | wiringPiI2CReadReg8(fd, ACCEL_ZOUT_L);
        
        struct timespec timestamp;
        clock_gettime(CLOCK_REALTIME, &timestamp);
        long long int timestamp_ms = timestamp.tv_sec * 1000 + timestamp.tv_nsec / 1000000;
        
        fprintf(file, "%lld\t%d\t%d\t%d\n", timestamp_ms, accel_x, accel_y, accel_z);
        fflush(file);
        
        delayMillis(100);  // Delay for 100 milliseconds
    }
    
    fclose(file);
    return 0;
}
