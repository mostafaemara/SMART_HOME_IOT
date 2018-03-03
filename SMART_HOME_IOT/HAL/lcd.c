/*
 * lcd.c
 *
 *  Created on: Oct 7, 2017
 *      Author: Mostafa
 */
#include"lcd.h"





void lcd_inti(void);
void lcd_send_command(char cmd);
void lcd_send_char(char value);
void lcd_send_data(char data);
void lcd_goto(char y, char x);
void lcd_clear_screen(void);
void lcd_print(char *string);



void lcd_inti(void)
{
	//inti lcd reg//
	lcd_data_reg|=0xF0;
	set_bit(lcd_control_reg,lcd_rs_pin);
	set_bit(lcd_control_reg,lcd_enable_pin);

//clear control port//
	clr_bit(lcd_control_port,lcd_rs_pin);
	clr_bit(lcd_control_port,lcd_enable_pin);

//clear Data port//
	clr_bit(lcd_data_port,lcd_d4);
	clr_bit(lcd_data_port,lcd_d5);
	clr_bit(lcd_data_port,lcd_d6);
	clr_bit(lcd_data_port,lcd_d7);


//inti LCD//
	lcd_send_command(0x28);
	lcd_send_command(0x0C);
	lcd_send_command(0x06);
	lcd_send_command(0x80);
	lcd_send_command(0x01);











}
void lcd_send_command(char cmd)
{
	clr_bit(lcd_control_port,lcd_rs_pin);
	lcd_send_char(cmd);




}

void lcd_send_char(char value )
{
//clear Data PORT//
clr_bit(lcd_data_port,lcd_d4);
clr_bit(lcd_data_port,lcd_d5);
clr_bit(lcd_data_port,lcd_d6);
clr_bit(lcd_data_port,lcd_d7);


lcd_data_port|=(value&0xF0);
lcd_control_port|=(1<<lcd_enable_pin);
_delay_us(2);
lcd_control_port&=~(1<<lcd_enable_pin);

//clear Data PORT//
clr_bit(lcd_data_port,lcd_d4);
clr_bit(lcd_data_port,lcd_d5);
clr_bit(lcd_data_port,lcd_d6);
clr_bit(lcd_data_port,lcd_d7);

lcd_data_port|=(value<<4)&(0xF0);
lcd_control_port|=(1<<lcd_enable_pin);
_delay_us(2);
lcd_control_port&=~(1<<lcd_enable_pin);
_delay_us(100);

}

void lcd_send_data(char data)
{
	set_bit(lcd_control_port,lcd_rs_pin);
	lcd_send_char(data);

		_delay_us(50);


}
void lcd_goto(char y, char x)
{


	char firstAddress[] = {0x80,0xC0,0x94,0xD4};
	lcd_send_command(firstAddress[y-1]+ x-1);
	_delay_ms(10);




}
void lcd_clear_screen(void){



	lcd_send_command(1);
	_delay_ms(10);



}
void lcd_print(char *string)
{
	int i = 0;

	while(string[i]!=0)
	{
		lcd_send_data(string[i]);
		i++;
	}
}

