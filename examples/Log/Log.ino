/**
 * example-2
 * 
 * 这个样例将指引您正确使用Log类
 * 进行详细的日志记录
 * 
 * 本样例包含了Log类的基本用法
 * 至于高级膜法请参考Log.h
 */

#include <kjArduino.h>

//在setup()的外面声明日志记录者,而不是在它里面(必须)
//至于为什么非得在外面,这涉及到Arduino源码编译原理,此处不细讲
Log logger;

void setup(){
    logger.begin(9600); //声明日志要使用的波特率,默认为9600Hz,使用默认值时可以无参调用
    logger.debugMode(true); //启用调试模式
    logger.timestamp(true); //输出时间戳
}

void loop(){
    logger.debugMode(false); //关闭调试模式

    //因为关闭了调试模式,所以这个 debug() 不会记录
    logger.debug("test");

    logger.debugMode(true);
    logger.timestamp(true);

    //输出:
    //[时间戳][DEBUG]test
    logger.debug("test");

    //输出:
    //[时间戳][INFO]test
    logger.info("test");

    //输出:
    //[时间戳][MESSAGE]test
    logger.log("MESSAGE","test");

    logger.timestamp(false); //停止输出时间戳

    //输出:
    //[MESSAGE]test
    logger.log("MESSAGE","test");

}