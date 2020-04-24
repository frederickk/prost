EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	2850 5950 2750 5950
$Comp
L prost-pcb-rescue:Device_LED_CRGB D1
U 1 1 5EA1AE32
P 3600 4650
F 0 "D1" H 3600 5147 39  0000 C CNN
F 1 "LED_CRGB" H 3600 5056 39  0000 C CNN
F 2 "LED:LED_5MM_RGB" H 3600 4600 39  0001 C CNN
F 3 "~" H 3600 4600 39  0001 C CNN
	1    3600 4650
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2100 5150 2000 5150
$Comp
L prost-pcb-rescue:SparkFun-Boards_SPARKFUN_PRO_MICRO MCA1
U 1 1 5EA0D962
P 2550 4800
F 0 "MCA1" H 2550 3996 39  0000 C CNN
F 1 "SPARKFUN_PRO_MICRO" H 2550 4080 39  0000 C CNN
F 2 "Boards:SPARKFUN_PRO_MICRO" H 2550 5600 20  0001 C CNN
F 3 "" H 2550 4800 50  0001 C CNN
F 4 "" H 2550 5531 60  0001 C CNN "Field4"
	1    2550 4800
	-1   0    0    1   
$EndComp
Wire Wire Line
	4500 6700 4100 6700
Wire Wire Line
	3800 4650 3850 4650
Wire Wire Line
	2750 5550 2750 5950
Wire Wire Line
	3250 6050 3250 6150
Wire Wire Line
	3400 4550 3400 4450
$Comp
L prost-pcb-rescue:Device_R_Small_US R1
U 1 1 5EA37809
P 5650 4400
F 0 "R1" V 5469 4400 39  0000 C CNN
F 1 "220" V 5544 4400 39  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" H 5650 4400 50  0001 C CNN
F 3 "~" H 5650 4400 50  0001 C CNN
	1    5650 4400
	0    1    1    0   
$EndComp
$Comp
L prost-pcb-rescue:SparkFun-Boards_SPARKFUN_PRO_MICRO MCB1
U 1 1 5EA108D1
P 5150 5800
F 0 "MCB1" H 5150 6604 39  0000 C CNN
F 1 "SPARKFUN_PRO_MICRO" H 5150 6520 39  0000 C CNN
F 2 "Boards:SPARKFUN_PRO_MICRO" H 5150 6600 20  0001 C CNN
F 3 "" H 5150 5800 50  0001 C CNN
F 4 "" H 5150 6531 60  0001 C CNN "Field4"
	1    5150 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 5450 5750 5450
Wire Wire Line
	5750 5450 5750 6600
Wire Wire Line
	3000 4550 3400 4550
Wire Wire Line
	3000 4650 3400 4650
Wire Wire Line
	3000 4850 3400 4850
$Comp
L prost-pcb-rescue:Device_LED_CRGB D2
U 1 1 5EA273C8
P 3050 5950
F 0 "D2" H 3050 6447 39  0000 C CNN
F 1 "LED_CRGB" H 3050 6356 39  0000 C CNN
F 2 "LED:LED_5MM_RGB" H 3050 5900 39  0001 C CNN
F 3 "~" H 3050 5900 39  0001 C CNN
	1    3050 5950
	1    0    0    1   
$EndComp
Wire Wire Line
	4700 6050 3250 6050
Wire Wire Line
	3250 5950 4700 5950
Wire Wire Line
	3250 5750 4700 5750
Connection ~ 3850 5550
$Comp
L prost-pcb-rescue:Device_R_Small_US R2
U 1 1 5EA6A42C
P 4650 4400
F 0 "R2" V 4469 4400 39  0000 C CNN
F 1 "220" V 4544 4400 39  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" H 4650 4400 50  0001 C CNN
F 3 "~" H 4650 4400 50  0001 C CNN
	1    4650 4400
	0    1    1    0   
$EndComp
Wire Wire Line
	4550 4400 4550 5250
Wire Wire Line
	4550 5250 4700 5250
Wire Wire Line
	3850 6650 4100 6650
Wire Wire Line
	4100 6700 4100 6650
Wire Wire Line
	4500 6700 4500 6650
Wire Wire Line
	2750 5550 3850 5550
Wire Wire Line
	3850 5550 3850 6650
Wire Wire Line
	4550 5250 3000 5250
Connection ~ 4550 5250
Wire Wire Line
	3000 5350 4700 5350
Wire Wire Line
	2000 5150 2000 6600
Wire Wire Line
	2000 6600 4100 6600
Connection ~ 3850 4650
Wire Wire Line
	3850 4650 5150 4650
Wire Wire Line
	3000 5150 3850 5150
Connection ~ 3850 5150
Wire Wire Line
	3850 5150 3850 5450
Wire Wire Line
	3850 4650 3850 5150
Wire Wire Line
	4700 5450 3850 5450
Connection ~ 3850 5450
Wire Wire Line
	3850 5450 3850 5550
Wire Wire Line
	4500 6600 5750 6600
Connection ~ 4100 6650
$Comp
L prost-pcb-rescue:button_no_01x02_Button_NO_01x02 S1
U 1 1 5EA27559
P 4300 6600
F 0 "S1" H 4300 6811 39  0000 C CNN
F 1 "MOMENTARY_SWITCH_SPST" H 4300 6736 39  0000 C CNN
F 2 "Switches:MINI_PUSHBUTTON_SWITCH" H 4300 6550 39  0001 C CNN
F 3 "" H 4300 6550 39  0000 C CNN
	1    4300 6600
	1    0    0    -1  
$EndComp
NoConn ~ 5450 4300
NoConn ~ 4850 4300
Wire Wire Line
	3850 3950 3850 4650
Wire Wire Line
	4050 3950 4050 4050
Wire Wire Line
	4050 4050 3950 4050
Wire Wire Line
	3950 4050 3950 3950
Wire Wire Line
	4700 6350 3950 6350
Wire Wire Line
	3950 6350 3950 4050
Connection ~ 3950 4050
NoConn ~ 2100 4250
NoConn ~ 2100 4350
NoConn ~ 2100 4450
NoConn ~ 2100 4550
NoConn ~ 2100 4650
NoConn ~ 2100 4750
NoConn ~ 2100 4850
NoConn ~ 2100 4950
NoConn ~ 2100 5050
NoConn ~ 2100 5350
NoConn ~ 3000 4950
NoConn ~ 3000 4750
NoConn ~ 3000 4450
NoConn ~ 3000 4350
NoConn ~ 3000 4250
NoConn ~ 4700 6250
NoConn ~ 4700 6150
NoConn ~ 4700 5850
NoConn ~ 4700 5650
NoConn ~ 5600 5250
NoConn ~ 5600 5650
NoConn ~ 5600 5750
NoConn ~ 5600 5850
NoConn ~ 5600 5950
NoConn ~ 5600 6050
NoConn ~ 5600 6150
NoConn ~ 5600 6250
NoConn ~ 5600 6350
Wire Wire Line
	5600 5550 5850 5550
Wire Wire Line
	5850 5550 5850 4400
Wire Wire Line
	5850 4400 5750 4400
$Comp
L power:GND #PWR0101
U 1 1 5EBF6900
P 3850 6900
F 0 "#PWR0101" H 3850 6650 50  0001 C CNN
F 1 "GND" H 3855 6727 50  0000 C CNN
F 2 "" H 3850 6900 50  0001 C CNN
F 3 "" H 3850 6900 50  0001 C CNN
	1    3850 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 6650 3850 6900
Connection ~ 3850 6650
$Comp
L power:GND #PWR0102
U 1 1 5EBF7BB0
P 3100 5050
F 0 "#PWR0102" H 3100 4800 50  0001 C CNN
F 1 "GND" V 3105 4922 50  0000 R CNN
F 2 "" H 3100 5050 50  0001 C CNN
F 3 "" H 3100 5050 50  0001 C CNN
	1    3100 5050
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5EBF8594
P 5700 5350
F 0 "#PWR0103" H 5700 5100 50  0001 C CNN
F 1 "GND" V 5705 5222 50  0000 R CNN
F 2 "" H 5700 5350 50  0001 C CNN
F 3 "" H 5700 5350 50  0001 C CNN
	1    5700 5350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5700 5350 5600 5350
Wire Wire Line
	3100 5050 3000 5050
$Comp
L power:GND #PWR0104
U 1 1 5EBFCD0F
P 4600 5550
F 0 "#PWR0104" H 4600 5300 50  0001 C CNN
F 1 "GND" V 4605 5422 50  0000 R CNN
F 2 "" H 4600 5550 50  0001 C CNN
F 3 "" H 4600 5550 50  0001 C CNN
	1    4600 5550
	0    1    1    0   
$EndComp
Wire Wire Line
	4700 5550 4600 5550
$Comp
L power:GND #PWR0105
U 1 1 5EBFECF3
P 1900 5250
F 0 "#PWR0105" H 1900 5000 50  0001 C CNN
F 1 "GND" V 1905 5122 50  0000 R CNN
F 2 "" H 1900 5250 50  0001 C CNN
F 3 "" H 1900 5250 50  0001 C CNN
	1    1900 5250
	0    1    1    0   
$EndComp
Wire Wire Line
	1900 5250 2100 5250
$Comp
L Connector:AudioJack3 J2
U 1 1 5EBC0CC1
P 3950 3750
F 0 "J2" V 3886 3520 50  0000 R CNN
F 1 "MONO 3.5mm AUDIO JACK" V 3977 3520 50  0000 R CNN
F 2 "prost:Jack_3.5mm_CUI_SJ-3523-SMT_Horizontal" H 3950 3750 50  0001 C CNN
F 3 "~" H 3950 3750 50  0001 C CNN
	1    3950 3750
	0    -1   1    0   
$EndComp
$Comp
L prost-pcb-rescue:Connector_DIN-5_TRS_180degree J1
U 1 1 5EA4206C
P 5150 4300
F 0 "J1" H 5150 3957 39  0000 C CNN
F 1 "MIDI-DIN-5" H 5150 4032 39  0000 C CNN
F 2 "prost:Jack_3.5mm_CUI_SJ-3523-SMT_Horizontal" H 5150 4300 50  0001 C CNN
F 3 "" H 5150 4300 50  0001 C CNN
	1    5150 4300
	-1   0    0    1   
$EndComp
Wire Wire Line
	4750 4400 4850 4400
Wire Wire Line
	5150 4650 5150 4600
Wire Wire Line
	5450 4400 5550 4400
$EndSCHEMATC
