
void Get_Fan2RPM(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = (uint)Fan2_TACH_HI;
  if ((Fan2_TACH_LO != 0) || (uVar1 != 0)) {
    uVar1 = 0x20e6da / (uVar1 + (uint)Fan2_TACH_LO * 0x100);
  }
  uVar2 = uVar1 & 0xffff;
  if (((uint)DAT_00101f0e * 100 < uVar2) && (uVar2 < (uint)DAT_00101f1e * 100)) {
    iVar3 = 0;
  }
  else if ((uVar2 <= (uint)DAT_00101f0f * 100) || (iVar3 = 1, (uint)DAT_00101f1f * 100 <= uVar2))
  goto LAB_00049428;
  Static_78_Value = **(byte **)(iVar3 * 0x10 + 0x251c8);
LAB_00049428:
  if (Static_78_Value == 0) {
    Static_78_Value = 0x32;
  }
  MainEC_Fan2_CurrentRPM*100 = (char)((uVar1 & 0xffff) / 100);
  if (100 < uVar2 % 100 + (uint)Static_78_Value) {
    MainEC_Fan2_CurrentRPM*100 = MainEC_Fan2_CurrentRPM*100 + '\x01';
  }
  Fan2_RPM_HI = (short)uVar1;
  Fan2_PWM_Target = Fan2_PWM;
  Fan2_CurrentRPM*100 = MainEC_Fan2_CurrentRPM*100;
  return;
}

