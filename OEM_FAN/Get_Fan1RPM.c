
void Get_Fan1RPM(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = (uint)Fan1_TACH_HI;
  if ((Fan1_TACH_LO != 0) || (uVar1 != 0)) {
    uVar1 = 0x20e6da / (uVar1 + (uint)Fan1_TACH_LO * 0x100);
  }
  uVar3 = uVar1 & 0xffff;
  if (((uint)TACH_HI_LOW_SPEED_BOUNDARY * 100 < uVar3) &&
     (uVar3 < (uint)TACH_HI_HIGH_SPEED_BOUNDARY * 100)) {
    iVar2 = 0;
  }
  else if ((uVar3 <= (uint)TACH_LO_LOW_SPEED_BOUNDARY * 100) ||
          (iVar2 = 1, (uint)TACH_LO_HIGH_SPEED_BOUNDARY * 100 <= uVar3)) goto LAB_00048f1c;
  Fan1_Tolerance = **(byte **)(iVar2 * 0x10 + 0x251c8);
LAB_00048f1c:
  if (Fan1_Tolerance == 0) {
    Fan1_Tolerance = 0x32;
  }
  MainEC_Fan1_CurrentRPM*100 = (char)((uVar1 & 0xffff) / 100);
  if (100 < (uVar1 & 0xffff) % 100 + (uint)Fan1_Tolerance) {
    MainEC_Fan1_CurrentRPM*100 = MainEC_Fan1_CurrentRPM*100 + '\x01';
  }
  Fan1_RPM_HI_FanPage = (short)uVar1;
  Fan1_PWM_Target = Fan1_PWM;
  Fan1_CurrentRPM*100 = MainEC_Fan1_CurrentRPM*100;
  return;
}

