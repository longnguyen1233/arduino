/*==========================//=================================================
  * Ten Tep      :        main.c
  * Tac Gia      :        www.hocdientu123.vn
  * Ngay         :        25-07-2019
  * Tom Tat      :        Chuong trinh dieu khien Led don.
==========================//=================================================*/
#include "main.h"
//=========================khai bao cac chan vao ra=========================//
//=========================khai bao cac bien va hang=========================//
unsigned int8 i=0; 
unsigned int8 x;
//=========================khai bao cac ham==================================//
//=======================================ham main============================//
void main()
{
   //dinh nghia chan LED la chan Output; =0 là Output, =1 la Input
   set_tris_d(0b00000000);// cho tat ca cac pin (chan) cua PORTD la ngo ra
   output_d(0xFF);   //muc 1 tat het LED
   x=0xFF;
   while(TRUE)// vong lap vo tan
   {
    //==========SANG DAN TU LED1 DEN LED8====================//
       for(i=0;i<8;i++)
         {
           x=x<<1;            //dich trai 1 bit 0
           output_d(x);      //gan gia tri x cho PORTD
           delay_ms(300);
         }
   //==========TAT DAN TU LED1 DEN LED8====================//
       for(i=0;i<8;i++)
         {
           x=(x<<1)+1;           //dich trai va cong 1 de dich bit 1 vao
           output_d(x);         //gan gia tri x cho PORT1
           delay_ms(300);
         }  
   }
 }



