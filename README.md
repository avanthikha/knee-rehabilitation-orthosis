# Knee Rehabilitation Orthosis

Every step puts weight on the knee. For someone with osteoarthritis, a bad
step means pain, and a pattern of bad steps slows recovery. The trouble is
that nobody can see those steps happening.

This project makes them visible. It's the sensing core of a wearable knee
orthosis: an Arduino strapped to the leg that watches how the leg swings,
how hard the foot strikes the ground, and where the weight lands. With that
data, a brace can give real-time feedback and assist the knee during walking.

## What it measures

The **ADXL345 accelerometer** (a MEMS sensor) tracks the leg's motion along
three axes, which shows how smoothly the leg swings and extends.

A **piezoelectric sensor** responds to the impact of each step, so sudden
heavy strikes stand out.

A **force-sensitive resistor** under the front of the foot measures how much
pressure goes through the forefoot, which shows how weight is being shifted
off the painful joint.

All three readings stream to the serial monitor every few seconds.

## Wiring

- ADXL345 → SDA / SCL (I2C)
- Piezo sensor → A1
- Force-sensitive resistor (with 10k pull-down) → A0

## Try it

1. In the Arduino IDE, install **Adafruit ADXL345** and **Adafruit Unified
   Sensor** from Tools → Manage Libraries.
2. Open `knee_orthosis/knee_orthosis.ino` and upload it to the board.
3. Open the Serial Monitor at 9600 baud and start walking.

## Where it goes next

The sensor data is the foundation for the next stage: motorized actuation
that gives the knee extra support at the right moment in each step.

