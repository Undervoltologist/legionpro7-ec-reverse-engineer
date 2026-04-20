
void Fan1_FailSafe(void)

{
  if (Fan1RPM_Target == '\0') {
    if (Fan1_PWM < 0x3c) {
      Fan1_RPM_HI_FanPage = 0;
      Fan1_PWM = Fan1RPM_Target;
      return;
    }
  }
  else if (Fan1_RPM_HI_FanPage == 0) {
    Fan1_PWM = 0x3c;
  }
  Fan1_PWM_Calculation();
  return;
}

