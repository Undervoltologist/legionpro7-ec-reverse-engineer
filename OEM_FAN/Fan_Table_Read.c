
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Fan_Table_Read(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  
  if ((FanTableToggle & 1) != 0) {
    return;
  }
  bVar1 = CPU_Temp;
  if (((((Temp_Priority_Selector & 1) == 0) && (bVar1 = GPU_Temp, (Temp_Priority_Selector & 2) == 0)
       ) && (bVar1 = PCH_Temp, (Temp_Priority_Selector & 4) == 0)) &&
     (bVar1 = Temp_Priority_Selector >> 3 & 1, (Temp_Priority_Selector >> 3 & 1) != 0)) {
    bVar1 = FailsafeTemp;
  }
  uVar4 = (uint)Fan_Target_FnQ_Mode;
  if ((Fan_Current_FnQ_Mode != uVar4) && (uVar4 < Max_FnQ_Mode_Count)) {
    Fan_Current_FnQ_Mode = Fan_Target_FnQ_Mode;
    Mode_LowTemp_Limit = (&LAB_00025c12+3)[uVar4 * 0x10];
    Mode_HighTemp_Limit = (&LAB_00025c16)[uVar4 * 0x10];
    Fan_State = Fan_State & 0xfc | 0x80;
  }
  if (Temp_Priority_Selector == 0) {
LAB_000486b8:
    Fan_State = Fan_State & 0xfd | 1;
    _Fan_Table_ROM_Pointer = *(int *)(&LAB_00025c16+2 + (uint)Fan_Current_FnQ_Mode * 0x10);
    Fan_Step_Size = (&LAB_00025c16+1)[(uint)Fan_Current_FnQ_Mode * 0x10];
  }
  else {
    if ((bVar1 < Mode_LowTemp_Limit) || ((Fan_State & 2) != 0)) {
      if ((Mode_HighTemp_Limit < bVar1) || ((Fan_State & 1) != 0)) goto LAB_000486f0;
      goto LAB_000486b8;
    }
    Fan_State = Fan_State & 0xfe | 2;
    _Fan_Table_ROM_Pointer = *(int *)(&LAB_00025c1e+2 + (uint)Fan_Current_FnQ_Mode * 0x10);
    Fan_Step_Size = (&LAB_00025c1a+2)[(uint)Fan_Current_FnQ_Mode * 0x10];
  }
  Fan_State = Fan_State | 0x80;
LAB_000486f0:
  if ((char)Fan_State < '\0') {
    uVar4 = 0xd;
    iVar2 = 0x24eb0;
    do {
      uVar4 = uVar4 - 1 & 0xff;
      **(undefined **)(iVar2 + 4) = 0;
      **(undefined **)(iVar2 + 8) = 0;
      **(undefined **)(iVar2 + 0xc) = 0;
      **(undefined **)(iVar2 + 0x10) = 0;
      **(undefined **)(iVar2 + 0x14) = 0;
      **(undefined **)(iVar2 + 0x18) = 0;
      **(undefined **)(iVar2 + 0x1c) = 0;
      **(undefined **)(iVar2 + 0x20) = 0;
      **(undefined **)(iVar2 + 0x24) = 0;
      **(undefined **)(iVar2 + 0x28) = 0;
      **(undefined **)(iVar2 + 0x2c) = 0;
      **(undefined **)(iVar2 + 0x30) = 0;
      **(undefined **)(iVar2 + 0x34) = 0;
      **(undefined **)(iVar2 + 0x38) = 0;
      iVar2 = iVar2 + 0x3c;
    } while (uVar4 != 0);
    for (; uVar4 < Fan_Step_Size; uVar4 = uVar4 + 1 & 0xff) {
      if ((Total_Fan_Count & 1) != 0) {
        **(undefined **)(uVar4 * 0x3c + 0x24eb4) =
             *(undefined *)(_Fan_Table_ROM_Pointer + uVar4 * 0xf + 1);
      }
      if ((Total_Fan_Count >> 1 & 1) != 0) {
        **(undefined **)(uVar4 * 0x3c + 0x24eb8) =
             *(undefined *)(_Fan_Table_ROM_Pointer + uVar4 * 0xf + 2);
      }
      if ((Total_Fan_Count >> 2 & 1) != 0) {
        **(undefined **)(uVar4 * 0x3c + 0x24ebc) =
             *(undefined *)(_Fan_Table_ROM_Pointer + uVar4 * 0xf + 3);
      }
      if ((Total_Fan_Count >> 3 & 1) != 0) {
        **(undefined **)(uVar4 * 0x3c + 0x24ec0) =
             *(undefined *)(_Fan_Table_ROM_Pointer + uVar4 * 0xf + 4);
      }
      iVar3 = uVar4 * 0xf;
      iVar2 = uVar4 * 0x3c;
      **(undefined **)(iVar2 + 0x24ec4) = *(undefined *)(_Fan_Table_ROM_Pointer + iVar3 + 5);
      **(undefined **)(iVar2 + 0x24ec8) = *(undefined *)(_Fan_Table_ROM_Pointer + iVar3 + 6);
      if ((Total_Sensor_Count & 1) != 0) {
        puVar5 = *(undefined **)(iVar2 + 0x24ed0);
        **(undefined **)(iVar2 + 0x24ecc) = *(undefined *)(_Fan_Table_ROM_Pointer + iVar3 + 7);
        *puVar5 = *(undefined *)(_Fan_Table_ROM_Pointer + iVar3 + 8);
      }
      if ((Total_Sensor_Count >> 1 & 1) != 0) {
        **(undefined **)(uVar4 * 0x3c + 0x24ed4) =
             *(undefined *)(_Fan_Table_ROM_Pointer + iVar3 + 9);
        **(undefined **)(uVar4 * 0x3c + 0x24ed8) =
             *(undefined *)(_Fan_Table_ROM_Pointer + iVar3 + 10);
      }
      if ((Total_Sensor_Count >> 2 & 1) != 0) {
        **(undefined **)(uVar4 * 0x3c + 0x24edc) =
             *(undefined *)(_Fan_Table_ROM_Pointer + iVar3 + 0xb);
        **(undefined **)(uVar4 * 0x3c + 0x24ee0) =
             *(undefined *)(_Fan_Table_ROM_Pointer + iVar3 + 0xc);
      }
      if ((Total_Sensor_Count >> 3 & 1) != 0) {
        **(undefined **)(uVar4 * 0x3c + 0x24ee4) =
             *(undefined *)(_Fan_Table_ROM_Pointer + iVar3 + 0xd);
        **(undefined **)(uVar4 * 0x3c + 0x24ee8) =
             *(undefined *)(iVar3 + _Fan_Table_ROM_Pointer + 0xe);
      }
    }
    CPU_Requested_Step = 0;
    GPU_Requested_Step = 0;
    PCH_Requested_Step = 0;
    Temp_4 = 0;
    Global_Final_Fan_Step = 0;
    Fan_State = Fan_State & 0x7f;
  }
  return;
}

