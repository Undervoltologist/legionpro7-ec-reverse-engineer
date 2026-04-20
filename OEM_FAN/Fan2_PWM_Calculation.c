
void Fan2_PWM_Calculation(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = 0;
  while (uVar2 = uVar1 & 0xff, uVar2 < Fan_Step_Size) {
    iVar3 = uVar1 * 0x3c;
    uVar1 = uVar1 + 1;
    if ((ushort)((ushort)**(byte **)(iVar3 + 0x24ebc) * 100) <= Fan2_RPM_HI) {
      param_2 = uVar2;
    }
  }
  if (Fan2_RPM_Target != 0) {
    iVar3 = (uint)Fan2_RPM_Target * 100;
    if ((int)(uint)Fan2_RPM_HI < (int)(iVar3 - (uint)Fan2_Tolerance)) {
      if (Max_PWM <= Fan2_PWM) {
        return;
      }
      if (Fan2_Acceleration_Timer == '\0') {
        Fan2_Acceleration_Timer = **(undefined **)(param_2 * 0x3c + 0x24ec4);
        Fan2_PWM = Fan2_PWM + 1;
        return;
      }
      Fan2_Acceleration_Timer = Fan2_Acceleration_Timer + -1;
      return;
    }
    if ((uint)Fan2_RPM_HI <= (uint)Fan2_Tolerance + iVar3) {
      return;
    }
  }
  if (Fan2_PWM != 0) {
    if (Fan2_Acceleration_Timer != '\0') {
      Fan2_Acceleration_Timer = Fan2_Acceleration_Timer + -1;
      return;
    }
    Fan2_Acceleration_Timer = **(char **)(param_2 * 0x3c + 0x24ec8);
    Fan2_PWM = Fan2_PWM - 1;
  }
  return;
}

