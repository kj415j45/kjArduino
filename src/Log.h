//规定要使用的语言，代号遵循ISO 639-1
#define Locale_zh

//导入本地化文件
#include "Locale.h"

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
         * 做一条记录(带时间戳)
         * 
         * @param char[] logType 记录类型
         * @param char[] logMessage 记录信息
         */
        void log(char logType[], char logMessage[]){ //TODO 字符串连接
            Serial.write('[');
            Serial.print(millis());
            Serial.write(']');
            
            this->bracketMessage(logType);
            
            Serial.println(logMessage);
        }
        
        /**
         * 启用调试模式(使 debug() 可用)
         */
        void debugMode(){
            this->DEBUG = true;
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
        
};
