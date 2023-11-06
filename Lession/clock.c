// Digital Clock with hour, minute and second

int h, m, s;
while (1)
{
    s++;
    if(s >= 60){
        s = 0;
        m++;
    }
    if(m >= 60){
        m = 0;
        h++;
    }
    if(h >= 12){
        h = 0;
    }
    delay(1000);
}
