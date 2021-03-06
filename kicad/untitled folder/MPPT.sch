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
LIBS:SD
LIBS:MPPT-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
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
L DS1307 U2
U 1 1 5A2F9669
P 4750 5475
F 0 "U2" H 5325 6650 60  0000 C CNN
F 1 "DS1307" V 5325 6275 60  0000 C CNN
F 2 "" H 5000 5475 60  0001 C CNN
F 3 "" H 5000 5475 60  0001 C CNN
	1    4750 5475
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR14
U 1 1 5A2FA083
P 4500 4375
F 0 "#PWR14" H 4500 4125 50  0001 C CNN
F 1 "GND" H 4500 4225 50  0000 C CNN
F 2 "" H 4500 4375 50  0001 C CNN
F 3 "" H 4500 4375 50  0001 C CNN
	1    4500 4375
	-1   0    0    1   
$EndComp
$Comp
L SW_Push SW3
U 1 1 5A30E703
P 8350 3600
F 0 "SW3" H 8400 3700 50  0000 L CNN
F 1 "Dw" H 8350 3540 50  0000 C CNN
F 2 "" H 8350 3800 50  0001 C CNN
F 3 "" H 8350 3800 50  0001 C CNN
	1    8350 3600
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW2
U 1 1 5A30E974
P 8350 3850
F 0 "SW2" H 8400 3950 50  0000 L CNN
F 1 "Up" H 8350 3790 50  0000 C CNN
F 2 "" H 8350 4050 50  0001 C CNN
F 3 "" H 8350 4050 50  0001 C CNN
	1    8350 3850
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW1
U 1 1 5A30E9EF
P 8350 4100
F 0 "SW1" H 8400 4200 50  0000 L CNN
F 1 "Edit" H 8350 4040 50  0000 C CNN
F 2 "" H 8350 4300 50  0001 C CNN
F 3 "" H 8350 4300 50  0001 C CNN
	1    8350 4100
	1    0    0    -1  
$EndComp
$Comp
L LED D7
U 1 1 5A380FBB
P 9875 3750
F 0 "D7" H 9975 3725 50  0000 C CNN
F 1 "LED_V" H 9875 3650 50  0000 C CNN
F 2 "" H 9875 3750 50  0001 C CNN
F 3 "" H 9875 3750 50  0001 C CNN
	1    9875 3750
	0    -1   -1   0   
$EndComp
$Comp
L LED D8
U 1 1 5A381040
P 10375 3750
F 0 "D8" H 10475 3725 50  0000 C CNN
F 1 "LED_R" H 10375 3650 50  0000 C CNN
F 2 "" H 10375 3750 50  0001 C CNN
F 3 "" H 10375 3750 50  0001 C CNN
	1    10375 3750
	0    -1   -1   0   
$EndComp
$Comp
L R R9
U 1 1 5A381442
P 9875 3450
F 0 "R9" V 9955 3450 50  0000 C CNN
F 1 "4K7" V 9875 3450 50  0000 C CNN
F 2 "" V 9805 3450 50  0001 C CNN
F 3 "" H 9875 3450 50  0001 C CNN
	1    9875 3450
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 5A3814AB
P 10375 3450
F 0 "R8" V 10455 3450 50  0000 C CNN
F 1 "4k7" V 10375 3450 50  0000 C CNN
F 2 "" V 10305 3450 50  0001 C CNN
F 3 "" H 10375 3450 50  0001 C CNN
	1    10375 3450
	1    0    0    -1  
$EndComp
$Comp
L +5VA #PWR11
U 1 1 5A878038
P 4350 4375
F 0 "#PWR11" H 4350 4225 50  0001 C CNN
F 1 "+5VA" H 4350 4515 50  0000 C CNN
F 2 "" H 4350 4375 50  0001 C CNN
F 3 "" H 4350 4375 50  0001 C CNN
	1    4350 4375
	1    0    0    -1  
$EndComp
$Comp
L LM2575-5.0BT U1
U 1 1 5A9733AE
P 2650 6675
F 0 "U1" H 2250 6925 50  0000 L CNN
F 1 "LM2575-5.0BT" H 2650 6925 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-220-5_Vertical" H 2650 6425 50  0001 L CIN
F 3 "" H 2650 6675 50  0001 C CNN
	1    2650 6675
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR6
U 1 1 5A9736B7
P 2650 6975
F 0 "#PWR6" H 2650 6725 50  0001 C CNN
F 1 "GND" H 2650 6825 50  0000 C CNN
F 2 "" H 2650 6975 50  0001 C CNN
F 3 "" H 2650 6975 50  0001 C CNN
	1    2650 6975
	1    0    0    -1  
$EndComp
$Comp
L DIODE-STANDARD_RevE_Date15jun2010 D1
U 1 1 5A973A7E
P 3275 6975
F 0 "D1" H 3275 7125 30  0000 C CNN
F 1 "BA159" H 3275 6825 30  0000 C CNN
F 2 "" H 3275 6975 60  0001 C CNN
F 3 "BA159" H 3275 6975 60  0001 C CNN
	1    3275 6975
	0    -1   -1   0   
$EndComp
$Comp
L L L1
U 1 1 5A973B46
P 3525 6775
F 0 "L1" V 3475 6775 50  0000 C CNN
F 1 "L" V 3600 6775 50  0000 C CNN
F 2 "" H 3525 6775 50  0001 C CNN
F 3 "" H 3525 6775 50  0001 C CNN
	1    3525 6775
	0    -1   -1   0   
$EndComp
$Comp
L CAPACITOR_POLARISED_RevE_Date15jun2010 C2
U 1 1 5A973D2E
P 3825 6975
F 0 "C2" H 3825 7125 30  0000 C CNN
F 1 "470uF 25V" H 3850 6850 30  0000 C CNN
F 2 "" H 3825 6975 60  0001 C CNN
F 3 "" H 3825 6975 60  0001 C CNN
	1    3825 6975
	0    1    1    0   
$EndComp
$Comp
L C C3
U 1 1 5A973DD3
P 4100 6925
F 0 "C3" H 4125 7025 50  0000 L CNN
F 1 "220nf" H 4125 6825 30  0000 L CNN
F 2 "" H 4138 6775 50  0001 C CNN
F 3 "" H 4100 6925 50  0001 C CNN
	1    4100 6925
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR10
U 1 1 5A973F3F
P 3825 7175
F 0 "#PWR10" H 3825 6925 50  0001 C CNN
F 1 "GND" H 3825 7025 50  0000 C CNN
F 2 "" H 3825 7175 50  0001 C CNN
F 3 "" H 3825 7175 50  0001 C CNN
	1    3825 7175
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR15
U 1 1 5A974320
P 4100 6775
F 0 "#PWR15" H 4100 6625 50  0001 C CNN
F 1 "+5V" H 4100 6915 50  0000 C CNN
F 2 "" H 4100 6775 50  0001 C CNN
F 3 "" H 4100 6775 50  0001 C CNN
	1    4100 6775
	1    0    0    -1  
$EndComp
$Comp
L ARDUINO_NANO_R3 SH?
U 1 1 5B7F30CA
P 6600 3225
F 0 "SH?" H 6625 2000 60  0000 C CNN
F 1 "ARDUINO_NANO_R3" H 6625 4575 60  0000 C CNN
F 2 "" H 6400 3000 60  0000 C CNN
F 3 "" H 6400 3000 60  0000 C CNN
	1    6600 3225
	1    0    0    -1  
$EndComp
$Comp
L PCF8574 U?
U 1 1 5B7F662F
P 2425 4900
F 0 "U?" H 2075 5500 50  0000 L CNN
F 1 "PCF8574" H 2525 5500 50  0000 L CNN
F 2 "" H 2425 4900 50  0001 C CNN
F 3 "" H 2425 4900 50  0001 C CNN
	1    2425 4900
	0    1    1    0   
$EndComp
$Comp
L WC1602A DS?
U 1 1 5B7F6BF8
P 2250 1625
F 0 "DS?" H 2020 2375 50  0000 C CNN
F 1 "WC1602A" V 2350 1450 50  0000 C CNN
F 2 "Displays:WC1602A" H 2250 725 50  0001 C CIN
F 3 "" H 2950 1625 50  0001 C CNN
	1    2250 1625
	-1   0    0    1   
$EndComp
Text GLabel 2650 1025 2    60   Input ~ 0
D7
Text GLabel 2650 1125 2    60   Input ~ 0
D6
Text GLabel 2650 1225 2    60   Input ~ 0
D5
Text GLabel 2650 1325 2    60   Input ~ 0
D4
Text GLabel 2650 2025 2    60   Input ~ 0
RS
Text GLabel 2650 2125 2    60   Input ~ 0
R/W
Text GLabel 2650 2225 2    60   Input ~ 0
E
Text GLabel 2125 5400 3    60   Input ~ 0
D7
Text GLabel 2225 5400 3    60   Input ~ 0
D6
Text GLabel 2325 5400 3    60   Input ~ 0
D5
Text GLabel 2425 5400 3    60   Input ~ 0
D4
Text GLabel 2525 5400 3    60   Input ~ 0
BL
Text GLabel 2625 5400 3    60   Input ~ 0
E
Text GLabel 2725 5400 3    60   Input ~ 0
R/W
Text GLabel 2825 5400 3    60   Input ~ 0
R
$Comp
L +5VA #PWR?
U 1 1 5B7F807E
P 3125 4900
F 0 "#PWR?" H 3125 4750 50  0001 C CNN
F 1 "+5VA" H 3125 5040 50  0000 C CNN
F 2 "" H 3125 4900 50  0001 C CNN
F 3 "" H 3125 4900 50  0001 C CNN
	1    3125 4900
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5B7F8223
P 1725 4900
F 0 "#PWR?" H 1725 4650 50  0001 C CNN
F 1 "GND" H 1725 4750 50  0000 C CNN
F 2 "" H 1725 4900 50  0001 C CNN
F 3 "" H 1725 4900 50  0001 C CNN
	1    1725 4900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5B7F9210
P 2250 825
F 0 "#PWR?" H 2250 575 50  0001 C CNN
F 1 "GND" H 2250 675 50  0000 C CNN
F 2 "" H 2250 825 50  0001 C CNN
F 3 "" H 2250 825 50  0001 C CNN
	1    2250 825 
	-1   0    0    1   
$EndComp
$Comp
L +5VA #PWR?
U 1 1 5B7F94DB
P 2250 2425
F 0 "#PWR?" H 2250 2275 50  0001 C CNN
F 1 "+5VA" H 2250 2565 50  0000 C CNN
F 2 "" H 2250 2425 50  0001 C CNN
F 3 "" H 2250 2425 50  0001 C CNN
	1    2250 2425
	-1   0    0    1   
$EndComp
$Comp
L POT RV?
U 1 1 5B7F9ACF
P 1675 2425
F 0 "RV?" V 1500 2425 50  0000 C CNN
F 1 "POT" V 1575 2425 50  0000 C CNN
F 2 "" H 1675 2425 50  0001 C CNN
F 3 "" H 1675 2425 50  0001 C CNN
	1    1675 2425
	1    0    0    -1  
$EndComp
$Comp
L +5VA #PWR?
U 1 1 5B7F9B72
P 1675 2275
F 0 "#PWR?" H 1675 2125 50  0001 C CNN
F 1 "+5VA" H 1675 2415 50  0000 C CNN
F 2 "" H 1675 2275 50  0001 C CNN
F 3 "" H 1675 2275 50  0001 C CNN
	1    1675 2275
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5B7F9C6B
P 1675 2575
F 0 "#PWR?" H 1675 2325 50  0001 C CNN
F 1 "GND" H 1675 2425 50  0000 C CNN
F 2 "" H 1675 2575 50  0001 C CNN
F 3 "" H 1675 2575 50  0001 C CNN
	1    1675 2575
	1    0    0    -1  
$EndComp
$Comp
L +5VA #PWR?
U 1 1 5B7F9E1F
P 1850 1925
F 0 "#PWR?" H 1850 1775 50  0001 C CNN
F 1 "+5VA" V 1775 1950 50  0000 C CNN
F 2 "" H 1850 1925 50  0001 C CNN
F 3 "" H 1850 1925 50  0001 C CNN
	1    1850 1925
	0    -1   -1   0   
$EndComp
$Comp
L BC237 Q?
U 1 1 5B7F9FA1
P 1525 1725
F 0 "Q?" V 1375 1525 50  0000 L CNN
F 1 "BC239" V 1475 1350 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Narrow" H 1725 1650 50  0001 L CIN
F 3 "" H 1525 1725 50  0001 L CNN
	1    1525 1725
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5B7FA3B2
P 1325 1825
F 0 "#PWR?" H 1325 1575 50  0001 C CNN
F 1 "GND" H 1325 1675 50  0000 C CNN
F 2 "" H 1325 1825 50  0001 C CNN
F 3 "" H 1325 1825 50  0001 C CNN
	1    1325 1825
	1    0    0    -1  
$EndComp
Text GLabel 1525 1525 1    60   Input ~ 0
BL
$Comp
L CONN_02X03 J?
U 1 1 5B7FA5CC
P 1575 4225
F 0 "J?" H 1575 4425 50  0000 C CNN
F 1 "CONN_02X03" H 1575 4025 50  0000 C CNN
F 2 "" H 1575 3025 50  0001 C CNN
F 3 "" H 1575 3025 50  0001 C CNN
	1    1575 4225
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 5B7FA71D
P 2325 3925
F 0 "R?" V 2325 3875 50  0000 C CNN
F 1 "10K" V 2225 3925 50  0000 C CNN
F 2 "" V 2255 3925 50  0001 C CNN
F 3 "" H 2325 3925 50  0001 C CNN
	1    2325 3925
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5B7FA848
P 2425 3925
F 0 "R?" V 2425 3875 50  0000 C CNN
F 1 "R" V 2425 3925 50  0001 C CNN
F 2 "" V 2355 3925 50  0001 C CNN
F 3 "" H 2425 3925 50  0001 C CNN
	1    2425 3925
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5B7FA90C
P 2525 3925
F 0 "R?" V 2525 3875 50  0000 C CNN
F 1 "R" V 2525 3925 50  0001 C CNN
F 2 "" V 2455 3925 50  0001 C CNN
F 3 "" H 2525 3925 50  0001 C CNN
	1    2525 3925
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5B7FB1E0
P 2425 3775
F 0 "#PWR?" H 2425 3525 50  0001 C CNN
F 1 "GND" H 2425 3625 50  0000 C CNN
F 2 "" H 2425 3775 50  0001 C CNN
F 3 "" H 2425 3775 50  0001 C CNN
	1    2425 3775
	-1   0    0    1   
$EndComp
$Comp
L +5VA #PWR?
U 1 1 5B7FB26F
P 1325 4225
F 0 "#PWR?" H 1325 4075 50  0001 C CNN
F 1 "+5VA" H 1325 4365 50  0000 C CNN
F 2 "" H 1325 4225 50  0001 C CNN
F 3 "" H 1325 4225 50  0001 C CNN
	1    1325 4225
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5B7FBFD1
P 8550 3850
F 0 "#PWR?" H 8550 3600 50  0001 C CNN
F 1 "GND" H 8550 3700 50  0000 C CNN
F 2 "" H 8550 3850 50  0001 C CNN
F 3 "" H 8550 3850 50  0001 C CNN
	1    8550 3850
	0    -1   -1   0   
$EndComp
$Comp
L LED D?
U 1 1 5B7FCECC
P 10125 3750
F 0 "D?" H 10225 3725 50  0000 C CNN
F 1 "LED_G" H 10125 3650 50  0000 C CNN
F 2 "" H 10125 3750 50  0001 C CNN
F 3 "" H 10125 3750 50  0001 C CNN
	1    10125 3750
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 5B7FCED2
P 10125 3450
F 0 "R?" V 10205 3450 50  0000 C CNN
F 1 "4k7" V 10125 3450 50  0000 C CNN
F 2 "" V 10055 3450 50  0001 C CNN
F 3 "" H 10125 3450 50  0001 C CNN
	1    10125 3450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5B7FCED8
P 10125 3900
F 0 "#PWR?" H 10125 3650 50  0001 C CNN
F 1 "GND" H 10125 3750 50  0000 C CNN
F 2 "" H 10125 3900 50  0001 C CNN
F 3 "" H 10125 3900 50  0001 C CNN
	1    10125 3900
	1    0    0    -1  
$EndComp
Text GLabel 10375 3300 1    60   Input ~ 0
LED_R
Text GLabel 10125 3300 1    60   Input ~ 0
LED_G
Text GLabel 9875 3300 1    60   Input ~ 0
LED_V
Text GLabel 7400 3475 2    60   Input ~ 0
LED_R
Text GLabel 7400 3350 2    60   Input ~ 0
LED_G
Text GLabel 7400 2950 2    60   Input ~ 0
LED_V
$Comp
L SDCARD J?
U 1 1 5B7FEA72
P 10125 1775
F 0 "J?" H 9975 2375 60  0000 C CNN
F 1 "SDCARD" H 10125 1125 60  0000 C CNN
F 2 "" H 10125 1775 60  0001 C CNN
F 3 "" H 10125 1775 60  0001 C CNN
	1    10125 1775
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5B7FECA6
P 9625 2275
F 0 "#PWR?" H 9625 2025 50  0001 C CNN
F 1 "GND" H 9625 2125 50  0000 C CNN
F 2 "" H 9625 2275 50  0001 C CNN
F 3 "" H 9625 2275 50  0001 C CNN
	1    9625 2275
	0    1    1    0   
$EndComp
$Comp
L +5VA #PWR?
U 1 1 5B7FECAC
P 9625 1325
F 0 "#PWR?" H 9625 1175 50  0001 C CNN
F 1 "+5VA" H 9625 1465 50  0000 C CNN
F 2 "" H 9625 1325 50  0001 C CNN
F 3 "" H 9625 1325 50  0001 C CNN
	1    9625 1325
	0    -1   -1   0   
$EndComp
Text GLabel 7400 2325 2    60   Input ~ 0
SCK
Text GLabel 7400 2450 2    60   Input ~ 0
MISO
Text GLabel 7400 2575 2    60   Input ~ 0
MOSI
Text GLabel 7400 3725 2    60   Input ~ 0
CS
Text GLabel 9625 1475 0    60   Input ~ 0
CS
Text GLabel 9625 1575 0    60   Input ~ 0
MOSI
Text GLabel 9625 1675 0    60   Input ~ 0
MISO
Text GLabel 9625 1775 0    60   Input ~ 0
SCK
$Comp
L R R?
U 1 1 5B7FF511
P 4675 3050
F 0 "R?" V 4755 3050 50  0000 C CNN
F 1 "R" V 4675 3050 50  0000 C CNN
F 2 "" V 4605 3050 50  0001 C CNN
F 3 "" H 4675 3050 50  0001 C CNN
	1    4675 3050
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 5B7FF773
P 4675 2750
F 0 "R?" V 4755 2750 50  0000 C CNN
F 1 "R" V 4675 2750 50  0000 C CNN
F 2 "" V 4605 2750 50  0001 C CNN
F 3 "" H 4675 2750 50  0001 C CNN
	1    4675 2750
	-1   0    0    1   
$EndComp
$Comp
L C C?
U 1 1 5B7FF889
P 4475 3050
F 0 "C?" H 4500 3150 50  0000 L CNN
F 1 "C" H 4500 2950 50  0000 L CNN
F 2 "" H 4513 2900 50  0001 C CNN
F 3 "" H 4475 3050 50  0001 C CNN
	1    4475 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 6950 2150 6950
Wire Wire Line
	2150 6950 2150 6775
Connection ~ 2650 6950
Wire Wire Line
	4100 6775 3675 6775
Wire Wire Line
	3375 6775 3150 6775
Wire Wire Line
	3275 7175 4100 7175
Wire Wire Line
	4100 7175 4100 7075
Connection ~ 3825 7175
Connection ~ 4100 7175
Connection ~ 3275 7175
Connection ~ 3150 6775
Connection ~ 3275 6775
Connection ~ 3375 6775
Connection ~ 3675 6775
Connection ~ 3825 6775
Connection ~ 4100 6775
Wire Wire Line
	8150 3850 7400 3850
Wire Wire Line
	2825 3975 5850 3975
Wire Wire Line
	2825 4400 2825 3975
Wire Wire Line
	2725 4400 2725 3850
Wire Wire Line
	2725 3850 5850 3850
Wire Wire Line
	4200 4375 4200 3850
Connection ~ 4200 3850
Wire Wire Line
	4050 4375 4050 3975
Connection ~ 4050 3975
Wire Wire Line
	1825 2425 1825 2225
Wire Wire Line
	1825 2225 1850 2225
Wire Wire Line
	1850 1825 1725 1825
Wire Wire Line
	2325 4075 2325 4400
Wire Wire Line
	2425 4400 2425 4075
Wire Wire Line
	2525 4075 2525 4400
Wire Wire Line
	2525 3775 2325 3775
Wire Wire Line
	1825 4125 2525 4125
Connection ~ 2525 4125
Wire Wire Line
	1825 4225 2425 4225
Connection ~ 2425 4225
Wire Wire Line
	1825 4325 2325 4325
Connection ~ 2325 4325
Wire Wire Line
	1325 4325 1325 4125
Wire Wire Line
	7400 3600 8150 3600
Wire Wire Line
	7400 3975 8100 3975
Wire Wire Line
	8100 3975 8100 4100
Wire Wire Line
	8100 4100 8150 4100
Wire Wire Line
	8550 3600 8550 4100
Wire Wire Line
	9875 3900 10375 3900
Wire Wire Line
	9625 2175 9625 2275
Wire Wire Line
	4475 2900 4800 2900
Wire Wire Line
	4675 3200 4475 3200
Wire Wire Line
	4800 2900 4800 3475
Wire Wire Line
	4800 3475 5850 3475
Connection ~ 4675 2900
$Comp
L R R?
U 1 1 5B7FFC8F
P 5100 3050
F 0 "R?" V 5180 3050 50  0000 C CNN
F 1 "R" V 5100 3050 50  0000 C CNN
F 2 "" V 5030 3050 50  0001 C CNN
F 3 "" H 5100 3050 50  0001 C CNN
	1    5100 3050
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 5B7FFC95
P 5100 2750
F 0 "R?" V 5180 2750 50  0000 C CNN
F 1 "R" V 5100 2750 50  0000 C CNN
F 2 "" V 5030 2750 50  0001 C CNN
F 3 "" H 5100 2750 50  0001 C CNN
	1    5100 2750
	-1   0    0    1   
$EndComp
$Comp
L C C?
U 1 1 5B7FFC9B
P 4900 3050
F 0 "C?" H 4925 3150 50  0000 L CNN
F 1 "C" H 4925 2950 50  0000 L CNN
F 2 "" H 4938 2900 50  0001 C CNN
F 3 "" H 4900 3050 50  0001 C CNN
	1    4900 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 2900 5225 2900
Wire Wire Line
	5100 3200 4900 3200
Connection ~ 5100 2900
Wire Wire Line
	5225 2900 5225 3350
Wire Wire Line
	5225 3350 5850 3350
$Comp
L GND #PWR?
U 1 1 5B7FFDBE
P 5100 3200
F 0 "#PWR?" H 5100 2950 50  0001 C CNN
F 1 "GND" H 5100 3050 50  0000 C CNN
F 2 "" H 5100 3200 50  0001 C CNN
F 3 "" H 5100 3200 50  0001 C CNN
	1    5100 3200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5B7FFE83
P 4675 3200
F 0 "#PWR?" H 4675 2950 50  0001 C CNN
F 1 "GND" H 4675 3050 50  0000 C CNN
F 2 "" H 4675 3200 50  0001 C CNN
F 3 "" H 4675 3200 50  0001 C CNN
	1    4675 3200
	1    0    0    -1  
$EndComp
Text GLabel 4675 2600 1    60   Input ~ 0
V_IN
Text GLabel 5100 2600 1    60   Input ~ 0
V_OUT
Text GLabel 2150 6575 0    60   Input ~ 0
v_IN
$Comp
L +5VA #PWR?
U 1 1 5B801453
P 5850 2450
F 0 "#PWR?" H 5850 2300 50  0001 C CNN
F 1 "+5VA" H 5850 2590 50  0000 C CNN
F 2 "" H 5850 2450 50  0001 C CNN
F 3 "" H 5850 2450 50  0001 C CNN
	1    5850 2450
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5B8016F3
P 5850 2575
F 0 "#PWR?" H 5850 2325 50  0001 C CNN
F 1 "GND" H 5850 2425 50  0000 C CNN
F 2 "" H 5850 2575 50  0001 C CNN
F 3 "" H 5850 2575 50  0001 C CNN
	1    5850 2575
	0    1    1    0   
$EndComp
$Comp
L DS1307 U?
U 1 1 5B804976
P 4750 5475
F 0 "U?" H 5325 6650 60  0000 C CNN
F 1 "DS1307" V 5325 6275 60  0000 C CNN
F 2 "" H 5000 5475 60  0001 C CNN
F 3 "" H 5000 5475 60  0001 C CNN
	1    4750 5475
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5B804977
P 4500 4375
F 0 "#PWR?" H 4500 4125 50  0001 C CNN
F 1 "GND" H 4500 4225 50  0000 C CNN
F 2 "" H 4500 4375 50  0001 C CNN
F 3 "" H 4500 4375 50  0001 C CNN
	1    4500 4375
	-1   0    0    1   
$EndComp
$Comp
L SW_Push SW?
U 1 1 5B804978
P 8350 3600
F 0 "SW?" H 8400 3700 50  0000 L CNN
F 1 "Dw" H 8350 3540 50  0000 C CNN
F 2 "" H 8350 3800 50  0001 C CNN
F 3 "" H 8350 3800 50  0001 C CNN
	1    8350 3600
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW?
U 1 1 5B804979
P 8350 3850
F 0 "SW?" H 8400 3950 50  0000 L CNN
F 1 "Up" H 8350 3790 50  0000 C CNN
F 2 "" H 8350 4050 50  0001 C CNN
F 3 "" H 8350 4050 50  0001 C CNN
	1    8350 3850
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW?
U 1 1 5B80497A
P 8350 4100
F 0 "SW?" H 8400 4200 50  0000 L CNN
F 1 "Edit" H 8350 4040 50  0000 C CNN
F 2 "" H 8350 4300 50  0001 C CNN
F 3 "" H 8350 4300 50  0001 C CNN
	1    8350 4100
	1    0    0    -1  
$EndComp
$Comp
L LED D?
U 1 1 5B80497B
P 9875 3750
F 0 "D?" H 9975 3725 50  0000 C CNN
F 1 "LED_V" H 9875 3650 50  0000 C CNN
F 2 "" H 9875 3750 50  0001 C CNN
F 3 "" H 9875 3750 50  0001 C CNN
	1    9875 3750
	0    -1   -1   0   
$EndComp
$Comp
L LED D?
U 1 1 5B80497C
P 10375 3750
F 0 "D?" H 10475 3725 50  0000 C CNN
F 1 "LED_R" H 10375 3650 50  0000 C CNN
F 2 "" H 10375 3750 50  0001 C CNN
F 3 "" H 10375 3750 50  0001 C CNN
	1    10375 3750
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 5B80497D
P 9875 3450
F 0 "R?" V 9955 3450 50  0000 C CNN
F 1 "4K7" V 9875 3450 50  0000 C CNN
F 2 "" V 9805 3450 50  0001 C CNN
F 3 "" H 9875 3450 50  0001 C CNN
	1    9875 3450
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5B80497E
P 10375 3450
F 0 "R?" V 10455 3450 50  0000 C CNN
F 1 "4k7" V 10375 3450 50  0000 C CNN
F 2 "" V 10305 3450 50  0001 C CNN
F 3 "" H 10375 3450 50  0001 C CNN
	1    10375 3450
	1    0    0    -1  
$EndComp
$Comp
L +5VA #PWR?
U 1 1 5B80497F
P 4350 4375
F 0 "#PWR?" H 4350 4225 50  0001 C CNN
F 1 "+5VA" H 4350 4515 50  0000 C CNN
F 2 "" H 4350 4375 50  0001 C CNN
F 3 "" H 4350 4375 50  0001 C CNN
	1    4350 4375
	1    0    0    -1  
$EndComp
$Comp
L LM2575-5.0BT U?
U 1 1 5B804980
P 2650 6675
F 0 "U?" H 2250 6925 50  0000 L CNN
F 1 "LM2575-5.0BT" H 2650 6925 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-220-5_Vertical" H 2650 6425 50  0001 L CIN
F 3 "" H 2650 6675 50  0001 C CNN
	1    2650 6675
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5B804981
P 2650 6975
F 0 "#PWR?" H 2650 6725 50  0001 C CNN
F 1 "GND" H 2650 6825 50  0000 C CNN
F 2 "" H 2650 6975 50  0001 C CNN
F 3 "" H 2650 6975 50  0001 C CNN
	1    2650 6975
	1    0    0    -1  
$EndComp
$Comp
L DIODE-STANDARD_RevE_Date15jun2010 D?
U 1 1 5B804982
P 3275 6975
F 0 "D?" H 3275 7125 30  0000 C CNN
F 1 "BA159" H 3275 6825 30  0000 C CNN
F 2 "" H 3275 6975 60  0001 C CNN
F 3 "BA159" H 3275 6975 60  0001 C CNN
	1    3275 6975
	0    -1   -1   0   
$EndComp
$Comp
L L L?
U 1 1 5B804983
P 3525 6775
F 0 "L?" V 3475 6775 50  0000 C CNN
F 1 "L" V 3600 6775 50  0000 C CNN
F 2 "" H 3525 6775 50  0001 C CNN
F 3 "" H 3525 6775 50  0001 C CNN
	1    3525 6775
	0    -1   -1   0   
$EndComp
$Comp
L CAPACITOR_POLARISED_RevE_Date15jun2010 C?
U 1 1 5B804984
P 3825 6975
F 0 "C?" H 3825 7125 30  0000 C CNN
F 1 "470uF 25V" H 3850 6850 30  0000 C CNN
F 2 "" H 3825 6975 60  0001 C CNN
F 3 "" H 3825 6975 60  0001 C CNN
	1    3825 6975
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 5B804985
P 4100 6925
F 0 "C?" H 4125 7025 50  0000 L CNN
F 1 "220nf" H 4125 6825 30  0000 L CNN
F 2 "" H 4138 6775 50  0001 C CNN
F 3 "" H 4100 6925 50  0001 C CNN
	1    4100 6925
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5B804986
P 3825 7175
F 0 "#PWR?" H 3825 6925 50  0001 C CNN
F 1 "GND" H 3825 7025 50  0000 C CNN
F 2 "" H 3825 7175 50  0001 C CNN
F 3 "" H 3825 7175 50  0001 C CNN
	1    3825 7175
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 5B804987
P 4100 6775
F 0 "#PWR?" H 4100 6625 50  0001 C CNN
F 1 "+5V" H 4100 6915 50  0000 C CNN
F 2 "" H 4100 6775 50  0001 C CNN
F 3 "" H 4100 6775 50  0001 C CNN
	1    4100 6775
	1    0    0    -1  
$EndComp
$Comp
L ARDUINO_NANO_R3 SH?
U 1 1 5B804988
P 6600 3225
F 0 "SH?" H 6625 2000 60  0000 C CNN
F 1 "ARDUINO_NANO_R3" H 6625 4575 60  0000 C CNN
F 2 "" H 6400 3000 60  0000 C CNN
F 3 "" H 6400 3000 60  0000 C CNN
	1    6600 3225
	1    0    0    -1  
$EndComp
$Comp
L PCF8574 U?
U 1 1 5B804989
P 2425 4900
F 0 "U?" H 2075 5500 50  0000 L CNN
F 1 "PCF8574" H 2525 5500 50  0000 L CNN
F 2 "" H 2425 4900 50  0001 C CNN
F 3 "" H 2425 4900 50  0001 C CNN
	1    2425 4900
	0    1    1    0   
$EndComp
$Comp
L WC1602A DS?
U 1 1 5B80498A
P 2250 1625
F 0 "DS?" H 2020 2375 50  0000 C CNN
F 1 "WC1602A" V 2350 1450 50  0000 C CNN
F 2 "Displays:WC1602A" H 2250 725 50  0001 C CIN
F 3 "" H 2950 1625 50  0001 C CNN
	1    2250 1625
	-1   0    0    1   
$EndComp
Text GLabel 2650 1025 2    60   Input ~ 0
D7
Text GLabel 2650 1125 2    60   Input ~ 0
D6
Text GLabel 2650 1225 2    60   Input ~ 0
D5
Text GLabel 2650 1325 2    60   Input ~ 0
D4
Text GLabel 2650 2025 2    60   Input ~ 0
RS
Text GLabel 2650 2125 2    60   Input ~ 0
R/W
Text GLabel 2650 2225 2    60   Input ~ 0
E
Text GLabel 2125 5400 3    60   Input ~ 0
D7
Text GLabel 2225 5400 3    60   Input ~ 0
D6
Text GLabel 2325 5400 3    60   Input ~ 0
D5
Text GLabel 2425 5400 3    60   Input ~ 0
D4
Text GLabel 2525 5400 3    60   Input ~ 0
BL
Text GLabel 2625 5400 3    60   Input ~ 0
E
Text GLabel 2725 5400 3    60   Input ~ 0
R/W
Text GLabel 2825 5400 3    60   Input ~ 0
R
$Comp
L +5VA #PWR?
U 1 1 5B80498B
P 3125 4900
F 0 "#PWR?" H 3125 4750 50  0001 C CNN
F 1 "+5VA" H 3125 5040 50  0000 C CNN
F 2 "" H 3125 4900 50  0001 C CNN
F 3 "" H 3125 4900 50  0001 C CNN
	1    3125 4900
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5B80498C
P 1725 4900
F 0 "#PWR?" H 1725 4650 50  0001 C CNN
F 1 "GND" H 1725 4750 50  0000 C CNN
F 2 "" H 1725 4900 50  0001 C CNN
F 3 "" H 1725 4900 50  0001 C CNN
	1    1725 4900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5B80498D
P 2250 825
F 0 "#PWR?" H 2250 575 50  0001 C CNN
F 1 "GND" H 2250 675 50  0000 C CNN
F 2 "" H 2250 825 50  0001 C CNN
F 3 "" H 2250 825 50  0001 C CNN
	1    2250 825 
	-1   0    0    1   
$EndComp
$Comp
L +5VA #PWR?
U 1 1 5B80498E
P 2250 2425
F 0 "#PWR?" H 2250 2275 50  0001 C CNN
F 1 "+5VA" H 2250 2565 50  0000 C CNN
F 2 "" H 2250 2425 50  0001 C CNN
F 3 "" H 2250 2425 50  0001 C CNN
	1    2250 2425
	-1   0    0    1   
$EndComp
$Comp
L POT RV?
U 1 1 5B80498F
P 1675 2425
F 0 "RV?" V 1500 2425 50  0000 C CNN
F 1 "POT" V 1575 2425 50  0000 C CNN
F 2 "" H 1675 2425 50  0001 C CNN
F 3 "" H 1675 2425 50  0001 C CNN
	1    1675 2425
	1    0    0    -1  
$EndComp
$Comp
L +5VA #PWR?
U 1 1 5B804990
P 1675 2275
F 0 "#PWR?" H 1675 2125 50  0001 C CNN
F 1 "+5VA" H 1675 2415 50  0000 C CNN
F 2 "" H 1675 2275 50  0001 C CNN
F 3 "" H 1675 2275 50  0001 C CNN
	1    1675 2275
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5B804991
P 1675 2575
F 0 "#PWR?" H 1675 2325 50  0001 C CNN
F 1 "GND" H 1675 2425 50  0000 C CNN
F 2 "" H 1675 2575 50  0001 C CNN
F 3 "" H 1675 2575 50  0001 C CNN
	1    1675 2575
	1    0    0    -1  
$EndComp
$Comp
L +5VA #PWR?
U 1 1 5B804992
P 1850 1925
F 0 "#PWR?" H 1850 1775 50  0001 C CNN
F 1 "+5VA" V 1775 1950 50  0000 C CNN
F 2 "" H 1850 1925 50  0001 C CNN
F 3 "" H 1850 1925 50  0001 C CNN
	1    1850 1925
	0    -1   -1   0   
$EndComp
$Comp
L BC237 Q?
U 1 1 5B804993
P 1525 1725
F 0 "Q?" V 1375 1525 50  0000 L CNN
F 1 "BC239" V 1475 1350 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Narrow" H 1725 1650 50  0001 L CIN
F 3 "" H 1525 1725 50  0001 L CNN
	1    1525 1725
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5B804994
P 1325 1825
F 0 "#PWR?" H 1325 1575 50  0001 C CNN
F 1 "GND" H 1325 1675 50  0000 C CNN
F 2 "" H 1325 1825 50  0001 C CNN
F 3 "" H 1325 1825 50  0001 C CNN
	1    1325 1825
	1    0    0    -1  
$EndComp
Text GLabel 1525 1525 1    60   Input ~ 0
BL
$Comp
L CONN_02X03 J?
U 1 1 5B804995
P 1575 4225
F 0 "J?" H 1575 4425 50  0000 C CNN
F 1 "CONN_02X03" H 1575 4025 50  0000 C CNN
F 2 "" H 1575 3025 50  0001 C CNN
F 3 "" H 1575 3025 50  0001 C CNN
	1    1575 4225
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 5B804996
P 2325 3925
F 0 "R?" V 2325 3875 50  0000 C CNN
F 1 "10K" V 2225 3925 50  0000 C CNN
F 2 "" V 2255 3925 50  0001 C CNN
F 3 "" H 2325 3925 50  0001 C CNN
	1    2325 3925
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5B804997
P 2425 3925
F 0 "R?" V 2425 3875 50  0000 C CNN
F 1 "R" V 2425 3925 50  0001 C CNN
F 2 "" V 2355 3925 50  0001 C CNN
F 3 "" H 2425 3925 50  0001 C CNN
	1    2425 3925
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5B804998
P 2525 3925
F 0 "R?" V 2525 3875 50  0000 C CNN
F 1 "R" V 2525 3925 50  0001 C CNN
F 2 "" V 2455 3925 50  0001 C CNN
F 3 "" H 2525 3925 50  0001 C CNN
	1    2525 3925
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5B804999
P 2425 3775
F 0 "#PWR?" H 2425 3525 50  0001 C CNN
F 1 "GND" H 2425 3625 50  0000 C CNN
F 2 "" H 2425 3775 50  0001 C CNN
F 3 "" H 2425 3775 50  0001 C CNN
	1    2425 3775
	-1   0    0    1   
$EndComp
$Comp
L +5VA #PWR?
U 1 1 5B80499A
P 1325 4225
F 0 "#PWR?" H 1325 4075 50  0001 C CNN
F 1 "+5VA" H 1325 4365 50  0000 C CNN
F 2 "" H 1325 4225 50  0001 C CNN
F 3 "" H 1325 4225 50  0001 C CNN
	1    1325 4225
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5B80499B
P 8550 3850
F 0 "#PWR?" H 8550 3600 50  0001 C CNN
F 1 "GND" H 8550 3700 50  0000 C CNN
F 2 "" H 8550 3850 50  0001 C CNN
F 3 "" H 8550 3850 50  0001 C CNN
	1    8550 3850
	0    -1   -1   0   
$EndComp
$Comp
L LED D?
U 1 1 5B80499C
P 10125 3750
F 0 "D?" H 10225 3725 50  0000 C CNN
F 1 "LED_G" H 10125 3650 50  0000 C CNN
F 2 "" H 10125 3750 50  0001 C CNN
F 3 "" H 10125 3750 50  0001 C CNN
	1    10125 3750
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 5B80499D
P 10125 3450
F 0 "R?" V 10205 3450 50  0000 C CNN
F 1 "4k7" V 10125 3450 50  0000 C CNN
F 2 "" V 10055 3450 50  0001 C CNN
F 3 "" H 10125 3450 50  0001 C CNN
	1    10125 3450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5B80499E
P 10125 3900
F 0 "#PWR?" H 10125 3650 50  0001 C CNN
F 1 "GND" H 10125 3750 50  0000 C CNN
F 2 "" H 10125 3900 50  0001 C CNN
F 3 "" H 10125 3900 50  0001 C CNN
	1    10125 3900
	1    0    0    -1  
$EndComp
Text GLabel 10375 3300 1    60   Input ~ 0
LED_R
Text GLabel 10125 3300 1    60   Input ~ 0
LED_G
Text GLabel 9875 3300 1    60   Input ~ 0
LED_V
Text GLabel 7400 3475 2    60   Input ~ 0
LED_R
Text GLabel 7400 3350 2    60   Input ~ 0
LED_G
Text GLabel 7400 2950 2    60   Input ~ 0
LED_V
$Comp
L SDCARD J?
U 1 1 5B80499F
P 10125 1775
F 0 "J?" H 9975 2375 60  0000 C CNN
F 1 "SDCARD" H 10125 1125 60  0000 C CNN
F 2 "" H 10125 1775 60  0001 C CNN
F 3 "" H 10125 1775 60  0001 C CNN
	1    10125 1775
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5B8049A0
P 9625 2275
F 0 "#PWR?" H 9625 2025 50  0001 C CNN
F 1 "GND" H 9625 2125 50  0000 C CNN
F 2 "" H 9625 2275 50  0001 C CNN
F 3 "" H 9625 2275 50  0001 C CNN
	1    9625 2275
	0    1    1    0   
$EndComp
$Comp
L +5VA #PWR?
U 1 1 5B8049A1
P 9625 1325
F 0 "#PWR?" H 9625 1175 50  0001 C CNN
F 1 "+5VA" H 9625 1465 50  0000 C CNN
F 2 "" H 9625 1325 50  0001 C CNN
F 3 "" H 9625 1325 50  0001 C CNN
	1    9625 1325
	0    -1   -1   0   
$EndComp
Text GLabel 7400 2325 2    60   Input ~ 0
SCK
Text GLabel 7400 2450 2    60   Input ~ 0
MISO
Text GLabel 7400 2575 2    60   Input ~ 0
MOSI
Text GLabel 7400 3725 2    60   Input ~ 0
CS
Text GLabel 9625 1475 0    60   Input ~ 0
CS
Text GLabel 9625 1575 0    60   Input ~ 0
MOSI
Text GLabel 9625 1675 0    60   Input ~ 0
MISO
Text GLabel 9625 1775 0    60   Input ~ 0
SCK
$Comp
L R R?
U 1 1 5B8049A2
P 4675 3050
F 0 "R?" V 4755 3050 50  0000 C CNN
F 1 "R" V 4675 3050 50  0000 C CNN
F 2 "" V 4605 3050 50  0001 C CNN
F 3 "" H 4675 3050 50  0001 C CNN
	1    4675 3050
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 5B8049A3
P 4675 2750
F 0 "R?" V 4755 2750 50  0000 C CNN
F 1 "R" V 4675 2750 50  0000 C CNN
F 2 "" V 4605 2750 50  0001 C CNN
F 3 "" H 4675 2750 50  0001 C CNN
	1    4675 2750
	-1   0    0    1   
$EndComp
$Comp
L C C?
U 1 1 5B8049A4
P 4475 3050
F 0 "C?" H 4500 3150 50  0000 L CNN
F 1 "C" H 4500 2950 50  0000 L CNN
F 2 "" H 4513 2900 50  0001 C CNN
F 3 "" H 4475 3050 50  0001 C CNN
	1    4475 3050
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5B8049A5
P 5100 3050
F 0 "R?" V 5180 3050 50  0000 C CNN
F 1 "R" V 5100 3050 50  0000 C CNN
F 2 "" V 5030 3050 50  0001 C CNN
F 3 "" H 5100 3050 50  0001 C CNN
	1    5100 3050
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 5B8049A6
P 5100 2750
F 0 "R?" V 5180 2750 50  0000 C CNN
F 1 "R" V 5100 2750 50  0000 C CNN
F 2 "" V 5030 2750 50  0001 C CNN
F 3 "" H 5100 2750 50  0001 C CNN
	1    5100 2750
	-1   0    0    1   
$EndComp
$Comp
L C C?
U 1 1 5B8049A7
P 4900 3050
F 0 "C?" H 4925 3150 50  0000 L CNN
F 1 "C" H 4925 2950 50  0000 L CNN
F 2 "" H 4938 2900 50  0001 C CNN
F 3 "" H 4900 3050 50  0001 C CNN
	1    4900 3050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5B8049A8
P 5100 3200
F 0 "#PWR?" H 5100 2950 50  0001 C CNN
F 1 "GND" H 5100 3050 50  0000 C CNN
F 2 "" H 5100 3200 50  0001 C CNN
F 3 "" H 5100 3200 50  0001 C CNN
	1    5100 3200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5B8049A9
P 4675 3200
F 0 "#PWR?" H 4675 2950 50  0001 C CNN
F 1 "GND" H 4675 3050 50  0000 C CNN
F 2 "" H 4675 3200 50  0001 C CNN
F 3 "" H 4675 3200 50  0001 C CNN
	1    4675 3200
	1    0    0    -1  
$EndComp
Text GLabel 4675 2600 1    60   Input ~ 0
V_IN
Text GLabel 5100 2600 1    60   Input ~ 0
V_OUT
Text GLabel 2150 6575 0    60   Input ~ 0
v_IN
$Comp
L +5VA #PWR?
U 1 1 5B8049AA
P 5850 2450
F 0 "#PWR?" H 5850 2300 50  0001 C CNN
F 1 "+5VA" H 5850 2590 50  0000 C CNN
F 2 "" H 5850 2450 50  0001 C CNN
F 3 "" H 5850 2450 50  0001 C CNN
	1    5850 2450
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5B8049AB
P 5850 2575
F 0 "#PWR?" H 5850 2325 50  0001 C CNN
F 1 "GND" H 5850 2425 50  0000 C CNN
F 2 "" H 5850 2575 50  0001 C CNN
F 3 "" H 5850 2575 50  0001 C CNN
	1    5850 2575
	0    1    1    0   
$EndComp
$Sheet
S 11975 7300 900  450 
U 5B806336
F0 "Power" 60
F1 "Power.sch" 60
$EndSheet
$EndSCHEMATC
