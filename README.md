Project Title: Distance Measurement with Capacitive Sensor – Smart Instruments Project

Project Description:

- This project presents the complete design, implementation, and testing of a capacitive sensor system for contactless distance measurement. The system integrates hardware components (Arduino Uno, capacitive sensor, stepper motor with EasyDriver) with software solutions (Arduino C++, Python GUI, LabVIEW interface) to provide real-time distance monitoring and visualization.

Key Features & Implementation:

- Capacitive Sensor Design: Built a capacitive sensor using two cylindrical metal plates connected to analog pins on an Arduino Uno. The sensor operates on the principle that capacitance changes with the distance between the plates, following the formula.

- Arduino Firmware: Developed C++ code for the Arduino Uno to measure capacitance using a charge/discharge method. The measured capacitance value is then converted to distance using a calibrated linear formula derived from experimental data.

- Stepper Motor Integration: Incorporated a stepper motor with an EasyDriver module to automate distance variation for testing purposes. The motor is controlled via step and direction signals, allowing precise positioning of the sensor plates.

- Python GUI Application: Created a user-friendly interface using Python (PyQt6/matplotlib) that:

- Reads real-time data from the Arduino via serial communication

- Displays capacitance and distance values in real-time

- Generates live plots showing the relationship between distance and capacitance

- LabVIEW Interface: Developed a graphical interface in LabVIEW for additional data visualization and analysis capabilities.

- Calibration & Testing: Performed extensive measurements using a precision bridge to calibrate the sensor. The system achieves reliable accuracy in the 6-10 cm range, with a distance-to-capacitance conversion factor of approximately 2700 steps per 1 cm.

Technologies Used: Arduino (C++), Python (PyQt6, matplotlib, pyqtgraph, pyserial), LabVIEW, Stepper Motors (EasyDriver), Serial Communication

Results:

- Successfully measures capacitance and converts it to distance in real-time

- Reliable accuracy achieved in the 6-10 cm measurement range

- Interactive GUI displays both numerical values and graphical plots

Stepper motor enables automated and repeatable testing

Limitations identified due to parasitic capacitance from cabling; differential capacitive sensor recommended for improved precision

