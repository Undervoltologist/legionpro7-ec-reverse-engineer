
void Reset_Fan_Control&Overrides(undefined4 param_1)

{
  undefined uVar1;
  
  switch(param_1) {
  case 1:
    Fan_Control_Toggle = 0;
    Fan1_RPM_Override = 0;
    Fan0_RPM_Override = 0;
    Fan2_RPM_Override = 0;
    Fan3_RPM_Control = 0;
    Fan1_PWM_Override = 0;
    Fan0_PWM_Override = 0;
    Fan2_PWM_Override = 0;
    Fan3_PWM_Override = 0;
    uVar1 = 0xac;
    break;
  case 2:
    uVar1 = Fan_Control_Toggle;
    break;
  case 3:
    uVar1 = Fan1_CurrentRPM*100;
    break;
  case 4:
    uVar1 = Fan0_CurrentRPM*100;
    break;
  case 5:
    uVar1 = Fan2_CurrentRPM*100;
    break;
  case 6:
    uVar1 = Fan3_CurrentRPM*100;
    break;
  case 7:
    uVar1 = Fan1_PWM_Target;
    break;
  case 8:
    uVar1 = Fan0_PWM_Target;
    break;
  case 9:
    uVar1 = Fan2_PWM_Target;
    break;
  case 10:
    uVar1 = Fan3_PWM_Target;
    break;
  default:
    FUN_0004ef28(0xf);
    return;
  }
  FUN_00015f28(uVar1);
  return;
}

