
void Get_Fan0RPM(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = (uint)Fan0_TACH_HI;
  if ((Fan0_TACH_LO != 0) || (uVar1 != 0)) {
    uVar1 = 0x20e6da / (uVar1 + (uint)Fan0_TACH_LO * 0x100);
  }
  uVar2 = uVar1 & 0xffff;
  if (((uint)DAT_00101f0e * 100 < uVar2) && (uVar2 < (uint)DAT_00101f1e * 100)) {
    iVar3 = 0;
  }
  else if ((uVar2 <= (uint)DAT_00101f0f * 100) || (iVar3 = 1, (uint)DAT_00101f1f * 100 <= uVar2))
  goto LAB_000491a4;
  Static_78_Value = **(byte **)(iVar3 * 0x10 + 0x251c8);
LAB_000491a4:
  if (Static_78_Value == 0) {
    Static_78_Value = 0x32;
  }
  MainEC_Fan0CurrentRPM = (char)((uVar1 & 0xffff) / 100);
  if (100 < uVar2 % 100 + (uint)Static_78_Value) {
    MainEC_Fan0CurrentRPM = MainEC_Fan0CurrentRPM + '\x01';
  }
  Fan0_RPM_HI_FanPage = (short)uVar1;
  Fan0_PWM_Target = Fan0_PWM;
  Fan0_CurrentRPM*100 = MainEC_Fan0CurrentRPM;
  return;
}

