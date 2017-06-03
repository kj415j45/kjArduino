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
        //Car();

        int speed; //默认车速

    public:
        virtual bool turnLeft();
        virtual bool turnRight();
        virtual bool straight();
        virtual bool needStop();
        virtual void left(); //左转
        virtual void right(); //右转
        virtual void stop(); //停车
        virtual void go(); //直走
        virtual void back(); //倒退

        virtual void set(...);

        void setSpeed(int speed){
            this->speed = speed;
        }

        int getSpeed(){
            return this->speed;
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

};

#endif

