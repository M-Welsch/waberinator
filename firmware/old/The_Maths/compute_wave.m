# compute sinus 1/4 wave
# these will be stored in the eeprom
# 8 bit
 
x = 0:511;
sinus = zeros(511,1);
sinus = sin(2*pi*x/2047);
sinus = (exp(sinus)-1)/(e-1);
sinus = sinus * 255;

plot(sinus)