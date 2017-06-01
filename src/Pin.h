#ifndef KJ_PIN_H
#define KJ_PIN_H

/**
 * 高效地使用针脚
 * 
 * @author kj415j45
 */
class Pin{

    private:
    
        /**
         * 禁用无参构造方法
         */
        Pin();
        
    protected:
        
        int pin;  //针脚编号
        int mode = -1; //模式
        
    public:
    
        /**
         * 定义一个针脚(但不定义模式)
         * 
         * @param int pin   针脚编号
         */
        Pin(int pin){
            this->pin = pin;
        }
        
        /**
         * 定义一个针脚
         * 
         * @param int pin   针脚编号
         * @param int mode  使用模式
         */
        Pin(int pin, int mode){
            this->pin = pin;
            this->setMode(mode);
        }

        /**
         * 取得针脚编号
         * 
         * @return int pin  针脚编号
         */
        int getPin(){
            return this->pin;
        }

        /**
         * 检查当前电位
         * 
         * @return bool     是否为高电位
         */
        bool isHigh(){
            return digitalRead(this->pin) == HIGH ? true : false;
        }

        /**
         * 检查当前电位
         * 
         * @return bool     是否为低电位
         */
        bool isLow(){
            return digitalRead(this->pin) == LOW ? true : false;
        }
        
        /**
         * 设置为低电位
         * 
         * @return void
         */
        void setLow(){
            return digitalWrite(this->pin, LOW);
        }
        
        /**
         * 设置为高电位
         * 
         * @return void
         */
        void setHigh(){
            return digitalWrite(this->pin, HIGH);
        }
        
        /**
         * 设置模式
         * 
         * @param int mode 模式
         * @return void
         */
        void setMode(int mode){
//            if(-1 != this->mode){
//                throw new class ReDefineException : Exception (){
//                    
//                };
//            }
            this->mode = mode;
            pinMode(this->pin, mode);
        }
        
        /**
         * 淡入淡出(闭区间)
         * 
         * @param int from       //从from
         * @param int to         //到to
         * @param int tick = 10  //每次变化延迟 tick ms
         * @param int jump = 1   //每次变化跳跃值
         * @param callback       //每次模拟值变化时调用的回调函数名
         */
        void fade(int from, int to, int tick = 10, int jump = 1, void (*callback)() = NULL){
            if(from<to){
                while(from<=to){
                    this->set(from);
                    callback();
                    from += jump;
                    delay(tick);
                }
            }else{
                while(from>=to){
                    this->set(from);
                    callback();
                    from -= jump;
                    delay(tick);
                }
            }
        }
        
        /**
         * 设置模拟值
         * 
         * @param int value
         */
        void set(int value){
            analogWrite(this->pin, value);
        }
        
        /**
         * 获得当前模拟值
         */
        int get(){
            return analogRead(this->pin);
        }

        /**
         * 死循直到低电平
         * 
         * @return void
         */
        void waitTillLow(){
            while(this->isHigh());
        }
        
        /**
         * 死循直到高电平
         * 
         * @return void
         */
        void waitTillHigh(){
            while(this->isLow());
        }
};

#endif
