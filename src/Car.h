#ifndef KJ_CAR_H
#define KJ_CAR_H

/**
 * 抽象Car
 * 
 * @author kj415j45
 */
class Car{
    private:

    protected:
        Car();

        int speed; //默认车速

    public:
        bool turnLeft();
        bool turnRight();
        bool straight();
        bool needStop();
        void left(); //左转
        void right(); //右转
        void go(); //直走
        void stop(); //停车

        void set(...);

        void setSpeed(int speed){
            this->speed = speed;
        }

        /**
         * 前进！
         */
        void Go(){
            if(this->turnLeft()){
                this->left();
            }else if(this->turnRight()){
                this->right();
            }else if(this->straight()){
                this->go();
            }else if(this->needStop()){
                this->stop();
            }else{
                this->go();
            }
        }

        void back(); //倒退
};

#endif

