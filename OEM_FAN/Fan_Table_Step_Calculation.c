
void Fan_Table_Step_Calculation(void)

{
  byte bVar1;
  
  if ((FanTableToggle >> 1 & 1) == 0) {
    bVar1 = Total_Sensor_Count & 1;
    if ((Total_Sensor_Count & 1) != 0) {
      if (((int)(uint)CPU_Requested_Step < (int)(Fan_Step_Size - 1)) &&
         (**(byte **)((uint)CPU_Requested_Step * 0x3c + 0x24ecc) < CPU_Temp)) {
        CPU_Requested_Step = CPU_Requested_Step + 1;
      }
      bVar1 = CPU_Requested_Step;
      if ((CPU_Requested_Step != 0) &&
         (CPU_Temp < **(byte **)((uint)CPU_Requested_Step * 0x3c + 0x24ed0))) {
        CPU_Requested_Step = CPU_Requested_Step - 1;
        bVar1 = CPU_Requested_Step;
      }
    }
    if ((Total_Sensor_Count >> 1 & 1) != 0) {
      if (((int)(uint)GPU_Requested_Step < (int)(Fan_Step_Size - 1)) &&
         (**(byte **)((uint)GPU_Requested_Step * 0x3c + 0x24ed4) < GPU_Temp)) {
        GPU_Requested_Step = GPU_Requested_Step + 1;
      }
      if ((GPU_Requested_Step != 0) &&
         (GPU_Temp < **(byte **)((uint)GPU_Requested_Step * 0x3c + 0x24ed8))) {
        GPU_Requested_Step = GPU_Requested_Step - 1;
      }
      if (bVar1 < GPU_Requested_Step) {
        bVar1 = GPU_Requested_Step;
      }
    }
    if ((Total_Sensor_Count >> 2 & 1) != 0) {
      if (((int)(uint)PCH_Requested_Step < (int)(Fan_Step_Size - 1)) &&
         (**(byte **)((uint)PCH_Requested_Step * 0x3c + 0x24edc) < PCH_Temp)) {
        PCH_Requested_Step = PCH_Requested_Step + 1;
      }
      if ((PCH_Requested_Step != 0) &&
         (PCH_Temp < **(byte **)((uint)PCH_Requested_Step * 0x3c + 0x24ee0))) {
        PCH_Requested_Step = PCH_Requested_Step - 1;
      }
      if (bVar1 < PCH_Requested_Step) {
        bVar1 = PCH_Requested_Step;
      }
    }
    if ((Total_Sensor_Count >> 3 & 1) != 0) {
      if (((int)(uint)Temp_4 < (int)(Fan_Step_Size - 1)) &&
         (**(byte **)((uint)Temp_4 * 0x3c + 0x24ee4) < FailsafeTemp)) {
        Temp_4 = Temp_4 + 1;
      }
      if ((Temp_4 != 0) && (FailsafeTemp < **(byte **)((uint)Temp_4 * 0x3c + 0x24ee8))) {
        Temp_4 = Temp_4 - 1;
      }
      if (bVar1 < Temp_4) {
        bVar1 = Temp_4;
      }
    }
    if (Pending_Fan_Step == bVar1) {
      FanStepHysteresis();
    }
    else {
      Hysteresis_Counter = 0;
      Pending_Fan_Step = bVar1;
    }
    Global_Final_Fan_Step = bVar1;
    CustomMode_StepCalculation();
    if ((Total_Fan_Count & 1) != 0) {
      Fan1RPM_Target = **(undefined **)((uint)Global_Final_Fan_Step * 0x3c + 0x24eb4);
      Fan1_Step_Logic();
    }
    if ((Total_Fan_Count >> 1 & 1) != 0) {
      Fan0RPM_Target = **(undefined **)((uint)Global_Final_Fan_Step * 0x3c + 0x24eb8);
      Fan0_Step_Logic();
    }
    if ((Total_Fan_Count >> 2 & 1) != 0) {
      Fan2_RPM_Target = **(undefined **)((uint)Global_Final_Fan_Step * 0x3c + 0x24ebc);
      Fan2_Step_Logic();
    }
    if ((Total_Fan_Count >> 3 & 1) != 0) {
      Fan3_RPM_Target = **(undefined **)((uint)Global_Final_Fan_Step * 0x3c + 0x24ec0);
      Fan3_Step_Logic();
    }
    return;
  }
  return;
}

