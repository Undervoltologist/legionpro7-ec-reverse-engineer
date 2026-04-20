
void Update_Fan0PWM(void)

{
  bool bVar1;
  int iVar2;
  
  if ((Fan_Control_Toggle & 2) == 0) {
    if ((Fan_Control_Toggle >> 5 & 1) == 0) {
      return;
    }
    if (Max_PWM < Fan0_PWM) {
      Fan0_PWM = Max_PWM;
      return;
    }
    if (Fan0_PWM <= Fan0_PWM_Override) {
      bVar1 = Fan0_PWM < Fan0_PWM_Override;
Increase/Decrease_Fan0_PWM:
      if (!bVar1) {
        return;
      }
      if (Max_PWM <= Fan0_PWM) {
        return;
      }
      Fan0_PWM = Fan0_PWM + 1;
      return;
    }
  }
  else {
    if (Max_PWM < Fan0_PWM) {
      Fan0_PWM = Max_PWM;
      return;
    }
    if (Fan0_RPM_Override != 0) {
      iVar2 = (uint)Fan0_RPM_Override * 100;
      if ((uint)Fan0_RPM_HI_FanPage <= iVar2 + (uint)Fan0_Tolerance) {
        bVar1 = (int)(uint)Fan0_RPM_HI_FanPage < (int)(iVar2 - (uint)Fan0_Tolerance);
        goto Increase/Decrease_Fan0_PWM;
      }
    }
  }
  if (Fan0_PWM != 0) {
    Fan0_PWM = Fan0_PWM - 1;
  }
  return;
}

