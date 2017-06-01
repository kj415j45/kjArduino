#ifndef KJ_CARF_H
#define KJ_CARF_H

#include "Car.h"
#include "Parking_lot/CarList.h"

class CarFactory{
    private:

    protected:

    public:

        Car getCar(int car){
            switch(car){
                case 1:
                    return (Car)Car_1();
            }
        }
        
};

#endif

