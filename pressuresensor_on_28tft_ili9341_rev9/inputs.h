//sensor and code taken from ovens garage, now modified
const int pressureInput1 = A7; //select the analog input pin for oil pressure
const int pressureInput2 = A8; //select the analog input pin for oil temp
const int pressureInput3 = A9; //select the analog input pin for trans temp
const int pressureInput4 = A10; //select the analog input pin for coolant temp
const int pressureInput5 = A11; //select the analog input pin for voltage
const int pressureInput6 = A12; //select the analog input pin for ambient temp
const int pressureInput7 = A13; //select the analog input pin for fuel pressure

//pressure transducer variables
const int pressureZero = 102.4; //analog reading of pressure transducer at 0psi
const int pressureMax = 921.6; //analog reading of pressure transducer at 100psi
const int pressuretransducermaxPSI = 100; //psi value of transducer being used
float pressureValue = 0; //variable to store the value coming from the pressure transducers
