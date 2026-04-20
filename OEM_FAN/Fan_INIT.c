
void Fan_INIT(void)

{
  byte bVar1;
  int iVar2;
  
  Get_Fan1RPM();
  Get_Fan0RPM();
  Get_Fan2RPM();
  bVar1 = DAT_00101ff6 >> 1 & 1;
  if ((DAT_00101ff6 >> 1 & 1) == 0) {
    iVar2 = Check_System_isNotSleep();
    if (iVar2 != 0) {
      Fan0_PWM = bVar1;
      Fan1_PWM = bVar1;
      Fan2_PWM = bVar1;
      return;
    }
    iVar2 = Check_FanTable();
    if (iVar2 != 0) {
      Fan0_PWM = Max_PWM;
      Fan1_PWM = Max_PWM;
      Fan2_PWM = Max_PWM;
      return;
    }
    if (DAT_00100c06 == '\0') {
      Fan1_FailSafe();
      Fan0_Failsafe();
      Fan2_Failsafe();
      return;
    }
    DAT_00100c06 = DAT_00100c06 + -1;
  }
  Fan1_PWM = FUN_0004a37a(0x20,Max_PWM);
  Fan0_PWM = FUN_0004a37a(0x20,Max_PWM);
  Fan2_PWM = FUN_0004a37a(0x20,Max_PWM);
  return;
}

