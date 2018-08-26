EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:Altera
LIBS:Msystem
LIBS:motor_drivers
LIBS:79xx-Regler-BuildingBlock_ModB_RevA-cache
LIBS:Switch
LIBS:Display
LIBS:Relay
LIBS:relays
LIBS:nxp
LIBS:dc-dc
LIBS:MPPT-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Screw_Terminal_1x02 J?
U 1 1 5B803474
P 1650 2150
F 0 "J?" H 1650 2400 50  0000 C TNN
F 1 "Screw_Terminal_1x02" V 1500 2150 50  0000 C TNN
F 2 "" H 1650 1925 50  0001 C CNN
F 3 "" H 1625 2150 50  0001 C CNN
	1    1650 2150
	1    0    0    -1  
$EndComp
$Comp
L Fuse F?
U 1 1 5B80361D
P 2000 2050
F 0 "F?" V 2080 2050 50  0000 C CNN
F 1 "Fuse" V 1925 2050 50  0000 C CNN
F 2 "" V 1930 2050 50  0001 C CNN
F 3 "" H 2000 2050 50  0001 C CNN
	1    2000 2050
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5B803654
P 1850 2250
F 0 "#PWR?" H 1850 2000 50  0001 C CNN
F 1 "GND" H 1850 2100 50  0000 C CNN
F 2 "" H 1850 2250 50  0001 C CNN
F 3 "" H 1850 2250 50  0001 C CNN
	1    1850 2250
	1    0    0    -1  
$EndComp
Text GLabel 2150 2050 2    60   Input ~ 0
V_IN
$Comp
L Q_PMOS_GDS Q?
U 1 1 5B8037D3
P 6600 2150
F 0 "Q?" H 6800 2200 50  0000 L CNN
F 1 "Q_PMOS_GDS" H 6800 2100 50  0000 L CNN
F 2 "" H 6800 2250 50  0001 C CNN
F 3 "" H 6600 2150 50  0001 C CNN
	1    6600 2150
	-1   0    0    1   
$EndComp
$Comp
L Q_PMOS_GDS Q?
U 1 1 5B80383F
P 6400 2800
F 0 "Q?" H 6600 2850 50  0000 L CNN
F 1 "Q_PMOS_GDS" H 6600 2750 50  0000 L CNN
F 2 "" H 6600 2900 50  0001 C CNN
F 3 "" H 6400 2800 50  0001 C CNN
	1    6400 2800
	1    0    0    -1  
$EndComp
$Comp
L Q_PMOS_GDS Q?
U 1 1 5B803873
P 6400 3600
F 0 "Q?" H 6600 3650 50  0000 L CNN
F 1 "Q_PMOS_GDS" H 6600 3550 50  0000 L CNN
F 2 "" H 6600 3700 50  0001 C CNN
F 3 "" H 6400 3600 50  0001 C CNN
	1    6400 3600
	1    0    0    -1  
$EndComp
$Comp
L IR2104 U?
U 1 1 5B8060D0
P 4950 3250
F 0 "U?" H 5000 3600 50  0000 L CNN
F 1 "IR2104" H 5050 3750 50  0000 L CNN
F 2 "SOIC-8" H 5150 2900 50  0001 C CIN
F 3 "" H 4950 3250 50  0001 C CNN
	1    4950 3250
	1    0    0    -1  
$EndComp
$Comp
L DIODE-STANDARD_RevE_Date15jun2010 D?
U 1 1 5B80643B
P 7000 2150
F 0 "D?" H 7000 2300 30  0000 C CNN
F 1 "DIODE-STANDARD_RevE_Date15jun2010" H 7000 2000 30  0000 C CNN
F 2 "" H 7000 2150 60  0001 C CNN
F 3 "" H 7000 2150 60  0001 C CNN
	1    7000 2150
	-1   0    0    1   
$EndComp
Text GLabel 6500 1700 1    60   Input ~ 0
V_IN
$Comp
L L_Core_Ferrite_Small L?
U 1 1 5B8067DC
P 7400 3250
F 0 "L?" H 7450 3290 50  0000 L CNN
F 1 "L_Core_Ferrite_Small" H 7450 3200 50  0000 L CNN
F 2 "" H 7400 3250 50  0001 C CNN
F 3 "" H 7400 3250 50  0001 C CNN
	1    7400 3250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6500 1950 6500 1700
Wire Wire Line
	6500 2600 6500 2350
Wire Wire Line
	6500 3400 6500 3000
Wire Wire Line
	7300 3250 6500 3250
Connection ~ 6500 3250
Text GLabel 4950 2650 1    60   Input ~ 0
V_IN
$Comp
L DIODE-STANDARD_RevE_Date15jun2010 D?
U 1 1 5B806DC1
P 5450 2850
F 0 "D?" H 5450 3000 30  0000 C CNN
F 1 "1N4148" H 5300 2800 30  0000 C CNN
F 2 "" H 5450 2850 60  0001 C CNN
F 3 "" H 5450 2850 60  0001 C CNN
	1    5450 2850
	0    1    1    0   
$EndComp
Wire Wire Line
	5250 3050 5450 3050
Wire Wire Line
	5450 2650 4950 2650
Wire Wire Line
	4950 2650 4950 2850
$Comp
L C C?
U 1 1 5B806F78
P 5450 3200
F 0 "C?" H 5475 3300 50  0000 L CNN
F 1 "C" H 5475 3100 50  0000 L CNN
F 2 "" H 5488 3050 50  0001 C CNN
F 3 "" H 5450 3200 50  0001 C CNN
	1    5450 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 3350 5250 3350
$EndSCHEMATC
