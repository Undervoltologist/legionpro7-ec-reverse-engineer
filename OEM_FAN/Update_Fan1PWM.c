
void Update_Fan1PWM(void)

{
  bool bVar1;
  int iVar2;
  
  if ((Fan_Control_Toggle & 1) == 0) {
    if ((Fan_Control_Toggle >> 4 & 1) == 0) {
      return;
    }
    if (Max_PWM < Fan1_PWM) {
      Fan1_PWM = Max_PWM;
      return;
    }
    if (Fan1_PWM <= Fan1_PWM_Override) {
      bVar1 = Fan1_PWM < Fan1_PWM_Override;
Increase/Decrease_Fan1PWM:
      if (!bVar1) {
        return;
      }
      if (Max_PWM <= Fan1_PWM) {
        return;
      }
      Fan1_PWM = Fan1_PWM + 1;
      return;
    }
  }
  else {
    if (Max_PWM < Fan1_PWM) {
      Fan1_PWM = Max_PWM;
      return;
    }
    if (Fan1_RPM_Override != 0) {
      iVar2 = (uint)Fan1_RPM_Override * 100;
      if ((uint)Fan1_RPM_HI_FanPage <= iVar2 + (uint)Fan1_Tolerance) {
        bVar1 = (int)(uint)Fan1_RPM_HI_FanPage < (int)(iVar2 - (uint)Fan1_Tolerance);
        goto Increase/Decrease_Fan1PWM;
      }
    }
  }
  if (Fan1_PWM != 0) {
    Fan1_PWM = Fan1_PWM - 1;
  }
  return;
}

