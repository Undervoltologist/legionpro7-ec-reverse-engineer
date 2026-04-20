
void Fan1_PWM_Calculation(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = 0;
  while (uVar2 = uVar1 & 0xff, uVar2 < Fan_Step_Size) {
    iVar3 = uVar1 * 0x3c;
    uVar1 = uVar1 + 1;
    if ((ushort)((ushort)**(byte **)(iVar3 + 0x24eb4) * 100) <= Fan1_RPM_HI_FanPage) {
      param_2 = uVar2;
    }
  }
  if (Fan1RPM_Target != 0) {
    iVar3 = (uint)Fan1RPM_Target * 100;
    if ((int)(uint)Fan1_RPM_HI_FanPage < (int)(iVar3 - (uint)Static_78_Value)) {
      if (Max_PWM <= Fan1_PWM) {
        return;
      }
      if (Fan1_Update_Timer == '\0') {
        Fan1_Update_Timer = **(undefined **)(param_2 * 0x3c + 0x24ec4);
        Fan1_PWM = Fan1_PWM + 1;
        return;
      }
      Fan1_Update_Timer = Fan1_Update_Timer + -1;
      return;
    }
    if ((uint)Fan1_RPM_HI_FanPage <= (uint)Static_78_Value + iVar3) {
      return;
    }
  }
  if (Fan1_PWM != 0) {
    if (Fan1_Update_Timer != '\0') {
      Fan1_Update_Timer = Fan1_Update_Timer + -1;
      return;
    }
    Fan1_Update_Timer = **(char **)(param_2 * 0x3c + 0x24ec8);
    Fan1_PWM = Fan1_PWM - 1;
  }
  return;
}

