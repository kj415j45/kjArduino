/**
 * example-1
 * 
 * 这个样例将指引您正确使用Pin类
 * 以高效使用针脚(Pin)
 * 
 * 本样例包含了Pin类的基本用法
 * 至于高级膜法请参考Pin.h
 */

#include <kjArduino.h>

//在setup()的外面声明一个针脚,而不是在它里面(必须)
//至于为什么非得在外面,这涉及到Arduino源码编译原理,此处不细讲
Pin led = Pin(13, OUTPUT);

//也允许只声明针脚却不声明用途,但最好之后在setup()中初始化
Pin button = Pin(D1);

//声明一个呼吸灯
Pin breath = Pin(9, OUTPUT);

void setup(){
    button.setMode(INPUT_PULLUP); //声明button这个针脚的用途
}

void loop(){
    if(button.isHigh()){ //如果按钮所在针脚为高电平
        led.setHigh(); //将LED的电平设置为高
    }else{
        led.setLow(); //将LED的电平设置为低
    }

    breath.fade(0, 255, 10, 1); //让呼吸灯开始呼吸,后两个参数不是必须值,参考Pin.h内的doc以了解更多
    breath.fade(255, 0);

    breath.set(233); //设置呼吸灯所在针脚的模拟值为233

    button.waitTillHigh(); //让按钮锁死程序,直到按钮按下使得按钮所在针脚变为高电平

    button.waitTillLow(); //让按钮锁死程序,直到松开按钮使得按钮所在针脚变为低电平
}