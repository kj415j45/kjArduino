#ifndef KJ_LOG_H
#define KJ_LOG_H

//规定要使用的语言，代号遵循ISO 639-1
#define Locale_zh

//导入本地化文件
#include "Locale.h"

#include <stdio.h>

#include "Pin.h"


/**
 * 日志记录(基于Serial)
 * 
 * @author kj415j45
 */
class Log{
    
    private:
        
        /**
         * 启动Serial
         */
        void setup(){
            Serial.begin(this->hz);
        }
        
        /**
         * 制造被方括号包围的消息
         */
        void bracketMessage(char message[]){
            Serial.write('[');
            Serial.print(message);
            Serial.write(']');
        }
        
    protected:
        
        int hz; //波特率
        bool DEBUG = false; //调试模式(默认关闭)
        bool useTimestamp = true; //输出时间戳(默认开启)
        
    public:

        /**
         * 日志记录开始
         * 
         * @param int hz = 9600 波特率
         */
        void begin(int hz = 9600){
            this->hz = hz;
            this->setup();
        }
        
        /**
         * 时间戳
         * 
         * @param bool 是否需要输出时间戳
         */
        void timestamp(bool use){
            this->useTimestamp = use;
        }

        /**
         * 做一条记录
         * 
         * @param char[] logType 记录类型
         * @param char[] logMessage 记录信息
         */
        void log(char logType[], char logMessage[]){
            if(this->useTimestamp){
                char time[10];
                sprintf(time,"%10d",millis());

                this->bracketMessage(time); //TODO 使用系统时间
            }
            
            this->bracketMessage(logType);
            
            Serial.println(logMessage);
        }
        
        /**
         * 调试模式(使 debug() 可用)
         * 
         * @param bool 是否开启调试模式
         */
        void debugMode(bool debug = true){
            this->DEBUG = debug;
        }
        
        /**
         * 输出调试级别的记录
         */
        void debug(char logMessage[]){
            if(this->DEBUG){
                this->log("DEBUG", logMessage);
            }
        }
        
        /**
         * 输出信息级别的记录
         */
        void info(char logMessage[]){
            this->log("INFO", logMessage);
        }

        enum type{
            DIGITAL = 0,
            ANALOG = 1,
            MIX = 2,
        };

        /**
         * 记录指定针脚的状态
         * 
         * @param Pin 指定针脚
         * @param int 需要信息的类型
         */
        void pinInfo(Pin x,int mode){
            char message[100];
            if(mode == DIGITAL){
                sprintf(message, "%s%d%s%s\0", PIN, x.getPin(), "->", HIGH_LEVEL);
            }else if(mode == ANALOG){
                sprintf(message, "%s%d%s%d\0", PIN, x.getPin(), "->", x.get());
            }else if(mode == MIX){
                sprintf(message, "%s%d%s%s,%s\0", PIN, x.getPin(), "->", HIGH_LEVEL, x.get());
            }
            this->debug(message);
        }
        
};

#endif
