--------
  RPM
--------
void Fan_Toggle_Fan0_DirectRPM(undefined param_1)

{
  Fan_Control_Toggle = Fan_Control_Toggle | 1;
  Fan1_RPM_Override = param_1;
  FUN_0004ef28(0xac);
  return;
}

void Fan_Toggle_Fan1_DirectRPM(undefined param_1)

{
  Fan_Control_Toggle = Fan_Control_Toggle | 2;
  Fan0_RPM_Override = param_1;
  FUN_0004ef28(0xac);
  return;
}


void Fan_Toggle_Fan2_DirectRPM(undefined param_1)

{
  Fan_Control_Toggle = Fan_Control_Toggle | 4;
  Fan2_RPM_Override = param_1;
  FUN_0004ef28(0xac);
  return;
}


--------
  PWM
--------
void Fan_Toggle_Fan0_DirectPWM(undefined param_1)

{
  Fan_Control_Toggle = Fan_Control_Toggle | 0x20;
  Fan0_PWM_Override = param_1;
  FUN_0004ef28(0xac);
  return;
}


void Fan_Toggle_Fan1_DirectPWM(undefined param_1)

{
  Fan_Control_Toggle = Fan_Control_Toggle | 0x40;
  Fan2_PWM_Override = param_1;
  FUN_0004ef28(0xac);
  return;
}


void Fan_Toggle_Fan2_DirectPWM(undefined param_1)

{
  Fan_Control_Toggle = Fan_Control_Toggle | 0x80;
  Fan3_PWM_Override = param_1;
  FUN_0004ef28(0xac);
  return;
}



