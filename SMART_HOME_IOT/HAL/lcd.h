/*
 * lcd.h
 *
 *  Created on: Oct 7, 2017
 *      Author: Mostafa
 */
#include<util/delay.h>
#include<avr/io.h>
#define lcd_rs_pin   6
#define lcd_enable_pin 7
#define lcd_d4 4
#define lcd_d5 5
#define lcd_d6 6
#define lcd_d7 7
#define lcd_data_port PORTB
#define lcd_control_port PORTC
#define lcd_control_reg DDRC
#define lcd_data_reg DDRB
#define clr_bit(reg,index)   (reg&=(~(1<<index)))
#define set_bit(reg,index)   (reg|=(1<<index))

void lcd_inti(void);
void lcd_send_command(char cmd);
void lcd_send_char(char value);
void lcd_send_data(char data);
void lcd_goto(char y, char x);
void lcd_clear_screen(void);
void lcd_print(char *string);
