#include "ZLAC8015.h"

ZLAC8015::ZLAC8015(ModbusMaster &node, uint8_t id)
    : node(node), id(id) {}

void ZLAC8015::begin() {
    node.begin(id, Serial1);
}

void ZLAC8015::enable() {
    node.writeSingleRegister(0x2031, 0x0008);
}

void ZLAC8015::disable() {
    node.writeSingleRegister(0x2031, 0x0007);
}

void ZLAC8015::setVelocityMode() {
    node.writeSingleRegister(0x2032, 0x0003);
}

void ZLAC8015::setRPM(int16_t rpm) {
    node.writeSingleRegister(0x203A, rpm);
}

float ZLAC8015::getRPM() {
    node.readHoldingRegisters(0x202C, 1);
    return node.getResponseBuffer(0);
}

int32_t ZLAC8015::getPosition() {
    node.readHoldingRegisters(0x202A, 2);
    int32_t position = node.getResponseBuffer(0);
    position = (position << 16) | node.getResponseBuffer(1);
    return position;
}

float ZLAC8015::getTorque() {
    // Implement get torque logic
    return 0.0;
}

uint16_t ZLAC8015::getError() {
    node.readHoldingRegisters(0x2020, 1);
    return node.getResponseBuffer(0);
}

void ZLAC8015::setAccelerationTime(uint16_t timeMs) {
    node.writeSingleRegister(0x2037, timeMs);
}

void ZLAC8015::setDecelerationTime(uint16_t timeMs) {
    node.writeSingleRegister(0x2038, timeMs);
}

void ZLAC8015::setVelocitySmoothing(uint16_t smoothingFactor) {
    node.writeSingleRegister(0x2018, smoothingFactor);
}

void ZLAC8015::setFeedforwardSmoothing(uint16_t smoothingFactor) {
    node.writeSingleRegister(0x201B, smoothingFactor);
}