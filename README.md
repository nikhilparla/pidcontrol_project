#### Project Notes and Observations

1. Initial parameters were chosen based on the class projects. Values of 0.2, 0.004 and 3.0 respectively chosen for Kp, Ki and Kd. The car could complete the track without leaving the drivable track surface. This is at 30mph. 
2. Twiddle implementation with initial parameter values as above and vector values for potential changes as {1,1,1} caused the car to veer off track even before it could correct itself. Reduced the speed from 30mph to 10mph to give some time for stabilization, still not sufficient.
3.  Observed that changing param values by a large number , ‘1’ in our case , is really making the steering value jump causing the car to veer off. Will reduce the change to 0.5
4. Corrected the error calculating mechanism. Printing out the accumulated error at every place. Reducing the dp values to 0.5,0.5,0.1. Any change in Ki is drastically affecting steering angle.
5. Car now finishes the track at 10Mph with final parameter values from Twiddle output of {Kp:0.463243	Kd:3.5	Ki: 0.014}
6. Added speed control based on steering angle measurement. The idea is to reduce the speed if there is a large steering value calculation. This will give the car some time to get back to right track.
7. After running the car at 40Mph for some time, the parameter values came to be {Kp: 	0.4775	Kd: 	3.26572	Ki: 	0.004}. Will use this as a basis and continue with Twiddle further.
8. Changed error calculation from +=CTE to +-2*CTE. Observed that a run cycle of 50 times for every change in param value gives better result than 25 times. Also observed that the performance is better over time, which means Twiddle is working. Still observe sharp turns though.
9. Final - Increased the cycle count to 100. Manually configured the final param values to (0.7275, 0.005, 3.137). Commented out the Twiddle function call. Max speed set to 50MPH.