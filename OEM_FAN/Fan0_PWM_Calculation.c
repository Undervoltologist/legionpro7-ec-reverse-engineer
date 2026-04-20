
void Fan0_PWM_Calculation(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = 0;
  while (uVar2 = uVar1 & 0xff, uVar2 < Fan_Step_Size) {
    iVar3 = uVar1 * 0x3c;
    uVar1 = uVar1 + 1;
    if ((ushort)((ushort)**(byte **)(iVar3 + 0x24eb8) * 100) <= Fan0_RPM_HI_FanPage) {
      param_2 = uVar2;
    }
  }
  if (Fan0RPM_Target != 0) {
    iVar3 = (uint)Fan0RPM_Target * 100;
    if ((int)(uint)Fan0_RPM_HI_FanPage < (int)(iVar3 - (uint)Fan0_Tolerance)) {
      if (Max_PWM <= Fan0_PWM) {
        return;
      }
      if (Fan0_Update_Timer == '\0') {
        Fan0_Update_Timer = **(undefined **)(param_2 * 0x3c + 0x24ec4);
        Fan0_PWM = Fan0_PWM + 1;
        return;
      }
      Fan0_Update_Timer = Fan0_Update_Timer + -1;
      return;
    }
    if ((uint)Fan0_RPM_HI_FanPage <= (uint)Fan0_Tolerance + iVar3) {
      return;
    }
  }
  if (Fan0_PWM != 0) {
    if (Fan0_Update_Timer != '\0') {
      Fan0_Update_Timer = Fan0_Update_Timer + -1;
      return;
    }
    Fan0_Update_Timer = **(char **)(param_2 * 0x3c + 0x24ec8);
    Fan0_PWM = Fan0_PWM - 1;
  }
  return;
}

