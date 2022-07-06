$fn = 100;
include <piano.scad>;

module TearDrop(radius,length){
  union(){
    cylinder(h=length,r=radius, center = true);
    intersection(){
      translate([0.71*radius,0,0]) rotate([0,0,45]) cube([radius,radius,length], center = true);
      translate([1.71*radius,0,0]) cube([2*radius,2*radius,length], center = true);
    }
  }
}

difference(){
  scale([0.42,0.42,0.42]) translate([-80,-10,0]) Piano(wkd=18,bkd=24);
  translate([0,13,3.3]) rotate([0,-90,0]) TearDrop(radius=1.7,length=200);
}

/* Thing-O-Matic Build Platform */
//translate([-55,-55,-1]) cube([110,110,1]);