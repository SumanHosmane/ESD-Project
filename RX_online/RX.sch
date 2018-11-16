EESchema Schematic File Version 4
LIBS:RX-cache
EELAYER 26 0
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
$Comp
L C501Lib:C501 U?
U 1 1 5BCB5F5E
P 1950 5050
F 0 "U?" H 5500 7865 50  0001 C CNN
F 1 "AT89C51RC2" H 5500 7773 50  0000 C CNN
F 2 "" H 5600 7250 50  0001 C CNN
F 3 "" H 5600 7250 50  0001 C CNN
	1    1950 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5BCB6D02
P 6200 2500
F 0 "C?" V 5971 2500 50  0001 C CNN
F 1 "0.1uF" V 6063 2500 50  0000 C CNN
F 2 "" H 6200 2500 50  0001 C CNN
F 3 "~" H 6200 2500 50  0001 C CNN
	1    6200 2500
	0    1    1    0   
$EndComp
Text GLabel 6300 2500 2    50   Input ~ 0
GND
Text GLabel 4900 4400 0    50   Input ~ 0
GND
$Comp
L Device:C_Small C?
U 1 1 5BCB7B38
P 3800 3950
F 0 "C?" V 3571 3950 50  0001 C CNN
F 1 "1uF" V 3663 3950 50  0000 C CNN
F 2 "" H 3800 3950 50  0001 C CNN
F 3 "~" H 3800 3950 50  0001 C CNN
	1    3800 3950
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5BCB7B72
P 3800 4250
F 0 "C?" V 3571 4250 50  0001 C CNN
F 1 "1uF" V 3663 4250 50  0000 C CNN
F 2 "" H 3800 4250 50  0001 C CNN
F 3 "~" H 3800 4250 50  0001 C CNN
	1    3800 4250
	0    1    1    0   
$EndComp
$Comp
L Device:Crystal DF?
U 1 1 5BCB7BB3
P 4250 4100
F 0 "DF?" V 4204 4231 50  0001 L CNN
F 1 "Crystal" V 4295 4231 50  0000 L CNN
F 2 "" H 4250 4100 50  0001 C CNN
F 3 "~" H 4250 4100 50  0001 C CNN
	1    4250 4100
	0    1    1    0   
$EndComp
Wire Wire Line
	3700 3950 3600 3950
Wire Wire Line
	3600 3950 3600 4250
Wire Wire Line
	3600 4250 3700 4250
Wire Wire Line
	4800 3950 4800 4200
Wire Wire Line
	4800 4200 4900 4200
Wire Wire Line
	4800 4250 4800 4300
Wire Wire Line
	4800 4300 4900 4300
Text HLabel 4750 3500 0    50   Input ~ 10
RF_RX_Module
$Comp
L Device:D_Small 1N4148
U 1 1 5BD35F5D
P 3650 3350
F 0 "1N4148" V 3650 3418 50  0000 L CNN
F 1 "D_Small" V 3695 3418 50  0001 L CNN
F 2 "" V 3650 3350 50  0001 C CNN
F 3 "~" V 3650 3350 50  0001 C CNN
	1    3650 3350
	0    1    1    0   
$EndComp
$Comp
L Device:R_US 10K
U 1 1 5BD3605F
P 3650 2950
F 0 "10K" H 3718 2950 50  0000 L CNN
F 1 "R_US" H 3718 2905 50  0001 L CNN
F 2 "" V 3690 2940 50  0001 C CNN
F 3 "~" H 3650 2950 50  0001 C CNN
	1    3650 2950
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US 10K
U 1 1 5BD3614C
P 4150 3300
F 0 "10K" H 4218 3300 50  0000 L CNN
F 1 "R_US" H 4218 3255 50  0001 L CNN
F 2 "" V 4190 3290 50  0001 C CNN
F 3 "~" H 4150 3300 50  0001 C CNN
	1    4150 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small 10uF
U 1 1 5BD36204
P 4150 2900
F 0 "10uF" H 4242 2900 50  0000 L CNN
F 1 "C_Small" H 4242 2855 50  0001 L CNN
F 2 "" H 4150 2900 50  0001 C CNN
F 3 "~" H 4150 2900 50  0001 C CNN
	1    4150 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small 10uF
U 1 1 5BD36250
P 4450 2900
F 0 "10uF" H 4542 2900 50  0000 L CNN
F 1 "C_Small" H 4542 2855 50  0001 L CNN
F 2 "" H 4450 2900 50  0001 C CNN
F 3 "~" H 4450 2900 50  0001 C CNN
	1    4450 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 3000 4450 3000
Wire Wire Line
	4150 2800 4450 2800
Wire Wire Line
	3650 2600 4150 2600
Wire Wire Line
	4150 2600 4150 2800
Wire Wire Line
	4900 3300 4500 3300
Wire Wire Line
	3650 3450 4150 3450
Wire Wire Line
	4500 3300 4500 3150
Wire Wire Line
	4500 3150 4150 3150
Wire Wire Line
	3650 3100 4150 3100
Wire Wire Line
	3650 3250 3650 3100
Text GLabel 3900 2600 1    50   Input ~ 0
5V
Text GLabel 3900 3450 3    50   Input ~ 0
GND
Wire Wire Line
	3650 2800 3650 2750
Wire Wire Line
	3650 2600 3650 2700
Wire Wire Line
	3600 2800 3600 2700
Wire Wire Line
	3600 2700 3450 2700
Connection ~ 3600 2700
Wire Wire Line
	3600 2700 3600 2650
Text GLabel 3600 4100 0    50   Input ~ 0
GND
Text Notes 5150 1850 0    157  Italic 31
RECEIVER END
Wire Wire Line
	4900 3400 4800 3400
Wire Wire Line
	4800 3400 4800 3500
Wire Wire Line
	4800 3500 4750 3500
$Comp
L Motor:Motor_DC M?
U 1 1 5BD389D8
P 8900 3350
F 0 "M?" V 9195 3300 50  0001 C CNN
F 1 "Motor_DC" V 9103 3300 50  0000 C CNN
F 2 "" H 8900 3260 50  0001 C CNN
F 3 "~" H 8900 3260 50  0001 C CNN
	1    8900 3350
	0    -1   -1   0   
$EndComp
$Comp
L Motor:Motor_DC M?
U 1 1 5BD39AB6
P 8900 3750
F 0 "M?" V 9195 3700 50  0001 C CNN
F 1 "Motor_DC" V 9103 3700 50  0000 C CNN
F 2 "" H 8900 3660 50  0001 C CNN
F 3 "~" H 8900 3660 50  0001 C CNN
	1    8900 3750
	0    -1   -1   0   
$EndComp
$Comp
L Driver_Motor:L293D U?
U 1 1 5BD39B59
P 7200 3450
F 0 "U?" H 7200 4628 50  0001 C CNN
F 1 "L293D" H 7200 4536 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 7450 2700 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/l293.pdf" H 6900 4150 50  0001 C CNN
	1    7200 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 3700 6450 3700
Wire Wire Line
	6450 3700 6450 3450
Wire Wire Line
	6450 3450 6700 3450
Wire Wire Line
	6100 3800 6550 3800
Wire Wire Line
	6550 3800 6550 3650
Wire Wire Line
	6550 3650 6700 3650
Wire Wire Line
	7700 3650 8500 3650
Wire Wire Line
	7700 3450 8500 3450
Wire Wire Line
	8500 3450 8500 3350
Wire Wire Line
	8500 3350 8700 3350
Wire Wire Line
	8700 3750 8500 3750
Wire Wire Line
	8500 3750 8500 3650
Wire Wire Line
	7400 4250 9200 4250
Wire Wire Line
	9200 4250 9200 3750
Wire Wire Line
	9200 3350 9300 3350
Wire Wire Line
	9300 3350 9300 4300
Wire Wire Line
	9300 4300 7300 4300
Wire Wire Line
	7300 4300 7300 4250
Text GLabel 6700 3850 0    50   Input ~ 0
5V
Text GLabel 7300 2450 2    50   Input ~ 0
10V
Wire Wire Line
	4150 3000 4150 3150
Wire Wire Line
	3900 3950 4800 3950
Wire Wire Line
	3900 4250 4800 4250
$EndSCHEMATC
