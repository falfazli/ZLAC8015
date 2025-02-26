#ifndef ZLAC8015_H
#define ZLAC8015_H

#include <Arduino.h>
#include <ModbusMaster.h>

class ZLAC8015 {
public:
    ZLAC8015(ModbusMaster &node, uint8_t id);
    void begin();
    void enable();
    void disable();
    void setVelocityMode();
    void setRPM(int16_t rpm);
    float getRPM();
    int32_t getPosition();
    float getTorque();
    uint16_t getError();
    void setAccelerationTime(uint16_t timeMs);
    void setDecelerationTime(uint16_t timeMs);
    void setVelocitySmoothing(uint16_t smoothingFactor);
    void setFeedforwardSmoothing(uint16_t smoothingFactor);

private:
    ModbusMaster &node;
    uint8_t id;
};

#endif