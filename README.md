# V-unit test using PLT-300A

## Introduction
This repository describes the test procedure for testing the V-unit, it also includes necesarry operator instructions to preform said test.
The testing of the V-unit is done with the PLT-300A, through designated .yaml files, which include the necesarry test steps.
Before preforming the test the operator should follow [operator instructions](#Operator-instructions), to connect the V-unit and handle test fails.

If you wish to assemble/reprint/fix the setup, the 3D CAD models can be found in [3D models](https://github.com/Licko004/PLT-300A_V-unit-test/tree/main/3D-models).

To preform this test you need: 
1. PLT-300A **with an internet connection** this is easily achieved through the provided Ethernet port
2. The correct test plan on the PLT, consisting of the [Full test yaml file](https://github.com/Licko004/PLT-300A_V-unit-test/blob/main/Full_test_V0.0.7.yaml), the uploaded version should be the highest avaliable

## Test procedure/steps

1. Firstly the QR code, containg the serial number of the currently tested V-unit is scanned, using the provided optical scanner
2. Then the V-unit should be setup according to [setting up V-unit](#Setting-up-V-unit)
3. The PLT measures pressures measured by the internal/reference V-unit and the currently tested V-unit, it then compares both pressures, to indicate any malfunctioning of the pressure sensor
4. An MCU health check is preformed, the test setup includes an internal MCU in form of a Arduino Nano, which is responsible for PWM generation for pump control. More on the wirring and the whole setup can be seen on the [connections diagram](https://github.com/Licko004/PLT-300A_V-unit-test/blob/main/diagrams-connections/V-unit_connection_diagram%20(1).pdf)
5. In this step there is a **test to confirm, the V-unit can achieve vacuum**, this is done by driving the pump with different PWM duty cycles and measuring if the pressure has reached the desired pressure after a set amount of time. The PWM then increments and the check is done again. The duty cycle is incremented in steps: 50%, 75% and 100%. The MCU has custom firmware flashed, which can be found [here](https://github.com/Licko004/PLT-300A_V-unit-test/tree/main/MCU-firmware)
6. The next step is a **RELEASE TEST** which is a test to confirm the V-unit can quickly release pressure and in turn confirm that the valve is working
7. The final step is a **LEAKAGE TEST** which is done by driving the pump, which creates a vacuum, then the pump is turned off and the valve is left closed. Pressure is remeasured after a set amount of time. The measured pressure should be within the set boundaries, to confim, there are no major leaks. 

## Operator instructions

The operator instruction can be divided in to different tasks:
1. The operator **Scans the QR code** on the currently tested V-unit
2. The operator is given 30 seconds to **connect the V-unit, mechanically, electricaly and connect the vacuum vessel**. The setting up is described in [Setting up V-unit](#setting-up-v-unit).
3. Once **step 2 is done** the operator **confirms the setup, by pressng START/PASS button**
4. The operator should be focused on the test, check for any visible leaks, which might indicate leaks due to bad setup, or any unexpected noises.
5. After the **test is done** the operator should **press the PASS button, enough times to enter the main menu of the PLT** after that the operator can **disconnect the V-unit**.
5. For any FAIL debugging, the operator should refer to the [PLT cloud reports](https://dewesoftrealtimebodysense.pltcloud.com/) automatically published after each test.
### Setting up V-unit
The setting up of the V-unit is described here:
1. The operator connects one end of the air tube to the V-unit
2. The operator **places the V-unit into its holder** (look at image below for reference)
3. The operator **connects the cable harness to the V-unit** 
4. The operator **pushes the loose end of the air tube into the push-fit connector**.
All of the V-unit preparations steps can be better understood, by refering to the image below:
![Test setup and placement of connections](https://github.com/Licko004/PLT-300A_V-unit-test/blob/main/images/V-unit-test-setup-MARKED.png)
