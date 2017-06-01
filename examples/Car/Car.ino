/*===================
这个样例完成通用技术课的期末考试

考试场地:(ASCII设计图)

假装这是90度弯道
  |
  V
    ______[障碍物]
   /         |
  /          |
 /           |
|            |
|            |
|            |
[E]         [S]

S是起点，E是终点，线条代表黑线
===================*/
#include <kjArduino.h>

CarFactory cf = CarFactory(); //创建车工厂
Car car = cf.getCar(1); //从车工厂得到1号车

void setup(){
    car.set(8, 9, 13, 4, 7, 5, 6, 255); //按照参数顺序设置好
}

void loop(){
    car.Go();
}

