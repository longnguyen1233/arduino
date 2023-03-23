/*==========================//=================================================
  * Ten Tep      :        main.c
  * Tac Gia      :        www.hocdientu123.vn
  * Ngay         :        25-07-2019
  * Tom Tat      :        Chuong trinh dieu khien Led don.
==========================//=================================================*/
#include "main.h"
//=========================khai bao cac chan vao ra=========================//
#define  LED1  PIN_D0
#define  LED2  PIN_D1
//=========================khai bao cac bien va hang=========================//
//=========================khai bao cac ham==================================//
//=========================ham main===========================================//
void main()
{
   //dinh nghia chan LED la chan Output; =0 là Output, =1 la Input
   set_tris_d(0b00000000);// cho tat ca cac pin cua PORTD la ngo ra
   output_d(0xFF);
   while(TRUE)// vong lap vo tan
   {
      output_low(LED1);
      output_low(LED2);   //sang muc 0
      delay_ms(200);       //delay de nhin led sang
      output_high(LED1);
      output_high(LED2);   //sang muc 0
      delay_ms(200);       //delay de nhin led tat
   }
 }



