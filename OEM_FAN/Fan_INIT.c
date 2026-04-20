
void Fan_INIT(void)

{
  byte bVar1;
  int iVar2;
  
  Get_Fan1RPM();
  Get_Fan0RPM();
  Get_Fan2RPM();
  bVar1 = FanTableToggle >> 1 & 1;
  if ((FanTableToggle >> 1 & 1) == 0) {
    iVar2 = Check_System_Status();
    if (iVar2 != 0) {
      Fan0_PWM = bVar1;
      Fan1_PWM = bVar1;
      Fan2_PWM = bVar1;
      return;
    }
    iVar2 = Check_CustomMode_MaxRPM();
    if (iVar2 != 0) {
      Fan0_PWM = Max_PWM;
      Fan1_PWM = Max_PWM;
      Fan2_PWM = Max_PWM;
      return;
    }
    if (ErrorFlag? == '\0') {
      Fan1_FailSafe();
      Fan0_Failsafe();
      Fan2_Failsafe();
      return;
    }
    ErrorFlag? = ErrorFlag? + -1;
  }
  Fan1_PWM = FUN_0004a37a(0x20,Max_PWM);
  Fan0_PWM = FUN_0004a37a(0x20,Max_PWM);
  Fan2_PWM = FUN_0004a37a(0x20,Max_PWM);
  return;
}

