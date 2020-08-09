double Read_Sensor()
{Level_water=0;
  unsigned long int Sample=0;
  for(int i=0;i<10;i++)
  {
 Sample= Sample+hx711.read();
 delay(20);
  }
 return Level_water=Sample/10;
  
  //Level_water=
}
