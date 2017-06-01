#ifndef KJ_CAR_1_H
#define KJ_CAR_1_H

#include "../Car.h"

/*===================
1号车(通用技术课专用车)

ASCII设计图：

正方向
A
|
|

i是灰度传感，l是红外距离传感
     ili
  L o---o R
      |
      o
    万向轮
===================*/

/**
 * 1号车(通用技术课专用车)
 * 走黑线，两个传感器同时发现黑线时停车
 *
 * @author kj415j45
 */
class Car_1 : Car{
    private:

        Pin Li = NULL; //左灰度
        Pin Ri = NULL; //右灰度
        Pin Ml = NULL; //中距离
        Pin Lm = NULL; //控制左轮转动方向
        Pin Rm = NULL; //控制右轮转动方向
        Pin Ls = NULL; //控制左轮速度
        Pin Rs = NULL; //控制右轮速度

        bool isSet = false;

    protected:

    public:
    
        Car_1();
        
        /**
         * 设置车的针脚接口(只能设置一次)
         * 
         * 参数顺序为左灰度，右灰度，中距离，左轮转向，右轮转向，左轮速度，右轮速度，默认速度(除默认速度均为针脚位置)
         * 默认值为8,9,13,4,7,5,6,255
         */
        void set(int Li = 8, int Ri = 9, int Ml = 13, int Lm = 4, int Rm = 7, int Ls = 5, int Rs = 6, int speed = 255){
            if(this->isSet){
                return;
            }

            this->Li = Pin(Li, INPUT);
            this->Ri = Pin(Ri, INPUT);
            this->Ml = Pin(Ml, INPUT);
            this->Lm = Pin(Lm, OUTPUT);
            this->Rm = Pin(Rm, OUTPUT);
            this->Ls = Pin(Ls, OUTPUT);
            this->Rs = Pin(Rs, OUTPUT);

            this->speed = speed;

            this->isSet = true;
        }
        
        bool turnLeft(){
            return this->Li.isHigh();
        }

        bool turnRight(){
            return this->Ri.isHigh();
        }

        bool straight(){
            if(true == this->Li.isLow() && true == this->Ri.isLow()){
                return true;
            }else{
                return false;
            }
        }

        bool needStop(){
            if(true == this->Ml.isHigh() || (true == this->Li.isHigh() && true == this->Ri.isHigh() ) ){
                return true;
            }else{
                return false;
            }
        }

        void left(){
            this->L(true, 0);
            this->R(true, this->speed);
        }

        void right(){
            this->L(true, this->speed);
            this->R(true, 0);
        }

        void go(){
            this->L(true, this->speed);
            this->R(true, this->speed);
        }

        void stop(){
            this->L(true, 0);
            this->R(true, 0);
        }

        /**
         * 设置左轮
         * 
         * @param bool go         是否前进
         * @param int speed = 255 速度
         */
        void L(bool go, int speed = 255){
            if(go){
                this->Lm.setHigh();
            }else{
                this->Lm.setLow();
            }
            this->Ls.set(speed);
        }

        /**
         * 设置右轮
         * 
         * @param bool go         是否前进
         * @param int speed = 255 速度
         */
        void R(bool go, int speed = 255){
            if(go){
                this->Rm.setHigh();
            }else{
                this->Rm.setLow();
            }
            this->Rs.set(speed);
        }

        /**
         * 倒车
         *
         * @param int speed = 100 倒车速度
         */
        void back(int speed = 100){
            this->L(false, speed);
            this->R(false, speed);
        }
};

#endif

