
void Fan_Control_Loop_INIT(void)

{
  if (System_Status == '\x10') {
    Get_Fan1RPM();
    GPIO_1615 = 0;
    Update_Fan1PWM();
    Get_Fan0RPM();
    GPIO_1614 = 0;
    Update_Fan0PWM();
    Get_Fan2RPM();
    GPIO_1616 = 0;
    Update_Fan2PWM();
    return;
  }
  return;
}

