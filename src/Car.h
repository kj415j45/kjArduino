#ifndef KJ_CAR_H
#define KJ_CAR_H

/**
 * 抽象Car
 * 
 * @author kj415j45
 */
class Car{
    private:
        Car();

    protected:
        int speed; //默认车速
        bool ((*turnLeft)());
        bool ((*turnRight)());
        void straight();

    public:
        void left(); //左转
        void right(); //右转

        /**
         * 设置左转的回调函数
         * 
         * @param (bool callback()) 返回true时左转
         */
        void turnLeftWhen(bool (*callback)()){
            this->turnLeft=callback;
        }

        /**
         * 设置右转的回调函数
         * 
         * @param (bool callback()) 返回true时右转
         */
        void turnRightWhen(bool (*callback)()){
            this->turnRight=callback;
        }

        void setSpeed(); //设置默认车速

        /**
         * 前进！
         */
        void go(){
            if(this->turnLeft()){
                this->left();
            }else if(this->turnRight()){
                this->right();
            }else{
                this->straight();
            }
        }

        void back(); //倒退
};

#endif