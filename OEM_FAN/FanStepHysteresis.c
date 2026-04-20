
void FanStepHysteresis(void)

{
  if ((Global_Final_Fan_Step == '\0') && (Pending_Fan_Step != '\0')) {
    Global_Final_Fan_Step = 1;
    return;
  }
  if (Hysteresis_Counter < 0x14) {
    Hysteresis_Counter = Hysteresis_Counter + 1;
  }
  else {
    Global_Final_Fan_Step = Pending_Fan_Step;
    Hysteresis_Counter = '\0';
  }
  return;
}

