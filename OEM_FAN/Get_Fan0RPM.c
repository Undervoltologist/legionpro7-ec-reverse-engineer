
void Get_Fan0RPM(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = (uint)Fan0_TACH_HI;
  if ((Fan0_TACH_LO != 0) || (uVar1 != 0)) {
    uVar1 = 0x20e6da / (uVar1 + (uint)Fan0_TACH_LO * 0x100);
  }
  uVar3 = uVar1 & 0xffff;
  if (((uint)DAT_00101f0e * 100 < uVar3) && (uVar3 < (uint)DAT_00101f1e * 100)) {
    iVar2 = 0;
  }
  else if ((uVar3 <= (uint)DAT_00101f0f * 100) || (iVar2 = 1, (uint)DAT_00101f1f * 100 <= uVar3))
  goto LAB_00048f1c;
  Static_78_Value = **(byte **)(iVar2 * 0x10 + 0x251c8);
LAB_00048f1c:
  if (Static_78_Value == 0) {
    Static_78_Value = 0x32;
  }
  MainEC_CurrentRPM*100 = (char)((uVar1 & 0xffff) / 100);
  if (100 < (uVar1 & 0xffff) % 100 + (uint)Static_78_Value) {
    MainEC_CurrentRPM*100 = MainEC_CurrentRPM*100 + '\x01';
  }
  Fan1_RPM_HI_FanPage = (short)uVar1;
  Fan1_PWM_Target = Fan1_PWM;
  Fan1_CurrentRPM*100 = MainEC_CurrentRPM*100;
  return;
}

