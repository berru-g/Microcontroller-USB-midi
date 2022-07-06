/*
Parametric Piano 
Tony Sherwood <iworkinpixels@gmail.com>
http://github.com/iworkinpixels
http://creativecommons.org/licenses/by/3.0/
*/

include <bitmap.scad>;

/* 
    PIANO
        
    Arguments:
    
    wkl:      White key length.  Defaults to 100.
    wkw:      White key width.   Defaults to 25.
    wkd:      The z depth of the white keys.  Defaults to 7.
    bkl:      Black key length.  Defaults to 70.
    bkw:      Black key width.   Defaults to 12.       
    bkd:      The z depth of the black keys.  Defaults to 10.
    spc:      The spacing between keys.  Defaults to 2.
    oct:      The number of octaves to print.  Defaults to 1.
    owk:      Only print the white keys.  Defaults to false.
    obk:      Only print the black keys.  Defaults to false.
    lbls:     Label the keys with their notes. Defaults to false. 
    lblh:     Label emboss height.  Defaults to 0.5.
    lblb:     Label block size.  Defaults to 1.
*/    
    
module Piano(wkl=100,wkw=25,wkd=7,bkl=60,bkw=12,bkd=10,spc=2,oct=1,owk=false,obk=false,lbls=false,lblh=0.5,lblb=1){  
  // Setup
  octw = (7*wkw) + (7*spc); // Octave Width
  wltrs = ["C","D","E","F","G","A","B"];

  //Mirror the whole thing to get the keys facing in the right direction.
  mirror([0,1,0]){  
    difference() {
      union(){
        if(!obk){
          // White keys
          for(i=[0:oct-1]){
            for(j=[0:6]){     
              translate([(i*octw)+(wkw*j)+(spc*j),0,(wkd/2)]) cube([wkw,wkl,wkd],center=true);
            }
          }
         } 
      }
  
      // Black key holes
      for(i=[0:oct-1]){
        for(j=[0:6]){
          if(j!=2&& j!=6) {    
           translate([(i*octw)+(j*(wkw+spc))+(wkw/2)+(spc/2),0-(wkl/2)+(bkl/2),(wkd/2)-1]) cube([bkw+(2*spc),bkl+spc,wkd+4],center=true);
          }   
        }
      }
    }
    
    // Black keys
    if(!owk){
      for(i=[0:oct-1]){
        for(j=[0:5]){
          if(j!=2) {    
           translate([(i*octw)+(j*(wkw+spc))+(wkw/2)+(spc/2),0-(wkl/2)+(bkl/2),(bkd/2)]) cube([bkw,bkl,bkd],center=true);
          }    
        } 
      }
    }
    
    // Letters
    if(lbls){
      // Label the white keys!
      for(i=[0:oct-1]){
        for(j=[0:6]){
          translate([(i*octw)+(j*(wkw+spc)),(wkl/2.5),wkd]) rotate([0,0,90]) mirror([0,1,0]) 8bit_str(wltrs[j], 1, lblb, lblh);       
        }
      } 
    }
  } // end mirror
} // end module