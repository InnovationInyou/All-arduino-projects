// Blocking.pde
// -*- mode: C++ -*-
//
// Shows how to use the blocking call runToNewPosition
// Which sets a new target position and then waits until the stepper has 
// achieved it.
//
// Copyright (C) 2009 Mike McCauley
// $Id: Blocking.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <AccelStepper.h>
#include<LiquidCrystal_I2C_Hangul.h>
LiquidCrystal_I2C_Hangul lcd(0x3F,16,2);
// Define a stepper and the pins it will use
AccelStepper stepper(2, 2, 5);  // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

void setup()
{  
  lcd.init();                       // initialize the lcd 
    lcd.backlight();    
    stepper.setMaxSpeed(1500.0);
    stepper.setAcceleration(400.0);
}

void loop()
{   
    int z = 20;
    unsigned long int val =map(z, 0, 88, 0,563200);
    lcd.setCursor(0, 0);
    lcd.print(val);
    stepper.runToNewPosition(0);    
}
