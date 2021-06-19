#include <stm32f10x.h>
#include <delay.h>

//保留出处的情况下，你可以任意使用本项目文件.
//author:bihaiqiankun
//email:bhqk@bhqk.top
//project address:
//date: 2021/06/19 afternoon
//保留出处的情况下，你可以任意使用本项目文件.

//tone explain
//首字母为调名(C、G)、次数字为唱名(1234567按顺序对应doremifasolati)、再次字母为音调(dzg按顺序对应低中高音)、最后b为升高半调(没有b则不升).
//例如 c2zb 为"C调 re 中音 升高半度".

//tone define start
#define c1d 3817
#define c1db 3610
#define c2d 3401
#define c2db 3215
#define c3d 3030
#define c4d 2865
#define c4db 2703
#define c5d 2551
#define c5db 2410
#define c6d 2273
#define c6db 2145
#define c7d 2024
#define c1z 1912
#define c1zb 1805
#define c2z 1704
#define c2zb 1608
#define c3z 1517
#define c4z 1433
#define c4zb 1351
#define c5z 1276
#define c5zb 1203
#define c6z 1136
#define c6zb 1073
#define c7z 1012
#define c1g 956
#define c1gb 902
#define c2g 851
#define c2gb 803
#define c3g 759
#define c4g 716
#define c4gb 676
#define c5g 638
#define c5gb 602
#define c6g 568
#define c6gb 536
#define c7g 506  //C
#define g1d c5d
#define g1db c5db
#define g2d c6d
#define g2db c6db
#define g3d c7d
#define g4d c1z
#define g4db c1zb
#define g5d c2z
#define g5db c2zb
#define g6d c3z
#define g7d c4zb
#define g1z c5z
#define g1zb c5zb
#define g2z c6z
#define g2zb c6zb
#define g3z c7z
#define g4z c1g
#define g4zb c1gb
#define g5z c2g
#define g5zb c2gb
#define g6z c3g
#define g7z c4gb
#define g1g c5g
#define g1gb c5gb
#define g2g c6g
#define g2gb c6gb
#define g3g c7g  //G

#define p4 652
#define p6 978
#define p8 326
#define p16 163
#define bb 10

#define stop 0
//tone define end

//timer and pin explain
//TIM3 PA6
//TIM4 PB6

void beep(u32 per){
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_Period=per-1;
	TIM_TimeBaseInitStructure.TIM_Prescaler=72-1;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructure);
}

void beep_init(){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3|RCC_APB1Periph_TIM4,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC1Init(TIM3,&TIM_OCInitStructure);
	TIM_OC1Init(TIM4,&TIM_OCInitStructure);
	
	TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_OC1PreloadConfig(TIM4,TIM_OCPreload_Enable);
	
	TIM_Cmd(TIM3,ENABLE);
	TIM_Cmd(TIM4,ENABLE);
	TIM_SetCompare1(TIM3,100);
	TIM_SetCompare1(TIM4,100);	
}

int main(){
	delay_init();
	beep_init();
	
	//music body start
	while(1){
		beep(g4d);
		delay_ms(p8);
		beep(g6d);
		delay_ms(p8);
		beep(g3z);
		delay_ms(p4);
		beep(g3d);
		delay_ms(p8);
		beep(g5d);
		delay_ms(p8);
		beep(g2z);
		delay_ms(p4);//1
		beep(g6d);
		delay_ms(p8);
		beep(g3d);
		delay_ms(p8);
		beep(g6d);
		delay_ms(p8);
		beep(g2z);
		delay_ms(p8);
		beep(g1zb);
		delay_ms(p8);
		beep(g6d);
		delay_ms(p8);
		beep(g3d);
		delay_ms(p4);//2
		beep(g4d);
		delay_ms(p8);
		beep(g6d);
		delay_ms(p8);
		beep(g3z);
		delay_ms(p4);
		beep(g5d);
		delay_ms(p8);
		beep(g7d);
		delay_ms(p8);
		beep(g2z);
		delay_ms(p4);//3
		beep(g6d);
		delay_ms(p8);
		beep(g3d);
		delay_ms(p8);
		beep(g6d);
		delay_ms(p8);
		beep(g2z);
		delay_ms(p8);
		beep(g1zb);
		delay_ms(p4);
		delay_ms(p4);//4
		beep(g4d);
		delay_ms(p8);
		beep(g6d);
		delay_ms(p8);
		beep(g1z);
		delay_ms(p4/2);
		beep(g3z);
		delay_ms(p4/2);
		beep(g5d);
		delay_ms(p8);
		beep(g7d);
		delay_ms(p8);
		beep(g2z);
		delay_ms(p4/2);
		beep(g3z);
		delay_ms(p4/2);//5
		beep(g6d);
		delay_ms(p8);
		beep(g3d);
		delay_ms(p8);
		beep(g6d);
		delay_ms(p8);
		beep(g2z);
		delay_ms(p8);
		beep(g1zb);
		delay_ms(p8);
		beep(g6d);
		delay_ms(p8);
		beep(g3d);
		delay_ms(p4);//6
		beep(g4d);
		delay_ms(p8);
		beep(g6d);
		delay_ms(p8);
		beep(g1z);
		delay_ms(p4/2);
		beep(g3z);
		delay_ms(p4/2);
		beep(g5d);
		delay_ms(p8);
		beep(g7d);
		delay_ms(p8);
		beep(g2z);
		delay_ms(p4/2);
		beep(g3z);
		delay_ms(p4/2);//7
		beep(g6d);
		delay_ms(p8);
		beep(g3z);
		delay_ms(p8);
		beep(g6z);
		delay_ms(p8);
		beep(g2g);
		delay_ms(p8);
		beep(g1gb);
		delay_ms(p4);
		beep(g4zb);
		delay_ms(p8);
		beep(g5zb);
		delay_ms(p8);//8
		beep(g6z);
		delay_ms(p6);
		beep(stop);
		delay_ms(bb);
		beep(g6z);
		delay_ms(p8-bb);
		beep(g5zb);
		delay_ms(p6);
		beep(g4zb);
		delay_ms(p8);//9
		beep(g3z);
		delay_ms(p4);
		beep(g1zb);
		delay_ms(p8);
		beep(g2z);
		delay_ms(p8);
		beep(g1zb);
		delay_ms(p6);
		beep(stop);
		delay_ms(bb);
		beep(g1zb);
		delay_ms(p8-bb);//10
		beep(g2z);
		delay_ms(p4);
		beep(g4zb);
		delay_ms(p4);
		beep(g3z);
		delay_ms(p4);
		beep(g2z);
		delay_ms(p4);//11
		beep(g1zb);
		delay_ms(p4);
		delay_ms(p4);
		delay_ms(p4);
		beep(g7d);
		delay_ms(p8);
		beep(g1zb);
		delay_ms(p8);//12
		beep(g2z);
		delay_ms(p4);
		beep(stop);
		delay_ms(bb);
		beep(g2z);
		delay_ms(p8-bb);
		beep(g4zb);
		delay_ms(p8);
		beep(g3z);
		delay_ms(p6);
		beep(g2z);
		delay_ms(p8);//13
		beep(g1zb);
		delay_ms(p4);
		beep(g3z);
		delay_ms(p4);
		beep(g4zb);
		delay_ms(p4);
		beep(stop);
		delay_ms(bb);
		beep(g4zb);
		delay_ms(p8-bb);
		beep(g5zb);
		delay_ms(p8);//14
		beep(g6z);
		delay_ms(p4);
		delay_ms(p8);
		beep(stop);
		delay_ms(bb);
		beep(g6z);
		delay_ms(p8-bb);
		beep(g5zb);
		delay_ms(p4);
		beep(g4zb);
		delay_ms(p8);
		beep(g5zb);
		delay_ms(p8);//15
		beep(g6z);
		delay_ms(p4);
		delay_ms(p4);
		delay_ms(p4);
		beep(g1zb);
		delay_ms(p4);//16
		beep(g3z);
		delay_ms(p8);
		beep(g1zb);
		delay_ms(p8);
		beep(g3z);
		delay_ms(p8);
		beep(g1zb);
		delay_ms(p8);
		beep(g3z);
		delay_ms(p4);
		beep(g1zb);
		delay_ms(p8);
		beep(g4zb);
		delay_ms(p8);//17
		delay_ms(p8);
		beep(g6z);
		delay_ms(p8);
		beep(g4zb);
		delay_ms(p8);
		beep(g3z);
		delay_ms(p8);
		beep(g4zb);
		delay_ms(p4);
		delay_ms(p4);//18
		beep(g7d);
		delay_ms(p8);
		beep(g6d);
		delay_ms(p8);
		beep(g7d);
		delay_ms(p8);
		beep(g6d);
		delay_ms(p8);
		beep(g7d);
		delay_ms(p4);
		beep(g6d);
		delay_ms(p8);
		beep(g3z);
		delay_ms(p8);//19
		delay_ms(p8);
		beep(g1zb);
		delay_ms(p8);
		beep(stop);
		delay_ms(bb);
		beep(g1zb);
		delay_ms(p8-bb);
		beep(g7d);
		delay_ms(p8);
		beep(g1zb);
		delay_ms(p4);
		delay_ms(p4);//20
		beep(g3z);
		delay_ms(p8);
		beep(g1zb);
		delay_ms(p8);
		beep(g3z);
		delay_ms(p8);
		beep(g1zb);
		delay_ms(p8);
		beep(g3z);
		delay_ms(p4);
		beep(g1zb);
		delay_ms(p8);
		beep(g4zb);
		delay_ms(p8);//21
		delay_ms(p8);
		beep(g6z);
		delay_ms(p8);
		beep(g4zb);
		delay_ms(p8);
		beep(g3z);
		delay_ms(p8);
		beep(g4zb);
		delay_ms(p4);
		delay_ms(p4);//22
		beep(g7d);
		delay_ms(p8);
		beep(g6d);
		delay_ms(p8);
		beep(g7d);
		delay_ms(p8);
		beep(g6d);
		delay_ms(p8);
		beep(g7d);
		delay_ms(p4);
		beep(g4zb);
		delay_ms(p4);//23
		beep(g3z);
		delay_ms(p4);
		delay_ms(p4);
		delay_ms(p4);
		beep(g4zb);
		delay_ms(p4);//24
		beep(g6z);
		delay_ms(p4);
		delay_ms(p4);
		delay_ms(p4);
		beep(g3z);
		delay_ms(p8);
		beep(g5z);
		delay_ms(p8);//25
		beep(g6z);
		delay_ms(p4);
		beep(g3z);
		delay_ms(p8);
		beep(g6z);
		delay_ms(p8);
		beep(g5z);
		delay_ms(p4);
		beep(g3z);
		delay_ms(p8);
		beep(g5z);
		delay_ms(p8);//26
		beep(g6z);
		delay_ms(p8);
		delay_ms(p16);
		beep(g1g);
		delay_ms(p16);
		beep(g7z);
		delay_ms(p8);
		beep(g5z);
		delay_ms(p8);
		beep(g3z);
		delay_ms(p4);
		beep(g2z);
		delay_ms(p8);
		beep(g1z);
		delay_ms(p8);//27
		beep(g2z);
		delay_ms(p4);
		beep(stop);
		delay_ms(bb);
		beep(g2z);
		delay_ms(p8-bb);
		beep(g3z);
		delay_ms(p8);
		beep(g5z);
		delay_ms(p8);
		beep(g3z);
		delay_ms(p8);
		beep(g2z);
		delay_ms(p8);
		beep(g1z);
		delay_ms(p8);//28
		beep(g2z);
		delay_ms(p8);
		delay_ms(p16);
		beep(stop);
		delay_ms(bb);
		beep(g2z);
		delay_ms(p16-bb);
		beep(stop);
		delay_ms(bb);
		beep(g2z);
		delay_ms(p8-bb);
		beep(g4z);
		delay_ms(p8);
		beep(g3z);
		delay_ms(p4);
		beep(stop);
		delay_ms(bb);
		beep(g3z);
		delay_ms(p8-bb);
		beep(g5z);
		delay_ms(p8);//29
		beep(g6z);
		delay_ms(p4);
		beep(g3z);
		delay_ms(p8);
		beep(g6z);
		delay_ms(p8);
		beep(g5z);
		delay_ms(p4);
		beep(g3z);
		delay_ms(p8);
		beep(g5z);
		delay_ms(p8);//30
		beep(g6z);
		delay_ms(p8);
		delay_ms(p16);
		beep(g1g);
		delay_ms(p16);
		beep(g7z);
		delay_ms(p8);
		beep(g5z);
		delay_ms(p8);
		beep(g3z);
		delay_ms(p4);
		beep(g2z);
		delay_ms(p8);
		beep(g1z);
		delay_ms(p8);//31
		beep(g2z);
		delay_ms(p4);
		beep(stop);
		delay_ms(bb);
		beep(g2z);
		delay_ms(p8-bb);
		beep(g3z);
		delay_ms(p8);
		beep(g5z);
		delay_ms(p8);
		beep(g3z);
		delay_ms(p8);
		beep(g2z);
		delay_ms(p8);
		beep(g1z);
		delay_ms(p8);//32
		beep(g1z);
		delay_ms(p4);
		delay_ms(p4);
		delay_ms(p4);
		beep(g4z);
		delay_ms(p8);
		beep(g3z);
		delay_ms(p8);//33
		beep(g2z);
		delay_ms(p4);
		beep(stop);
		delay_ms(bb);
		beep(g2z);
		delay_ms(p8-bb);
		beep(g3z);
		delay_ms(p8);
		beep(g5z);
		delay_ms(p8);
		beep(g3z);
		delay_ms(p8);
		beep(g5z);
		delay_ms(p8);
		beep(g7z);
		delay_ms(p8);//34
		beep(g6z);
		delay_ms(p4);
		delay_ms(p4);
		delay_ms(p4);
		delay_ms(p4);//end part
		
		beep(stop);
		delay_ms(1000);
		delay_ms(1000);
	}
	//music body end
}
