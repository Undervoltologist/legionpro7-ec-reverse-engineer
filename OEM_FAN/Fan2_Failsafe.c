
void Fan2_Failsafe(void)

{
  if (Fan2_RPM_Target == '\0') {
    if (Fan2_PWM < 0x23) {
      Fan2_RPM_HI = 0;
      Fan2_PWM = Fan2_RPM_Target;
      return;
    }
  }
  else if (Fan2_RPM_HI == 0) {
    Fan2_PWM = 0x23;
  }
  Fan2_PWM_Calculation();
  return;
}

