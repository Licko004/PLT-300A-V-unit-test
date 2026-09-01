# V-unit test using PLT-300A

## Introduction
This repository describes the test procedure for testing the V-unit, it also includes necesarry operator instructions to preform said test.
The testing of the V-unit is done with the PLT-300A, through designated .yaml files, which include the necesarry test steps.
Before preforming the test the operator should follow [operator instructions](#Operator-instructions), to connect the V-unit and handle test fails.

If you wish to assemble/reprint/fix the setup, the 3D CAD models can be found in [3D models]()

## Test procedure/steps

1. Firstly the QR code, containg the serial number of the currently tested V-unit is scanned, using the provided optical scanner
2. Then the V-unit should be setup accordin to [setting up V-unit](#Setting-up-V-unit)
3. The PLT measures pressures measured by the internal/reference V-unit and the currently tested V-unit, it then compares both pressures, to indicate any malfunctioning of the pressure sensor
4. An MCU health check is preformed, the test setup includes an internal MCU in form of a Arduino Nano, which is responsible for PWM generation for pump control. More on the wirring and the whole setup can be seen on the [connections diagram](https://github.com/Licko004/PLT-300A_V-unit-test/blob/main/diagrams-connections/V-unit_connection_diagram%20(1).pdf)
5. In this step there is a **test to confirm, the V-unit can achieve vacuum**, this is done by driving the pump with different PWM duty cycle and measuring if the pressure has reached the desired pressure after a set amount of time. The PWM then increments and the check is done again. The duty cycle is incremented in steps: 50%, 75% and 100%.
6. The next step is a **RELEASE TEST** which is a test to confirm the V-unit can quickly release pressure and in turn confirm that the valve is working
7. The final step is a **LEAKAGE TEST** which is done by driving the pump, which creates a vacuum, then the pump is turned off and the valve is left closed. Pressure is remeasured after a set amount of time. The pressure is measured again and should be within the set boundaries, to confim, there is no major leaks. 

## Operator instructions

### Setting up V-unit
