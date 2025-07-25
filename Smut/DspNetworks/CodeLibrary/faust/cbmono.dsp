import("stdfaust.lib");

intdel = hslider("del",0,0,1000,0.01);
maxdel = 1024;

b0 = 1;
aN = hslider("aN",0,0,1,0.01);


process = fi.fb_fcomb(maxdel,intdel,b0,aN)
;
