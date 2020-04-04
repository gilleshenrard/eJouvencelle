EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "eJouvencelle"
Date "2020-04-03"
Rev "v3.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 "License : MIT"
Comment4 "Author : Gilles Henrard"
$EndDescr
$Comp
L eJouvencelle:ATmega328P-AU U?
U 1 1 5E886BB2
P 6000 4550
F 0 "U?" H 5550 6050 50  0000 C CNN
F 1 "ATmega328P-AU" H 6400 3100 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 6000 4300 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 6000 4550 50  0001 C CNN
	1    6000 4550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E88977D
P 6000 6050
F 0 "#PWR?" H 6000 5800 50  0001 C CNN
F 1 "GND" H 6005 5877 50  0000 C CNN
F 2 "" H 6000 6050 50  0001 C CNN
F 3 "" H 6000 6050 50  0001 C CNN
	1    6000 6050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5E88AC5A
P 6000 2650
F 0 "#PWR?" H 6000 2500 50  0001 C CNN
F 1 "+5V" H 6015 2823 50  0000 C CNN
F 2 "" H 6000 2650 50  0001 C CNN
F 3 "" H 6000 2650 50  0001 C CNN
	1    6000 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 3050 6100 3000
Wire Wire Line
	6100 3000 6000 3000
Connection ~ 6000 3000
Wire Wire Line
	6000 3000 6000 3050
Wire Wire Line
	6000 2650 6000 2700
$Comp
L Device:C_Small C?
U 1 1 5E88DADF
P 6300 2900
F 0 "C?" H 6150 2950 50  0000 L CNN
F 1 "1uF" H 6100 2850 50  0000 L CNN
F 2 "" H 6300 2900 50  0001 C CNN
F 3 "~" H 6300 2900 50  0001 C CNN
	1    6300 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E88EB48
P 6450 2900
F 0 "C?" H 6500 3000 50  0000 L CNN
F 1 "4.7uF" H 6500 2800 50  0000 L CNN
F 2 "" H 6450 2900 50  0001 C CNN
F 3 "~" H 6450 2900 50  0001 C CNN
	1    6450 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E88F030
P 6750 2900
F 0 "C?" H 6842 2946 50  0000 L CNN
F 1 "1uF" H 6842 2855 50  0000 L CNN
F 2 "" H 6750 2900 50  0001 C CNN
F 3 "~" H 6750 2900 50  0001 C CNN
	1    6750 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 2800 6750 2700
Wire Wire Line
	6750 2700 6450 2700
Connection ~ 6000 2700
Wire Wire Line
	6000 2700 6000 3000
Wire Wire Line
	6450 2800 6450 2700
Connection ~ 6450 2700
Wire Wire Line
	6450 2700 6300 2700
Wire Wire Line
	6300 2800 6300 2700
Connection ~ 6300 2700
Wire Wire Line
	6300 2700 6000 2700
Wire Wire Line
	6300 3000 6300 3050
Wire Wire Line
	6300 3050 6450 3050
Wire Wire Line
	6750 3050 6750 3000
Wire Wire Line
	6450 3000 6450 3050
Connection ~ 6450 3050
Wire Wire Line
	6450 3050 6750 3050
$Comp
L power:GND #PWR?
U 1 1 5E891A89
P 6750 3050
F 0 "#PWR?" H 6750 2800 50  0001 C CNN
F 1 "GND" H 6755 2877 50  0000 C CNN
F 2 "" H 6750 3050 50  0001 C CNN
F 3 "" H 6750 3050 50  0001 C CNN
	1    6750 3050
	1    0    0    -1  
$EndComp
Connection ~ 6750 3050
$Comp
L eJouvencelle:SW_DP4T SW?
U 1 1 5E8A8418
P 1900 1250
F 0 "SW?" H 1850 1835 50  0000 C CNN
F 1 "SW_DP4T" H 1850 1744 50  0000 C CNN
F 2 "" H 1800 1400 50  0001 C CNN
F 3 "~" H 1800 1400 50  0001 C CNN
	1    1900 1250
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5E8AB0B1
P 800 1100
F 0 "J?" H 718 775 50  0000 C CNN
F 1 "Vin" H 718 866 50  0000 C CNN
F 2 "" H 800 1100 50  0001 C CNN
F 3 "~" H 800 1100 50  0001 C CNN
	1    800  1100
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E8AD4E2
P 1000 1300
F 0 "#PWR?" H 1000 1050 50  0001 C CNN
F 1 "GND" H 1005 1127 50  0000 C CNN
F 2 "" H 1000 1300 50  0001 C CNN
F 3 "" H 1000 1300 50  0001 C CNN
	1    1000 1300
	1    0    0    -1  
$EndComp
NoConn ~ 2050 850 
NoConn ~ 2050 1350
Text GLabel 2350 950  2    50   Input ~ 0
Vbatt
Wire Wire Line
	2050 1050 2300 1050
Wire Wire Line
	2300 1050 2300 950 
Wire Wire Line
	2300 950  2050 950 
Wire Wire Line
	2050 1150 2300 1150
Wire Wire Line
	2300 1150 2300 1050
Connection ~ 2300 1050
Wire Wire Line
	2350 950  2300 950 
Connection ~ 2300 950 
$Comp
L power:+5V #PWR?
U 1 1 5E8B2017
P 1550 1450
F 0 "#PWR?" H 1550 1300 50  0001 C CNN
F 1 "+5V" H 1565 1623 50  0000 C CNN
F 2 "" H 1550 1450 50  0001 C CNN
F 3 "" H 1550 1450 50  0001 C CNN
	1    1550 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 1450 1550 1500
Wire Wire Line
	1550 1500 1650 1500
Text GLabel 2500 1450 2    50   Input ~ 0
BPM1
Text GLabel 2500 1550 2    50   Input ~ 0
BPM2
Text GLabel 2500 1650 2    50   Input ~ 0
BPM3
$Comp
L Device:R R?
U 1 1 5E8B44F5
P 2100 1950
F 0 "R?" H 1950 2000 50  0000 L CNN
F 1 "10k" H 1900 1900 50  0000 L CNN
F 2 "" V 2030 1950 50  0001 C CNN
F 3 "~" H 2100 1950 50  0001 C CNN
	1    2100 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E8B514B
P 2350 1950
F 0 "R?" H 2200 2000 50  0000 L CNN
F 1 "10k" H 2150 1900 50  0000 L CNN
F 2 "" V 2280 1950 50  0001 C CNN
F 3 "~" H 2350 1950 50  0001 C CNN
	1    2350 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E8B5557
P 2450 1950
F 0 "R?" H 2550 2000 50  0000 L CNN
F 1 "10k" H 2520 1905 50  0000 L CNN
F 2 "" V 2380 1950 50  0001 C CNN
F 3 "~" H 2450 1950 50  0001 C CNN
	1    2450 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 1800 2100 1650
Wire Wire Line
	2100 1650 2050 1650
Wire Wire Line
	2350 1800 2350 1550
Wire Wire Line
	2450 1800 2450 1450
$Comp
L power:GND #PWR?
U 1 1 5E8BA2A4
P 2350 2150
F 0 "#PWR?" H 2350 1900 50  0001 C CNN
F 1 "GND" H 2355 1977 50  0000 C CNN
F 2 "" H 2350 2150 50  0001 C CNN
F 3 "" H 2350 2150 50  0001 C CNN
	1    2350 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 2100 2100 2150
Wire Wire Line
	2450 2150 2450 2100
Connection ~ 2350 2150
Wire Wire Line
	2350 2100 2350 2150
Wire Wire Line
	2500 1450 2450 1450
Connection ~ 2450 1450
Wire Wire Line
	2500 1550 2350 1550
Connection ~ 2350 1550
Wire Wire Line
	2050 1450 2450 1450
Wire Wire Line
	2050 1550 2350 1550
Wire Wire Line
	2100 1650 2500 1650
Connection ~ 2100 1650
Wire Wire Line
	2100 2150 2350 2150
Wire Wire Line
	2450 2150 2350 2150
Wire Notes Line
	650  2550 650  600 
Text Notes 700  2500 0    50   ~ 0
Main switch (DP4T) + reverse voltage protection
$Comp
L power:+5V #PWR?
U 1 1 5E8E172E
P 6650 1000
F 0 "#PWR?" H 6650 850 50  0001 C CNN
F 1 "+5V" H 6665 1173 50  0000 C CNN
F 2 "" H 6650 1000 50  0001 C CNN
F 3 "" H 6650 1000 50  0001 C CNN
	1    6650 1000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E8E3004
P 6050 1500
F 0 "#PWR?" H 6050 1250 50  0001 C CNN
F 1 "GND" H 6055 1327 50  0000 C CNN
F 2 "" H 6050 1500 50  0001 C CNN
F 3 "" H 6050 1500 50  0001 C CNN
	1    6050 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E8E579B
P 6400 1300
F 0 "C?" H 6492 1346 50  0000 L CNN
F 1 "10pF" H 6492 1255 50  0000 L CNN
F 2 "" H 6400 1300 50  0001 C CNN
F 3 "~" H 6400 1300 50  0001 C CNN
	1    6400 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 1500 6400 1500
Wire Wire Line
	6400 1500 6400 1400
Connection ~ 6050 1500
Wire Wire Line
	6400 1200 6400 1000
Wire Wire Line
	6400 1000 6350 1000
Connection ~ 6400 1000
Wire Wire Line
	6050 1300 6050 1500
$Comp
L Regulator_Linear:LM1117-5.0 U?
U 1 1 5E8E0075
P 6050 1000
F 0 "U?" H 6050 1242 50  0000 C CNN
F 1 "LM1117IMPX-5.0/NOPB" H 6050 1151 50  0000 C CNN
F 2 "" H 6050 1000 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm1117.pdf" H 6050 1000 50  0001 C CNN
	1    6050 1000
	1    0    0    -1  
$EndComp
Text GLabel 5500 1000 0    50   Input ~ 0
Vbatt
$Comp
L Device:C_Small C?
U 1 1 5E8F774D
P 5650 1300
F 0 "C?" H 5742 1346 50  0000 L CNN
F 1 "10pF" H 5742 1255 50  0000 L CNN
F 2 "" H 5650 1300 50  0001 C CNN
F 3 "~" H 5650 1300 50  0001 C CNN
	1    5650 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 1200 5650 1000
Connection ~ 5650 1000
Wire Wire Line
	5650 1000 5750 1000
Wire Wire Line
	5650 1400 5650 1500
Wire Wire Line
	5650 1500 6050 1500
Text Notes 5150 1900 0    50   ~ 0
Voltage regulation (5V)
Wire Wire Line
	6400 1000 6650 1000
Wire Notes Line
	6800 1950 6800 650 
$Comp
L Device:C_Small C?
U 1 1 5E90CACE
P 5150 3450
F 0 "C?" H 5000 3500 50  0000 L CNN
F 1 "100pF" H 4850 3450 50  0000 L CNN
F 2 "" H 5150 3450 50  0001 C CNN
F 3 "~" H 5150 3450 50  0001 C CNN
	1    5150 3450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E90D7E6
P 5150 3550
F 0 "#PWR?" H 5150 3300 50  0001 C CNN
F 1 "GND" H 5155 3377 50  0000 C CNN
F 2 "" H 5150 3550 50  0001 C CNN
F 3 "" H 5150 3550 50  0001 C CNN
	1    5150 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 3350 5150 3350
$Comp
L Connector:Conn_01x06_Female J?
U 1 1 5E912E98
P 9050 1650
F 0 "J?" H 8942 1125 50  0000 C CNN
F 1 "1X6 female header" H 8942 1216 50  0000 C CNN
F 2 "" H 9050 1650 50  0001 C CNN
F 3 "~" H 9050 1650 50  0001 C CNN
	1    9050 1650
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E9155DD
P 9350 1850
F 0 "#PWR?" H 9350 1600 50  0001 C CNN
F 1 "GND" H 9355 1677 50  0000 C CNN
F 2 "" H 9350 1850 50  0001 C CNN
F 3 "" H 9350 1850 50  0001 C CNN
	1    9350 1850
	1    0    0    -1  
$EndComp
NoConn ~ 9250 1750
$Comp
L power:+5V #PWR?
U 1 1 5E917405
P 9550 1700
F 0 "#PWR?" H 9550 1550 50  0001 C CNN
F 1 "+5V" H 9565 1873 50  0000 C CNN
F 2 "" H 9550 1700 50  0001 C CNN
F 3 "" H 9550 1700 50  0001 C CNN
	1    9550 1700
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5E91C82E
P 9550 1550
F 0 "R?" V 9600 1350 50  0000 L CNN
F 1 "1k" V 9600 1700 50  0000 L CNN
F 2 "" V 9480 1550 50  0001 C CNN
F 3 "~" H 9550 1550 50  0001 C CNN
	1    9550 1550
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5E91D625
P 9550 1450
F 0 "R?" V 9600 1250 50  0000 L CNN
F 1 "1k" V 9500 1600 50  0000 L CNN
F 2 "" V 9480 1450 50  0001 C CNN
F 3 "~" H 9550 1450 50  0001 C CNN
	1    9550 1450
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E91D857
P 9750 1250
F 0 "C?" V 9700 1100 50  0000 L CNN
F 1 "100nF" V 9600 1100 50  0000 L CNN
F 2 "" H 9750 1250 50  0001 C CNN
F 3 "~" H 9750 1250 50  0001 C CNN
	1    9750 1250
	0    1    1    0   
$EndComp
Wire Wire Line
	9350 1850 9250 1850
Wire Wire Line
	9550 1700 9550 1650
Wire Wire Line
	9550 1650 9250 1650
Wire Wire Line
	9400 1450 9250 1450
Wire Wire Line
	9400 1550 9250 1550
Text GLabel 9950 1450 2    50   Input ~ 0
TX
Wire Wire Line
	9950 1450 9700 1450
Text GLabel 9950 1550 2    50   Input ~ 0
RX
Wire Wire Line
	9950 1550 9700 1550
Text GLabel 9950 1250 2    50   Input ~ 0
RST
Wire Wire Line
	9250 1350 9650 1350
Wire Wire Line
	9650 1350 9650 1250
$Comp
L Device:R R?
U 1 1 5E9329C4
P 9900 1050
F 0 "R?" H 9750 950 50  0000 L CNN
F 1 "100k" H 9650 1050 50  0000 L CNN
F 2 "" V 9830 1050 50  0001 C CNN
F 3 "~" H 9900 1050 50  0001 C CNN
	1    9900 1050
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5E933D66
P 9900 900
F 0 "#PWR?" H 9900 750 50  0001 C CNN
F 1 "+5V" H 9915 1073 50  0000 C CNN
F 2 "" H 9900 900 50  0001 C CNN
F 3 "" H 9900 900 50  0001 C CNN
	1    9900 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 1200 9900 1250
Wire Wire Line
	9900 1250 9850 1250
Wire Wire Line
	9950 1250 9900 1250
Connection ~ 9900 1250
Wire Notes Line
	10450 600  10450 2350
Wire Notes Line
	10450 2350 8650 2350
Wire Notes Line
	8650 2350 8650 600 
Wire Notes Line
	8650 600  10450 600 
Text Notes 8700 2300 0    50   ~ 0
FTDI header (reprogramming)
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 5E94B563
P 1250 1100
F 0 "Q?" V 1592 1100 50  0000 C CNN
F 1 "PPMT30V4" V 1501 1100 50  0000 C CNN
F 2 "" H 1450 1200 50  0001 C CNN
F 3 "~" H 1250 1100 50  0001 C CNN
	1    1250 1100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1000 1100 1000 1300
Wire Wire Line
	1050 1000 1000 1000
Wire Wire Line
	1250 1300 1000 1300
Connection ~ 1000 1300
Wire Wire Line
	1650 1000 1450 1000
Wire Notes Line
	2900 2550 2900 600 
Wire Notes Line
	650  600  2900 600 
Wire Notes Line
	650  2550 2900 2550
Wire Wire Line
	5500 1000 5650 1000
Wire Notes Line
	6800 650  5100 650 
Wire Notes Line
	5100 650  5100 1950
Wire Notes Line
	5100 1950 6800 1950
$Comp
L Switch:SW_Push_Dual_x2 SW?
U 1 1 5E988120
P 3650 6700
F 0 "SW?" H 3650 6985 50  0000 C CNN
F 1 "START/PAUSE" H 3650 6894 50  0000 C CNN
F 2 "" H 3650 6900 50  0001 C CNN
F 3 "~" H 3650 6900 50  0001 C CNN
	1    3650 6700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E9886EF
P 3850 6800
F 0 "#PWR?" H 3850 6550 50  0001 C CNN
F 1 "GND" H 3855 6627 50  0000 C CNN
F 2 "" H 3850 6800 50  0001 C CNN
F 3 "" H 3850 6800 50  0001 C CNN
	1    3850 6800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E9894CA
P 3250 6950
F 0 "#PWR?" H 3250 6700 50  0001 C CNN
F 1 "GND" H 3255 6777 50  0000 C CNN
F 2 "" H 3250 6950 50  0001 C CNN
F 3 "" H 3250 6950 50  0001 C CNN
	1    3250 6950
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E98A244
P 3250 6850
F 0 "C?" H 3342 6896 50  0000 L CNN
F 1 "100nF" H 3342 6805 50  0000 L CNN
F 2 "" H 3250 6850 50  0001 C CNN
F 3 "~" H 3250 6850 50  0001 C CNN
	1    3250 6850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E98C381
P 3000 6700
F 0 "R?" V 3200 6700 50  0000 L CNN
F 1 "10k" V 3100 6650 50  0000 L CNN
F 2 "" V 2930 6700 50  0001 C CNN
F 3 "~" H 3000 6700 50  0001 C CNN
	1    3000 6700
	0    -1   -1   0   
$EndComp
Text GLabel 2800 6700 0    50   Input ~ 0
Btn1
Wire Wire Line
	3850 6700 3850 6800
Wire Wire Line
	3450 6700 3250 6700
Wire Wire Line
	3250 6750 3250 6700
Connection ~ 3250 6700
Wire Wire Line
	3250 6700 3150 6700
Wire Wire Line
	2850 6700 2800 6700
$Comp
L Switch:SW_Push_Dual_x2 SW?
U 1 1 5E9A157F
P 2000 6700
F 0 "SW?" H 2000 6985 50  0000 C CNN
F 1 "RESET" H 2000 6894 50  0000 C CNN
F 2 "" H 2000 6900 50  0001 C CNN
F 3 "~" H 2000 6900 50  0001 C CNN
	1    2000 6700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E9A1585
P 2200 6800
F 0 "#PWR?" H 2200 6550 50  0001 C CNN
F 1 "GND" H 2205 6627 50  0000 C CNN
F 2 "" H 2200 6800 50  0001 C CNN
F 3 "" H 2200 6800 50  0001 C CNN
	1    2200 6800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E9A158B
P 1600 6950
F 0 "#PWR?" H 1600 6700 50  0001 C CNN
F 1 "GND" H 1605 6777 50  0000 C CNN
F 2 "" H 1600 6950 50  0001 C CNN
F 3 "" H 1600 6950 50  0001 C CNN
	1    1600 6950
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E9A1591
P 1600 6850
F 0 "C?" H 1692 6896 50  0000 L CNN
F 1 "100nF" H 1692 6805 50  0000 L CNN
F 2 "" H 1600 6850 50  0001 C CNN
F 3 "~" H 1600 6850 50  0001 C CNN
	1    1600 6850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E9A1597
P 1350 6700
F 0 "R?" V 1550 6700 50  0000 L CNN
F 1 "10k" V 1450 6650 50  0000 L CNN
F 2 "" V 1280 6700 50  0001 C CNN
F 3 "~" H 1350 6700 50  0001 C CNN
	1    1350 6700
	0    -1   -1   0   
$EndComp
Text GLabel 1150 6700 0    50   Input ~ 0
Btn2
Wire Wire Line
	2200 6700 2200 6800
Wire Wire Line
	1800 6700 1600 6700
Wire Wire Line
	1600 6750 1600 6700
Connection ~ 1600 6700
Wire Wire Line
	1600 6700 1500 6700
Wire Wire Line
	1200 6700 1150 6700
Wire Notes Line
	4050 6250 4050 7450
Wire Notes Line
	4050 7450 800  7450
Wire Notes Line
	800  7450 800  6250
Wire Notes Line
	800  6250 4050 6250
Text Notes 850  7400 0    50   ~ 0
Buttons w/ hardware debouncing
Text GLabel 6650 5350 2    50   Input ~ 0
Btn2
Text GLabel 6650 5250 2    50   Input ~ 0
Btn1
Text GLabel 6650 5150 2    50   Input ~ 0
TX
Text GLabel 6650 5050 2    50   Input ~ 0
RX
Text GLabel 6650 4000 2    50   Input ~ 0
RST
Text GLabel 6650 5450 2    50   Input ~ 0
BPM3
Text GLabel 5350 5450 0    50   Input ~ 0
BPM1
Text GLabel 5350 5250 0    50   Input ~ 0
BPM2
Wire Wire Line
	6650 4000 6600 4000
Wire Wire Line
	6650 5050 6600 5050
Wire Wire Line
	6650 5150 6600 5150
Wire Wire Line
	6600 5250 6650 5250
Wire Wire Line
	6650 5350 6600 5350
Wire Wire Line
	6600 5450 6650 5450
Wire Wire Line
	5400 5450 5350 5450
Wire Wire Line
	5350 5250 5400 5250
$Comp
L Device:Crystal_Small Y?
U 1 1 5E9C7E98
P 5050 4500
F 0 "Y?" H 5050 4725 50  0000 C CNN
F 1 "16MHz" H 5050 4634 50  0000 C CNN
F 2 "" H 5050 4500 50  0001 C CNN
F 3 "~" H 5050 4500 50  0001 C CNN
	1    5050 4500
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E9C9A95
P 4950 4350
F 0 "C?" V 4700 4300 50  0000 L CNN
F 1 "22pF" V 4800 4300 50  0000 L CNN
F 2 "" H 4950 4350 50  0001 C CNN
F 3 "~" H 4950 4350 50  0001 C CNN
	1    4950 4350
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E9CA38F
P 4950 4650
F 0 "C?" V 5050 4600 50  0000 L CNN
F 1 "22pF" V 5150 4600 50  0000 L CNN
F 2 "" H 4950 4650 50  0001 C CNN
F 3 "~" H 4950 4650 50  0001 C CNN
	1    4950 4650
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E9CA80F
P 4850 4500
F 0 "#PWR?" H 4850 4250 50  0001 C CNN
F 1 "GND" H 4855 4327 50  0000 C CNN
F 2 "" H 4850 4500 50  0001 C CNN
F 3 "" H 4850 4500 50  0001 C CNN
	1    4850 4500
	0    1    1    0   
$EndComp
Wire Wire Line
	5050 4650 5050 4600
Wire Wire Line
	5050 4400 5050 4350
Wire Wire Line
	4850 4350 4850 4500
Connection ~ 4850 4500
Wire Wire Line
	4850 4500 4850 4650
Wire Wire Line
	5350 4650 5050 4650
Connection ~ 5050 4650
Wire Wire Line
	5350 4350 5050 4350
Connection ~ 5050 4350
Wire Wire Line
	5350 4350 5350 4450
Wire Wire Line
	5350 4650 5350 4550
Wire Wire Line
	5350 4450 5400 4450
Wire Wire Line
	5350 4550 5400 4550
$Comp
L eJouvencelle:CD4511 U?
U 1 1 5E88C72D
P 8550 3700
F 0 "U?" H 8300 4250 50  0000 C CNN
F 1 "CD4511" H 8350 4150 50  0000 C CNN
F 2 "" H 8550 3700 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4543b.pdf" H 8550 3700 50  0001 C CNN
	1    8550 3700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5E88FEF1
P 8550 2850
F 0 "#PWR?" H 8550 2700 50  0001 C CNN
F 1 "+5V" H 8565 3023 50  0000 C CNN
F 2 "" H 8550 2850 50  0001 C CNN
F 3 "" H 8550 2850 50  0001 C CNN
	1    8550 2850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E890F98
P 8550 4300
F 0 "#PWR?" H 8550 4050 50  0001 C CNN
F 1 "GND" H 8555 4127 50  0000 C CNN
F 2 "" H 8550 4300 50  0001 C CNN
F 3 "" H 8550 4300 50  0001 C CNN
	1    8550 4300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E89153F
P 8750 3100
F 0 "#PWR?" H 8750 2850 50  0001 C CNN
F 1 "GND" H 8750 2950 50  0000 C CNN
F 2 "" H 8750 3100 50  0001 C CNN
F 3 "" H 8750 3100 50  0001 C CNN
	1    8750 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E891BA1
P 8750 3000
F 0 "C?" H 8842 3046 50  0000 L CNN
F 1 "1uF" H 8842 2955 50  0000 L CNN
F 2 "" H 8750 3000 50  0001 C CNN
F 3 "~" H 8750 3000 50  0001 C CNN
	1    8750 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 2850 8550 2900
Wire Wire Line
	8750 2900 8550 2900
Connection ~ 8550 2900
Wire Wire Line
	8550 2900 8550 3100
$Comp
L power:+5V #PWR?
U 1 1 5E89B064
P 8000 3100
F 0 "#PWR?" H 8000 2950 50  0001 C CNN
F 1 "+5V" H 8015 3273 50  0000 C CNN
F 2 "" H 8000 3100 50  0001 C CNN
F 3 "" H 8000 3100 50  0001 C CNN
	1    8000 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 3700 7200 3600
Wire Wire Line
	7200 3600 6600 3600
Wire Wire Line
	7100 3800 7100 3700
Wire Wire Line
	7100 3700 6600 3700
Wire Wire Line
	7000 3900 7000 3800
Wire Wire Line
	7000 3800 6600 3800
Wire Wire Line
	6900 4000 6900 3900
Wire Wire Line
	6900 3900 6600 3900
$Comp
L Device:R R?
U 1 1 5E8C3C3B
P 9450 3400
F 0 "R?" V 9400 3500 50  0000 L CNN
F 1 "270R" V 9400 3100 50  0000 L CNN
F 2 "" V 9380 3400 50  0001 C CNN
F 3 "~" H 9450 3400 50  0001 C CNN
	1    9450 3400
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5E8C5DAE
P 9450 3500
F 0 "R?" V 9400 3600 50  0000 L CNN
F 1 "270R" V 9400 3200 50  0000 L CNN
F 2 "" V 9380 3500 50  0001 C CNN
F 3 "~" H 9450 3500 50  0001 C CNN
	1    9450 3500
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5E8C62CF
P 9450 3600
F 0 "R?" V 9400 3700 50  0000 L CNN
F 1 "270R" V 9400 3300 50  0000 L CNN
F 2 "" V 9380 3600 50  0001 C CNN
F 3 "~" H 9450 3600 50  0001 C CNN
	1    9450 3600
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5E8C65DA
P 9450 3700
F 0 "R?" V 9400 3800 50  0000 L CNN
F 1 "270R" V 9400 3400 50  0000 L CNN
F 2 "" V 9380 3700 50  0001 C CNN
F 3 "~" H 9450 3700 50  0001 C CNN
	1    9450 3700
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5E8C683A
P 9450 3800
F 0 "R?" V 9400 3900 50  0000 L CNN
F 1 "270R" V 9400 3500 50  0000 L CNN
F 2 "" V 9380 3800 50  0001 C CNN
F 3 "~" H 9450 3800 50  0001 C CNN
	1    9450 3800
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5E8C6BCA
P 9450 3900
F 0 "R?" V 9400 4000 50  0000 L CNN
F 1 "270R" V 9400 3600 50  0000 L CNN
F 2 "" V 9380 3900 50  0001 C CNN
F 3 "~" H 9450 3900 50  0001 C CNN
	1    9450 3900
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5E8C6F2C
P 9450 4000
F 0 "R?" V 9400 4100 50  0000 L CNN
F 1 "270R" V 9400 3700 50  0000 L CNN
F 2 "" V 9380 4000 50  0001 C CNN
F 3 "~" H 9450 4000 50  0001 C CNN
	1    9450 4000
	0    1    1    0   
$EndComp
$Comp
L eJouvencelle:FJ11001AH U?
U 1 1 5E91DF8A
P 10200 3700
F 0 "U?" H 10200 4367 50  0000 C CNN
F 1 "FJ11001AH" H 10200 4276 50  0000 C CNN
F 2 "Display_7Segment:HDSP-7801" H 10200 3150 50  0001 C CNN
F 3 "https://docs.broadcom.com/docs/AV02-2553EN" H 10200 3700 50  0001 C CNN
	1    10200 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E923BE0
P 10550 4200
F 0 "#PWR?" H 10550 3950 50  0001 C CNN
F 1 "GND" H 10550 4050 50  0000 C CNN
F 2 "" H 10550 4200 50  0001 C CNN
F 3 "" H 10550 4200 50  0001 C CNN
	1    10550 4200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E924C4B
P 9850 4200
F 0 "#PWR?" H 9850 3950 50  0001 C CNN
F 1 "GND" H 9850 4050 50  0000 C CNN
F 2 "" H 9850 4200 50  0001 C CNN
F 3 "" H 9850 4200 50  0001 C CNN
	1    9850 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	10550 4200 10550 4100
Wire Wire Line
	10550 4000 10500 4000
Wire Wire Line
	10550 4100 10500 4100
Connection ~ 10550 4100
Wire Wire Line
	10550 4100 10550 4000
Wire Wire Line
	9850 4200 9850 4100
Wire Wire Line
	9850 4100 9900 4100
Wire Wire Line
	9300 3400 9050 3400
Wire Wire Line
	9300 3500 9050 3500
Wire Wire Line
	9300 3600 9050 3600
Wire Wire Line
	9300 3700 9050 3700
Wire Wire Line
	9300 3800 9050 3800
Wire Wire Line
	9300 3900 9050 3900
Wire Wire Line
	9300 4000 9050 4000
Wire Wire Line
	9600 3400 9900 3400
Wire Wire Line
	9600 3500 9900 3500
Wire Wire Line
	9600 3600 9900 3600
Wire Wire Line
	9600 3700 9900 3700
Wire Wire Line
	9600 3800 9900 3800
Wire Wire Line
	9600 3900 9900 3900
Wire Wire Line
	9600 4000 9900 4000
Wire Wire Line
	8000 3100 8000 3600
Wire Wire Line
	8000 3600 8050 3600
Wire Wire Line
	6600 3400 8050 3400
Wire Wire Line
	6600 3500 8050 3500
Wire Wire Line
	7200 3700 8050 3700
Wire Wire Line
	7100 3800 8050 3800
Wire Wire Line
	7000 3900 8050 3900
Wire Wire Line
	6900 4000 8050 4000
Wire Notes Line
	10800 2500 10800 4800
Wire Notes Line
	10800 4800 7700 4800
Wire Notes Line
	7700 4800 7700 2500
Wire Notes Line
	7700 2500 10800 2500
Text Notes 7800 4750 0    50   ~ 0
7-segment w/ BCD decoder
$Comp
L Device:Buzzer BZ?
U 1 1 5E9C10D5
P 1700 4050
F 0 "BZ?" H 1852 4079 50  0000 L CNN
F 1 "GPC3010YB-5V" H 1852 3988 50  0000 L CNN
F 2 "" V 1675 4150 50  0001 C CNN
F 3 "~" V 1675 4150 50  0001 C CNN
	1    1700 4050
	-1   0    0    -1  
$EndComp
Text GLabel 1800 3500 1    50   Input ~ 0
Vbatt
$Comp
L Device:R R?
U 1 1 5EA2CADF
P 1800 3700
F 0 "R?" H 1600 3750 50  0000 L CNN
F 1 "2.2k" H 1550 3650 50  0000 L CNN
F 2 "" V 1730 3700 50  0001 C CNN
F 3 "~" H 1800 3700 50  0001 C CNN
	1    1800 3700
	-1   0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_DGS Q?
U 1 1 5EA2D5DD
P 1900 4400
F 0 "Q?" H 2104 4446 50  0000 L CNN
F 1 "RFM04U6P(TE12L,F)" H 2104 4355 50  0000 L CNN
F 2 "" H 2100 4500 50  0001 C CNN
F 3 "~" H 1900 4400 50  0001 C CNN
	1    1900 4400
	-1   0    0    -1  
$EndComp
Text GLabel 2300 4400 2    50   Input ~ 0
Buzzer
$Comp
L power:GND #PWR?
U 1 1 5EA2FE7F
P 1800 4900
F 0 "#PWR?" H 1800 4650 50  0001 C CNN
F 1 "GND" H 1805 4727 50  0000 C CNN
F 2 "" H 1800 4900 50  0001 C CNN
F 3 "" H 1800 4900 50  0001 C CNN
	1    1800 4900
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5EA30E37
P 2200 4650
F 0 "R?" H 2300 4600 50  0000 L CNN
F 1 "10k" H 2300 4700 50  0000 L CNN
F 2 "" V 2130 4650 50  0001 C CNN
F 3 "~" H 2200 4650 50  0001 C CNN
	1    2200 4650
	1    0    0    1   
$EndComp
Wire Wire Line
	1800 3500 1800 3550
Wire Wire Line
	1800 3850 1800 3950
Wire Wire Line
	1800 4150 1800 4200
Wire Wire Line
	1800 4600 1800 4800
Wire Wire Line
	2300 4400 2200 4400
Wire Wire Line
	2200 4400 2200 4500
Connection ~ 2200 4400
Wire Wire Line
	2200 4400 2100 4400
Wire Wire Line
	2200 4800 1800 4800
Connection ~ 1800 4800
Wire Wire Line
	1800 4800 1800 4900
Wire Notes Line
	2900 3200 2900 5350
Wire Notes Line
	2900 5350 850  5350
Wire Notes Line
	850  5350 850  3200
Wire Notes Line
	850  3200 2900 3200
Text Notes 900  5300 0    50   ~ 0
MOSFET-driven buzzer
Text GLabel 5350 5350 0    50   Input ~ 0
Buzzer
Wire Wire Line
	5400 5350 5350 5350
$EndSCHEMATC
