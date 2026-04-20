
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
  if (((uint)TACH_HI_LOW_SPEED_BOUNDARY * 100 < uVar2) &&
     (uVar2 < (uint)TACH_HI_HIGH_SPEED_BOUNDARY * 100)) {
    iVar3 = 0;
  }
  else if ((uVar2 <= (uint)TACH_LO_LOW_SPEED_BOUNDARY * 100) ||
          (iVar3 = 1, (uint)TACH_LO_HIGH_SPEED_BOUNDARY * 100 <= uVar2)) goto LAB_00049428;
  Fan2_Tolerance = **(byte **)(iVar3 * 0x10 + 0x251c8);
LAB_00049428:
  if (Fan2_Tolerance == 0) {
    Fan2_Tolerance = 0x32;
  }
  MainEC_Fan2_CurrentRPM*100 = (char)((uVar1 & 0xffff) / 100);
  if (100 < uVar2 % 100 + (uint)Fan2_Tolerance) {
    MainEC_Fan2_CurrentRPM*100 = MainEC_Fan2_CurrentRPM*100 + '\x01';
  }
  Fan2_RPM_HI = (short)uVar1;
  Fan2_PWM_Target = Fan2_PWM;
  Fan2_CurrentRPM*100 = MainEC_Fan2_CurrentRPM*100;
  return;
}

