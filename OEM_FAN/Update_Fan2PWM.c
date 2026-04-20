
void Update_Fan2PWM(void)

{
  bool bVar1;
  int iVar2;
  
  if ((Fan_Control_Toggle & 4) == 0) {
    if ((Fan_Control_Toggle >> 6 & 1) == 0) {
      return;
    }
    if (Max_PWM < Fan2_PWM) {
      Fan2_PWM = Max_PWM;
      return;
    }
    if (Fan2_PWM <= Fan2_PWM_Override) {
      bVar1 = Fan2_PWM < Fan2_PWM_Override;
Increase/Decrease_Fan2PWM:
      if (!bVar1) {
        return;
      }
      if (Max_PWM <= Fan2_PWM) {
        return;
      }
      Fan2_PWM = Fan2_PWM + 1;
      return;
    }
  }
  else {
    if (Max_PWM < Fan2_PWM) {
      Fan2_PWM = Max_PWM;
      return;
    }
    if (Fan2_RPM_Override != 0) {
      iVar2 = (uint)Fan2_RPM_Override * 100;
      if ((uint)Fan2_RPM_HI <= iVar2 + (uint)Fan2_Tolerance) {
        bVar1 = (int)(uint)Fan2_RPM_HI < (int)(iVar2 - (uint)Fan2_Tolerance);
        goto Increase/Decrease_Fan2PWM;
      }
    }
  }
  if (Fan2_PWM != 0) {
    Fan2_PWM = Fan2_PWM - 1;
  }
  return;
}

