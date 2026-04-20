
void Fan0_Failsafe(void)

{
  if (Fan0RPM_Target == '\0') {
    if (Fan0_PWM < 0x3c) {
      Fan0_RPM_HI_FanPage = 0;
      Fan0_PWM = Fan0RPM_Target;
      return;
    }
  }
  else if (Fan0_RPM_HI_FanPage == 0) {
    Fan0_PWM = 0x3c;
  }
  Fan0_PWM_Calculation();
  return;
}

