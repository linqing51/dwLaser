//Biblioteca I2C para a disciplina de microcontroladores
//Autora: Mariana Cabral

#include "lib.h"
void init(void);
void start(void);
void stop(void);
void ack(void);
void nack(void);
void write(unsigned char dado);
unsigned char read(void);
void i2c_device_write(unsigned char slave ,unsigned char reg_add ,unsigned char dado);
unsigned char i2c_device_read(unsigned char slave, unsigned char reg_add);